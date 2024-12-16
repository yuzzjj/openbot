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


#include "openbot/transform/static_transform_component.hpp"

#include "cyber/init.h"
#include "gtest/gtest.h"

namespace openbot {
namespace transform {

TEST(TransformComponentTest, Init) 
{
  ::apollo::cyber::Init("transform_component_test");
  StaticTransformComponent component;
}

}  // namespace transform
}  // namespace openbot
