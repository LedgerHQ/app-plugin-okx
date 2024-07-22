#include "okx_plugin.h"

// Called once to init.
void handle_init_contract(ethPluginInitContract_t *msg) {
    // Make sure we are running a compatible version.
    if (msg->interfaceVersion != ETH_PLUGIN_INTERFACE_VERSION_LATEST) {
        // If not the case, return the `UNAVAILABLE` status.
        msg->result = ETH_PLUGIN_RESULT_UNAVAILABLE;
        return;
    }

    // Double check that the `context_t` struct is not bigger than the maximum size (defined by
    // `msg->pluginContextLength`).
    if (msg->pluginContextLength < sizeof(context_t)) {
        PRINTF("Plugin parameters structure is bigger than allowed size\n");
        msg->result = ETH_PLUGIN_RESULT_ERROR;
        return;
    }

    context_t *context = (context_t *) msg->pluginContext;

    // Initialize the context (to 0).
    memset(context, 0, sizeof(*context));

    size_t index;
    if (!find_selector(U4BE(msg->selector, 0), OKX_SELECTORS, NUM_SELECTORS, &index)) {
        msg->result = ETH_PLUGIN_RESULT_UNAVAILABLE;
        return;
    }
    context->selectorIndex = index;

    // Set `next_param` to be the first field we expect to parse.
    switch (context->selectorIndex) {
        case OKX_EARN_SWAP:
            context->next_param = EARN_STAKE;
            break;
        case OKX_DEX_UNX_SWAP_BY_ORDER_ID:
            context->next_param = DEX_UNX_SWAP_BY_ORDER_ID;
            break;
        case OKX_DEX_UNI_SWAPV3_SWAP_TO:
            context->next_param = DEX_UNI_SWAPV3_SWAP_TO;
            break;
        case OKX_DEX_PMMV2_SWAP:
            context->next_param = DEX_PMMV2_SWAP;
            break;
        case OKX_DEX_SMART_SWAP_BY_ORDER_ID:
            context->next_param = DEX_SMART_SWAP_BY_ORDER_ID;
            break;
        case OKX_DEX_BRIDGE_TO_V2:
            context->next_param = DEX_BRIDGE_TO_V2;
            break;
        case OKX_DEX_SWAP_BRIDGE_TO_V2:
            context->next_param = DEX_SWAP_BRIDGE_TO_V2;
            break;
        // Keep this
        default:
            PRINTF("Missing selectorIndex: %d\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return;
    }

    // Return valid status.
    msg->result = ETH_PLUGIN_RESULT_OK;
}
