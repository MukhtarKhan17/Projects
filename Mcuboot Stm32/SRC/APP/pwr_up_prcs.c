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
* @file     pwr_up_prcs.c
* @version  V1.0.0
* @brief    Power Up Process
*           ---
*           ---
*           ---
* @author   MK
* @date     01-MAR-2021
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "pwr_up_prcs.h"


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
	PWR_UP_ENTRY_STATE = 0,
	WIFI_GEN_INIT_PRCS,
	WIFI_AP_MODE_INIT_PRCS,
	WIFI_UDP_SOCKET_ON_PRCS,
	WIFI_PASS_THRU_MODE_PRCS,
	PWR_UP_EXIT_STATE
}pwr_up_prcs_state_t;

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
* @fn  bool_t PwrUp_Prcs (void)
*==============================================================================
* @brief    PwrUp_Prcs
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
bool_t PwrUp_Prcs (void)
{
	#define PWR_UP_EXIT_TO             (2000U)

	static pwr_up_prcs_state_t pwr_up_prcs_state = PWR_UP_ENTRY_STATE;
	static uint32_t prcs_tmr = 0;
	bool_t prcs_over_f = FALSE;
	bool_t sub_prcs_ovr_f = FALSE;


	switch(pwr_up_prcs_state)
	{
		case PWR_UP_ENTRY_STATE:
			ErrInd_Disable();
			prcs_tmr = SysTick_GetTickTmrVal();
			pwr_up_prcs_state = WIFI_GEN_INIT_PRCS;
			break;

		case WIFI_GEN_INIT_PRCS:
			sub_prcs_ovr_f = Esp8266_GenInitPrcs();
			if(sub_prcs_ovr_f == TRUE)
			{
				pwr_up_prcs_state = WIFI_AP_MODE_INIT_PRCS;
			}
			break;

		case WIFI_AP_MODE_INIT_PRCS:
			sub_prcs_ovr_f = Esp8266_WiFiInitPrcs();
			if(sub_prcs_ovr_f == TRUE)
			{
//				pwr_up_prcs_state = WIFI_UDP_SOCKET_ON_PRCS;
				pwr_up_prcs_state = PWR_UP_EXIT_STATE;
			}
			break;

		case WIFI_UDP_SOCKET_ON_PRCS:
			sub_prcs_ovr_f = Esp8266_UdpSocketOnPrcs();
			if(sub_prcs_ovr_f == TRUE)
			{
				pwr_up_prcs_state = WIFI_PASS_THRU_MODE_PRCS;
			}
			break;

		case WIFI_PASS_THRU_MODE_PRCS:
			sub_prcs_ovr_f = Esp8266_PassThruInitPrcs();
			if(sub_prcs_ovr_f == TRUE)
			{
				pwr_up_prcs_state = PWR_UP_EXIT_STATE;
			}
			break;

		case PWR_UP_EXIT_STATE:
			if(SysTick_CheckTimeOut(&prcs_tmr, PWR_UP_EXIT_TO) == TRUE)
			{
				prcs_over_f = TRUE;
				pwr_up_prcs_state = PWR_UP_ENTRY_STATE;
			}
			break;

		default:
			pwr_up_prcs_state = PWR_UP_ENTRY_STATE;
			break;
	}

	return(prcs_over_f);
}// >>End of PwrUp_Prcs

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
