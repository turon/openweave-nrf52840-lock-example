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

#include "ble_config.h"

// Disable the Nordic-supplied OpenThread logging facilities and use
// the facilities provided by the OpenWeave Device Layer (see
// openweave/src/adaptations/device-layer/nRF5/Logging.cpp).
#define OPENTHREAD_CONFIG_LOG_OUTPUT OPENTHREAD_CONFIG_LOG_OUTPUT_APP

// Turn on a moderate level of logging in OpenThread.
// Set to OT_LOG_LEVEL_INFO or OT_LOG_LEVEL_DEBG for more verbose output if experiencing
// issues with Thread.
#define OPENTHREAD_CONFIG_LOG_LEVEL OT_LOG_LEVEL_DEBG

// To turn on Nordic platform logs set this to 1
#define OPENTHREAD_CONFIG_LOG_PLATFORM 1

/// Turns on Child Supervision to properly recover network connectivity after device reset.
#define OPENTHREAD_CONFIG_CHILD_SUPERVISION_ENABLE 0

// When operating in a less than ideal RF environment, having a more forgiving configuration
// of OpenThread makes thread a great deal more reliable.
#define OPENTHREAD_CONFIG_MAC_MAX_FRAME_RETRIES_DIRECT 15 // default is 3
#define OPENTHREAD_CONFIG_MAC_MAX_FRAME_RETRIES_INDIRECT 1 // default is 0
#define OPENTHREAD_CONFIG_MAC_MAX_TX_ATTEMPTS_INDIRECT_POLLS 16 // default is 4

// ==============================================================
//          CONFIG TOBLE
// ==============================================================

#if OPENTHREAD_CONFIG_ENABLE_TOBLE

#define OPENTHREAD_CONFIG_ENABLE_BLE 1
#define OPENTHREAD_CONFIG_ENABLE_TOBLE_TO_BLE 1
#define OPENTHREAD_CONFIG_TOBLE_CENTRAL_ENABLE 0
#define OPENTHREAD_CONFIG_TOBLE_PERIPHERAL_ENABLE 1
#define OPENTHREAD_CONFIG_TOBLE_MULTI_RADIO_ENABLE 1
#define OPENTHREAD_CONFIG_TOBLE_154_ATTACH_ATTEMPT_RATIO 0

#define OPENTHREAD_DISABLE_TOBLE_GATT_ACKNOWLEDGEMENTS 0

#define OPENTHREAD_CONFIG_6LOWPAN_REASSEMBLY_TIMEOUT 60
#define OPENTHREAD_CONFIG_MLE_PARENT_REQUEST_ROUTER_TIMEOUT 1500
#define OPENTHREAD_CONFIG_MLE_PARENT_REQUEST_REED_TIMEOUT 3000

#define OPENTHREAD_CONFIG_BLE_EVENTS 1

#endif // OPENTHREAD_CONFIG_ENABLE_TOBLE

#define OPENTHREAD_CONFIG_NORDIC_BLE_CFG_TAG NRF_BLE_CFG_TAG

// Use the Nordic-supplied default platform configuration for remainder
// of OpenThread config options.  Include *after* application overrides above.
//
// NB: This file gets included during the build of OpenThread.  Hence
// it cannot use "openthread" in the path to the included file.
//
#include "openthread-core-nrf52840-config.h"

#endif // OPENTHREAD_PLATFORM_CONFIG_H
