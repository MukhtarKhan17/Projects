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
* @file     api_esp8266.h
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

#ifndef API_ESP8266_H_
#define API_ESP8266_H_

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "vdef_types.h"
#include "hal_esp8266_io.h"
#include "esp8266.h"
#include "api_sys_tick.h"
#include "api_data_conv.h"
#include "api_uart_com1.h"
#include "api_nv_mem1.h"
#include "data_base.h"

/**
*==============================================================================
*                          	  \V/ Global DefineS
*==============================================================================
*/



/**
*==============================================================================
*                          	  \V/ Global MacroS
*==============================================================================
*/
#define WIFI_STA_MODE                  (0U)
#define WIFI_AP_MODE                   (1U)
#define WIFI_MODE_SEL                  (WIFI_AP_MODE)

#define WIFI_SINGLE_CONN               (0U)
#define WIFI_MULTIPLE_CONN             (1U)
#define WIFI_CONN_SEL                  (WIFI_MULTIPLE_CONN)

#define TCP_SERVER_OFF                 (0U)
#define TCP_SERVER_ON                  (1U)
#define TCP_SERVER_SEL                 (TCP_SERVER_ON)

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
extern void Esp8266_Init (void);
extern bool_t Esp8266_GetInitErrFlag(void);

extern bool_t Esp8266_GenInitPrcs (void);
extern bool_t Esp8266_WiFiInitPrcs (void);
extern bool_t Esp8266_UdpSocketOnPrcs (void);
extern bool_t Esp8266_PassThruInitPrcs (void);

extern bool_t Esp8266_ApSearchPrcs (int8_t *ap_name_str_ptr,
		                            bool_t *search_sts_f_ptr);

extern bool_t Esp8266_ApJoinPrcs (int8_t *ap_name_str_ptr,
		                          int8_t *ap_pswd_str_ptr,
		                          bool_t *join_sts_f_ptr);

extern bool_t Esp8266_SendTcpDataPrcs (esp_ch_id_t tcp_set_ch_id,
									   int8_t *ip_addr_str_ptr,
							           int8_t *port_num_str_ptr,
							           int8_t *data_str_ptr,
							           bool_t *send_sts_f_ptr);

extern bool_t Esp8266_UdpStartConnPrcs (esp_ch_id_t udp_set_ch_id,
									    int8_t *remote_ip_addr_str_ptr,
									    int8_t *remote_port_num_str_ptr,
								        int8_t *local_port_num_str_ptr,
						   		        bool_t *send_sts_f_ptr);

extern bool_t Esp8266_UdpSendDataPrcs (esp_ch_id_t udp_set_ch_id,
									   int8_t *data_str_ptr,
									   bool_t *send_sts_f_ptr);

extern bool_t Esp8266_UdpCloseConnPrcs (esp_ch_id_t udp_set_ch_id,
							     	 	bool_t *send_sts_f_ptr);


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
#endif // >> End of API_ESP8266_H_

