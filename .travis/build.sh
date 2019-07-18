#!/bin/sh

#
#    Copyright 2019 Google LLC All Rights Reserved.
#
#    Licensed under the Apache License, Version 2.0 (the "License");
#    you may not use this file except in compliance with the License.
#    You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
#    Unless required by applicable law or agreed to in writing, software
#    distributed under the License is distributed on an "AS IS" BASIS,
#    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#    See the License for the specific language governing permissions and
#    limitations under the License.
#

#
#    Description:
#      Travis CI build script for the OpenWeave nRF52840 Lock Example Application.
#

# Initialize and update all submodules within the example app.
#
set -x

# Source the nrf setup variables
. ${TRAVIS_BUILD_DIR}/nrf_setup_vars.sh

git -C ${TRAVIS_BUILD_DIR} submodule init || exit 1
git -C ${TRAVIS_BUILD_DIR} submodule update || exit 1

set +x

# Log relevant build information.
#
echo '---------------------------------------------------------------------------'
echo 'Build Preparation Complete'
echo ''
echo "openweave-nrf52840-lock-example branch: ${TRAVIS_BRANCH}"
echo "Nordic SDK for Thread and Zigbee: ${NORDIC_SDK_URL}"
echo "Nordic nRF5x Command Line Tools: ${NORDIC_COMMAND_LINE_TOOLS_URL}"
echo "ARM GCC Toolchain: ${ARM_GCC_TOOLCHAIN_URL}"
echo 'Commit Hashes'
echo '  openweave-nrf52840-lock-example: '`git -C ${TRAVIS_BUILD_DIR} rev-parse --short HEAD`
echo '---------------------------------------------------------------------------'

# Build the example application.
make -C ${TRAVIS_BUILD_DIR} || exit 1
