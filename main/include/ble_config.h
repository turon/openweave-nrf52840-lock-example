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

#ifndef BLE_CONFIG_H
#define BLE_CONFIG_H

/**
 * @file
 *   This file implements the BLE configuration shared by OpenThread and OpenWeave.
 */

// ---- BLE Config ----
#define NRF_BLE_CFG_TAG	1

/**
 * Increase # of connections supported to two so both WoBLE and ToBLE can advertise.
 */
#define NRF_SDH_BLE_PERIPHERAL_LINK_COUNT 2

/**
 * To enable the Thread-over-BLE feature set this to 1.
 */
#define OPENTHREAD_CONFIG_ENABLE_TOBLE 1

#if OPENTHREAD_CONFIG_ENABLE_TOBLE
/**
 * When ToBLE enabled, use the same advertising handle for ToBLE and WoBLE.
 */
#define BLE_DEFAULT_ADVERTISING_HANDLE  0
#else
#define BLE_DEFAULT_ADVERTISING_HANDLE  BLE_GAP_ADV_SET_HANDLE_NOT_SET
#endif

#endif // BLE_CONFIG_H
