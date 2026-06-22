/*
*##############################################################################
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
*##############################################################################
*/
//=============================================================================
/*!
* @file      esp8266.h
* @brief     ESP8266 command File
*            + Contains interface to Serial Communication
*            + ESP Initialization
*            + ESP Commands & Response
* @version   V1.0.4
* @author    MK
* @date      15-DEC-2021
* @remark    Designed & Developed by VOIDRON CO.
* @attention
*
* THIS CONTENT IS DESIGNED AND  DEVELOPED BY VOIDRON CO. UNATUHORISED  USED  IS
* PROHIBITED. CONTENT  OF  THIS  FILE  MAY  BE  UNPUBLISHED  OR   CONFIDENTIAL.
* SELLING  OR DISTRIBUTION  WILL  VOID  THE  LICENSE  AND  AGREEMENT  WITH  US.
* DOING  SO MAY LEAD TO  TAKE LEGAL  ACTION BY US  WHICH MAY RESULT IN PENALISE
* OFFENCE CHARGES ON YOU. DON'T  TRY TO MODIFY THE CONTENT OF THIS FILE, IT MAY
* GIVE  UNWANTED  RESULTS. IF  YOU  FIND  ANY TROUBLE  OR WANT  CHANGES  PLEASE
* CONTACT US.
*
* Email: contact@voidron.com
*
* <h2><center>             (C) VOIDRON CO. 2020-21.             </center></h2>
*/
//=============================================================================


#ifndef ESP8266_CMD_H_
#define ESP8266_CMD_H_

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

//#############################################################################
//                             \V/ Include SectioN
//#############################################################################
#include "vdef_types.h"
#include "string.h"
#include "stdlib.h"



//#############################################################################
//                            \V/ Global DefineS
//#############################################################################
#define ESP_SCAN_MAX_SZ                (1024) // In Bytes
#define ESP_RESP_MAX_SZ                (128U) // In Bytes
#define ESP_DATA_MAX_SZ                (128U) // In Bytes
#define MAC_ADDR_BUF_SZ                (17U) // >> XX:XX:XX:XX:XX:XX

#define ESP_BUSY_TO                    (50U)
#define ESP_RDY_PRCS_TO                (10U)
//#############################################################################
//                            \V/ Global MacroS
//#############################################################################



//#############################################################################
//                           \V/ Global Data TypeS
//#############################################################################
typedef void (*Esp8266GpioInitFptrT) (void);
typedef void (*Esp8266SerialInitFptrT) (void);
typedef void (*Esp8266RstHighFptrT) (void);
typedef void (*Esp8266RstLowFptrT) (void);
typedef void (*Esp8266EnableFptrT) (void);
typedef void (*Esp8266DisableFptrT) (void);
typedef bool_t (*Esp8266TxDataFptrT) (void *ip_data_ptr, uint16_t data_sz);
typedef bool_t (*Esp8266TxOverFptrT) (void);
typedef bool_t (*Esp8266RxDataFptrT) (void *op_data_ptr, uint16_t data_sz);
typedef uint16_t (*Esp8266GetRxDatSzFptrT) (void);
typedef bool_t (*Esp8266RxFlagFptrT) (void);
typedef void (*Esp8266ClrRecFlagFptrT) (void);
typedef void (*Esp8266TxCbufInitFptrT) (void);
typedef void (*Esp8266RxCbufInitFptrT) (void);
typedef void (*Esp8266DelayMsFptrT) (uint32_t delay_ms);
typedef uint32_t (*Esp8266GetTickMsFptrT) (void);
typedef bool_t (*Esp8266ChkTimeoutFptrT) (uint32_t *prvs_tick_tmr_ptr,
		                                  uint32_t tick_timeout_ms);

