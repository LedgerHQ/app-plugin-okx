/*******************************************************************************
 *   Ethereum 2 Deposit Application
 *   (c) 2020 Ledger
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ********************************************************************************/

#include <stdint.h>
#include "okx_plugin.h"

// List of selectors supported by this plugin.
static const uint32_t OKX_EARN_SWAP_SELECTOR = 0x016cba5f;
static const uint32_t OKX_DEX_UNX_SWAP_BY_ORDER_ID_SELECTOR = 0x9871efa4;
static const uint32_t OKX_DEX_UNI_SWAPV3_SWAP_TO_SELECTOR = 0x0d5f0e3b;
static const uint32_t OKX_DEX_PMMV2_SWAP_SELECTOR = 0x12a0ddc7;
static const uint32_t OKX_DEX_SMART_SWAP_BY_ORDER_ID_SELECTOR = 0xb80c2f09;
static const uint32_t OKX_DEX_BRIDGE_TO_V2_SELECTOR = 0x972250fe;
static const uint32_t OKX_DEX_SWAP_BRIDGE_TO_V2_SELECTOR = 0x3d21e25a;

// Array of all the different boilerplate selectors. Make sure this follows the same order as the
// enum defined in `okx_plugin.h`
const uint32_t OKX_SELECTORS[NUM_SELECTORS] = {
    OKX_EARN_SWAP_SELECTOR,
    OKX_DEX_UNX_SWAP_BY_ORDER_ID_SELECTOR,
    OKX_DEX_UNI_SWAPV3_SWAP_TO_SELECTOR,
    OKX_DEX_PMMV2_SWAP_SELECTOR,
    OKX_DEX_SMART_SWAP_BY_ORDER_ID_SELECTOR,
    OKX_DEX_BRIDGE_TO_V2_SELECTOR,
    OKX_DEX_SWAP_BRIDGE_TO_V2_SELECTOR,
};
