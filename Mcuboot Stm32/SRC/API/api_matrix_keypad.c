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
* @file     api_matrix_keypad.c
* @version  V1.0.0
* @brief    API Matrix Keypad
*           ---
*           ---
*           ---
* @author   MK
* @date     16-OCT-2023
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "api_matrix_keypad.h"


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
int8_t vTag_MatrixKeypad_Key[] = "VOIDRON";

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
* @fn  void MatrixKeypad_Init (void)
*==============================================================================
* @brief    MatrixKeypad_Init
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     16-OCT-2023 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void MatrixKeypad_Init (void)
{
	matrix_keypad_base_t set_matrix_keypad_base_s = {0};

	set_matrix_keypad_base_s.GpioInit   = &MatrixKeypadIO_GpioInit;
	set_matrix_keypad_base_s.SelectLine = &MatrixKeypadIO_SelectLine;
	set_matrix_keypad_base_s.ReadLine   = &MatrixKeypadIO_ReadLine;
	set_matrix_keypad_base_s.GetTickMs  = &SysTick_GetTickTmrVal;
	set_matrix_keypad_base_s.ChkTimeout = &SysTick_CheckTimeOut;

	set_matrix_keypad_base_s.debounce_timeout_ms   = KEYPAD_DEBOUNCE_MS;
	set_matrix_keypad_base_s.press_timeout_ms      = KEYPAD_KEY_PRESS_MS;
	set_matrix_keypad_base_s.detect_method         = DETECT_ON_RELEASE;

	MatrixKeypad_BaseInit(set_matrix_keypad_base_s);
	(void)MatrixKeypad_Enable(vTag_MatrixKeypad_Key);
} // >> End of MatrixKeypad_Init()


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
