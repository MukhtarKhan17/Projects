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
* @file     web_host_prcs.c
* @version  V1.0.0
* @brief    Web Host Process
*           ---
*           ---
*           ---
* @author   MK
* @date     22-DEC-2017
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "web_host_prcs.h"


/**
*==============================================================================
*                          	   \V/ Local DefineS
*==============================================================================
*/
static const uint8_t HTTP_KEYWORD[]             = "GET / HTTP/1.1";
static const uint8_t HTTP_SAVE_NET_KEYWORD[]	= "GET /SAVE+NETWORK";
static const uint8_t SSID_KEYWORD[]		        = "SSID=";
static const uint8_t PSWD_KEYWORD[]		        = "PSWD=";
static const uint8_t SSID_VAL_KEYWORD[]	        = "SSID+VAL";
static const uint8_t PSWD_VAL_KEYWORD[]	        = "PSWD+VAL";


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
const uint8_t WEB_HOST_CONFIG_NET_PAGE[] =

"<h1 style=\"text-align: left;\"><span style=\"color: #ff0000;\">Network Settings</span></h1>    \
<form action=\"/SAVE+NETWORK\"><strong>SSID:</strong><br />                                      \
<input maxlength=\"31\" name=\"SSID\" type=\"text\" value=\"SSID+VAL\" /> <br />                 \
<strong>Password:</strong><br />                                                                 \
<input maxlength=\"31\" name=\"PSWD\" type=\"password\" value=\"PSWD+VAL\" /> <br /> <br />      \
<input type=\"submit\" value=\"Save\" /></form>                                                  \
<p>&nbsp;</p> \
<p><span style=\"color: #993300;\">&copy; Voidron Co. 2021 </span>&nbsp;</p>";

