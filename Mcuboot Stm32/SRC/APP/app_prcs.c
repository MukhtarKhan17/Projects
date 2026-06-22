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
* @file     app_prcs.c
* @version  V1.0.0 <Update version of this file>
* @brief    TODO: <Write the file description over here>
*           ---
*           ---
*           ---
* @author   MK
* @date     21-FEB-2021
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "app_prcs.h"


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
typedef enum
{
	PWR_UP_PRCS_STATE = 0,
	APP_MAIN_PRCS_STATE,
	APP_TEST_PRCS_STATE
}app_loop_prcs_state_t;

/**
*==============================================================================
*                              \V/ Local VariableS
*==============================================================================
*/
// >> Declare Local Variables Here.

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
* @fn  void App_LoopPrcs (void)
*==============================================================================
* @brief    App_LoopPrcs
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     21-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void App_LoopPrcs (void)
{
	static app_loop_prcs_state_t app_loop_prcs_state = APP_TEST_PRCS_STATE;
	bool_t prcs_ovr_f = FALSE;
	static uint32_t prcs_tmr = 0;
//	uint8_t key_val = NO_KEY;
	GoledDisp_Refresh();
//	Xmodem_PktRxPrcs();

	switch(app_loop_prcs_state)
	{
		case PWR_UP_PRCS_STATE:
			prcs_ovr_f = PwrUp_Prcs();
			if(prcs_ovr_f == TRUE)
			{
				ErrInd_Disable();
//				WebHost_Init();
				app_loop_prcs_state = APP_TEST_PRCS_STATE;
			}
			break;

		case APP_MAIN_PRCS_STATE:
//			WebHost_Prcs();
			break;

		case APP_TEST_PRCS_STATE:
			#if(TRUE)
			Disp_TestPrcs();
//			Comm_TcpLoopBckPrcs();
//			Comm_UdpLoopBckPrcs();
			if(SysTick_CheckTimeOut(&prcs_tmr, 50)== TRUE)
			{
				StsLed_Toggle();
			}
			#endif
			break;

		default:
			app_loop_prcs_state = PWR_UP_PRCS_STATE;
			break;
	}

}// >>End of App_LoopPrcs

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void App_TickPrcs (void)
*==============================================================================
* @brief    App_TickPrcs
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     21-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void App_TickPrcs (void)
{
	#define IDLE_COMM_TO_MS            (30000U)
//	UartCom1_TickIsrPrcs();
//	UartCom2_TickIsrPrcs();
//	UartCom3_TickIsrPrcs();
//	ErrInd_TickIsrPrcs();
//	Esp8266_RxScanPrcs();
//	Keypad_ScanPrcs();
//	CanCom1_TickIsrPrcs();
}// >>End of App_TickPrcs

/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     DD-MMM-YYYY
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
