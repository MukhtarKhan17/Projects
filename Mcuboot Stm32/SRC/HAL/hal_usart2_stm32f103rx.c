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
* @file     hal_usart2_stm32f103rx.c
* @version  V1.0.0 <Update version of this file if changing>
* @brief    HAL USART2 Routines
*           ---
*           ---
*           ---
* @author   MK
* @date     26-AUG-2021
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "hal_usart2_stm32f103rx.h"


/**
*==============================================================================
*                          	   \V/ Local DefineS
*==============================================================================
*/
#define USART2_PERI_CLK_EN           (RCC_APB1Periph_USART2)


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
static Uart2TxIsrFptrT Uart2TxIsrFptr = NULL;
static Uart2RxIsrFptrT Uart2RxIsrFptr = NULL;
/**
*==============================================================================
*                          \V/ Local Function PrototypeS
*==============================================================================
*/
static void Usart2_GpioInit (void);
static void Usart2_Config (void);

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Usart2_Init (Uart2TxIsrFptrT SetTxIsrFptr,
*             		     Uart2RxIsrFptrT SetRxIsrFptr)
*==============================================================================
* @brief    Usart2_Init
*           ---
*           ---
*           ---
* @note     None
* @param    SetTxIsrFptr
* @param    SetRxIsrFptr
* @retval   None
* @author   MK
* @date     23-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Usart2_Init (Uart2TxIsrFptrT SetTxIsrFptr,
		          Uart2RxIsrFptrT SetRxIsrFptr)
{
	Uart2TxIsrFptr = SetTxIsrFptr;
	Uart2RxIsrFptr = SetRxIsrFptr;
	Usart2_GpioInit();
	Usart2_Config();
	NVIC_EnableIRQ(USART2_IRQn);
	USART_Cmd(USART2, ENABLE);
	USART_ITConfig(USART2, USART_IT_TC, ENABLE);
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
} // End of Usart2_Init()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Usart2_TxData (uint8_t tx_data)
*==============================================================================
* @brief    Usart2_TxData
*           ---
*           ---
*           ---
* @note     None
* @param    tx_data
* @retval   None
* @author   MK/SM
* @date     23-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Usart2_TxData (uint8_t tx_data)
{
	USART_SendData(USART2, tx_data);
}// End of Usart2_TxData()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  uint8_t Usart2_RxData (void)
*==============================================================================
* @brief    Usart2_RxData
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   rx_data
* @author   MK/SM
* @date     23-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
uint8_t Usart2_RxData (void)
{
	uint8_t rx_data = 0;

	rx_data = USART_ReceiveData(USART2);

	return(rx_data);
}// End of Usart2_RxData()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void USART2_IRQHandler (void)
*==============================================================================
* @brief    USART2_IRQHandler
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     23-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void USART2_IRQHandler (void)
{
	if(SET == USART_GetFlagStatus(USART2, USART_FLAG_TC))
	{
		if(Uart2TxIsrFptr != NULL)
		{
			Uart2TxIsrFptr();
		}
		USART_ClearFlag(USART2, USART_FLAG_TC);
	}

	if (SET == USART_GetFlagStatus(USART2, USART_FLAG_RXNE))
	{
		if(Uart2RxIsrFptr != NULL)
		{
			Uart2RxIsrFptr();
		}
		USART_ClearFlag(USART2, USART_FLAG_RXNE);
	}

	if (SET == USART_GetFlagStatus(USART2, USART_FLAG_LBD))
	{
		USART_ClearFlag(USART2, USART_FLAG_LBD);
	}

	if (SET == USART_GetFlagStatus(USART2, USART_FLAG_TXE))
	{
		USART_ClearFlag(USART2, USART_FLAG_TXE);
	}

	if (SET == USART_GetFlagStatus(USART2, USART_FLAG_ORE))
	{
		USART_ClearFlag(USART2, USART_FLAG_ORE);
	}

	if (SET == USART_GetFlagStatus(USART2, USART_FLAG_IDLE))
	{
		USART_ClearFlag(USART2, USART_FLAG_IDLE);
	}
}// End of USART2_IRQHandler()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Usart2_GpioInit (void)
*==============================================================================
* @brief    Usart2_GpioInit
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     23-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Usart2_GpioInit (void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(USART2_PORT_CLK_EN, ENABLE);

	/* Configure USART2 TX as alternate function push-pull */
	GPIO_InitStruct.GPIO_Pin = USART2_PIN_TX_DEF;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(USART2_PORT_TX_DEF, &GPIO_InitStruct);

	/* Configure USART2 RX as input floating */
	GPIO_InitStruct.GPIO_Pin = USART2_PIN_RX_DEF;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(USART2_PORT_RX_DEF, &GPIO_InitStruct);
} // End of Usart2_GpioInit()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Usart2_Config (void)
*==============================================================================
* @brief    Usart2_Config
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     23-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Usart2_Config (void)
{
	USART_InitTypeDef USART_InitStruct;

	RCC_APB1PeriphClockCmd(USART2_PERI_CLK_EN, ENABLE);

	USART_InitStruct.USART_BaudRate = 115200;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(USART2, &USART_InitStruct);
} // End of Usart2_Config()


/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     23-FEB-2021
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
