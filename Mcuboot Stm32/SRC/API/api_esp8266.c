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
* @file     api_esp8266
* @version  V1.0.0 <Update version of this file if changing>
* @brief    API ESP8266
*           ---
*           ---
*           ---
* @author   MK
* @date     29-APR-2021
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "api_esp8266.h"


/**
*==============================================================================
*                          	   \V/ Local DefineS
*==============================================================================
*/





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
	ESP_HARD_RST_STATE = 0,
	ESP_RDY_WAIT_STATE,
	ESP_RESTORE_STATE,
	ESP_SOFT_RST_STATE,
	ESP_SET_BAUD_STATE,
	ESP_TEST_OK_STATE,
	ESP_DISABLE_ECHO1_STATE,
	ESP_DISABLE_ECHO2_STATE,
	ESP_SET_WIFI_MODE_STATE,
	ESP_JOIN_AP_STATE,
	ESP_SET_AP_NAME_STATE,
	ESP_SET_NUM_OF_CONN_STATE,
	ESP_SET_TCP_SERVER_STATE,
	ESP_ERROR_STATE
}esp_init_state_t;

/**
*==============================================================================
*                              \V/ Local VariableS
*==============================================================================
*/
int8_t vTag_Esp8266_Key[] = "VOIDRON";

static bool_t esp_init_err_f = FALSE;

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
* @fn  void Esp8266_Init (void)
*==============================================================================
* @brief    Esp8266_Init
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     26-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Esp8266_Init (void)
{
	static esp8266_base_t set_esp8266_base_s = {0};

	set_esp8266_base_s.GpioInit   = &Esp8266IO_GpioInit;
	set_esp8266_base_s.Enable     = &Esp8266IO_Enable;
	set_esp8266_base_s.Disable    = &Esp8266IO_Disable;
	set_esp8266_base_s.RstLow     = &Esp8266IO_RstLow;
	set_esp8266_base_s.RstHigh    = &Esp8266IO_RstHigh;
	set_esp8266_base_s.SerialInit = &UartCom1_Init;
	set_esp8266_base_s.TxData     = &UartCom1_TxData;
	set_esp8266_base_s.TxOver     = &UartCom1_GetTxOverFlag;
	set_esp8266_base_s.RxData     = &UartCom1_RxData;
	set_esp8266_base_s.GetRxDatSz = &UartCom1_GetRxDataSz;
	set_esp8266_base_s.GetRxFlag  = &UartCom1_GetRxFlag;
	set_esp8266_base_s.ClrRxFlag  = &UartCom1_ClrRxFlag;
	set_esp8266_base_s.TxCbufInit = &UartCom1_TxCbufInit;
	set_esp8266_base_s.RxCbufInit = &UartCom1_RxCbufInit;
	set_esp8266_base_s.GetTickMs  = &SysTick_GetTickTmrVal;
	set_esp8266_base_s.ChkTimeout = &SysTick_CheckTimeOut;
	set_esp8266_base_s.DelayMs    = &SysTick_Delay;

	Esp8266_BaseInit(set_esp8266_base_s);
	(void)Esp8266_Enable(vTag_Esp8266_Key);
} // End of Esp8266_Init()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t Esp8266_GetInitErrFlag(void)
*==============================================================================
* @brief    Esp8266_GetInitErrFlag
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   esp_init_err_f
* @author   MK
* @date     26-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t Esp8266_GetInitErrFlag(void)
{
	return(esp_init_err_f);
}// >>End of Esp8266_GetInitErrFlag

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t Esp8266_GenInitPrcs (void)
*==============================================================================
* @brief    Esp8266_GenInitPrcs
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   prcs_ovr_f
* @author   MK
* @date     09-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t Esp8266_GenInitPrcs (void)
{
	#define ESP_CONFIG_CMD_TO          (250U)
	#define ESP_READY_TO               (500U)


	static esp_init_state_t esp_init_state = ESP_HARD_RST_STATE;
	static uint32_t prcs_tmr = 0;
	bool_t prcs_ovr_f = FALSE;
	esp_resp_t esp_resp_val = ESP_NO_RESP;
	static uint8_t esp_reinit_cntr = 0;

	switch(esp_init_state)
	{
	case ESP_HARD_RST_STATE:
		Esp8266_HardRst();
		prcs_tmr = SysTick_GetTickTmrVal();
		esp_reinit_cntr = 0;
		esp_init_state = ESP_RDY_WAIT_STATE;
		break;


	case ESP_RDY_WAIT_STATE:
		if(SysTick_CheckTimeOut(&prcs_tmr, ESP_READY_TO) == TRUE)
		{
			Esp8266_ClrBuffers();
			esp_init_state = ESP_RESTORE_STATE;
		}
		break;

		case ESP_RESTORE_STATE:
			esp_resp_val = Esp8266_Restore();

			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					esp_init_state = ESP_TEST_OK_STATE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
						esp_init_state = ESP_ERROR_STATE;
					}
				}
			}
			break;

		case ESP_SOFT_RST_STATE:
			esp_resp_val = Esp8266_Reset();

			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					esp_init_state = ESP_TEST_OK_STATE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
						esp_init_state = ESP_ERROR_STATE;
					}
				}
			}
			break;


		case ESP_TEST_OK_STATE:
			esp_resp_val = Esp8266_TestOk();

			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					esp_init_state = ESP_DISABLE_ECHO1_STATE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
						esp_init_state = ESP_ERROR_STATE;
					}
				}
			}
			break;

		case ESP_DISABLE_ECHO1_STATE:
			esp_resp_val = Esp8266_SetEcho(ECHO_DISABLE);

			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					esp_init_state = ESP_DISABLE_ECHO2_STATE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
						esp_init_state = ESP_ERROR_STATE;
					}
				}
			}
			break;

		case ESP_DISABLE_ECHO2_STATE: // Due Issues encounters in disable added twice.
			esp_resp_val = Esp8266_SetEcho(ECHO_DISABLE);

			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					prcs_ovr_f = TRUE;
					esp_init_state = ESP_HARD_RST_STATE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
						esp_init_state = ESP_ERROR_STATE;
					}
				}
			}
			break;

		case ESP_ERROR_STATE:
			esp_init_err_f = TRUE;
			prcs_ovr_f = TRUE;
			esp_init_state = ESP_HARD_RST_STATE;
			break;

		default:
			esp_init_state = ESP_HARD_RST_STATE;
			break;

	}
	return(prcs_ovr_f);
}// >>End of Esp8266_GenInitPrcs

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t Esp8266_WiFiInitPrcs (void)
*==============================================================================
* @brief    Esp8266_WiFiInitPrcs
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   prcs_ovr_f
* @author   MK
* @date     26-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t Esp8266_WiFiInitPrcs (void)
{
	#define ESP_CONFIG_CMD_TO          (250U)
	#define ESP_READY_TO               (500U)

	static esp_init_state_t esp_init_state = ESP_SET_WIFI_MODE_STATE;
	static uint8_t esp_reinit_cntr = 0;
	esp_resp_t esp_resp_val = ESP_NO_RESP;
	bool_t prcs_ovr_f = FALSE;


	switch(esp_init_state)
	{

		case ESP_SET_WIFI_MODE_STATE:
			#if(WIFI_MODE_SEL == WIFI_STA_MODE)
				esp_resp_val = Esp8266_SetWiFiMode(STA_MODE);
			#else
				esp_resp_val = Esp8266_SetWiFiMode(AP_MODE);
			#endif

			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					esp_init_state = ESP_SET_AP_NAME_STATE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
						esp_init_state = ESP_ERROR_STATE;
					}
				}
			}
			break;

		case ESP_SET_AP_NAME_STATE:
			esp_resp_val = Esp8266_ConfigureAP((uint8_t*)DataBase_GetDbPtr()->ap_ssid_str_buf,
											   (uint8_t*)DataBase_GetDbPtr()->ap_pswd_str_buf,
					                           CH_ID_1, ENCRYPT_WPA_WPA2_PSK);

			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					esp_init_state = ESP_SET_NUM_OF_CONN_STATE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
						esp_init_state = ESP_ERROR_STATE;
					}
				}
			}
			break;

		case ESP_SET_NUM_OF_CONN_STATE:
			#if(WIFI_CONN_SEL == WIFI_SINGLE_CONN)
				esp_resp_val = Esp8266_SetNumOfConn(SINGLE_CONN);
			#else
				esp_resp_val = Esp8266_SetNumOfConn(MULTIPLE_CONN);
			#endif
			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					esp_init_state = ESP_SET_TCP_SERVER_STATE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
						esp_init_state = ESP_ERROR_STATE;
					}
				}
			}
			break;

		case ESP_SET_TCP_SERVER_STATE:
			#if(TCP_SERVER_SEL == TCP_SERVER_ON)
				esp_resp_val = Esp8266_SetTcpServer(TCP_SERV_ON);
			#else
				esp_resp_val = Esp8266_SetTcpServer(TCP_SERV_OFF);
			#endif

			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					prcs_ovr_f = TRUE;
					esp_init_state = ESP_HARD_RST_STATE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
						esp_init_state = ESP_ERROR_STATE;
					}
				}
			}
			break;

		case ESP_ERROR_STATE:
			esp_init_err_f = TRUE;
			prcs_ovr_f = TRUE;
			esp_init_state = ESP_HARD_RST_STATE;
			break;

		default:
			esp_init_state = ESP_HARD_RST_STATE;
			break;
	}

	return(prcs_ovr_f);
}// >>End of Esp8266_WiFiInitPrcs

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t Esp8266_UdpSocketOnPrcs (void)
*==============================================================================
* @brief    Esp8266_UdpSocketOnPrcs
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   prcs_ovr_f
* @author   MK
* @date     26-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t Esp8266_UdpSocketOnPrcs (void)
{
	#define  REMOTE_IP_ADDR            "192.168.4.255"
	#define  REMOTE_UDP_PORT      	   "15000"
	#define  LOCAL_UDP_PORT            "15001"

	bool_t prcs_ovr_f = FALSE;
	esp_resp_t esp_resp_val = ESP_NO_RESP;
	static uint8_t esp_reinit_cntr = 0;

	esp_resp_val = Esp8266_EstablishConn(CH_ID_NONE,
										CONN_TYPE_UDP,
										(uint8_t*)REMOTE_IP_ADDR,
										(uint8_t*)REMOTE_UDP_PORT,
										(uint8_t*)LOCAL_UDP_PORT);
	if(esp_resp_val != ESP_NO_RESP)
	{
		if(esp_resp_val == ESP_SUCCESS)
		{
			prcs_ovr_f = TRUE;
		}
		else
		{
			esp_reinit_cntr++;
			if(esp_reinit_cntr > 3)
			{
				esp_reinit_cntr = 0;
			}
		}
	}

	return(prcs_ovr_f);

}// >>End of Esp8266_UdpSocketOnPrcs

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t Esp8266_PassThruInitPrcs (void)
*==============================================================================
* @brief    Esp8266_PassThruInitPrcs
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   prcs_ovr_f
* @author   MK
* @date     26-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t Esp8266_PassThruInitPrcs (void)
{
	bool_t prcs_ovr_f = FALSE;
	esp_resp_t esp_resp_val = ESP_NO_RESP;
	static uint8_t esp_reinit_cntr = 0;

	typedef enum
	{
		PT_MODE_CONFIG_STATE,
		PT_DATA_CONFIG_STATE,
	}pt_mode_config_state_t;

	static pt_mode_config_state_t pt_mode_config_state = PT_MODE_CONFIG_STATE;

	switch(pt_mode_config_state)
	{
		case PT_MODE_CONFIG_STATE:
			esp_resp_val = Esp8266_SetPassThruMode(PASS_THRU_MODE_ENABLE);
			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					pt_mode_config_state = PT_DATA_CONFIG_STATE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
					}
				}
			}
			break;

		case PT_DATA_CONFIG_STATE:
			esp_resp_val = Esp8266_PassThruDataOn(PASS_THRU_DATA_ON);
			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					Esp8266_SetAtModeFlag(FALSE);
					prcs_ovr_f = TRUE;
					pt_mode_config_state = PT_MODE_CONFIG_STATE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
					}
				}
			}
			break;

		default:
			break;
	}

	return(prcs_ovr_f);
}//>> End of Esp8266_PassThruInitPrcs

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t Esp8266_ApSearchPrcs (int8_t *ap_name_str_ptr,
*                                   bool_t *search_sts_f_ptr)
*==============================================================================
* @brief    Esp8266_ApSearchPrcs
*           ---
*           ---
*           ---
* @note     None
* @param    *ap_name_str_ptr
* @param    *search_sts_f_ptr
* @retval   prcs_ovr_f
* @author   MK
* @date     26-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t Esp8266_ApSearchPrcs (int8_t *ap_name_str_ptr, bool_t *search_sts_f_ptr)
{

	typedef enum
	{
		AP_SEARCH_INIT_STATE,
		AP_SEARCH_CONFIG_STATE,
		AP_SEARCH_MAIN_STATE
	}esp_ap_search_state_t;

	static esp_ap_search_state_t esp_ap_search_state = AP_SEARCH_INIT_STATE;
	bool_t prcs_ovr_f = FALSE;
	esp_resp_t esp_resp_val = ESP_NO_RESP;
	static uint8_t esp_reinit_cntr = 0;
	static uint8_t ap_list_buf[256] = {0};

	switch(esp_ap_search_state)
	{

		case AP_SEARCH_INIT_STATE:
			 esp_reinit_cntr = 0;
			 esp_ap_search_state = AP_SEARCH_CONFIG_STATE;
			break;

		case AP_SEARCH_CONFIG_STATE:
			esp_resp_val= Esp8266_ConfigureListAP(SORT_NOT_BY_RSSI_LEVEL, ONLY_SSID_LISTING);
			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					esp_ap_search_state = AP_SEARCH_MAIN_STATE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
						*search_sts_f_ptr = FALSE;
						esp_ap_search_state = AP_SEARCH_INIT_STATE;
						prcs_ovr_f = TRUE;
					}
				}
			}
			break;

		case AP_SEARCH_MAIN_STATE:
			esp_resp_val = Esp8266_ListAP(ap_list_buf);
			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					if(NULL != strstr ((const char *)ap_list_buf, (const char *)ap_name_str_ptr))
					{
						*search_sts_f_ptr = TRUE;
					}
					else
					{
						*search_sts_f_ptr = FALSE;
					}

					esp_ap_search_state = AP_SEARCH_INIT_STATE;
					prcs_ovr_f = TRUE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
					}

					*search_sts_f_ptr = FALSE;
					esp_ap_search_state = AP_SEARCH_INIT_STATE;
					prcs_ovr_f = TRUE;
				}
			}
			break;

		default:
			break;

	}

	return(prcs_ovr_f);

}// >>End of Esp8266_ApSearchPrcs

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t Esp8266_ApJoinPrcs (int8_t *ap_name_str_ptr,
*		                          int8_t *ap_pswd_str_ptr,
*		                          bool_t *join_sts_f_ptr)
*==============================================================================
* @brief    Esp8266_ApJoinPrcs
*           ---
*           ---
*           ---
* @note     *ap_name_str_ptr
* @param    *ap_pswd_str_ptr
* @param    *join_sts_f_ptr
* @retval   prcs_ovr_f
* @author   MK
* @date     26-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t Esp8266_ApJoinPrcs (int8_t *ap_name_str_ptr,
		                   int8_t *ap_pswd_str_ptr,
		                   bool_t *join_sts_f_ptr)
{

	typedef enum
	{
		AP_JOIN_INIT_STATE,
		AP_JOIN_MAIN_STATE
	}esp_ap_join_state_t;

	static esp_ap_join_state_t esp_ap_join_state = AP_JOIN_INIT_STATE;
	static uint8_t esp_reinit_cntr = 0;
	bool_t prcs_ovr_f = FALSE;
	esp_resp_t esp_resp_val = ESP_NO_RESP;



	switch(esp_ap_join_state)
	{

		case AP_JOIN_INIT_STATE:
			 esp_reinit_cntr = 0;
			 esp_ap_join_state = AP_JOIN_MAIN_STATE;
			break;

		case AP_JOIN_MAIN_STATE:
			esp_resp_val= Esp8266_ConnectAP((uint8_t*)ap_name_str_ptr, (uint8_t*)ap_pswd_str_ptr, NULL);
			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					esp_ap_join_state = AP_JOIN_INIT_STATE;
					*join_sts_f_ptr = TRUE;
					prcs_ovr_f = TRUE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						*join_sts_f_ptr = FALSE;
						prcs_ovr_f = TRUE;
						esp_reinit_cntr = 0;
						esp_ap_join_state = AP_JOIN_INIT_STATE;
					}

				}
			}
			break;

		default:
			break;

	}

	return(prcs_ovr_f);

}// >>End of Esp8266_ApJoinPrcs

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t Esp8266_SendTcpDataPrcs (esp_ch_id_t tcp_set_ch_id,
*								       int8_t *ip_addr_str_ptr,
*							           int8_t *port_num_str_ptr,
*							           int8_t *data_str_ptr,
*							           bool_t *send_sts_f_ptr)
*==============================================================================
* @brief    Esp8266_SendTcpDataPrcs
*           ---
*           ---
*           ---
* @note     None
* @param    tcp_set_ch_id
* @param    *ip_addr_str_ptr
* @param    *port_num_str_ptr
* @param    *data_str_ptr
* @param    *send_sts_f_ptr
* @retval   prcs_ovr_f
* @author   MK
* @date     26-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t Esp8266_SendTcpDataPrcs (esp_ch_id_t tcp_set_ch_id,
								int8_t *ip_addr_str_ptr,
							    int8_t *port_num_str_ptr,
							    int8_t *data_str_ptr,
							    bool_t *send_sts_f_ptr)
{
	typedef enum
	{
		TCP_INIT_STATE,
		TCP_ESTABLISH_CONN_STATE,
		TCP_SEND_DATA_STATE,
		TCP_CLOSE_CONN_STATE
	}esp_tcp_state_t;

	static esp_tcp_state_t esp_tcp_state = TCP_INIT_STATE;
	bool_t prcs_ovr_f = FALSE;
	esp_resp_t esp_resp_val = ESP_NO_RESP;
	static uint8_t esp_reinit_cntr = 0;
	uint8_t str_sz = 0;
	uint8_t data_sz_str_buf[4];


	switch(esp_tcp_state)
	{
		case TCP_INIT_STATE:
			 esp_reinit_cntr = 0;
			 esp_tcp_state = TCP_ESTABLISH_CONN_STATE;
			break;

		case TCP_ESTABLISH_CONN_STATE:
			esp_resp_val = Esp8266_EstablishConn(tcp_set_ch_id,
					                             CONN_TYPE_TCP,
					                             (uint8_t*) ip_addr_str_ptr,
					                             (uint8_t*)port_num_str_ptr,
					                             NULL);
			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					esp_tcp_state = TCP_SEND_DATA_STATE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
						*send_sts_f_ptr = FALSE;
						esp_tcp_state = TCP_INIT_STATE;
						prcs_ovr_f = TRUE;
					}
				}
			}
			break;

		case TCP_SEND_DATA_STATE:
			str_sz = strlen((const char*)data_str_ptr);
			(void)memset(data_sz_str_buf, 0, sizeof(data_sz_str_buf));
			if((str_sz >= 0) && (str_sz <= 10))
			{
				DataConv_LtoA((uint32_t)str_sz, data_sz_str_buf, 1, TRUE, 0);
			}
			else if((str_sz >= 10) && (str_sz <= 99))
			{
				DataConv_LtoA((uint32_t)str_sz, data_sz_str_buf, 2, TRUE, 0);
			}
			else
			{
				DataConv_LtoA((uint32_t)str_sz, data_sz_str_buf, 3, TRUE, 0);
			}

			esp_resp_val = 	Esp8266_SendData(tcp_set_ch_id, (uint8_t*) data_str_ptr, (uint8_t*)data_sz_str_buf);
			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					esp_tcp_state = TCP_CLOSE_CONN_STATE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
					}

					*send_sts_f_ptr = FALSE;
					esp_tcp_state = TCP_INIT_STATE;
					prcs_ovr_f = TRUE;
				}
			}
			break;

		case TCP_CLOSE_CONN_STATE:
			esp_resp_val = Esp8266_CloseConn(tcp_set_ch_id);
			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					*send_sts_f_ptr = TRUE;
					esp_tcp_state = TCP_INIT_STATE;
					prcs_ovr_f = TRUE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
					}

					*send_sts_f_ptr = FALSE;
					esp_tcp_state = TCP_INIT_STATE;
					prcs_ovr_f = TRUE;
				}
			}
			break;
	}

	return(prcs_ovr_f);
}// >>End of Esp8266_SendTcpDataPrcs

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn bool_t Esp8266_UdpStartConnPrcs ( esp_ch_id_t udp_set_ch_id,
*									  int8_t *remote_ip_addr_str_ptr,
*									  int8_t *remote_port_num_str_ptr,
*									  int8_t *local_port_num_str_ptr,
*									  bool_t *send_sts_f_ptr)
*==============================================================================
* @brief    Esp8266_UdpStartConnPrcs
*           ---
*           ---
*           ---
* @note     None
* @param    udp_set_ch_id
* @param    *remote_ip_addr_str_ptr
* @param    *remote_port_num_str_ptr
* @param    *local_port_num_str_ptr
* @param    *send_sts_f_ptr
* @retval   prcs_ovr_f
* @author   MK
* @date     09-DEC-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t Esp8266_UdpStartConnPrcs (esp_ch_id_t udp_set_ch_id,
								 int8_t *remote_ip_addr_str_ptr,
								 int8_t *remote_port_num_str_ptr,
								 int8_t *local_port_num_str_ptr,
								 bool_t *send_sts_f_ptr)
{
	esp_resp_t esp_resp_val = ESP_NO_RESP;
	static uint8_t esp_reinit_cntr = 0;
	bool_t prcs_ovr_f = FALSE;

	esp_resp_val = Esp8266_EstablishConn(udp_set_ch_id, CONN_TYPE_UDP,
										(uint8_t*) remote_ip_addr_str_ptr,
										(uint8_t*)remote_port_num_str_ptr,
										(uint8_t*)local_port_num_str_ptr);
	if(esp_resp_val != ESP_NO_RESP)
	{
		if(esp_resp_val == ESP_SUCCESS)
		{
			*send_sts_f_ptr = TRUE;
			prcs_ovr_f = TRUE;
		}
		else
		{
			esp_reinit_cntr++;
			if(esp_reinit_cntr > 3)
			{
				esp_reinit_cntr = 0;
				*send_sts_f_ptr = FALSE;
			}
		}

		prcs_ovr_f = TRUE;
	}

	return(prcs_ovr_f);
}// >>End of Esp8266_UdpStartConnPrcs

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn bool_t Esp8266_UdpSendDataPrcs (esp_ch_id_t udp_set_ch_id,
*									  int8_t *data_str_ptr,
*							    	  bool_t *send_sts_f_ptr)
*==============================================================================
* @brief    Esp8266_UdpStartConnPrcs
*           ---
*           ---
*           ---
* @note     None
* @param    udp_set_ch_id
* @param    *data_str_ptr
* @param    *send_sts_f_ptr
* @retval   prcs_ovr_f
* @author   MK
* @date     09-DEC-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t Esp8266_UdpSendDataPrcs (esp_ch_id_t udp_set_ch_id,
								int8_t *data_str_ptr,
							    bool_t *send_sts_f_ptr)
{
	esp_resp_t esp_resp_val = ESP_NO_RESP;
	static uint8_t esp_reinit_cntr = 0;
	bool_t prcs_ovr_f = FALSE;
	uint8_t data_sz_str_buf[4];
	uint8_t str_sz = 0;

	str_sz = strlen((const char*)data_str_ptr);
	(void)memset(data_sz_str_buf, 0, sizeof(data_sz_str_buf));
	if((str_sz >= 0) && (str_sz <= 10))
	{
		DataConv_LtoA((uint32_t)str_sz, data_sz_str_buf, 1, TRUE, 0);
	}
	else if((str_sz >= 10) && (str_sz <= 99))
	{
		DataConv_LtoA((uint32_t)str_sz, data_sz_str_buf, 2, TRUE, 0);
	}
	else
	{
		DataConv_LtoA((uint32_t)str_sz, data_sz_str_buf, 3, TRUE, 0);
	}

	esp_resp_val = 	Esp8266_SendData(udp_set_ch_id, (uint8_t*) data_str_ptr, (uint8_t*)data_sz_str_buf);
	if(esp_resp_val != ESP_NO_RESP)
	{
		if(esp_resp_val == ESP_SUCCESS)
		{
			*send_sts_f_ptr = TRUE;
		}
		else
		{
			esp_reinit_cntr++;
			if(esp_reinit_cntr > 3)
			{
				esp_reinit_cntr = 0;
			}
			*send_sts_f_ptr = FALSE;
		}

		prcs_ovr_f = TRUE;
	}
	return(prcs_ovr_f);
}// >>End of Esp8266_UdpSendDataPrcs

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn bool_t Esp8266_UdpCloseConnPrcs (esp_ch_id_t udp_set_ch_id,
*							     	   bool_t *send_sts_f_ptr)
*==============================================================================
* @brief    Esp8266_UdpCloseConnPrcs
*           ---
*           ---
*           ---
* @note     None
* @param    udp_set_ch_id
* @param    *send_sts_f_ptr
* @retval   prcs_ovr_f
* @author   MK
* @date     09-DEC-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t Esp8266_UdpCloseConnPrcs (esp_ch_id_t udp_set_ch_id,
							     bool_t *send_sts_f_ptr)
{
	esp_resp_t esp_resp_val = ESP_NO_RESP;
	static uint8_t esp_reinit_cntr = 0;
	bool_t prcs_ovr_f = FALSE;

	esp_resp_val = Esp8266_CloseConn(udp_set_ch_id);
	if(esp_resp_val != ESP_NO_RESP)
	{
		if(esp_resp_val == ESP_SUCCESS)
		{
			*send_sts_f_ptr = TRUE;
		}
		else
		{
			esp_reinit_cntr++;
			if(esp_reinit_cntr > 3)
			{
				esp_reinit_cntr = 0;
			}
			*send_sts_f_ptr = FALSE;
		}
		prcs_ovr_f = TRUE;
	}
	return(prcs_ovr_f);
}// >>End of Esp8266_UdpCloseConnPrcs

/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     26-FEB-2021
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
