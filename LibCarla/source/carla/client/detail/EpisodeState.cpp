// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include "carla/client/detail/EpisodeState.h"

namespace carla {
namespace client {
namespace detail {

  EpisodeState::EpisodeState(const sensor::data::RawEpisodeState &state)
    : _episode_id(state.GetEpisodeId()),
      _timestamp(
          state.GetFrame(),
          state.GetGameTimeStamp(),
          state.GetDeltaSeconds(),
          state.GetPlatformTimeStamp()) {
    _actors.reserve(state.size());
    for (auto &&actor : state) {
      DEBUG_ONLY(auto result = )
      _actors.emplace(
          actor.id,
          ActorSnapshot{
              actor.id,
              actor.transform,
              actor.velocity,
              actor.angular_velocity,
              actor.acceleration,
              actor.state,
              actor.keypoints});
      DEBUG_ASSERT(result.second);
    }
  }

} // namespace detail
} // namespace client
} // namespace carla
