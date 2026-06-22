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
* @file     api_x_modem.c
* @version  V1.0.0 <Update version of this file if changing>
* @brief    API X-MODEM
*           ---
*           ---
*           ---
* @author   MK
* @date     22-AUG-2021
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "api_x_modem.h"


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
int8_t vTag_Xmodem_Key[] = "VOIDRON";

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
* @fn  void Xmodem_Init (void)
*==============================================================================
* @brief    Xmodem_Init
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     22-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Xmodem_Init (void)
{
	x_modem_base_t set_x_modem_base_s = {0};

	set_x_modem_base_s.ComTxCbufInit = &UartCom3_TxCbufInit;
	set_x_modem_base_s.ComRxCbufInit = &UartCom3_RxCbufInit;
	set_x_modem_base_s.ComTxData     = &UartCom3_TxData;
	set_x_modem_base_s.ComRxData     = &UartCom3_RxData;
	set_x_modem_base_s.ComRxDataSz   = &UartCom3_GetRxDataSz;
	set_x_modem_base_s.ComDirTxOn    = &Rs485Dir_TxOn;
	set_x_modem_base_s.ComDirRxOn    = &Rs485Dir_RxOn;
	set_x_modem_base_s.DelayMs       = &SysTick_Delay;
	set_x_modem_base_s.GetTickMs     = &SysTick_GetTickTmrVal;
	set_x_modem_base_s.ChkTimeout    = &SysTick_CheckTimeOut;
	set_x_modem_base_s.dir_delay_ms  = 1;

	Xmodem_BaseInit(set_x_modem_base_s);
	Xmodem_Config();

	(void)Xmodem_Enable(vTag_Xmodem_Key);
} // End of Xmodem_Init()

/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     22-AUG-2021
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
