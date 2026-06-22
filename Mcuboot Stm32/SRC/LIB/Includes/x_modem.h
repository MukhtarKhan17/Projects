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
* @file      x_modem.h
* @brief     x-modem 1k file transfer protocol API. Operating in receiver mode.
*
* Xmodem is a half-duplex communication protocol. The receiver, after receiving
* a packet, will either acknowledge  (ACK) or not acknowledge  (NAK) the packet.
* The CRC extension to the original  protocol uses a more robust  16-bit CRC to
* validate the data block  and is  used here. Xmodem  can be considered  to  be
* receiver driven. That is, the receiver  sends an initial character “C” to the
* sender indicating that it’s ready to receive data in CRC mode. The sender then
* sends a 133-byte packet, the receiver validates it and responds with an ACK or
* a NAK at which time the sender will either send the next packet or re-send the
* last packet. This process is continued until an EOT is received at the receiver
* side and is  properly ACKed to  the sender. After  the  initial handshake  the
* receiver controls the flow of data  through ACKing and NAKing the sender.
*
* @version   V1.0.1
* @author    MK
* @date      29-AUG-2021
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


#ifndef X_MODEM_H_
#define X_MODEM_H_

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



//#############################################################################
//                            \V/ Global MacroS
//#############################################################################



//#############################################################################
//                           \V/ Global Data TypeS
//#############################################################################
typedef void (*XmodemComTxCbufInitFptrT) (void);
typedef void (*XmodemComRxCbufInitFptrT) (void);
typedef bool_t (*XmodemComTxDataFptrT) (void *ip_data_ptr, uint16_t data_sz);
typedef bool_t (*XmodemComRxDataFptrT) (void *op_data_ptr, uint16_t data_sz);
typedef uint16_t (*XmodemComRxDataSzFptrT) (void);
typedef void (*XmodemComDirTxOnFptrT) (void);
typedef void (*XmodemComDirRxOnFptrT) (void);
typedef void (*XmodemDelayMsFptrT) (uint32_t delay_ms);
typedef uint32_t (*XmodemGetTickMsFptrT) (void);
typedef bool_t (*XmodemChkTimeoutFptrT) (uint32_t *prvs_tick_tmr_ptr,
		                                 uint32_t tick_timeout_ms);

typedef struct
{
	XmodemComTxCbufInitFptrT  ComTxCbufInit;
	XmodemComRxCbufInitFptrT  ComRxCbufInit;
	XmodemComTxDataFptrT      ComTxData;
	XmodemComRxDataFptrT      ComRxData;
	XmodemComRxDataSzFptrT    ComRxDataSz;
	XmodemComDirTxOnFptrT     ComDirTxOn;
	XmodemComDirRxOnFptrT     ComDirRxOn;
	XmodemDelayMsFptrT        DelayMs;
	XmodemGetTickMsFptrT      GetTickMs;
	XmodemChkTimeoutFptrT     ChkTimeout;
	uint32_t                  dir_delay_ms;
}x_modem_base_t;

//#############################################################################
//                            \V/ Global VariableS
//#############################################################################




//#############################################################################
//                        \V/ Global Function PrototypeS
//#############################################################################

//=============================================================================
//                         \V/ Xmodem_Enable
//=============================================================================
/*!
* @fn       bool_t Xmodem_Enable (int8_t *vtag_ptr)
* @brief    This function enables this library.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Enabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     20-AUG-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Xmodem_Enable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ Xmodem_Disable
//=============================================================================
/*!
* @fn       bool_t Xmodem_Disable (int8_t *vtag_ptr)
* @brief    This function disables this library.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Disabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     20-AUG-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Xmodem_Disable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ Xmodem_BaseInit
//=============================================================================
/*!
* @fn       void Xmodem_BaseInit (x_modem_base_t set_x_modem_base_s)
* @brief    Xmodem_BaseInit
* @param    set_x_modem_base_s
* @retval   None
* @warning  if any member of set_x_modem_base_s is NULL then routine will not
*           move ahead. Remains in while loop.
* @note     ComDirTxOn & ComDirRxOn can assigned NULL if not required.
* @author   MK
* @date     29-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void Xmodem_BaseInit (x_modem_base_t set_x_modem_base_s);

//=============================================================================
//                         \V/ Xmodem_Config
//=============================================================================
/*!
* @fn       void Xmodem_Config (void)
* @brief    Xmodem_Config
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     20-AUG-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void Xmodem_Config (void);

//=============================================================================
//                         \V/ Xmodem_PktRxPrcs
//=============================================================================
/*!
* @fn       void Xmodem_PktRxPrcs (void)
* @brief    Xmodem_PktRxPrcs
* @param    None
* @retval   None
* @warning  None
* @note     Call this function continuous
* @author   MK
* @date     20-AUG-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void Xmodem_PktRxPrcs (void);

//=============================================================================
//                         \V/ Xmodem_RdPktNum
//=============================================================================
/*!
* @fn       uint8_t Xmodem_RdPktNum (void)
* @brief    Xmodem_RdPktNum
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     20-AUG-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint8_t Xmodem_RdPktNum (void);

//=============================================================================
//                         \V/ Xmodem_RdPktData
//=============================================================================
/*!
* @fn       bool_t Xmodem_RdPktData (uint16_t start_indx,
*						             uint8_t *op_buf_ptr,
*					                 uint16_t read_sz)
* @brief    Xmodem_RdPktData
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     20-AUG-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Xmodem_RdPktData (uint16_t start_indx,
						        uint8_t *op_buf_ptr,
					            uint16_t read_sz);

//=============================================================================
//                         \V/ Xmodem_RdRxData
//=============================================================================
/*!
* @fn       bool_t Xmodem_RdRxData(void *in_data_ptr, uint16_t data_sz)
* @brief    Xmodem_RdRxData
* @param    *op_data_ptr
* @param    data_sz
* @retval   cbuf_empty_err_f
* @warning  None
* @note     None
* @author   MK
* @date     20-AUG-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Xmodem_RdRxData(void *op_data_ptr, uint16_t data_sz);

//=============================================================================
//                         \V/ Xmodem_GetRxDataSz
//=============================================================================
/*!
* @fn       uint16_t Xmodem_GetRxDataSz(void)
* @brief    Xmodem_GetRxDataSz
* @param    None
* @retval   rx_data_sz
* @warning  None
* @note     None
* @author   MK
* @date     20-AUG-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint16_t Xmodem_GetRxDataSz(void);

/*
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     20-AUG-2021
* @brief    Initial Release
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.1
* @author   MK
* @date     29-AUG-2021
* @brief    1) x_modem_base_s.dir_delay_ms added
*           2) CBUF Bugs fixed
*           ---
*           ---
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
#endif // >> End of X_MODEM_H_
/*! <h2><center>           (C) VOIDRON CO. 2020-21.           </center></h2> */
/*                        086 079 073 068 082 079 078                        */

