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
* @{ <h2><center>           (C) VOIDRON CO. 2023.          </center></h2> @}
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
* @file     hal_spi2_stm32f103rx.c
* @version  V1.0.0 <Update version of this file>
* @brief    HAL Routines SPI2
*           ---
*           ---
*           ---
* @author   MK/RS
* @date     16-JAN-2022
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "hal_spi2_stm32f103rx.h"


/**
*==============================================================================
*                          	   \V/ Local DefineS
*==============================================================================
*/


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
static uint32_t spi2_tick_tmr_ms = 0;

/**
*==============================================================================
*                          \V/ Local Function PrototypeS
*==============================================================================
*/
static void Spi2_MasterGpioInit(void);
static void Spi2_MasterConfig(void);

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Spi2_MasterInit(void)
*==============================================================================
* @brief    Spi2_MasterInit
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK/RS
* @date     16-JAN-2022 //>> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Spi2_MasterInit(void)
{
	Spi2_MasterGpioInit();
	Spi2_MasterConfig();
}//End of Spi2_MasterInit()
/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  uint8_t Spi2_MasterTxRxByte(uint8_t tx_byte)
*==============================================================================
* @brief    Spi2_MasterTxRxByte
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK/RS
* @date     16-JAN-2022 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
uint8_t Spi2_MasterTxRxByte(uint8_t tx_byte)
{
	#define SPI2_STUCK_TIMEOUT_MS      (10U) //10ms

	uint8_t rx_byte = 0;

	// >> SPI Transmit
	SPI_I2S_SendData(SPI2, tx_byte);
	spi2_tick_tmr_ms = 0;
	while (RESET == SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE)
		   && (spi2_tick_tmr_ms < SPI2_STUCK_TIMEOUT_MS));

	// >> SPI Receive
	spi2_tick_tmr_ms = 0;
	while (RESET == SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE)
		   && (spi2_tick_tmr_ms < SPI2_STUCK_TIMEOUT_MS));
	rx_byte = SPI_I2S_ReceiveData(SPI2);

	return(rx_byte);
}//End of Spi2_MasterTxRxByte()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Spi2_MasterTickIsrPrcs(void)
*==============================================================================
* @brief    Spi2_MasterTickIsrPrcs
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK/RS
* @date     16-JAN-2022 //>> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Spi2_MasterTickIsrPrcs(void)
{
	spi2_tick_tmr_ms++;
}//End of Spi2_MasterTickIsrPrcs()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Spi2_MasterSetCsHigh(void)
*==============================================================================
* @brief    Spi2_MasterSetCsHigh
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK/RS
* @date     16-JAN-2022 //>> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Spi2_MasterSetCsHigh(void)
{
	GPIO_WriteBit(SPI2_GPIO_PORT, SPI2_CS_GPIO_PIN, Bit_SET);
}//End of Spi2_MasterSetCsHigh()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Spi2_MasterSetCsLow(void)
*==============================================================================
* @brief    Spi2_MasterSetCsLow
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK/RS
* @date     16-JAN-2022 //>> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Spi2_MasterSetCsLow(void)
{
	GPIO_WriteBit(SPI2_GPIO_PORT, SPI2_CS_GPIO_PIN, Bit_RESET);
}//End of Spi2_MasterSetCsLow()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Spi2_MasterGpioInit(void)
*==============================================================================
* @brief    Spi2_MasterGpioInit
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK/RS
* @date     16-JAN-2022 //>> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Spi2_MasterGpioInit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);
    RCC_APB2PeriphClockCmd(SPI2_CLK_PORT, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitStructure.GPIO_Pin   = SPI2_SCK_GPIO_PIN | SPI2_MISO_GPIO_PIN |SPI2_MOSI_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(SPI2_GPIO_PORT, &GPIO_InitStructure);


    GPIO_InitStructure.GPIO_Pin   = SPI2_CS_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(SPI2_GPIO_PORT, &GPIO_InitStructure);

    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);

    //Enable CS
    GPIO_ResetBits(SPI2_GPIO_PORT, SPI2_CS_GPIO_PIN);

}//End of Spi2_MasterGpioInit()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Spi2_MasterConfig(void)
*==============================================================================
* @brief    Spi2_MasterConfig
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK/RS
* @date     16-JAN-2022 //>> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Spi2_MasterConfig(void)
{
    SPI_InitTypeDef SPI_InitStructure;

    SPI_InitStructure.SPI_Direction         = SPI_Direction_2Lines_FullDuplex;
    SPI_InitStructure.SPI_Mode              = SPI_Mode_Master;
    SPI_InitStructure.SPI_DataSize          = SPI_DataSize_8b;
    SPI_InitStructure.SPI_CPOL              = SPI_CPOL_Low;
    SPI_InitStructure.SPI_CPHA              = SPI_CPHA_1Edge;
    SPI_InitStructure.SPI_NSS               = SPI_NSS_Soft;
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
    SPI_InitStructure.SPI_FirstBit          = SPI_FirstBit_MSB;
    SPI_InitStructure.SPI_CRCPolynomial     = 7;
    SPI_Init(SPI2, &SPI_InitStructure);

	SPI_Cmd(SPI2, ENABLE);
}//End of Spi2_MasterConfig()


/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK/RS
* @date     16-JAN-2022
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



/*-------------------------------END OF FILE----------------------------------*/
