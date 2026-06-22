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
* @file     hal_can1_stm32f103rx.c
* @version  V1.0.0 <Update version of this file>
* @brief    HAL CAN1 Routines
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
#include "hal_can1_stm32f103rx.h"


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
// >> Declare local user data types here. Example typedef, structure & union.

/**
*==============================================================================
*                              \V/ Local VariableS
*==============================================================================
*/
static uint8_t tx_mailbox = 0;

/**
*==============================================================================
*                          \V/ Local Function PrototypeS
*==============================================================================
*/
static void Can1_GpioInit (void);
static void Can1_Config (can1_bitrate_t can1_bitrate );
static void Can1_FilterInit (uint32_t mask, uint32_t id );
static void Can1_Nvic(void);


/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Can1_Init(uint32_t mask, uint32_t id)
*==============================================================================
* @brief    Can1_Init
*           ---
*           ---
*           ---
* @note     None
* @param    mask
* @param    id
* @retval   None
* @author   MK
* @date     26-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Can1_Init(uint32_t mask, uint32_t id)
{
	CAN_DeInit(CAN1);

	Can1_GpioInit();

	Can1_Config(BITRATE_1MBPS);

	Can1_FilterInit(mask,id);

	Can1_Nvic();

	//>> CAN RX Interrupt
	CAN_ClearITPendingBit(CAN1, CAN_IT_FMP0);
	CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);

	//>> CAN TX Interrupt
	CAN_ClearITPendingBit(CAN1, CAN_IT_TME);
	CAN_ITConfig(CAN1, CAN_IT_TME, ENABLE);

}//End of Can1_Init()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Can1_GpioInit (void)
*==============================================================================
* @brief    Can1_GpioInit
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     26-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Can1_GpioInit (void)
{

	GPIO_InitTypeDef GPIO_InitStructure;

	// Enable Clocks
	RCC_APB2PeriphClockCmd(CAN1_PORT_TXRX_CLK_EN | CAN1_PORT_RS_CLK_EN | CAN1_PORT_LP_CLK_EN , ENABLE);

	// Init CAN_TX & CAN_RX
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin   = (CAN1_PIN_TX_DEF | CAN1_PIN_RX_DEF);
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(CAN1_PORT_TXRX_DEF, &GPIO_InitStructure);

	// Init CAN_RS
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin  = (CAN1_PIN_RS_DEF);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(CAN1_PORT_RS_DEF, &GPIO_InitStructure);
	GPIO_ResetBits(CAN1_PORT_RS_DEF, CAN1_PIN_RS_DEF);

	// Init CAN_LP
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin  = (CAN1_PIN_LP_DEF);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(CAN1_PORT_RS_DEF, &GPIO_InitStructure);
	GPIO_ResetBits(CAN1_PORT_LP_DEF, CAN1_PIN_LP_DEF);
}

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Can1_Config (can1_bitrate_t can1_bitrate)
*==============================================================================
* @brief    Can1_Config
*           ---
*           ---
*           ---
* @note     1. CAN bitrate = APB1 / (Prescaler × Total_TQ)
*           2. Sample Point = (1 + BS1) / TQ  (70% to 80% recommended)
* @param    can1_bitrate
* @retval   None
* @author   MK
* @date     03-JAN-2026 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Can1_Config (can1_bitrate_t can1_bitrate)
{

	CAN_InitTypeDef CAN_InitStructure;
	RCC_ClocksTypeDef RCC_ClocksStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
	RCC_GetClocksFreq(&RCC_ClocksStructure);

	CAN_StructInit(&CAN_InitStructure);
	CAN_InitStructure.CAN_TTCM = 	DISABLE;
	CAN_InitStructure.CAN_ABOM =	ENABLE;
	CAN_InitStructure.CAN_AWUM =	DISABLE;
	CAN_InitStructure.CAN_NART =	DISABLE;
	CAN_InitStructure.CAN_RFLM =	ENABLE;
	CAN_InitStructure.CAN_TXFP =	ENABLE;

	CAN_InitStructure.CAN_Mode = CAN_Mode_Normal;

	if(SystemCoreClock == 72000000)
	{
		if(can1_bitrate == BITRATE_125KBPS)
		{
			CAN_InitStructure.CAN_SJW  =  CAN_SJW_1tq;
			CAN_InitStructure.CAN_BS1 = CAN_BS1_11tq;
			CAN_InitStructure.CAN_BS2 = CAN_BS2_6tq;
			CAN_InitStructure.CAN_Prescaler = 16;

		}
		else if(can1_bitrate == BITRATE_250KBPS)
		{
			CAN_InitStructure.CAN_SJW  =  CAN_SJW_1tq;
			CAN_InitStructure.CAN_BS1 = CAN_BS1_11tq;
			CAN_InitStructure.CAN_BS2 = CAN_BS2_6tq;
			CAN_InitStructure.CAN_Prescaler = 8;


		}
		else if(can1_bitrate == BITRATE_500KBPS)
		{
			CAN_InitStructure.CAN_SJW  =  CAN_SJW_1tq;
			CAN_InitStructure.CAN_BS1 = CAN_BS1_11tq;
			CAN_InitStructure.CAN_BS2 = CAN_BS2_6tq;
			CAN_InitStructure.CAN_Prescaler = 4;

		}
		else if(can1_bitrate == BITRATE_1MBPS)
		{
			CAN_InitStructure.CAN_SJW  =  CAN_SJW_1tq;
			CAN_InitStructure.CAN_BS1 = CAN_BS1_11tq;
			CAN_InitStructure.CAN_BS2 = CAN_BS2_6tq;
			CAN_InitStructure.CAN_Prescaler = 2;
		}
		else
		{
			// Default BITRATE_1MBPS
			CAN_InitStructure.CAN_SJW  =  CAN_SJW_1tq;
			CAN_InitStructure.CAN_BS1 = CAN_BS1_11tq;
			CAN_InitStructure.CAN_BS2 = CAN_BS2_6tq;
			CAN_InitStructure.CAN_Prescaler = 2;
		}

	}
	else
	{
		while(TRUE); //TODO: Improve error indication
	}

	CAN_Init(CAN1, &CAN_InitStructure);

}//End of Can1_Config()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  vvoid Can1_FilterInit (uint32_t mask, uint32_t id)
*==============================================================================
* @brief    Can1_FilterInit
*           ---
*           ---
*           ---
* @note     None
* @param    mask
* @param    id
* @retval   None
* @author   MK
* @date     26-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Can1_FilterInit (uint32_t mask, uint32_t id)
{
	#define CAN_EXT_ID_POS				(3U)
	#define IDE_BIT_MASK				(0)
	#define RTR_BIT_MASK				(0)
	#define DATA_FRAME					(0)
	#define EXENDED_ID					(1U)
	uint16_t id_hi = 0;
	uint16_t id_low = 0;
	uint16_t mask_hi = 0;
	uint16_t mask_low = 0;


	// adjusting Identifier bits
	id = ((id << CAN_EXT_ID_POS)|(DATA_FRAME << 1) |(EXENDED_ID << 2));
	mask =((mask << CAN_EXT_ID_POS)|(IDE_BIT_MASK << 2) |(RTR_BIT_MASK << 1));

	//-->> dividing id and mask to 2 16bit variable >>
	id_hi = id >> 16;
	id_low = id & 0x0000FFFF;
	mask_hi = mask >> 16;
	mask_low = mask & 0x0000FFFF;

	CAN_FilterInitTypeDef CAN_FilterInitStructure;

	CAN_FilterInit(&CAN_FilterInitStructure);
	CAN_FilterInitStructure.CAN_FilterNumber = 0;
	CAN_FilterInitStructure.CAN_FilterScale = CAN_FilterScale_32bit;
	CAN_FilterInitStructure.CAN_FilterMode = CAN_FilterMode_IdMask;

	CAN_FilterInitStructure.CAN_FilterIdHigh =id_hi;
	CAN_FilterInitStructure.CAN_FilterIdLow =id_low;

	CAN_FilterInitStructure.CAN_FilterMaskIdHigh = mask_hi;
	CAN_FilterInitStructure.CAN_FilterMaskIdLow = mask_low;

	CAN_FilterInitStructure.CAN_FilterFIFOAssignment = CAN_Filter_FIFO0;
	CAN_FilterInitStructure.CAN_FilterActivation = ENABLE;
	CAN_FilterInit( &CAN_FilterInitStructure);
}//End of Can1_FilterInit()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Can1_Nvic(void)
*==============================================================================
* @brief    Can1_Nvic
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     26-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Can1_Nvic(void)
{
	NVIC_EnableIRQ(USB_HP_CAN1_TX_IRQn);
	NVIC_EnableIRQ(USB_LP_CAN1_RX0_IRQn);
	NVIC_EnableIRQ(CAN1_SCE_IRQn);
}//End of Can1_Nvic()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Can1_TxFrame(can_frm_t can_frm_s)
*==============================================================================
* @brief    Can1_TxFrame
*           ---
*           ---
*           ---
* @note     None
* @param    can_frm_s
* @retval   None
* @author   MK
* @date     26-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Can1_TxFrame(can_frm_t can_frm_s)
{
	static uint8_t i =0;
	CanTxMsg TxMessage;

	TxMessage.StdId = 0x00;
	TxMessage.ExtId = can_frm_s.id;
	TxMessage.RTR = CAN_RTR_DATA;
	TxMessage.IDE = CAN_ID_EXT;
	TxMessage.DLC = can_frm_s.data_sz;

	for(i = 0; i < can_frm_s.data_sz; i++ )
	{
		TxMessage.Data[i] = can_frm_s.data_buf[i];

	}
	tx_mailbox = CAN_Transmit(CAN1, &TxMessage);
	Can1_EnableTxInterrupt();
}// End of Can1_TxFrame()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  can_frm_t Can1_RxFrame(void)
*==============================================================================
* @brief    Can1_RxFrame
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   can_frm_s
* @author   MK
* @date     26-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
can_frm_t Can1_RxFrame(void)
{
	static uint8_t i = 0;
	can_frm_t can_frm_s;
 	CanRxMsg RxMessage;

	CAN_Receive(CAN1, CAN_FIFO0, &RxMessage);

	RxMessage.StdId = 0x00;
	can_frm_s.id = RxMessage.ExtId ;
	RxMessage.IDE = CAN_ID_EXT;
	can_frm_s.data_sz = RxMessage.DLC ;

	for(i = 0; i < 8; i++)
	{
		if(i < can_frm_s.data_sz)
		{
			can_frm_s.data_buf[i] = RxMessage.Data[i] ;
		}
		else
		{
			can_frm_s.data_buf[i] = 0;
		}
	}

	CAN_FIFORelease(CAN1, CAN_FIFO0);

	return(can_frm_s);

}//End of Can1_RxFrame()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void USB_HP_CAN1_TX_IRQHandler(void)
*==============================================================================
* @brief    USB_HP_CAN1_TX_IRQHandler
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     26-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void USB_HP_CAN1_TX_IRQHandler(void)
{
	if(CAN_GetITStatus(CAN1, CAN_IT_TME) == SET)
	{
		// Transmit Frame
		CanCom1_TxIsrPrcs();
		CAN_ClearITPendingBit(CAN1, CAN_IT_TME);
	}
}//End of USB_HP_CAN1_TX_IRQHandler()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void USB_LP_CAN1_RX0_IRQHandler(void)
*==============================================================================
* @brief    USB_LP_CAN1_RX0_IRQHandler
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     26-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void USB_LP_CAN1_RX0_IRQHandler(void)
{

	if(CAN_GetITStatus(CAN1, CAN_IT_FMP0) == SET)
	{
		// Receive Frame
		CanCom1_RxIsrPrcs();
		CAN_ClearITPendingBit(CAN1, CAN_IT_FMP0);
	}
}//End of USB_LP_CAN1_RX0_IRQHandler()


/**
 *=============================================================================
 * @fn  void Can1_EnableTxInterrupt (void)
 *=============================================================================
 * @brief   None
 * @note    None
 * @param   None
 * @retval  None
 * @author  RS
 * @date    5-JAN-2021
 *=============================================================================
 */
void Can1_EnableTxInterrupt(void)
{
	CAN_ITConfig(CAN1, CAN_IT_TME, ENABLE);
}// End of Can1_EnableTxInterrupt()

/**
 *=============================================================================
 * @fn  void Can1_DisableTxInterrupt (void)
 *=============================================================================
 * @brief   None
 * @note    None
 * @param   None
 * @retval  None
 * @author  RS
 * @date    5-JAN-2021
 *=============================================================================
 */
void Can1_DisableTxInterrupt(void)
{
	CAN_ITConfig(CAN1, CAN_IT_TME, DISABLE);
}// End of Can1_DisableTxInterrupt()


/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     DD-FEB-2021
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
