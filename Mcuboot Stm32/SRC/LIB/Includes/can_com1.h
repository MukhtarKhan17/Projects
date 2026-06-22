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
* @file      can_com1.h
* @brief     Buffered CAN communication library.
* @version   V1.0.1
* @author    MK
* @date      29-APR-2021
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


#ifndef CAN_COM1_H_
#define CAN_COM1_H_

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

//#############################################################################
//                             \V/ Include SectioN
//#############################################################################
#include "vdef_types.h"
#include "string.h"


//#############################################################################
//                            \V/ Global DefineS
//#############################################################################
#define CAN1_TX_CBUF_SZ          (10U) // CAN Frames
#define CAN1_RX_CBUF_SZ          (10U) // CAN Frames
#define CAN1_RX_TIMEOUT_MS       (25U) // 25ms
#define CAN1_FRM_DATA_SZ         (8U)  // 8 Byte/frame


//#############################################################################
//                            \V/ Global MacroS
//#############################################################################



//#############################################################################
//                           \V/ Global Data TypeS
//#############################################################################

typedef struct
{
	uint8_t  data_buf[CAN1_FRM_DATA_SZ];
	uint8_t  data_sz;
	uint32_t id;
}can_frm_t;

typedef void (*CanTxFptrT) (can_frm_t can_frm_s);
typedef can_frm_t (*CanRxFptrT) (void);

typedef struct
{
	CanTxFptrT   CanTx;
	CanRxFptrT   CanRx;
}can_com1_base_t;

//#############################################################################
//                            \V/ Global VariableS
//#############################################################################




//#############################################################################
//                        \V/ Global Function PrototypeS
//#############################################################################

