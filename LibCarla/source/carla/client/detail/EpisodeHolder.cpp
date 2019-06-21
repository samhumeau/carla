// Copyright (c) 2019 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include "carla/client/detail/EpisodeHolder.h"

#include "carla/AtomicSharedPtr.h"
#include "carla/NonCopyable.h"
#include "carla/RecurrentSharedFuture.h"
#include "carla/client/Timestamp.h"
#include "carla/client/WorldSnapshot.h"
#include "carla/client/detail/CachedActorList.h"
#include "carla/client/detail/CallbackList.h"
#include "carla/client/detail/EpisodeState.h"
#include "carla/rpc/EpisodeInfo.h"

#include <mutex>

namespace carla {
namespace client {
namespace detail {

  static auto &CastData(const sensor::SensorData &data) {
    using target_t = const sensor::data::RawEpisodeState;
    return static_cast<target_t &>(data);
  }

  class EpisodeHolder::Episode {
  public:

    void Tick(WorldSnapshot state);

    void TickOutdated(WorldSnapshot state);

  private:

    WalkerNavigation _navigation;

    CachedActorList _actors;

    CallbackList<WorldSnapshot> _on_tick_callbacks;
  };

  void EpisodeHolder::Episode::Tick(WorldSnapshot state, bool outdated) {
    _on_tick_callbacks.Call(state);
  }

  void EpisodeHolder::Episode::TickOutdated(WorldSnapshot state, bool outdated) {
    _on_tick_callbacks.Call(state);
  }

  void EpisodeHolder::InitializeEpisode(Client &client) {
    auto info = client.GetEpisodeInfo();
    _episode = std::make_shared<Episode>();
    _state = std::make_shared<EpisodeState>(info.id);
    client.SubscribeToStream(
        info.token,
        [this](auto &&data) { Tick(std::move(data)); });
  }

  void EpisodeHolder::Tick(Buffer &&buffer) {
    CARLA_PROFILE_SCOPE(EpisodeHolder, Tick);

    auto data = sensor::Deserializer::Deserialize(std::move(buffer));

    auto next = std::make_shared<const EpisodeState>(CastData(*data));
    auto prev = GetState();

    do {
      if (prev->GetFrameCount() >= next->GetFrameCount()) {
        _episode->TickOutdated(next);
        return;
      }
    } while (!_state.compare_exchange(&prev, next));

    if (next->GetEpisodeId() != prev->GetEpisodeId()) {
      // New episode started, this part is guaranteed to be called only once
      // per episode change.
      _episode = std::make_shared<Episode>();
    }

    _notify_wait_for_tick.SetValue(next);
    _episode->Tick(next);
  }

} // namespace detail
} // namespace client
} // namespace carla
