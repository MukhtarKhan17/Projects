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
* @file      hal_goled_disp_io.c
* @brief     HAL Graphic OLED Display IO Interface File
*            + Contains interface to control IOs
*            + GPIO Initialization
*            + Reset High/Low routine
*            + Enable/Disable routine
*            + Data/Command Read/Write routines
* @version   V1.0.0
* @author    MK
* @date      17-MAR-2021
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


//#############################################################################
//                             \V/ Include SectioN
//#############################################################################

#include "hal_goled_disp_io.h"


//#############################################################################
//                          	\V/ Local DefineS
//#############################################################################




//#############################################################################
//                          	\V/ Local MacroS
//#############################################################################




//#############################################################################
//                             \V/ Local Data TypeS
//#############################################################################




//#############################################################################
//                              \V/ Local VariableS
//#############################################################################




//#############################################################################
//                          \V/ Local Function PrototypeS
//#############################################################################




//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void GoledDispIO_GpioInit (void)
* @brief    GoledDispIO_GpioInit
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
void GoledDispIO_GpioInit (void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

	RCC_APB2PeriphClockCmd(GOLED_DISP_CS_PORT_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(GOLED_DISP_RST_PORT_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(GOLED_DISP_RD_PORT_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(GOLED_DISP_RW_PORT_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(GOLED_DISP_DC_PORT_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(GOLED_DISP_D0_PORT_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(GOLED_DISP_D1_PORT_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(GOLED_DISP_D2_PORT_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(GOLED_DISP_D3_PORT_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(GOLED_DISP_D4_PORT_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(GOLED_DISP_D5_PORT_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(GOLED_DISP_D6_PORT_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(GOLED_DISP_D7_PORT_CLK, ENABLE);

	GPIO_InitStruct.GPIO_Pin   = GOLED_DISP_CS_PIN;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GOLED_DISP_CS_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin   = GOLED_DISP_RST_PIN;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GOLED_DISP_RST_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin   = GOLED_DISP_RD_PIN;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GOLED_DISP_RD_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin   = GOLED_DISP_RW_PIN;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GOLED_DISP_RW_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin   = GOLED_DISP_DC_PIN;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GOLED_DISP_DC_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin   = GOLED_DISP_D0_PIN;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GOLED_DISP_D0_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin   = GOLED_DISP_D1_PIN;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GOLED_DISP_D1_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin   = GOLED_DISP_D2_PIN;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GOLED_DISP_D2_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin   = GOLED_DISP_D3_PIN;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GOLED_DISP_D3_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin   = GOLED_DISP_D4_PIN;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GOLED_DISP_D4_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin   = GOLED_DISP_D5_PIN;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GOLED_DISP_D5_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin   = GOLED_DISP_D6_PIN;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GOLED_DISP_D6_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin   = GOLED_DISP_D7_PIN;
	GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GOLED_DISP_D7_PORT, &GPIO_InitStruct);

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
}// >> End of GoledDispIO_GpioInit

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void GoledDispIO_CsHigh (void)
* @brief    GoledDispIO_CsHigh
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
void GoledDispIO_CsHigh (void)
{
	GPIO_SetBits(GOLED_DISP_CS_PORT, GOLED_DISP_CS_PIN);
}// >> End of GoledDispIO_CsHigh

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void GoledDispIO_CsLow (void)
* @brief    GoledDispIO_CsLow
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
void GoledDispIO_CsLow (void)
{
	GPIO_ResetBits(GOLED_DISP_CS_PORT, GOLED_DISP_CS_PIN);
}// >> End of GoledDispIO_CsLow

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void GoledDispIO_RstHigh (void)
* @brief    GoledDispIO_RstHigh
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
void GoledDispIO_RstHigh (void)
{
	GPIO_SetBits(GOLED_DISP_RST_PORT, GOLED_DISP_RST_PIN);
}// >> End of GoledDispIO_RstHigh

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void GoledDispIO_RstLow (void)
* @brief    GoledDispIO_RstLow
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
void GoledDispIO_RstLow (void)
{
	GPIO_ResetBits(GOLED_DISP_RST_PORT, GOLED_DISP_RST_PIN);
}// >> End of GoledDispIO_RstLow

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void GoledDispIO_RdHigh (void)
* @brief    GoledDispIO_RdHigh
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
void GoledDispIO_RdHigh (void)
{
	GPIO_SetBits(GOLED_DISP_RD_PORT, GOLED_DISP_RD_PIN);
}// >> End of GoledDispIO_RdHigh

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void GoledDispIO_RdLow (void)
* @brief    GoledDispIO_RdLow
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
void GoledDispIO_RdLow (void)
{
	GPIO_ResetBits(GOLED_DISP_RD_PORT, GOLED_DISP_RD_PIN);
}// >> End of GoledDispIO_RdLow

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void GoledDispIO_WrHigh (void)
* @brief    GoledDispIO_WrHigh
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
void GoledDispIO_WrHigh (void)
{
	GPIO_SetBits(GOLED_DISP_RW_PORT, GOLED_DISP_RW_PIN);
}// >> End of GoledDispIO_WrHigh

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void GoledDispIO_WrLow (void)
* @brief    GoledDispIO_WrLow
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
void GoledDispIO_WrLow (void)
{
	GPIO_ResetBits(GOLED_DISP_RW_PORT, GOLED_DISP_RW_PIN);
}// >> End of GoledDispIO_WrLow

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void GoledDispIO_DcHigh (void)
* @brief    GoledDispIO_DcHigh
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
void GoledDispIO_DcHigh (void)
{
	GPIO_SetBits(GOLED_DISP_DC_PORT, GOLED_DISP_DC_PIN);
}// >> End of GoledDispIO_DcHigh

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void GoledDispIO_DcLow (void)
* @brief    GoledDispIO_DcLow
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
void GoledDispIO_DcLow (void)
{
	GPIO_ResetBits(GOLED_DISP_DC_PORT, GOLED_DISP_DC_PIN);
}// >> End of GoledDispIO_DcLow

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void GoledDispIO_WrDatBus (uint8_t wr_data)
* @brief    GoledDispIO_WrDatBus
* @param    wr_data
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
void GoledDispIO_WrDatBus (uint8_t wr_data)
{
	//D0
	if((wr_data & 0x01) == 0x01)
	{
		GPIO_SetBits(GOLED_DISP_D0_PORT, GOLED_DISP_D0_PIN);
	}
	else
	{
		GPIO_ResetBits(GOLED_DISP_D0_PORT, GOLED_DISP_D0_PIN);
	}

	//D1
	if((wr_data & 0x02) == 0x02)
	{
		GPIO_SetBits(GOLED_DISP_D1_PORT, GOLED_DISP_D1_PIN);
	}
	else
	{
		GPIO_ResetBits(GOLED_DISP_D1_PORT, GOLED_DISP_D1_PIN);
	}

	//D2
	if((wr_data & 0x04) == 0x04)
	{
		GPIO_SetBits(GOLED_DISP_D2_PORT, GOLED_DISP_D2_PIN);
	}
	else
	{
		GPIO_ResetBits(GOLED_DISP_D2_PORT, GOLED_DISP_D2_PIN);
	}

	//D3
	if((wr_data & 0x08) == 0x08)
	{
		GPIO_SetBits(GOLED_DISP_D3_PORT, GOLED_DISP_D3_PIN);
	}
	else
	{
		GPIO_ResetBits(GOLED_DISP_D3_PORT, GOLED_DISP_D3_PIN);
	}

	//D4
	if((wr_data & 0x10) == 0x10)
	{
		GPIO_SetBits(GOLED_DISP_D4_PORT, GOLED_DISP_D4_PIN);
	}
	else
	{
		GPIO_ResetBits(GOLED_DISP_D4_PORT, GOLED_DISP_D4_PIN);
	}

	//D5
	if((wr_data & 0x20) == 0x20)
	{
		GPIO_SetBits(GOLED_DISP_D5_PORT, GOLED_DISP_D5_PIN);
	}
	else
	{
		GPIO_ResetBits(GOLED_DISP_D5_PORT, GOLED_DISP_D5_PIN);
	}

	//D6
	if((wr_data & 0x40) == 0x40)
	{
		GPIO_SetBits(GOLED_DISP_D6_PORT, GOLED_DISP_D6_PIN);
	}
	else
	{
		GPIO_ResetBits(GOLED_DISP_D6_PORT, GOLED_DISP_D6_PIN);
	}

	//D7
	if((wr_data & 0x80) == 0x80)
	{
		GPIO_SetBits(GOLED_DISP_D7_PORT, GOLED_DISP_D7_PIN);
	}
	else
	{
		GPIO_ResetBits(GOLED_DISP_D7_PORT, GOLED_DISP_D7_PIN);
	}


}// >> End of GoledDispIO_WrDatBus

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       uint8_t GoledDispIO_RdDatBus (void)
* @brief    GoledDispIO_RdDatBus
* @param    None
* @retval   rd_data
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
uint8_t GoledDispIO_RdDatBus (void)
{
	uint8_t rd_data = 0x00;

	rd_data = (rd_data << 1);
	rd_data |= GPIO_ReadInputDataBit(GOLED_DISP_D7_PORT, GOLED_DISP_D7_PIN);

	rd_data = (rd_data << 1);
	rd_data |= GPIO_ReadInputDataBit(GOLED_DISP_D6_PORT, GOLED_DISP_D6_PIN);

	rd_data = (rd_data << 1);
	rd_data |= GPIO_ReadInputDataBit(GOLED_DISP_D5_PORT, GOLED_DISP_D5_PIN);

	rd_data = (rd_data << 1);
	rd_data |= GPIO_ReadInputDataBit(GOLED_DISP_D4_PORT, GOLED_DISP_D4_PIN);

	rd_data = (rd_data << 1);
	rd_data |= GPIO_ReadInputDataBit(GOLED_DISP_D3_PORT, GOLED_DISP_D3_PIN);

	rd_data = (rd_data << 1);
	rd_data |= GPIO_ReadInputDataBit(GOLED_DISP_D2_PORT, GOLED_DISP_D2_PIN);

	rd_data = (rd_data << 1);
	rd_data |= GPIO_ReadInputDataBit(GOLED_DISP_D1_PORT, GOLED_DISP_D1_PIN);

	rd_data = (rd_data << 1);
	rd_data |= GPIO_ReadInputDataBit(GOLED_DISP_D0_PORT, GOLED_DISP_D0_PIN);

	return(rd_data);
}// >> End of GoledDispIO_RdDatBus


/*
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     17-MAR-2021
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
/*! <h2><center>           (C) VOIDRON CO. 2020-21.           </center></h2> */
/*                        086 079 073 068 082 079 078                        */
