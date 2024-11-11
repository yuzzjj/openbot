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

#ifndef OPENBOT_MAP_RAND_MAP_GENERATOR_HPP_
#define OPENBOT_MAP_RAND_MAP_GENERATOR_HPP_

#include <vector>
#include <string>

#include "openbot/common/macros.hpp"
#include "openbot/common/msgs/msgs.hpp"
#include "openbot/map/mockamap/maps.hpp"
#include "openbot/map/mockamap/map_opionts.hpp"

namespace openbot {
namespace map { 

class MapGenerator
{
public:
    /**
     *  @brief SharedPtr typedef
     */
    OPENBOT_SMART_PTR_DEFINITIONS(MapGenerator);

    MapGenerator(const mockamap::Maps::BasicInfo& option);

    MapGenerator(const mockamap::MapOption& option);

    ~MapGenerator();

    bool Generate(common::sensor_msgs::PointCloud2& point_cloud2);

private:

    mockamap::Maps::SharedPtr map_{nullptr};
    mockamap::Maps::BasicInfo basic_option_;
    mockamap::MapOption option_;
};





}  // namespace map
}  // namespace openbot


#endif  // OPENBOT_MAP_RAND_MAP_GENERATOR_HPP_