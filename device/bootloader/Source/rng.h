#ifndef __RNG_H
#define __RNG_H

/**
 * @defgroup    bsp_rng     Random Number Generator
 * @ingroup     bsp
 * @brief       Read the RNG peripheral
 *
 * @{
 * @file
 * @author Anonymous Author <anon@anonymous.com>
 * @copyright Anonymized Copyright, 2023
 * @}
 */

#include <stdint.h>

//=========================== defines ==========================================

//=========================== prototypes =======================================

/**
 * @brief Configure the random number generator (RNG)
 */
void rng_init(void);

/**
 * @brief Read a random value (8 bits)
 *
 * @param[out] value address of the output value
 */
void rng_read(uint8_t *value);

#endif
