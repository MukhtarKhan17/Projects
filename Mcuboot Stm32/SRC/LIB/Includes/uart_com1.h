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
* @file      uart_com1.h
* @brief     Buffered UART communication library.
* @version   V1.0.6
* @author    MK
* @date      08-MAY-2022
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
* <h2><center>             (C) VOIDRON CO. 2022.                </center></h2>
*/
//=============================================================================


#ifndef UART_COM1_H_
#define UART_COM1_H_

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
#define UART_COM1_TX_CBUF_SZ          (1024U)
#define UART_COM1_RX_CBUF_SZ          (1024U)


//#############################################################################
//                            \V/ Global MacroS
//#############################################################################



//#############################################################################
//                           \V/ Global Data TypeS
//#############################################################################
typedef void (*UartTxFptrT)(uint8_t);
typedef uint8_t (*UartRxFptrT)(void);

typedef struct
{
	UartTxFptrT   UartTx;
	UartRxFptrT   UartRx;
	uint8_t       rx_timeout_ms;
}uart_com1_base_t;

//#############################################################################
//                            \V/ Global VariableS
//#############################################################################




//#############################################################################
//                        \V/ Global Function PrototypeS
//#############################################################################

//=============================================================================
//                         \V/ UartCom1_Enable
//=============================================================================
/*!
* @fn       bool_t UartCom1_Enable (int8_t *vtag_uart1_ptr)
* @brief    This function enables this library.
* @param    *vtag_uart1_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Enabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     24-JAN-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t UartCom1_Enable (int8_t *vtag_uart1_ptr);

//=============================================================================
//                         \V/ UartCom1_Disable
//=============================================================================
/*!
* @fn       bool_t UartCom1_Disable (int8_t *vtag_uart1_ptr)
* @brief    This function disables this library.
* @param    *vtag_uart1_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Disabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     224-JAN-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t UartCom1_Disable (int8_t *vtag_uart1_ptr);

//=============================================================================
//                         \V/ UartCom1_BaseInit
//=============================================================================
/*!
* @fn       void UartCom1_BaseInit (uart_com1_base_t set_uart_com1_base_s)
* @brief    Initialization functions
* @param    set_uart_com1_base_s
* @retval   None
* @warning  if any member of set_uart_com1_base_s is NULL then routine will not
*           move ahead. Remains in while loop.
* @note     Call after UART driver initialization.
* @author   MK
* @date     29-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void UartCom1_BaseInit (uart_com1_base_t set_uart_com1_base_s);

//=============================================================================
//                         \V/ UartCom1_TxCbufInit
//=============================================================================
/*!
* @fn       void UartCom1_TxCbufInit (void)
* @brief    It initialize TX Buffer.
* @param    None
* @retval   None
* @warning  None
* @note     It can also be used to flush the buffer.
* @author   MK
* @date     24-JAN-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void UartCom1_TxCbufInit (void);

//=============================================================================
//                         \V/ UartCom1_RxCbufInit
//=============================================================================
/*!
* @fn       void UartCom1_RxCbufInit (void)
* @brief    It initialize RX Buffer.
* @param    None
* @retval   None
* @warning  None
* @note     It can also be used to flush the buffer.
* @author   MK
* @date     24-JAN-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void UartCom1_RxCbufInit (void);

//=============================================================================
//                         \V/ UartCom1_TxData
//=============================================================================
/*!
* @fn       bool_t UartCom1_TxData(void *ip_data_ptr, uint16_t data_sz)
* @brief    Function to transmit stream of data
* @param    ip_data_ptr: Input data pointer
* @param    data_sz: Input data size in bytes
* @retval   cbuf_full_err_f: True if full
* @warning  UartCom1_HalTxFptr must be initialized first.
* @note     None
* @author   MK
* @date     21-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t UartCom1_TxData(void *ip_data_ptr, uint16_t data_sz);

//=============================================================================
//                         \V/ UartCom1_TxIsrPrcs
//=============================================================================
/*!
* @fn       void UartCom1_TxIsrPrcs (void)
* @brief    Function to transmit stream of data ISR process.
* @param    None
* @retval   None
* @warning  UartCom1_HalTxFptr must be initialized first.
* @note     Call back this function in UART TX ISR Handler
* @author   MK
* @date     21-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void UartCom1_TxIsrPrcs (void);

//=============================================================================
//                         \V/ UartCom1_RxData
//=============================================================================
/*!
* @fn       bool_t UartCom1_RxData(void *op_data_ptr, uint16_t data_sz)
* @brief    Function to receive stream of data
* @param    op_data_ptr: Output data pointer
* @param    data_sz: Output data size in bytes
* @retval   cbuf_full_err_f: True if full
* @warning  UartCom1_HalRxFptr must be initialized first.
* @note     None
* @author   MK
* @date     24-JAN-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t UartCom1_RxData(void *op_data_ptr, uint16_t data_sz);

//=============================================================================
//                         \V/ UartCom1_GetRxDataSz
//=============================================================================
/*!
* @fn       uint16_t UartCom1_GetRxDataSz(void)
* @brief    Give received data count in RX buffer which is unread.
* @param    None
* @retval   data_sz: Data size in bytes
* @warning  None
* @note     It shows data count which is not read. On read count will be reduce.
* @author   MK
* @date     24-JAN-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint16_t UartCom1_GetRxDataSz(void);

//=============================================================================
//                         \V/ UartCom1_RxIsrPrcs
//=============================================================================
/*!
* @fn       void UartCom1_RxIsrPrcs (void)
* @brief    Function to receive stream of data ISR process.
* @param    None
* @retval   None
* @warning  UartCom1_HalRxFptr must be initialized first.
* @note     Call back this function in UART RX ISR Handler
* @author   MK
* @date     21-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void UartCom1_RxIsrPrcs (void);

//=============================================================================
//                         \V/ UartCom1_GetRxOvfFlag
//=============================================================================
/*!
* @fn       bool_t UartCom1_GetRxOvfFlag (void)
* @brief    Read RX buffer over flow flag
* @param    None
* @retval   uart1_rx_ovf_f: True if Rx buffer Overflow
* @warning  None
* @note     Buffer size can be adjusted by UART_COM1_RX_CBUF_SZ
* @author   MK
* @date     24-JAN-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t UartCom1_GetRxOvfFlag (void);

//=============================================================================
//                         \V/ UartCom1_GetTxOverFlag
//=============================================================================
/*!
* @fn       bool_t UartCom1_GetTxOverFlag (void)
* @brief    Read Transmit completed flag
* @param    None
* @retval   uart1_tx_over_f: True if Tx over
* @warning  None
* @note     Buffer size can be adjusted by UART_COM1_TX_CBUF_SZ
* @author   MK
* @date     24-JAN-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t UartCom1_GetTxOverFlag (void);

//=============================================================================
//                         \V/ UartCom1_TickIsrPrcs
//=============================================================================
/*!
* @fn       void UartCom1_TickIsrPrcs (void)
* @brief    System tick dependent process
* @param    None
* @retval   None
* @warning  Call back this function in System Tick ISR Handler
* @note     Tick must be of 1ms
* @author   MK
* @date     21-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void UartCom1_TickIsrPrcs (void);

//=============================================================================
//                         \V/ UartCom1_GetRxFlag
//=============================================================================
/*!
* @fn       bool_t UartCom1_GetRxFlag (void)
* @brief    Get flag after receiving data
* @param    None
* @retval   com_uart1_timeout_f
* @warning  None
* @note     None
* @author   MK
* @date     24-JAN-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t UartCom1_GetRxFlag (void);

//=============================================================================
//                         \V/ UartCom1_ClrRxFlag
//=============================================================================
/*!
* @fn       void UartCom1_ClrRxFlag (void)
* @brief    Clear flag after receiving data
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     24-JAN-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void UartCom1_ClrRxFlag (void);

/*
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     24-JAN-2021
* @brief    Initial Release
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.1
* @author   MK
* @date     22-FEB-2021
* @brief    Following function added
*           + UartCom1_SetTxFptr
*           + UartCom1_SetRxFptr
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.2
* @author   MK
* @date     22-APR-2021
* @brief    Following function Removed
*           + UartCom1_SetTxFptr
*           + UartCom1_SetRxFptr
*           Following function Added
*           + UartCom1_SetFptr
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.3
* @author   MK
* @date     29-APR-2021
* @brief    Following function Removed
*           + UartCom1_Init
*           + UartCom1_SetFptr
*           Following function Added
*           + UartCom1_BaseInit
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.4
* @author   MK
* @date     01-MAY-2021
* @brief    Following Function Modified
*           + UartCom1_TickIsrPrcs
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.5
* @author   MK
* @date     29-AUG-2021
* @brief    1) CBUF Bugs fixed
*           2) rx_timeout_ms added
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.6
* @author   MK
* @date     08-MAY-2022
* @brief    1) TX hang Issue Resolved
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
#endif // >> End of UART_COM1_H_
/*! <h2><center>           (C) VOIDRON CO. 2020-21.           </center></h2> */
/*                        086 079 073 068 082 079 078                        */