//=============================================================================
//                         \V/ CanCom1_Enable
//=============================================================================
/*!
* @fn       bool_t CanCom1_Enable (int8_t *vtag_can1_ptr)
* @brief    This function enables this library.
* @param    *vtag_can1_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Enabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     15-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t CanCom1_Enable (int8_t *vtag_can1_ptr);

//=============================================================================
//                         \V/ CanCom1_Disable
//=============================================================================
/*!
* @fn       bool_t CanCom1_Disable (int8_t *vtag_can1_ptr)
* @brief    This function disables this library.
* @param    *vtag_can1_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Disabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     15-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t CanCom1_Disable (int8_t *vtag_can1_ptr);

//=============================================================================
//                         \V/ CanCom1_BaseInit
//=============================================================================
/*!
* @fn       void CanCom1_BaseInit (can_com1_base_t set_can_com1_base_s)
* @brief    CanCom1_BaseInit
* @param    set_can_com1_base_s
* @retval   None
* @warning  if any member of set_can_com1_base_s is NULL then routine will not
*           move ahead. Remains in while loop.
* @note     None
* @author   MK
* @date     29-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void CanCom1_BaseInit (can_com1_base_t set_can_com1_base_s);

//=============================================================================
//                         \V/ CanCom1_TxCbufInit
//=============================================================================
/*!
* @fn       void CanCom1_TxCbufInit (void)
* @brief    It initialize TX Buffer.
* @param    None
* @retval   None
* @warning  None
* @note     It can also be used to flush the buffer.
* @author   MK
* @date     15-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void CanCom1_TxCbufInit (void);

//=============================================================================
//                         \V/ CanCom1_RxCbufInit
//=============================================================================
/*!
* @fn       void CanCom1_RxCbufInit (void)
* @brief    It initialize RX Buffer.
* @param    None
* @retval   None
* @warning  None
* @note     It can also be used to flush the buffer.
* @author   MK
* @date     15-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void CanCom1_RxCbufInit (void);

//=============================================================================
//                         \V/ CanCom1_TxData
//=============================================================================
/*!
* @fn       bool_t CanCom1_TxData(can_frm_t *can_frm_s_ptr)
* @brief    Function to transmit stream of data
* @param    *can_frm_s_ptr
* @retval   cbuf_full_f
* @warning  None
* @note     None
* @author   MK
* @date     15-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t CanCom1_TxData(can_frm_t *can_frm_s_ptr);

//=============================================================================
//                         \V/ CanCom1_TxIsrPrcs
//=============================================================================
/*!
* @fn       void CanCom1_TxIsrPrcs (void)
* @brief    Function to transmit stream of data ISR process.
* @param    None
* @retval   None
* @warning  CanCom1_HalTxFptr must be initialized first.
* @note     Call back this function in CAN TX ISR Handler
* @author   MK
* @date     15-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void CanCom1_TxIsrPrcs (void);

//=============================================================================
//                         \V/ CanCom1_RxData
//=============================================================================
/*!
* @fn       bool_t CanCom1_RxData(can_frm_t *can_frm_s_ptr)
* @brief    Function to receive stream of data
* @param    *can_frm_s_ptr
* @retval   cbuf_empty_f: True if Empty
* @warning  None
* @note     None
* @author   MK
* @date     15-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t CanCom1_RxData(can_frm_t *can_frm_s_ptr);

//=============================================================================
//                         \V/ CanCom1_GetRxDataSz
//=============================================================================
/*!
* @fn       uint8_t CanCom1_GetRxDataSz(void)
* @brief    Give received data count in RX buffer which is unread.
* @param    None
* @retval   data_sz: Data size in bytes
* @warning  None
* @note     It shows data count which is not read. On read count will be reduce.
* @author   MK
* @date     15-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint8_t CanCom1_GetRxDataSz(void);

//=============================================================================
//                         \V/ CanCom1_RxIsrPrcs
//=============================================================================
/*!
* @fn       void CanCom1_RxIsrPrcs (void)
* @brief    Function to receive stream of data ISR process.
* @param    None
* @retval   None
* @warning  CanCom1_HalRxFptr must be initialized first.
* @note     Call back this function in CAN RX ISR Handler
* @author   MK
* @date     15-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void CanCom1_RxIsrPrcs (void);

//=============================================================================
//                         \V/ CanCom1_GetRxOvfFlag
//=============================================================================
/*!
* @fn       bool_t CanCom1_GetRxOvfFlag (void)
* @brief    Read RX buffer over flow flag
* @param    None
* @retval   can1_rx_ovf_f: True if Rx buffer Overflow
* @warning  None
* @note     Buffer size can be adjusted by CAN1_RX_CBUF_SZ
* @author   MK
* @date     15-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t CanCom1_GetRxOvfFlag (void);

//=============================================================================
//                         \V/ CanCom1_GetTxOverFlag
//=============================================================================
/*!
* @fn       bool_t CanCom1_GetTxOverFlag (void)
* @brief    Read Transmit completed flag
* @param    None
* @retval   can1_tx_over_f: True if Tx over
* @warning  None
* @note     Buffer size can be adjusted by CAN1_TX_CBUF_SZ
* @author   MK
* @date     15-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t CanCom1_GetTxOverFlag (void);

//=============================================================================
//                         \V/ CanCom1_TickIsrPrcs
//=============================================================================
/*!
* @fn       void CanCom1_TickIsrPrcs (void)
* @brief    System tick dependent process
* @param    None
* @retval   None
* @warning  Call back this function in System Tick ISR Handler
* @note     Tick must be of 1ms
* @author   MK
* @date     15-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void CanCom1_TickIsrPrcs (void);

//=============================================================================
//                         \V/ CanCom1_GetRxFlag
//=============================================================================
/*!
* @fn       bool_t CanCom1_GetRxFlag (void)
* @brief    Get flag after receiving data
* @param    None
* @retval   can1_timeout_f
* @warning  None
* @note     None
* @author   MK
* @date     15-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t CanCom1_GetRxFlag (void);

//=============================================================================
//                         \V/ CanCom1_ClrRxFlag
//=============================================================================
/*!
* @fn       void CanCom1_ClrRxFlag (void)
* @brief    Clear flag after receiving data
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     15-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void CanCom1_ClrRxFlag (void);

/*
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     15-APR-2021
* @brief    Initial Release
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.1
* @author   MK
* @date     29-APR-2021
* @brief    Following function removed
*           CanCom1_SetFptr
*           CanCom1_Init
*           Following function added
*           CanCom1_BaseInit
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
#endif // >> End of CAN_COM1_H_
/*! <h2><center>           (C) VOIDRON CO. 2020-21.           </center></h2> */
/*                        086 079 073 068 082 079 078                        */

