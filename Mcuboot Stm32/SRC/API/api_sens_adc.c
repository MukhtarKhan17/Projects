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
* @file     api_sens_adc.c
* @version  V1.0.0 <Update version of this file if changing>
* @brief    API ADC Routines
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
#include "api_sens_adc.h"

/**
*==============================================================================
*                          	   \V/ Local DefineS
*==============================================================================
*/
// >> 1. Local Constants
#define TH_DIV_FACTOR					(2U)

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
typedef enum
{
	SENS_THT_LOC =0,
	SENS_VREF_LOC,
}sens_data_buf_loc_t;

/**
*==============================================================================
*                              \V/ Local VariableS
*==============================================================================
*/
volatile static  sens_adc_db_t sens_adc_db_s = {0};

volatile static uint16_t adc_raw_data_buf[MAX_ADC_CH];
volatile static uint32_t adc_acc_data_buf[MAX_ADC_CH];
volatile static uint16_t adc_avg_data_buf[MAX_ADC_CH];

volatile static uint16_t  adc_acc_data_cntr = 0;
volatile static uint16_t  adc_data_avg_cnt  = 5;

/**
*==============================================================================
*                           Local Function Prototypes
*==============================================================================
*/
// >> Declare Local Function Prototypes Here.

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void SensAdc_Init (void)
*==============================================================================
* @brief    SensAdc_Init
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
void SensAdc_Init (void)
{
	(void)memset((uint16_t*)adc_raw_data_buf, 0, sizeof(adc_raw_data_buf));
	(void)memset((uint32_t*)adc_acc_data_buf, 0, sizeof(adc_acc_data_buf));
	(void)memset((uint16_t*)adc_avg_data_buf, 0, sizeof(adc_avg_data_buf));

	adc_acc_data_cntr = 0;

	sens_adc_db_s.sens_tht_mv  = 0;
	sens_adc_db_s.sens_vcc_mv     = 3300;

	Adc1_Init();

	SensAdc_SetAvgCnt(5);
}// >>End of SensAdc_Init

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void SensAdc_FetchDataPrcs (uint8_t* data_ptr, uint8_t data_sz)
*==============================================================================
* @brief    SensAdc_FetchDataPrcs
*           ---
*           ---
*           ---
* @note     None
* @param    data_ptr
* @param    data_sz
* @retval   None
* @author   SM
* @date     28-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void SensAdc_FetchDataPrcs (uint8_t* data_ptr, uint8_t data_sz)
{
	uint8_t i = 0;
	uint32_t aref_mv = 0;

	// Get ADC Raw Data
	(void)memcpy((uint16_t*)adc_raw_data_buf, data_ptr, data_sz);

	// Accumulate Data
	for(i = 0; i < MAX_ADC_CH; i++)
	{
		adc_acc_data_buf[i] += adc_raw_data_buf[i];
	}

	adc_acc_data_cntr++;
	if(adc_acc_data_cntr >= adc_data_avg_cnt)
	{
		//Find Average Value
		for(i = 0; i < MAX_ADC_CH; i++)
		{
			adc_avg_data_buf[i] = (adc_acc_data_buf[i] / adc_acc_data_cntr);
		}

		// Convert into voltage
		sens_adc_db_s.sens_vcc_mv = ((VREF_INT_MV * MAX_ADC_COUNT) / adc_avg_data_buf[SENS_VREF_LOC]);
		aref_mv = sens_adc_db_s.sens_vcc_mv;
		sens_adc_db_s.sens_tht_mv  = ((((aref_mv * adc_avg_data_buf[SENS_THT_LOC ])  / MAX_ADC_COUNT))* TH_DIV_FACTOR);

		// Clear ACC & Cntr
		(void)memset((uint32_t*)adc_acc_data_buf, 0, sizeof(adc_acc_data_buf));
 		adc_acc_data_cntr = 0;
	}
}// >>End of SensAdc_FetchDataPrcs

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void SensAdc_SetAvgCnt (uint16_t avg_cnt_val)
*==============================================================================
* @brief    SensAdc_SetAvgCnt
*           ---
*           ---
*           ---
* @note     None
* @param    avg_cnt_val
* @retval   None
* @author   SM
* @date     28-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void SensAdc_SetAvgCnt (uint16_t avg_cnt_val)
{
	adc_data_avg_cnt = avg_cnt_val;
}// >>End of SensAdc_SetAvgCnt

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  volatile sens_adc_db_t* SensAdc_GetDbPtr (void)
*==============================================================================
* @brief    SensAdc_SetAvgCnt
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   sens_adc_db_t
* @author   SM
* @date     28-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
volatile sens_adc_db_t* SensAdc_GetDbPtr (void)
{
	return(&sens_adc_db_s);
}// >>End of SensAdc_GetDbPtr

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  volatile sens_adc_db_t* SensAdc_GetDbPtr (void)
*==============================================================================
* @brief    SensAdc_SetAvgCnt
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   sens_adc_db_t
* @author   SM
* @date     28-AUG-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void SensAdc_TickPrcs(void)
{
	Adc1_TickPrcs();
}// >> End of SensAdc_TickPrcs

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
