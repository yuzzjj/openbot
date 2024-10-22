/*
 * Copyright 2024 The OpenRobotic Beginner Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OPENBOT_SMOOTHER_COMPONENTS_SAVITZKY_GOLAY_SMOOTHER_HPP_
#define OPENBOT_SMOOTHER_COMPONENTS_SAVITZKY_GOLAY_SMOOTHER_HPP_

#include <memory>
#include <string>

#include "openbot/common/macros.hpp"
#include "openbot/smoother/smoother.hpp"
#include "openbot/common/proto/nav_msgs/path.pb.h"
#include "openbot/common/proto/geometry_msgs/twist.pb.h"
#include "openbot/common/proto/geometry_msgs/twist_stamped.pb.h"
#include "openbot/common/proto/geometry_msgs/pose_stamped.pb.h"

namespace openbot {
namespace smoother { 
namespace components { 

/**
 * @class Smoother
 * @brief smoother interface that acts as a virtual base class for all controller plugins
 */
class SavitzkyGolaySmoother : public Smoother
{
public:
  /**
   *  @brief SharedPtr
   */
  OPENBOT_SMART_PTR_DEFINITIONS(SavitzkyGolaySmoother)

  /**
   * @brief Virtual destructor
   */
  virtual ~SavitzkyGolaySmoother();

  /**
   * @param name
   */
  virtual void Configure() override;

  /**
   * @brief Method to cleanup resources.
   */
  virtual void Cleanup() override;

  /**
   * @brief Method to active planner and any threads involved in execution.
   */
  virtual void Activate() override;

  /**
   * @brief Method to deactive planner and any threads involved in execution.
   */
  virtual void Deactivate() override;

  /**
   * @brief Method to smooth given path
   *
   * @param path In-out path to be smoothed
   * @param max_time Maximum duration smoothing should take
   * @return If smoothing was completed (true) or interrupted by time limit (false)
   */
  virtual bool Smooth(
      common::proto::nav_msgs::Path& path,
      const common::Duration & max_time) = 0;

};

}  // namespace components
}  // namespace smoother 
}  // namespace openbot

#endif  // OPENBOT_SMOOTHER_COMPONENTS_SAVITZKY_GOLAY_SMOOTHER_HPP_