typedef struct
{
	Esp8266GpioInitFptrT     GpioInit;
	Esp8266SerialInitFptrT   SerialInit;
	Esp8266RstHighFptrT      RstHigh;
	Esp8266RstLowFptrT       RstLow;
	Esp8266EnableFptrT       Enable;
	Esp8266DisableFptrT      Disable;
	Esp8266TxDataFptrT       TxData;
	Esp8266TxOverFptrT       TxOver;
	Esp8266RxDataFptrT       RxData;
	Esp8266GetRxDatSzFptrT   GetRxDatSz;
	Esp8266RxFlagFptrT       GetRxFlag;
	Esp8266ClrRecFlagFptrT   ClrRxFlag;
	Esp8266TxCbufInitFptrT   TxCbufInit;
	Esp8266RxCbufInitFptrT   RxCbufInit;
	Esp8266DelayMsFptrT      DelayMs;
	Esp8266GetTickMsFptrT    GetTickMs;
	Esp8266ChkTimeoutFptrT   ChkTimeout;
}esp8266_base_t;

typedef enum
{
	ESP_NO_RESP,
	ESP_BUSY,
	ESP_SUCCESS,
	ESP_ERROR,
	ESP_TIMEOUT,
}esp_resp_t;

typedef enum
{
	ECHO_DISABLE,
	ECHO_ENABLE
}esp_echo_t;

typedef enum
{
	ESP_BAUD_9600,
	ESP_BAUD_19200,
	ESP_BAUD_38400,
	ESP_BAUD_115200,
}esp_baud_t;

typedef enum
{
	SINGLE_CONN,
	MULTIPLE_CONN
}esp_conn_t;

typedef enum
{
	TCP_SERV_OFF,
	TCP_SERV_ON
}esp_tcp_serv_t;

typedef enum
{
	STA_MODE,
	AP_MODE,
	STA_AP_MODE
}esp_wifi_mode_t;

typedef enum
{
	SORT_BY_RSSI_LEVEL,
	SORT_NOT_BY_RSSI_LEVEL,
}lap_sort_t;

typedef enum
{
	FULL_DETAIL_LISTING,
	ONLY_SSID_LISTING
}lap_list_type_t;

typedef enum
{
	DHCP_ENABLE,
	DHCP_DISABLE
}esp_dhcp_t;

typedef enum
{
	PASS_THRU_MODE_DISABLE,
	PASS_THRU_MODE_ENABLE
}pass_thru_mode_t;

typedef enum
{
	PASS_THRU_DATA_OFF,
	PASS_THRU_DATA_ON
}pass_thru_data_t;

typedef enum
{
	CH_ID_0 = 0,
	CH_ID_1,
	CH_ID_2,
	CH_ID_3,
	CH_ID_4,
	CH_ID_ALL,
	CH_ID_NONE
}esp_ch_id_t;

typedef enum
{
	CONN_TYPE_TCP,
	CONN_TYPE_UDP,
	CONN_TYPE_SSL,
}esp_conn_type_t;


typedef enum
{
	ENCRYPT_OPEN,
	ENCRYPT_WPA_PSK,
	ENCRYPT_WPA2_PSK,
	ENCRYPT_WPA_WPA2_PSK
}esp_encryp_type_t;


typedef struct
{
	uint8_t ip_4;
	uint8_t ip_3;
	uint8_t ip_2;
	uint8_t ip_1;
}ip_number_t;


//#############################################################################
//                            \V/ Global VariableS
//#############################################################################




//#############################################################################
//                        \V/ Global Function PrototypeS
//#############################################################################

