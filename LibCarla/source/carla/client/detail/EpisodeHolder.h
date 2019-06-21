// Copyright (c) 2019 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "carla/AtomicSharedPtr.h"
#include "carla/NonCopyable.h"
#include "carla/RecurrentSharedFuture.h"
#include "carla/client/Timestamp.h"
#include "carla/client/WorldSnapshot.h"
#include "carla/client/detail/CachedActorList.h"
#include "carla/client/detail/CallbackList.h"
#include "carla/client/detail/EpisodeState.h"
#include "carla/client/detail/WalkerNavigation.h"
#include "carla/rpc/EpisodeInfo.h"

#include <mutex>

namespace carla {
namespace client {
namespace detail {

  /// Holds the current episode, and the current episode state.
  class EpisodeHolder : private NonCopyable {
  public:

    /// @pre Can only be called once.
    /// @pre The client should be destroyed before this object is destroyed.
    void InitializeEpisode(Client &client);

    std::shared_ptr<Episode> GetEpisode() {
      return _episode.Load();
    }

    std::shared_ptr<const EpisodeState> GetEpisodeState() const {
      return _state.Load();
    }

  private:

    class Episode;

    void Tick(Buffer &&episode_data);

    AtomicSharedPtr<Episode> _episode;

    AtomicSharedPtr<const EpisodeState> _state;

    RecurrentSharedFuture<WorldSnapshot> _notify_wait_for_tick;
  };

} // namespace detail
} // namespace client
} // namespace carla
