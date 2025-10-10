#ifndef __RADIO_H
#define __RADIO_H

/**
 * @defgroup    bsp_radio   Radio support
 * @ingroup     bsp
 * @brief       Control the radio peripheral
 *
 * This radio driver supports BLE 1MBit, 2MBit, Long Range 125KBit and Long Range 500KBit.
 *
 * @{
 * @file
 *  @author Anonymous Author <anon@anonymous.com>
 * @author Anonymous Author <anon@anonymous.com>
 * @copyright Anonymized Copyright, 2022-2023
 * @}
 */

#include <nrf.h>

//=========================== defines ==========================================

/// BLE modes supported by the radio
typedef enum {
    RADIO_BLE_1MBit,
    RADIO_BLE_2MBit,
    RADIO_BLE_LR125Kbit,
    RADIO_BLE_LR500Kbit,
    RADIO_IEEE802154_250Kbit,
} radio_mode_t;

#endif
