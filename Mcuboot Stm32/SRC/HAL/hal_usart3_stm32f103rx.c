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
* @file     hal_usart3_stm32f103rx.c
* @version  V1.0.0 <Update version of this file if changing>
* @brief    HAL USART3 Routines
*           ---
*           ---
*           ---
* @author   MK/SM
* @date     23-FEB-2021
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "hal_usart3_stm32f103rx.h"


/**
*==============================================================================
*                          	   \V/ Local DefineS
*==============================================================================
*/
#define USART3_PERI_CLK_EN           (RCC_APB1Periph_USART3)


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
static Uart3TxIsrFptrT Uart3TxIsrFptr = NULL;
static Uart3RxIsrFptrT Uart3RxIsrFptr = NULL;
/**
*==============================================================================
*                          \V/ Local Function PrototypeS
*==============================================================================
*/
static void Usart3_GpioInit (void);
static void Usart3_Config (void);

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Usart3_Init (Uart3TxIsrFptrT SetTxIsrFptr,
*             		     Uart3RxIsrFptrT SetRxIsrFptr)
*==============================================================================
* @brief    Usart3_Init
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
void Usart3_Init (Uart3TxIsrFptrT SetTxIsrFptr,
		          Uart3RxIsrFptrT SetRxIsrFptr)
{
	Uart3TxIsrFptr = SetTxIsrFptr;
	Uart3RxIsrFptr = SetRxIsrFptr;
	Usart3_GpioInit();
	Usart3_Config();
	NVIC_SetPriority(USART3_IRQn, 0);
	NVIC_EnableIRQ(USART3_IRQn);
	USART_Cmd(USART3, ENABLE);
	USART_ITConfig(USART3, USART_IT_TC, ENABLE);
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
} // End of Usart3_Init()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Usart3_TxData (uint8_t tx_data)
*==============================================================================
* @brief    Usart3_TxData
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
void Usart3_TxData (uint8_t tx_data)
{
	USART_SendData(USART3, tx_data);
}// End of Usart3_TxData()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  uint8_t Usart3_RxData (void)
*==============================================================================
* @brief    Usart3_RxData
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
uint8_t Usart3_RxData (void)
{
	uint8_t rx_data = 0;

	rx_data = USART_ReceiveData(USART3);

	return(rx_data);
}// End of Usart3_RxData()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void USART3_IRQHandler (void)
*==============================================================================
* @brief    USART3_IRQHandler
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
void USART3_IRQHandler (void)
{
	if(SET == USART_GetFlagStatus(USART3, USART_FLAG_TC))
	{
		if(Uart3TxIsrFptr != NULL)
		{
			Uart3TxIsrFptr();
		}
		USART_ClearFlag(USART3, USART_FLAG_TC);
	}

	if (SET == USART_GetFlagStatus(USART3, USART_FLAG_RXNE))
	{
		if(Uart3RxIsrFptr != NULL)
		{
			Uart3RxIsrFptr();
		}
		USART_ClearFlag(USART3, USART_FLAG_RXNE);
	}

	if (SET == USART_GetFlagStatus(USART3, USART_FLAG_LBD))
	{
		USART_ClearFlag(USART3, USART_FLAG_LBD);
	}

	if (SET == USART_GetFlagStatus(USART3, USART_FLAG_TXE))
	{
		USART_ClearITPendingBit(USART3, USART_IT_TC);
		USART_ITConfig(USART3, USART_IT_TXE, DISABLE);
	}

	if (SET == USART_GetFlagStatus(USART3, USART_FLAG_ORE))
	{
		USART_ClearFlag(USART3, USART_FLAG_ORE);
	}

	if (SET == USART_GetFlagStatus(USART3, USART_FLAG_IDLE))
	{
		USART_ClearFlag(USART3, USART_FLAG_IDLE);
	}
}// End of USART3_IRQHandler()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Usart3_GpioInit (void)
*==============================================================================
* @brief    Usart3_GpioInit
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
void Usart3_GpioInit (void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(USART3_PORT_CLK_EN, ENABLE);

	/* Configure USART3 TX as alternate function push-pull */
	GPIO_InitStruct.GPIO_Pin = USART3_PIN_TX_DEF;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(USART3_PORT_TX_DEF, &GPIO_InitStruct);

	/* Configure USART3 RX as input floating */
	GPIO_InitStruct.GPIO_Pin = USART3_PIN_RX_DEF;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(USART3_PORT_RX_DEF, &GPIO_InitStruct);
} // End of Usart3_GpioInit()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Usart3_Config (void)
*==============================================================================
* @brief    Usart3_Config
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
void Usart3_Config (void)
{
	USART_InitTypeDef USART_InitStruct;

	RCC_APB1PeriphClockCmd(USART3_PERI_CLK_EN, ENABLE);

	USART_InitStruct.USART_BaudRate = 115200;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(USART3, &USART_InitStruct);
} // End of Usart3_Config()


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
