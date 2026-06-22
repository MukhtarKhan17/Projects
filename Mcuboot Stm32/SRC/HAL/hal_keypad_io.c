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
* @file     hal_keypad_io.c
* @version  V1.0.0
* @brief    HAL Keypad IO
*           ---
*           ---
*           ---
* @author   MK
* @date     26-MAR-2021
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "hal_keypad_io.h"


/**
*==============================================================================
*                          	   \V/ Local DefineS
*==============================================================================
*/
// >> 1. Local Constants


/**
*==============================================================================
*                          	    \V/ Local MacroS
*==============================================================================
*/
// >> 1. Local Macros


/**
*==============================================================================
*                             \V/ Local Data TypeS
*==============================================================================
*/
// >> Declare local user data types here. Example typedef, structure & union.

/**
*==============================================================================
*                              \V/ Local VariableS
*==============================================================================
*/


/**
*==============================================================================
*                          \V/ Local Function PrototypeS
*==============================================================================
*/
// >> Declare Local Function Prototypes Here.


/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void KeypadIO_GpioInit (void)
*==============================================================================
* @brief    KeypadIO_GpioInit
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     26-MAR-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void KeypadIO_GpioInit (void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(KEY_PORT_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = (KEY_SEL_PIN | KEY_UP_PIN | KEY_DN_PIN | KEY_BCK_PIN);
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(KEY_PORT, &GPIO_InitStructure);
} // End of KeypadIO_GpioInit()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t KeypadIO_RdKeySts (uint8_t key_num)
*==============================================================================
* @brief    KeypadIO_RdKeySts
*           ---
*           ---
*           ---
* @note     None
* @param    key_num
* @retval   key_sts_f
* @author   MK
* @date     26-MAR-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t KeypadIO_RdKeySts (uint8_t key_num)
{
	bool_t key_sts_f = FALSE;

	switch(key_num)
	{
		case SEL_KEY:
			if(GPIO_ReadInputDataBit(KEY_PORT, KEY_SEL_PIN) == Bit_RESET)
			{
				key_sts_f = TRUE;
			}
			break;

		case UP_KEY:
			if(GPIO_ReadInputDataBit(KEY_PORT, KEY_UP_PIN) == Bit_RESET)
			{
				key_sts_f = TRUE;
			}
			break;

		case DOWN_KEY:
			if(GPIO_ReadInputDataBit(KEY_PORT, KEY_DN_PIN) == Bit_RESET)
			{
				key_sts_f = TRUE;
			}
			break;

		case BACK_KEY:
			if(GPIO_ReadInputDataBit(KEY_PORT, KEY_BCK_PIN) == Bit_RESET)
			{
				key_sts_f = TRUE;
			}
			break;

		default:
			break;
	}

	return(key_sts_f);
} // End of KeypadIO_RdKeySts()


/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     26-MAR-2021
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
