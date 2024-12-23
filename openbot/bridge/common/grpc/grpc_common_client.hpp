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
#include <mutex>

#include <grpc++/grpc++.h>

#include "cyber/cyber.h"

#include "openbot_bridge/sensor_msgs/sensor_image.pb.h"
#include "openbot_bridge/service_msgs/sensor_service.pb.h"
#include "openbot_bridge/service_msgs/sensor_service.grpc.pb.h"


namespace openbot {
namespace bridge { 
namespace grpc { 

template <class ServiceType, class RequestType, class ResponseType>
class GrpcClient 
{
  public:
    OPENBOT_SMART_PTR_DEFINITIONS(GrpcClient);
    
    using RpcMethod = std::function<::grpc::Status(ServiceType*, ::grpc::ClientContext*, const RequestType&, ResponseType*)>;    
    
    /**
     * @brief construct function
     * @param input car_status type msg shared ptr
     */
    explicit GrpcClient(std::unique_ptr<ServiceType>& stub_ptr):stub_(std::move(stub_ptr))
    {
       CHECK(!!stub_);
       LOG(INFO) << "GrpcClient initial success";
       init_flag_ = true;  
    } 

    ~GrpcClient() {}

    bool InitFlag() { return init_flag_; }

    void StartListen() {}

    void registerMethod(const std::string& method_name, const RpcMethod& method) {
        methods_[method_name] = method;
    }

    /**
     * @brief function that send car status msg through grpc
     * @param input car_status type msg shared ptr
     */
    bool CallMethod(const std::string& method_name, const RequestType& request, ResponseType* response, int timeout_ms=5000)
    {
       auto it = methods_.find(method_name);
       if (it != methods_.end()) {
         ::grpc::ClientContext context;
         context.set_deadline(std::chrono::system_clock::now() + std::chrono::milliseconds(timeout_ms));
         ::grpc::Status status = it->second(stub_.get(), &context, request, response);
         if (status.ok()) {
            return true;
         } else {
           std::cerr << "RPC failed: " << status.error_message() << std::endl;
         }
       } else {
         std::cerr << "Unsupported method: " << method_name << std::endl;
       }
       return false;
    }

private:
    // grpc service stub
    std::shared_ptr<ServiceType> stub_;

    bool init_flag_ = false;

    std::unordered_map<std::string, RpcMethod> methods_;
};
}  // namespace grpc 
}  // namespace bridge 
}  // namespace openbot
