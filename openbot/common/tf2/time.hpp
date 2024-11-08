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

#ifndef OPENBOT_COMMON_TF2_TIME_HPP_
#define OPENBOT_COMMON_TF2_TIME_HPP_

#include <stdint.h>
#include <limits>

#include "openbot/common/msgs/msgs.hpp"

namespace openbot {
namespace common {
namespace tf2 {

// typedef uint64_t Time;
using Time = builtin_interfaces::Time;
typedef uint64_t Duration;
const uint64_t TIME_MAX = std::numeric_limits<uint64_t>::max();

double time_to_sec(Time t);
}  // namespace tf2
}  // namespace common
}  // namespace openbot

#endif  // OPENBOT_COMMON_TF2_TIME_HPP_
