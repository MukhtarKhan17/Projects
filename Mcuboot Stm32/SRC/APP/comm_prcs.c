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
* @file     comm_prcs.c
* @version  V1.0.0 <Update version of this file>
* @brief    TODO: <Write the file description over here>
*           ---
*           ---
*           ---
* @author   MK
* @date     09-DEC-2021
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "comm_prcs.h"


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
* @fn  void Comm_UdpLoopBckPrcs (void)
*==============================================================================
* @brief    Comm_UdpLoopBckPrcs
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
void Comm_UdpLoopBckPrcs (void)
{
	#define  REMOTE_UDP_IP_ADDR        "192.168.4.255"
	#define  REMOTE_UDP_PORT           "15001"
	#define  LOCAL_UDP_PORT            "15011"

	typedef enum
	{
		UDP_START_CONN_STATE = 0,
		UDP_TX_DATA_STATE,
		UDP_RX_DATA_STATE,
		UDP_WAIT_STATE,
		UDP_CLOSE_CONN_STATE
	}comm_udp_prcs_state_t;

	static comm_udp_prcs_state_t comm_udp_prcs_state = UDP_START_CONN_STATE;
	static uint32_t prcs_tmr = 0;
	static uint8_t temp_data_buf[256];
	bool_t sub_prcs_ovr_f = FALSE;
	bool_t udp_sts_f = FALSE;
	esp_ch_id_t udp_ch_id = CH_ID_0;

	switch(comm_udp_prcs_state)
	{
		case UDP_START_CONN_STATE:
			sub_prcs_ovr_f = Esp8266_UdpStartConnPrcs(udp_ch_id,
													 (int8_t*)REMOTE_UDP_IP_ADDR,
													 (int8_t*)REMOTE_UDP_PORT,
													 (int8_t*)LOCAL_UDP_PORT,
					                                 &udp_sts_f);
			if(sub_prcs_ovr_f == TRUE)
			{
				prcs_tmr = SysTick_GetTickTmrVal();
				comm_udp_prcs_state = UDP_RX_DATA_STATE;
			}
			break;

		case UDP_RX_DATA_STATE:
			if(Esp8266_GetRxDataFlag() == TRUE)
			{
				(void)memset(temp_data_buf, 0, sizeof(temp_data_buf));
				strcpy((char*)temp_data_buf, (const char*)Esp8266_GetRxDataPtr());
				Esp8266_ClrRxDataFlag();
				comm_udp_prcs_state = UDP_TX_DATA_STATE;
			}
			break;

		case UDP_TX_DATA_STATE:
			sub_prcs_ovr_f = Esp8266_UdpSendDataPrcs (udp_ch_id,
													 (int8_t*)temp_data_buf,
					                                 &udp_sts_f);
			if(sub_prcs_ovr_f == TRUE)
			{
				prcs_tmr = SysTick_GetTickTmrVal();
				comm_udp_prcs_state = UDP_WAIT_STATE;
			}
			break;

		case UDP_CLOSE_CONN_STATE:
			sub_prcs_ovr_f = Esp8266_UdpCloseConnPrcs (udp_ch_id,
					                                   &udp_sts_f);
			if(sub_prcs_ovr_f == TRUE)
			{
				comm_udp_prcs_state = UDP_WAIT_STATE;
			}
			break;

		case UDP_WAIT_STATE:
			if(SysTick_CheckTimeOut(&prcs_tmr, 100) == TRUE)
			{
				comm_udp_prcs_state = UDP_RX_DATA_STATE;
			}
			break;

		default:
			comm_udp_prcs_state = UDP_START_CONN_STATE;
			break;

	}
}// >>End of Comm_UdpLoopBckPrcs

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Comm_TcpLoopBckPrcs (void)
*==============================================================================
* @brief    Comm_TcpLoopBckPrcs
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
void Comm_TcpLoopBckPrcs (void)
{
	#define  REMOTE_TCP_IP_ADDR        "192.168.4.2"
	#define  REMOTE_TCP_PORT           "80"

	typedef enum
	{
		TCP_TX_DATA_STATE = 0,
		TCP_RX_DATA_STATE,
		TCP_WAIT_STATE,
	}comm_tcp_prcs_state_t;


	static comm_tcp_prcs_state_t comm_tcp_prcs_state = TCP_RX_DATA_STATE;
	static uint32_t prcs_tmr = 0;
	static uint8_t temp_data_buf[256];
	bool_t sub_prcs_ovr_f = FALSE;
	bool_t tcp_sts_f = FALSE;
	esp_ch_id_t tcp_ch_id = CH_ID_0;

	switch(comm_tcp_prcs_state)
	{
		case TCP_RX_DATA_STATE:
			if(Esp8266_GetRxDataFlag() == TRUE)
			{
				(void)memset(temp_data_buf, 0, sizeof(temp_data_buf));
				strcpy((char*)temp_data_buf, (const char*)Esp8266_GetRxDataPtr());
				Esp8266_ClrRxDataFlag();
				comm_tcp_prcs_state = TCP_TX_DATA_STATE;
			}
			break;

		case TCP_TX_DATA_STATE:
			sub_prcs_ovr_f = Esp8266_SendTcpDataPrcs(tcp_ch_id,
													 (int8_t*)REMOTE_TCP_IP_ADDR,
													 (int8_t*)REMOTE_TCP_PORT,
													 (int8_t*)temp_data_buf,
					                                  &tcp_sts_f);
			if(sub_prcs_ovr_f == TRUE)
			{
				prcs_tmr = SysTick_GetTickTmrVal();
				comm_tcp_prcs_state = TCP_WAIT_STATE;
			}
			break;

		case TCP_WAIT_STATE:
			if(SysTick_CheckTimeOut(&prcs_tmr, 1000) == TRUE)
			{
				comm_tcp_prcs_state = TCP_RX_DATA_STATE;
			}
			break;

		default:
			comm_tcp_prcs_state = TCP_TX_DATA_STATE;
			break;
	}


}// >>End of Comm_TcpLoopBckPrcs


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
