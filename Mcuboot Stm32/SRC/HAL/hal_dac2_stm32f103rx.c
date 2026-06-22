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
* @file     hal_dac_stm32f4rx.c
* @version  V1.0.0
* @brief    HAL DAC Routines
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
#include "hal_dac2_stm32f103rx.h"


/**
*==============================================================================
*                          	  \V/ Local DefineS
*==============================================================================
*/
// >> 1. Local Constants


/**
*==============================================================================
*                          	  \V/ Local MacroS
*==============================================================================
*/
// >> 1. Local Macros


/**
*==============================================================================
*                           \V/ Local Data TypeS
*==============================================================================
*/
// >> Declare local user data types here. Example typedef, structure & union.

/**
*==============================================================================
*                            \V/ Local VariableS
*==============================================================================
*/
// >> Declare Local Variables Here.

/**
*==============================================================================
*                        \V/ Local Function PrototypeS
*==============================================================================
*/
// >> Declare Local Function Prototypes Here.


/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Dac2_Init (void)
*==============================================================================
* @brief    Dac2_Init
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
void Dac2_Init (void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	DAC_InitTypeDef  DAC_InitStructure;

	/* DMA1 clock and GPIOA clock enable (to be used with DAC) */
	RCC_APB2PeriphClockCmd(DAC2_PORT_CLK, ENABLE);

	/* DAC Peripheral clock enable */
	RCC_APB1PeriphClockCmd(DAC2_PERI_CLK, ENABLE);

	/* DAC channel2(DAC_OUT2 = PA.5) configuration */
	GPIO_InitStructure.GPIO_Pin = DAC2_PA5_GPIO;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(DAC2_PA5_PORT, &GPIO_InitStructure);

	/* DAC channel2 Configuration */
	DAC_InitStructure.DAC_Trigger = DAC_Trigger_None;
	DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;
	DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Disable;
	DAC_Init(DAC_Channel_2, &DAC_InitStructure);

	/* Enable DAC Channel2 */
	DAC_Cmd(DAC_Channel_2, ENABLE);

}// >>End of Dac2_Init

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Dac2_SetOutput (uint16_t dac_out)
*==============================================================================
* @brief    Dac2_SetOutput
*           ---
*           ---
*           ---
* @note     None
* @param    dac_out
* @retval   None
* @author   MK
* @date     26-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Dac2_SetOutput (uint16_t dac_out)
{
	DAC_SetChannel2Data(DAC_Align_12b_R, dac_out);
}// >>End of Dac2_SetOutput

/**===============================End of File================================*/
