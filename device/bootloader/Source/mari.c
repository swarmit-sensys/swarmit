/**
 * @file
 * @ingroup drv_tdma_client
 *
 * @brief  nrf5340-app-specific definition of the "tdma_client" drv module.
 *
 *  @author Anonymous Author <anon@anonymous.com>
 *
 * @copyright Anonymized Copyright, 2024
 */
#include <nrf.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "ipc.h"
#include "tz.h"
#include "mari.h"

//=========================== variables ========================================

extern volatile __attribute__((section(".shared_data"))) ipc_shared_data_t ipc_shared_data;

//=========================== public ===========================================

void mari_init(void) {

    // APPMUTEX (address at 0x41030000 => periph ID is 48)
    tz_configure_periph_non_secure(NRF_APPLICATION_PERIPH_ID_MUTEX);

    // Initialize TDMA client drv in the net-core
    ipc_network_call(IPC_MARI_INIT_REQ);
}

void mari_node_tx(const uint8_t *packet, uint8_t length) {
    ipc_shared_data.tx_pdu.length = length;
    memcpy((void *)ipc_shared_data.tx_pdu.buffer, packet, length);
    ipc_network_call(IPC_MARI_NODE_TX_REQ);
}
