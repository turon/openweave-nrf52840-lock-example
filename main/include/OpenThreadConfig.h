/*
 *
 *    Copyright (c) 2019 Google LLC.
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *      Overrides to default OpenThread configuration.
 *
 */

#ifndef OPENTHREAD_PLATFORM_CONFIG_H
#define OPENTHREAD_PLATFORM_CONFIG_H

// Disable the Nordic-supplied OpenThread logging facilities and use
// the facilities provided by the OpenWeave Device Layer (see
// openweave/src/adaptations/device-layer/nRF5/Logging.cpp).
#define OPENTHREAD_CONFIG_LOG_OUTPUT OPENTHREAD_CONFIG_LOG_OUTPUT_APP

// Turn on a moderate level of logging in OpenThread.
// Set to OT_LOG_LEVEL_INFO or OT_LOG_LEVEL_DEBG for more verbose output if experiencing
// issues with Thread.
#define OPENTHREAD_CONFIG_LOG_LEVEL OT_LOG_LEVEL_NOTE

// When operating in a less than ideal RF environment, having a more forgiving configuration
// of OpenThread makes thread a great deal more reliable.
#define OPENTHREAD_CONFIG_ADDRESS_QUERY_MAX_RETRY_DELAY 120 // default is 28800
#define OPENTHREAD_CONFIG_MAC_MAX_FRAME_RETRIES_DIRECT 15 // default is 3
#define OPENTHREAD_CONFIG_MAC_MAX_FRAME_RETRIES_INDIRECT 1 // default is 0
#define OPENTHREAD_CONFIG_MAC_MAX_TX_ATTEMPTS_INDIRECT_POLLS 16 // default is 4

// Use the Nordic-supplied default platform configuration for remainder
// of OpenThread config options.
//
// NB: This file gets included during the build of OpenThread.  Hence
// it cannot use "openthread" in the path to the included file.
//
#include "openthread-core-nrf52840-config.h"

#endif // OPENTHREAD_PLATFORM_CONFIG_H


