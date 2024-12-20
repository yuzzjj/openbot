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

#ifndef OPENBOT_COMMON_COVARIANCE_INSERTION__TRAITS_HPP_
#define OPENBOT_COMMON_COVARIANCE_INSERTION__TRAITS_HPP_

#include <type_traits>

namespace openbot {
namespace common {
namespace covariance_insertion {

template<typename T, typename = void>
struct has_covariance_member : std::false_type {};

template<typename T>
struct has_covariance_member<T, decltype((void)T::covariance, void())>: std::true_type
{
};

template<typename T, typename = void>
struct has_pose_member : std::false_type {};

template<typename T>
struct has_pose_member<T, decltype((void)T::pose, void())>: std::true_type
{
};

template<typename T, typename = void>
struct has_twist_member : std::false_type {};

template<typename T>
struct has_twist_member<T, decltype((void)T::twist, void())>: std::true_type
{
};

}  // namespace covariance_insertion
}  // namespace common
}  // namespace openbot


#endif  // OPENBOT_COMMON_COVARIANCE_INSERTION__TRAITS_HPP_
