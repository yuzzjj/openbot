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



#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include "cyber/class_loader/class_loader.h"
#include "cyber/component/component.h"
#include "cyber/message/raw_message.h"

#include "openbot/common/macros.hpp"
#include "openbot/map/proto/grid_map.pb.h"
#include "openbot/map/proto/filter_config.pb.h"


using openbot::map::FilterConfig;

namespace openbot {
namespace map { 

class MapComponent final : public apollo::cyber::Component<> 
{
public:
    MapComponent() = default;
    ~MapComponent() = default;

    bool Init() override;

private:

    std::shared_ptr<FilterConfig> filter_config_;

};

CYBER_REGISTER_COMPONENT(MapComponent)

}  // namespace map 
}  // namespace openbot
