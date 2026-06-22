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
* @file     hal_adc1_stm32f103rx.c
* @version  V1.0.0 <Update version of this file if changing>
* @brief    HAL ADC1 Routines
*           ---
*           ---
*           ---
* @author   SM
* @date     28-AUG-2021
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "hal_adc1_stm32f103rx.h"

/**
*==============================================================================
*                          	   \V/ Local DefineS
*==============================================================================
*/
#define SENS_ANA_PORT_CLK             	(RCC_APB2Periph_GPIOA)
#define SENS_ANA_PORT                 	(GPIOA)

#define SENS_THT_GPIO			   	   	(GPIO_Pin_1)

//ADC Channel Number Assignment
#define NUM_OF_SCAN_CH				   	(2U)

#define THT_VOLT_ADC_CH					(ADC_Channel_1)
#define REF_VOLT_ADC_CH					(ADC_Channel_17)

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

const uint8_t adc_scan_seq_list[] =	{
										THT_VOLT_ADC_CH,
										REF_VOLT_ADC_CH,
									 };

uint8_t adc_ch_seq_buf[NUM_OF_SCAN_CH] = {0};

static uint16_t adc_result_buf[NUM_OF_SCAN_CH] = {0};
static uint8_t adc_ch_seq_index = 0;


/**
*==============================================================================
*                          \V/ Local Function PrototypeS
*==============================================================================
*/
static void ADC1_GpioInit (void);
static void ADC1_Config (void);

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Adc1_Init (void)
*==============================================================================
* @brief    Adc1_Init
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @param    None
* @retval   None
* @author   SM
* @date     28-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Adc1_Init (void)
{
	ADC1_GpioInit();

	ADC1_Config();

	if(sizeof(adc_scan_seq_list)>= NUM_OF_SCAN_CH)
	{
		(void)memcpy(adc_ch_seq_buf, (uint8_t*)adc_scan_seq_list, NUM_OF_SCAN_CH);
	}
	else
	{
		(void)memcpy(adc_ch_seq_buf, (uint8_t*)adc_scan_seq_list, sizeof(adc_scan_seq_list));
	}

	//Select ADC THT_VOLT_ADC_CH to start conversion
	ADC_RegularChannelConfig(ADC1, THT_VOLT_ADC_CH, 1, ADC_SampleTime_239Cycles5);

	NVIC_DisableIRQ(ADC1_2_IRQn);
	NVIC_ClearPendingIRQ(ADC1_2_IRQn);
	NVIC_EnableIRQ(ADC1_2_IRQn);

	ADC_ITConfig(ADC1, ADC_IT_EOC, ENABLE);

	// >>Enable ADC
	ADC_Cmd (ADC1,ENABLE);

}// >>End of Adc1_Init

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Adc1_TickPrcs (void)
*==============================================================================
* @brief    Adc1_TickPrcs
*           ---
*           ---
*           ---
* @note     Start ADC conversion on every 1 ms, need to call in Tick timer.
* @param    None
* @param    None
* @retval   None
* @author   SM
* @date     28-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Adc1_TickPrcs (void)
{
	ADC_SoftwareStartConvCmd(ADC1, ENABLE); //1KHz Sampling frequency

	// If ADC Overrun
	if(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == SET)
	{
		ADC_Cmd (ADC1,DISABLE);
		ADC_DeInit(ADC1);
		Adc1_Init();
		ADC_ClearFlag(ADC1, ADC_FLAG_EOC);
	}

}// >>End of Adc1_TickPrcs

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void ADC1_GpioInit (void)
*==============================================================================
* @brief    ADC1_GpioInit
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @param    None
* @retval   None
* @author   SM
* @date     28-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void ADC1_GpioInit (void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	//Enable GPIO PORT Clock
	RCC_APB2PeriphClockCmd(SENS_ANA_PORT_CLK, ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div8) ;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

	//Configure GPIO as Analog pin
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = (SENS_THT_GPIO);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz ;
	GPIO_Init(SENS_ANA_PORT, &GPIO_InitStructure);

}// >>End of ADC1_GpioInit

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void ADC1_Config (void)
*==============================================================================
* @brief    ADC1_Config
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @param    None
* @retval   None
* @author   SM
* @date     28-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void ADC1_Config (void)
{
	ADC_InitTypeDef ADC_InitStructure;

	ADC_StructInit(&ADC_InitStructure);

	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfChannel = 1;
	ADC_Init(ADC1, &ADC_InitStructure);
	ADC_TempSensorVrefintCmd(ENABLE);

}// >>End of ADC1_Config

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void ADC1_2_IRQHandler (void)
*==============================================================================
* @brief    ADC1_2_IRQHandler
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @param    None
* @retval   None
* @author   SM
* @date     28-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void ADC1_2_IRQHandler (void)
{

	// >> Collect ADC Data
	adc_result_buf[adc_ch_seq_index] = ADC_GetConversionValue(ADC1);
	adc_ch_seq_index++;
	ADC_RegularChannelConfig(ADC1, REF_VOLT_ADC_CH, 1, ADC_SampleTime_239Cycles5);

	if(adc_ch_seq_index >= NUM_OF_SCAN_CH)
	{
		adc_ch_seq_index = 0;
		ADC_RegularChannelConfig(ADC1, THT_VOLT_ADC_CH, 1, ADC_SampleTime_239Cycles5);
		// Read All Data
		SensAdc_FetchDataPrcs((uint8_t*)adc_result_buf, sizeof(adc_result_buf));
	}

	ADC_ClearFlag(ADC1, ADC_FLAG_EOC);
	ADC_ClearITPendingBit(ADC1, ADC_FLAG_EOC);

	if(ADC_GetFlagStatus(ADC1, ADC_FLAG_STRT) == SET)
	{
		ADC_ClearFlag(ADC1, ADC_FLAG_STRT);
		ADC_ClearITPendingBit(ADC1, ADC_FLAG_STRT);
	}

}// >>End of ADC_IRQHandler

/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   SM
* @date     28-AUG-2021
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
