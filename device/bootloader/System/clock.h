#ifndef __CLOCK_H
#define __CLOCK_H

/**
 * @defgroup    bsp_clock   Clock
 * @ingroup     bsp
 * @brief       Functions to initialize low and high frequency clocks
 *
 * @{
 * @file
 * @author Anonymous Author <anon@anonymous.com>
 * @copyright Anonymized Copyright, 2022
 * @}
 */

#if defined(NRF5340_XXAA)
#if defined(NRF_APPLICATION)
#define NRF_CLOCK NRF_CLOCK_S
#else
#define NRF_CLOCK NRF_CLOCK_NS
#endif
#endif

/**
 * @brief Initialize and start the High Frequency clock
 */
void hfclk_init(void);

/**
 * @brief Initialize and start the Low Frequency clock
 */
void lfclk_init(void);

#endif