const uint8_t WEB_HOST_SAVE_PAGE[] = "<h1>Saved!</h1>";

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
* @fn  void WebHost_Init (void)
*==============================================================================
* @brief    WebHost_Init
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     22-DEC-2017 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void WebHost_Init (void)
{
	Esp8266_ClrBuffers();
}//End of WebHost_Init

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void WebHost_Prcs (void)
*==============================================================================
* @brief    WebHost_Prcs
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     22-DEC-2017 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void WebHost_Prcs (void)
{
	#define RX_LINK_ID_POS             (0U)
	#define RX_RESP_DATA_SZ            (7U)
	#define RX_RESP_DATA_SZ_STR        ("7")
	#define RX_DIS_WEB_HOST_TO         (30000U)

	typedef enum
	{
		WEB_HOST_RX_PRCS_STATE = 0,
		WEB_HOST_RX_RESP_STATE,
		WEB_HOST_CLOSE1_CONN_STATE,
		WEB_HOST_CLOSE2_CONN_STATE,
		WEB_HOST_RELOAD_DELAY_STATE,
	}web_host_prcs_state_t;

	static web_host_prcs_state_t web_host_prcs_state = WEB_HOST_RX_PRCS_STATE;
	static uint8_t comm_tx_buf[1024] = {0};
	static uint8_t comm_tx_sz_str[5] = {0};
	uint16_t str_len = 0;
	uint8_t *rx_data_start_ptr = NULL;
	uint8_t *rx_data_end_ptr   = NULL;
	esp_resp_t esp_resp_val = ESP_NO_RESP;
	static uint8_t esp_reinit_cntr = 0;
	static uint8_t rx_link_id = 0;
	static uint32_t prcs_tmr = 0;
	uint8_t ssid_buf[MEM1_AP_SSID_SZ];
	uint8_t pswd_buf[MEM1_AP_PSWD_SZ];


	switch(web_host_prcs_state)
	{
		case WEB_HOST_RX_PRCS_STATE:
			if(Esp8266_GetRxDataFlag() == TRUE)
			{

				// Extract Link ID
				rx_data_start_ptr = Esp8266_GetRxDataPtr();
				rx_link_id = *rx_data_start_ptr;
				if((rx_link_id >= '0') && (rx_link_id <= '9'))
				{
					rx_link_id = (0x0F & rx_data_start_ptr[RX_LINK_ID_POS]);
				}
				else if(rx_link_id == 'N')
				{
					rx_link_id = CH_ID_NONE;
				}
				else
				{
					rx_link_id = CH_ID_ALL;
				}

				if(NULL != strstr ((const char *)Esp8266_GetRxDataPtr(), (const char *)HTTP_KEYWORD))
				{

					//Append Last saved SSID
					(void)memset(comm_tx_buf, 0, sizeof(comm_tx_buf));
					rx_data_start_ptr = (uint8_t*)&WEB_HOST_CONFIG_NET_PAGE[0];
					rx_data_end_ptr = (uint8_t*)strstr ((const char *)WEB_HOST_CONFIG_NET_PAGE, (const char *)SSID_VAL_KEYWORD);

					if(rx_data_end_ptr > rx_data_start_ptr)
					{
						str_len = (rx_data_end_ptr - rx_data_start_ptr);
					}

					(void)memcpy(comm_tx_buf, WEB_HOST_CONFIG_NET_PAGE, str_len);
					(void)memset(ssid_buf, 0, sizeof(ssid_buf));
					(void)NvMem1_DataRd(MEM1_AP_SSID_ADDR, ssid_buf, sizeof(ssid_buf));
					(void)strcat((char*)comm_tx_buf, (const char *)ssid_buf);

					//Append Last saved PSWD
					rx_data_start_ptr = (uint8_t*)strstr ((const char *)WEB_HOST_CONFIG_NET_PAGE, (const char *)SSID_VAL_KEYWORD);
					rx_data_start_ptr += strlen((const char *)SSID_VAL_KEYWORD);
					rx_data_end_ptr = (uint8_t*)strstr ((const char *)WEB_HOST_CONFIG_NET_PAGE, (const char *)PSWD_VAL_KEYWORD);
					str_len = (rx_data_end_ptr - rx_data_start_ptr);
					(void)memcpy((&comm_tx_buf[0] + strlen((const char *)comm_tx_buf)), rx_data_start_ptr, str_len);
					rx_data_start_ptr = (&comm_tx_buf[0] + strlen((const char *)comm_tx_buf));
					(void)memset(pswd_buf, 0, sizeof(pswd_buf));
					(void)NvMem1_DataRd(MEM1_AP_PSWD_ADDR, pswd_buf, sizeof(pswd_buf));
					(void)strcat((char*)comm_tx_buf, (const char *)pswd_buf);
					rx_data_start_ptr = (uint8_t*)strstr ((const char *)WEB_HOST_CONFIG_NET_PAGE, (const char *)PSWD_VAL_KEYWORD);
					rx_data_start_ptr += strlen((const char *)PSWD_VAL_KEYWORD);
					(void)strcat((char*)comm_tx_buf, (const char *)rx_data_start_ptr);

					str_len = strlen((const char*) comm_tx_buf);
					DataConv_LtoA(str_len, comm_tx_sz_str, (sizeof(comm_tx_sz_str)-1),
							TRUE, 0);
					web_host_prcs_state = WEB_HOST_RX_RESP_STATE;
				}
				else if(NULL != strstr ((const char *)Esp8266_GetRxDataPtr(), (const char *)HTTP_SAVE_NET_KEYWORD))
				{

					//Extract SSID
					rx_data_start_ptr  = (uint8_t*)strstr ((const char *)Esp8266_GetRxDataPtr(), (const char *)SSID_KEYWORD);
					rx_data_start_ptr += strlen((const char *)SSID_KEYWORD);
					rx_data_end_ptr  = (uint8_t*)strstr ((const char *)rx_data_start_ptr, "&");

					if(rx_data_end_ptr > rx_data_start_ptr)
					{
						str_len = (rx_data_end_ptr - rx_data_start_ptr);
					}

					if(str_len <= (sizeof(ssid_buf)-1))
					{
						(void)memset(ssid_buf, 0, sizeof(ssid_buf));
						(void)memcpy(ssid_buf, rx_data_start_ptr, str_len);
						(void)NvMem1_DataWr(MEM1_AP_SSID_ADDR, ssid_buf, sizeof(ssid_buf));
						NvMem1_Save();
					}

					//Extract PSWD
					rx_data_start_ptr  = (uint8_t*)strstr ((const char *)Esp8266_GetRxDataPtr(), (const char *)PSWD_KEYWORD);
					rx_data_start_ptr += strlen((const char *)PSWD_KEYWORD);
					rx_data_end_ptr  = (uint8_t*)strstr ((const char *)rx_data_start_ptr, " ");

					if(rx_data_end_ptr > rx_data_start_ptr)
					{
						str_len = (rx_data_end_ptr - rx_data_start_ptr);
					}

					if(str_len <= sizeof(ssid_buf)-1)
					{
						(void)memset(pswd_buf, 0, sizeof(pswd_buf));
						(void)memcpy(pswd_buf, rx_data_start_ptr, str_len);
						(void)NvMem1_DataWr(MEM1_AP_PSWD_ADDR, pswd_buf, sizeof(pswd_buf));
						NvMem1_Save();
					}

					//Clear
					(void)memset(comm_tx_buf, 0, sizeof(comm_tx_buf));
					str_len = strlen((const char*) WEB_HOST_SAVE_PAGE);
					DataConv_LtoA(str_len, comm_tx_sz_str, (sizeof(comm_tx_sz_str)-1),
							      TRUE, 0);
					(void)memcpy(comm_tx_buf, WEB_HOST_SAVE_PAGE, strlen((const char *)WEB_HOST_SAVE_PAGE));

					web_host_prcs_state = WEB_HOST_RX_RESP_STATE;
				}
				else
				{
					//Nothing
				}

				Esp8266_ClrRxDataFlag();

			}
			break;

		case WEB_HOST_RX_RESP_STATE:
			esp_resp_val = 	Esp8266_SendData((esp_ch_id_t)rx_link_id, comm_tx_buf, comm_tx_sz_str);
			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					web_host_prcs_state = WEB_HOST_CLOSE1_CONN_STATE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
						web_host_prcs_state = WEB_HOST_CLOSE1_CONN_STATE;
					}
				}

			}
			break;

		case WEB_HOST_CLOSE1_CONN_STATE:
			esp_resp_val = 	Esp8266_CloseConn(rx_link_id);
			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					prcs_tmr = SysTick_GetTickTmrVal();
					web_host_prcs_state = WEB_HOST_RELOAD_DELAY_STATE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
						prcs_tmr = SysTick_GetTickTmrVal();
						web_host_prcs_state = WEB_HOST_CLOSE2_CONN_STATE;
					}
				}

			}
			break;

		case WEB_HOST_CLOSE2_CONN_STATE:
			esp_resp_val = 	Esp8266_CloseConn(CH_ID_ALL);
			if(esp_resp_val != ESP_NO_RESP)
			{
				if(esp_resp_val == ESP_SUCCESS)
				{
					prcs_tmr = SysTick_GetTickTmrVal();
					web_host_prcs_state = WEB_HOST_RELOAD_DELAY_STATE;
				}
				else
				{
					esp_reinit_cntr++;
					if(esp_reinit_cntr > 3)
					{
						esp_reinit_cntr = 0;
						prcs_tmr = SysTick_GetTickTmrVal();
						web_host_prcs_state = WEB_HOST_RELOAD_DELAY_STATE;
					}
				}

			}
			break;

		case WEB_HOST_RELOAD_DELAY_STATE:
			if(SysTick_CheckTimeOut(&prcs_tmr, 1000) == TRUE)
			{
				if(Esp8266_GetRxDataFlag() == TRUE)
				{
					Esp8266_ClrRxDataFlag();
				}
				web_host_prcs_state = WEB_HOST_RX_PRCS_STATE;
			}
			break;
	}

}//End of WebHost_Prcs

/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     22-DEC-2017
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
