#!/usr/bin/env bash

###############################################################################
# Copyright 2024 The AOpenRobotic Beginner Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
###############################################################################

# Fail on first error.
set -e

# Clean up.
rm -rf build

cd /openbot/3rdparty
git clone https://github.com/abseil/abseil-cpp.git
mkdir build && cd build && cmake ..
make -j6
make install

# Clean up.
rm -rf build