//=============================================================================
//                         \V/ Esp8266_Enable
//=============================================================================
/*!
* @fn       bool_t Esp8266_Enable (int8_t *vtag_ptr)
* @brief    This function enables this library.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Enabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     26-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Esp8266_Enable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ Esp8266_Disable
//=============================================================================
/*!
* @fn       bool_t Esp8266_Disable (int8_t *vtag_ptr)
* @brief    This function disables this library.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Disabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     26-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Esp8266_Disable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void Esp8266_HardRst (void)
* @brief    Esp8266_HardRst
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     25-NOV-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void Esp8266_HardRst (void);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void Esp8266_ClrBuffers (void)
* @brief    Esp8266_ClrBuffers
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     25-NOV-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void Esp8266_ClrBuffers (void);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void Esp8266_BaseInit (esp8266_base_t set_esp8266_base_s)
* @brief    Esp8266_BaseInit
* @param    set_esp8266_base_s
* @retval   None
* @warning  if any member of set_esp8266_base_s is NULL then routine will not
*           move ahead. Remains in while loop.
* @note     None
* @author   MK
* @date     29-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void Esp8266_BaseInit (esp8266_base_t set_esp8266_base_s);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void Esp8266_RxScanPrcs (void)
* @brief    Esp8266_RxScanPrcs
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     09-DEC-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void Esp8266_RxScanPrcs (void);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       bool_t Esp8266_GetAtModeFlag(void)
* @brief    Esp8266_GetAtModeFlag
* @param    None
* @retval   esp_at_mode_f
* @warning  None
* @note     None
* @author   MK
* @date     25-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Esp8266_GetAtModeFlag(void);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void Esp8266_SetAtModeFlag(bool_t set_at_mode_f)
* @brief    Esp8266_SetAtModeFlag
* @param    set_at_mode_f
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     25-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void Esp8266_SetAtModeFlag(bool_t set_at_mode_f);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       uint8_t* Esp8266_GetRxDataPtr (void)
* @brief    Esp8266_GetRxDataPtr
* @param    None
* @retval   &esp_data_buf[0]
* @warning  None
* @note     None
* @author   MK
* @date     25-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint8_t* Esp8266_GetRxDataPtr (void);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       bool_t Esp8266_GetRxDataFlag (void)
* @brief    Esp8266_GetRxDataFlag
* @param    None
* @retval   esp_rx_data_f
* @warning  None
* @note     None
* @author   MK
* @date     25-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Esp8266_GetRxDataFlag (void);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void Esp8266_ClrRxDataFlag (void)
* @brief    Esp8266_ClrRxDataFlag
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     25-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void Esp8266_ClrRxDataFlag (void);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       uint8_t* Esp8266_GetRxRespPtr (void)
* @brief    Esp8266_GetRxRespPtr
* @param    None
* @retval   &esp_resp_buf[0]
* @warning  None
* @note     None
* @author   MK
* @date     25-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint8_t* Esp8266_GetRxRespPtr (void);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       bool_t Esp8266_GetRxRespFlag (void)
* @brief    Esp8266_GetRxRespFlag
* @param    None
* @retval   esp_rx_resp_f
* @warning  None
* @note     None
* @author   MK
* @date     25-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Esp8266_GetRxRespFlag (void);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void Esp8266_ClrRxRespFlag (void)
* @brief    Esp8266_ClrRxRespFlag
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     25-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void Esp8266_ClrRxRespFlag (void);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_TestOk (void)
* @brief    Esp8266_TestOk
* @param    None
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     26-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_TestOk (void);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_SetEcho (esp_echo_t esp_set_echo)
* @brief    Esp8266_SetEcho
* @param    esp_set_echo
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     26-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_SetEcho (esp_echo_t esp_set_echo);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_Reset (void)
* @brief    Esp8266_Reset
* @param    None
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     26-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_Reset (void);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_SetBaudRate (void)
* @brief    Esp8266_SetBaudRate
* @param    set_esp_baud
* @retval   esp_response
* @warning  None
* @note     8 data bits, 1 Stop Bit & No parity
* @author   MK
* @date     26-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_SetBaudRate (esp_baud_t set_esp_baud);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_Restore (void)
* @brief    Esp8266_Restore
* @param    None
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     26-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_Restore (void);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_TestOk (void)
* @brief    Esp8266_TestOk
* @param    None
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     26-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_GetVerInfo (void);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_SetWiFiMode (esp_wifi_mode_t esp_set_wifi_mode)
* @brief    Esp8266_SetWiFiMode
* @param    esp_set_wifi_mode
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     26-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//============================================================================
extern esp_resp_t Esp8266_SetWiFiMode (esp_wifi_mode_t esp_set_wifi_mode);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_SetDHCP (esp_wifi_mode_t esp_set_wifi_mode,
*                                       esp_dhcp_t esp_set_dhcp)
* @brief    Esp8266_SetDHCP
* @param    esp_set_wifi_mode
* @param    esp_set_dhcp
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     26-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_SetDHCP (esp_wifi_mode_t esp_set_wifi_mode,
		                           esp_dhcp_t esp_set_dhcp);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_ConnectAP (uint8_t *ssid_str_ptr,
*							              uint8_t *pswd_str_ptr,
*							              uint8_t *mac_str_ptr)
* @brief    Esp8266_ConnectAP
* @param    *ssid_str_ptr
* @param    *pswd_str_ptr
* @param    *mac_str_ptr
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     26-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_ConnectAP (uint8_t *ssid_str_ptr,
							         uint8_t *pswd_str_ptr,
							         uint8_t *mac_str_ptr);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_DisconnectAP (void)
* @brief    Esp8266_DisconnectAP
* @param    None
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     26-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_DisconnectAP (void);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_ConfigureListAP (lap_sort_t set_lap_sort,
*		                                        lap_list_type_t set_lap_list_type)
* @brief    Esp8266_TestOk
* @param    set_lap_sort
* @param    set_lap_list_type
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     26-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_ConfigureListAP (lap_sort_t set_lap_sort,
		                                   lap_list_type_t set_lap_list_type);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_ListAP (uint8_t *out_list_ap_ptr)
* @brief    Esp8266_TestOk
* @param    *out_list_ap_ptr
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     26-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_ListAP (uint8_t *out_list_ap_ptr);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_ConfigureAP (uint8_t *ssid_str_ptr,
*							                uint8_t *pswd_str_ptr,
*							                esp_ch_id_t esp_ch_id,
*							                esp_encryp_type_t esp_encryp_type)
* @brief    Esp8266_ConfigureAP
* @param    *ssid_str_ptr
* @param    *pswd_str_ptr
* @param    esp_ch_id
* @param    esp_encryp_type
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     26-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_ConfigureAP (uint8_t *ssid_str_ptr,
									   uint8_t *pswd_str_ptr,
									   esp_ch_id_t esp_ch_id,
									   esp_encryp_type_t esp_encryp_type);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_EstablishConn (esp_ch_id_t esp_set_ch_id,
*		                                      esp_conn_type_t esp_set_conn_type,
*		                                      uint8_t *in_remote_ip_str_ptr,
*		                                      uint8_t *in_remote_port_str_ptr,
*		                                      uint8_t *in_local_port_str_ptr)
* @brief    Esp8266_SetTcpServer
* @param    esp_set_ch_id
* @param    esp_set_conn_type
* @param    *in_remote_ip_str_ptr
* @param    *in_remote_port_str_ptr
* @param    *in_local_port_str_ptr
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     09-DEC-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_EstablishConn (esp_ch_id_t esp_set_ch_id,
		                                 esp_conn_type_t esp_set_conn_type,
		                                 uint8_t *in_remote_ip_str_ptr,
		                                 uint8_t *in_remote_port_str_ptr,
		                                 uint8_t *in_local_port_str_ptr);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_CloseConn (esp_ch_id_t esp_set_ch_id)
* @brief    Esp8266_CloseConn
* @param    esp_set_ch_id
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     09-DEC-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_CloseConn (esp_ch_id_t esp_set_ch_id);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_SendData (esp_ch_id_t esp_set_ch_id,
*							             uint8_t *in_data_str_ptr,
*							             uint8_t *in_data_sz_str_ptr)
* @brief    Esp8266_SetTcpServer
* @param    esp_set_ch_id
* @param    *in_data_str_ptr
* @param    *in_data_sz_str_ptr
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     09-DEC-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_SendData (esp_ch_id_t esp_set_ch_id,
							        uint8_t *in_data_str_ptr,
							        uint8_t *in_data_sz_str_ptr);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_SetNumOfConn (esp_conn_t esp_set_conn)
* @brief    Esp8266_SetNumOfConn
* @param    esp_set_conn
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     09-DEC-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_SetNumOfConn (esp_conn_t esp_set_conn);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_SetTcpServer (esp_tcp_serv_t esp_set_tcp_serv)
* @brief    Esp8266_SetTcpServer
* @param    esp_set_tcp_serv
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     26-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_SetTcpServer (esp_tcp_serv_t esp_set_tcp_serv);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_GetCipStatus(uint8_t *cip_status_ptr)
* @brief    Esp8266_GetCipStatus
* @param    *cip_status_ptr
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     25-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_GetCipStatus(uint8_t *cip_status_ptr);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_ReadMacAddr(uint8_t *mac_addr_ptr)
* @brief    Esp8266_ReadMacAddr
* @param    *mac_addr_ptr
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     25-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_ReadMacAddr(uint8_t *mac_addr_ptr);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_RdStaIp (ip_number_t *ip_num_ptr)
* @brief    Esp8266_RdStaIp
* @param    *ip_num_ptr
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     25-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_RdStaIp (ip_number_t *ip_num_ptr);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_SetPassThruMode (pass_thru_mode_t pass_thru_mode)
* @brief    Esp8266_SetPassThruMode
* @param    pass_thru_mode
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     25-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_SetPassThruMode (pass_thru_mode_t pass_thru_mode);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       esp_resp_t Esp8266_PassThruDataOn (pass_thru_data_t pass_thru_data)
* @brief    Esp8266_PassThruDataOn
* @param    pass_thru_data
* @retval   esp_response
* @warning  None
* @note     None
* @author   MK
* @date     25-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern esp_resp_t Esp8266_PassThruDataOn (pass_thru_data_t pass_thru_data);
/*
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     25-FEB-2021
* @brief    Initial Release
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.1
* @author   MK
* @date     29-APR-2021
* @brief    Following Function Removed
*           + Esp8266_Init
*           + Esp8266_SetFptr
*           Following Function Added
*           + Esp8266_Config
*           + Esp8266_BaseInit
*------------------------------------------------------------------------------
* @version  V1.0.2
* @author   MK
* @date     25-NOV-2021
* @brief    Bugs fixed in following functions
*           + Esp8266_RxScanPrcs
*           + Esp8266_SendData
*           + Esp8266_GetCipStatus
*           + Esp8266_ReadMacAddr
*           + Esp8266_RdStaIp
*           + Esp8266_SendCmd
*           + Esp8266_SendDat
*           Following functions are added
*           + Esp8266_ClrBuffers
*			+ Esp8266_HardRst
*------------------------------------------------------------------------------
* @version  V1.0.3
* @author   MK
* @date     09-DEC-2021
* @brief    Bugs fixed in following functions
*           + Esp8266_EstablishConn
*           + Esp8266_CloseConn
*           + Esp8266_SendData
*           + Esp8266_GetScanData
*           + Esp8266_RxScanPrcs
*           + Esp8266_SetNumOfConn
*------------------------------------------------------------------------------
* @version  V1.0.4
* @author   MK
* @date     15-DEC-2021
* @brief    Bugs fixed in following functions
*           + Esp8266_GetScanData
*------------------------------------------------------------------------------
* @version  V1.X.X
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
#endif // >> End of ESP8266_CMD_H_
/*! <h2><center>           (C) VOIDRON CO. 2020-21.           </center></h2> */
/*                        086 079 073 068 082 079 078                        */

