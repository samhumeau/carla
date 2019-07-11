// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "carla/MsgPack.h"

namespace carla {
namespace rpc {

  class WalkerKeypoints {
  public:

    WalkerKeypoints() = default;

    geom::Vector3D crl_root = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_hips_c = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_spine_c = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_spine01_c = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_shoulder_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_arm_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_forearm_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_hand_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handthumb_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handthumb01_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handthumb02_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handthumbend_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handindex_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handindex01_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handindex02_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handindexend_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handmiddle_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handmiddle01_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handmiddle02_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handmiddleend_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handring_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handring01_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handring02_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handringend_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handpinky_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handpinky01_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handpinky02_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handpinkyend_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_neck_c = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_head_c = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_eye_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_eye_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_shoulder_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_arm_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_forearm_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_hand_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handthumb_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handthumb01_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handthumb02_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handthumbend_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handindex_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handindex01_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handindex02_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handindexend_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handmiddle_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handmiddle01_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handmiddle02_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handmiddleend_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handring_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handring01_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handring02_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handringend_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handpinky_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handpinky01_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handpinky02_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_handpinkyend_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_thigh_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_leg_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_foot_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_toe_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_toeend_r = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_thigh_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_leg_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_foot_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_toe_l = {0.0f, 0.0f, 0.0f};
    geom::Vector3D crl_toeend_l = {0.0f, 0.0f, 0.0f};

    MSGPACK_DEFINE_ARRAY(
      crl_root,
      crl_hips_c,
      crl_spine_c,
      crl_spine01_c,
      crl_shoulder_l,
      crl_arm_l,
      crl_forearm_l,
      crl_hand_l,
      crl_handthumb_l,
      crl_handthumb01_l,
      crl_handthumb02_l,
      crl_handthumbend_l,
      crl_handindex_l,
      crl_handindex01_l,
      crl_handindex02_l,
      crl_handindexend_l,
      crl_handmiddle_l,
      crl_handmiddle01_l,
      crl_handmiddle02_l,
      crl_handmiddleend_l,
      crl_handring_l,
      crl_handring01_l,
      crl_handring02_l,
      crl_handringend_l,
      crl_handpinky_l,
      crl_handpinky01_l,
      crl_handpinky02_l,
      crl_handpinkyend_l,
      crl_neck_c,
      crl_head_c,
      crl_eye_l,
      crl_eye_r,
      crl_shoulder_r,
      crl_arm_r,
      crl_forearm_r,
      crl_hand_r,
      crl_handthumb_r,
      crl_handthumb01_r,
      crl_handthumb02_r,
      crl_handthumbend_r,
      crl_handindex_r,
      crl_handindex01_r,
      crl_handindex02_r,
      crl_handindexend_r,
      crl_handmiddle_r,
      crl_handmiddle01_r,
      crl_handmiddle02_r,
      crl_handmiddleend_r,
      crl_handring_r,
      crl_handring01_r,
      crl_handring02_r,
      crl_handringend_r,
      crl_handpinky_r,
      crl_handpinky01_r,
      crl_handpinky02_r,
      crl_handpinkyend_r,
      crl_thigh_r,
      crl_leg_r,
      crl_foot_r,
      crl_toe_r,
      crl_toeend_r,
      crl_thigh_l,
      crl_leg_l,
      crl_foot_l,
      crl_toe_l,
      crl_toeend_l)
  };

} // namespace rpc
} // namespace carla
