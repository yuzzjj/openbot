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

#include "openbot/common/macros.hpp"
#include "openbot/common/utils/logging.hpp"

namespace openbot {
namespace bridge { 

class BridgeServer
{
public:
    /**
     *  @brief SharedPtr typedef
     */
    OPENBOT_SMART_PTR_DEFINITIONS(BridgeServer);

    /**
     * @brief A constructor for openbot::bridge::BridgeServer
     * @param options Additional options to control creation of the node.
     */
    explicit BridgeServer();

    /**
     * @brief Destructor for openbot::bridge::BridgeServer
     */
    ~BridgeServer();

private:

};

}  // namespace bridge 
}  // namespace openbot