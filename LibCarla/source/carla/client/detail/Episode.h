// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
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

#include <vector>

namespace carla {
namespace client {
namespace detail {

  class Episode : private NonCopyable {
  public:

    CachedActorList &GetCachedActors();

    void RegisterOnTickCallback(std::function<void(WorldSnapshot)> &&callback) {
      _on_tick_callbacks.RegisterCallback(std::move(callback));
    }

    void Tick(WorldSnapshot state) {
      _on_tick_callbacks.Call(state);
    }

    void TickOutdated(WorldSnapshot state) {
      _on_tick_callbacks.Call(state);
    }

  private:

    WalkerNavigation _navigation;

    CachedActorList _actors;

    CallbackList<WorldSnapshot> _on_tick_callbacks;
  };

} // namespace detail
} // namespace client
} // namespace carla
