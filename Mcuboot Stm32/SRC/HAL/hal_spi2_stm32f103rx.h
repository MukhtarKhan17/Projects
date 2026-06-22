/**
*##############################################################################
*####################### # # # ################ # # # #########################
*######################## # # # ############## # # # ##########################
*######################### # # # ############ # # # ###########################
*########################## # # # ########## # # # ############################
*########################### # # # ######## # # # #############################
*############################ # # # ###### # # # ##############################
*############################# # # # #### # # # ###############################
*############################## # # # ## # # # ################################
*############################### # # #  # # # #################################
*################################ # # ## # # ##################################
*############################### V O I D R O N ################################
*##############################################################################
*==============================================================================
* @{ <h2><center>           (C) VOIDRON CO. 2023.          </center></h2> @}
*==============================================================================
* @attention
*
* THIS CONTENT IS DESIGNED AND  DEVELOPED BY VOIDRON CO. UNATUHORISED  USED  IS
* PROHIBITED. CONTENT  OF  THIS  FILE  MAY  BE  UNPUBLISHED  OR   CONFIDENTIAL.
* SELLING  OR DISTRIBUTION  WILL  VOID  THE  LICENSE  AND  AGREEMENT  WITH  US.
* DOING  SO MAY LEAD TO  TAKE LEGAL  ACTION BY US  WHICH MAY RESULT IN PENALISE
* OFFENCE CHARGES ON YOU. DON'T  TRY TO MODIFY THE CONTENT OF THIS FILE, IT MAY
* GIVE  UNWANTED  RESULTS. IF  YOU  FIND  ANY TROUBLE  OR WANT  CHANGES  PLEASE
* CONTACT US.
*==============================================================================
* Email: contact@voidron.com          |          Website: www.voidron.com
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ File DetaiL
*==============================================================================
* @file     hal_spi2_stm32f103rx.h
* @version  V1.0.0 <Update version of this file>
* @brief    HAL Routines SPI2
*           ---
*           ---
*           ---
* @author   MK/RS
* @date     16-JAN-2022
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
#ifndef HAL_SPI2_STM32F103RX_H_
#define HAL_SPI2_STM32F103RX_H_

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "stm32f10x.h"
#include "stm32f10x_spi.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "api_sys_tick.h"
/**
*==============================================================================
*                          	  \V/ Global DefineS
*==============================================================================
*/


#define SPI2_CLK_PORT                  (RCC_APB2Periph_GPIOB)
#define SPI2_GPIO_PORT                 (GPIOB)

#define SPI2_CS_GPIO_PIN               (GPIO_Pin_12)
#define SPI2_SCK_GPIO_PIN              (GPIO_Pin_13)
#define SPI2_MISO_GPIO_PIN             (GPIO_Pin_14)
#define SPI2_MOSI_GPIO_PIN             (GPIO_Pin_15)
#define SPI1_CS_GPIO_SRC               (GPIO_PinSource12)
#define SPI1_SCK_GPIO_SRC              (GPIO_PinSource13)
#define SPI1_MOSI_GPIO_SRC             (GPIO_PinSource14)
#define SPI1_MISO_GPIO_SRC             (GPIO_PinSource15)

/**
*==============================================================================
*                          	  \V/ Global MacroS
*==============================================================================
*/
// >> 1. Global Macros


/**
*==============================================================================
*                           \V/ Global Data TypeS
*==============================================================================
*/
// >> Declare global user data types here. Example typedef, structure & union.

/**
*==============================================================================
*                            \V/ Global VariableS
*==============================================================================
*/
// >> Declare Global Variables Here.

/**
*==============================================================================
*                        \V/ Global Function PrototypeS
*==============================================================================
*/
extern void Spi2_MasterInit(void);

extern void Spi2_MasterSetCsHigh(void);
extern void Spi2_MasterSetCsLow(void);

extern uint8_t Spi2_MasterTxRxByte(uint8_t tx_byte);

extern void Spi2_MasterTickIsrPrcs(void);

/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK/RS
* @date     16-JAN-2022
* @brief    Initial Release
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.1
* @author   XX
* @date     DD-MMM-YYYY
* @brief    <Add Change Description>
*           ---
*           ---
*           ---
*##############################################################################
*================================End of FilE===================================
*##############################################################################
*/
// >> 086 079 073 068 082 079 078
#endif /* HAL_SPI2_STM32F103RX_H_ */

