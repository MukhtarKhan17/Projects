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
* @{ <h2><center>            (C) VOIDRON CO. 2023             </center></h2> @}
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
* @file     hal_matrix_keypad_io.h
* @version  V1.0.0
* @brief    HAL Matrix Keypad IO
*           ---
*           ---
*           ---
* @author   MK
* @date     16-OCT-2023
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

#ifndef HAL_MATRIX_KEYPAD_IO_H_
#define HAL_MATRIX_KEYPAD_IO_H_

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
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"



/**
*==============================================================================
*                          	  \V/ Global DefineS
*==============================================================================
*/
#define KEYPAD_ROW_PORT_CLK      	(RCC_APB2Periph_GPIOB)
#define KEYPAD_ROW_PORT				(GPIOB)
#define KEYPAD_R1_PIN				(GPIO_Pin_4)  //(GPIO_Pin_9)
#define KEYPAD_R2_PIN				(GPIO_Pin_5)  //(GPIO_Pin_8)
#define KEYPAD_R3_PIN				(GPIO_Pin_6)  //(GPIO_Pin_11)
#define KEYPAD_R4_PIN				(GPIO_Pin_7)  //(GPIO_Pin_10)

#define KEYPAD_COL_PORT_CLK      	(RCC_APB2Periph_GPIOB)
#define KEYPAD_COL_PORT				(GPIOB)
#define KEYPAD_C1_PIN				(GPIO_Pin_8)   //(GPIO_Pin_5)
#define KEYPAD_C2_PIN				(GPIO_Pin_9)   //(GPIO_Pin_4)
#define KEYPAD_C3_PIN				(GPIO_Pin_10)  //(GPIO_Pin_7)
#define KEYPAD_C4_PIN				(GPIO_Pin_11)  //(GPIO_Pin_6)


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
extern void MatrixKeypadIO_GpioInit (void);
extern void MatrixKeypadIO_SelectLine (uint8_t sel_val);
extern uint8_t MatrixKeypadIO_ReadLine (void);



/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     16-OCT-2023
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
#endif // >> End of HAL_MATRIX_KEYPAD_IO_H_

