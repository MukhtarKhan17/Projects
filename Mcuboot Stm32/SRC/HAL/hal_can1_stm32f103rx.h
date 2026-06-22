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
* @{ <h2><center>           (C) VOIDRON CO. 2020-21.          </center></h2> @}
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
* @file     hal_can1_stm32f103rx.h
* @version  V1.0.0 <Update version of this file>
* @brief    HAL CAN1 Routines
*           ---
*           ---
*           ---
* @author   MK
* @date     26-AUG-2021
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

#ifndef HAL_CAN1_STM32F103RX_H
#define HAL_CAN1_STM32F103RX_H

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "vdef_types.h"
#include "stm32f10x.h"
#include "core_cm3.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_can.h"
#include "can_com1.h"
#include "misc.h"

/**
*==============================================================================
*                          	  \V/ Global DefineS
*==============================================================================
*/
#define CAN1_PORT_TXRX_CLK_EN      (RCC_APB2Periph_GPIOA)
#define CAN1_PORT_TXRX_DEF         (GPIOA)
#define CAN1_PIN_RX_DEF        	   (GPIO_Pin_11)
#define CAN1_PIN_TX_DEF        	   (GPIO_Pin_12)
#define CAN1_PIN_RX_SRC        	   (GPIO_PinSource11)
#define CAN1_PIN_TX_SRC        	   (GPIO_PinSource12)

#define CAN1_PORT_RS_CLK_EN        (RCC_APB2Periph_GPIOA)
#define CAN1_PORT_RS_DEF           (GPIOA)
#define CAN1_PIN_RS_DEF        	   (GPIO_Pin_3)

#define CAN1_PORT_LP_CLK_EN        (RCC_APB2Periph_GPIOA)
#define CAN1_PORT_LP_DEF           (GPIOA)
#define CAN1_PIN_LP_DEF        	   (GPIO_Pin_2)


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
typedef enum
{
	BITRATE_125KBPS,
	BITRATE_250KBPS,
	BITRATE_500KBPS,
	BITRATE_1MBPS,
}can1_bitrate_t;


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
extern void Can1_Init(uint32_t mask, uint32_t id );
extern void Can1_TxFrame(can_frm_t can_frm_s);
extern can_frm_t Can1_RxFrame(void);
extern  void Can1_EnableTxInterrupt(void);
extern  void Can1_DisableTxInterrupt(void);


/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     26-AUG-2021
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
#endif // >> End of HAL_CAN1_STM32F103RX_H

