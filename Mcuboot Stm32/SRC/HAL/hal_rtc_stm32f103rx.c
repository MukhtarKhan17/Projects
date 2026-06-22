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
 * @file     hal_rtc_stm32f103rx.c
 * @version  V1.0.0
 * @brief    HAL RTC
 *           The whole date and time is based on single second counter
 *           ---
 *           ---
 * @author   MK
 * @date     14-OCT-2023
 * @remark   Designed & Developed by Voidron Co.
 *==============================================================================
 */

/**
 *==============================================================================
 *                             \V/ Include SectioN
 *==============================================================================
 */
#include "hal_rtc_stm32f103rx.h"


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

/**
 *==============================================================================
 *                          \V/ Local Function PrototypeS
 *==============================================================================
 */
static void Rtc_Config(rtc_src_t set_rtc_src);

/**
 *==============================================================================
 *                         \V/ Function Information
 *------------------------------------------------------------------------------
 * @fn  void Rtc_Init(void)
 *==============================================================================
 * @brief    Rtc_Init
 *           ---
 *           ---
 *           ---
 * @note     None
 * @param    None
 * @retval   None
 * @author   MK
 * @date     14-OCT-2023 // >> Enter Last Change Date
 * @remark   Designed & Developed by Voidron Co.
 *==============================================================================
 */

void Rtc_Init(void)
{
	Rtc_Config(RTC_LSE);
}// >> End of Rtc_Init

/**
 *==============================================================================
 *                         \V/ Function Information
 *------------------------------------------------------------------------------
 * @fn  void Rtc_SetCounter(uint32_t set_val)
 *==============================================================================
 * @brief    Rtc_SetCounter
 *           ---
 *           ---
 *           ---
 * @note     None
 * @param    set_val
 * @retval   None
 * @author   MK
 * @date     14-OCT-2023 // >> Enter Last Change Date
 * @remark   Designed & Developed by Voidron Co.
 *==============================================================================
 */
void Rtc_SetCounter(uint32_t set_val)
{
	RTC_WaitForLastTask();
	RTC_SetCounter(set_val);
	RTC_WaitForLastTask();
}// >> End of Rtc_SetCounter

/**
 *==============================================================================
 *                         \V/ Function Information
 *------------------------------------------------------------------------------
 * @fn  uint32_t Rtc_GetCounter(void)
 *==============================================================================
 * @brief    Rtc_GetCounter
 *           ---
 *           ---
 *           ---
 * @note     None
 * @param    None
 * @retval   return_val
 * @author   MK
 * @date     14-OCT-2023 // >> Enter Last Change Date
 * @remark   Designed & Developed by Voidron Co.
 *==============================================================================
 */
uint32_t Rtc_GetCounter(void)
{
	uint32_t return_val = 0;

	return_val = RTC_GetCounter();

	return(return_val);
}// >> End of Rtc_GetCounter

/**
 *==============================================================================
 *                         \V/ Function Information
 *------------------------------------------------------------------------------
 * @fn  void Rtc_Config(void)
 *==============================================================================
 * @brief    Rtc_Config
 *           ---
 *           ---
 *           ---
 * @note     None
 * @param    None
 * @retval   None
 * @author   MK
 * @date     14-OCT-2023 // >> Enter Last Change Date
 * @remark   Designed & Developed by Voidron Co.
 *==============================================================================
 */
void Rtc_Config(rtc_src_t set_rtc_src)
{
	/* Enable PWR and BKP clocks */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);

	//	BKP_DeInit();
	RCC_BackupResetCmd(ENABLE);
	RCC_BackupResetCmd(DISABLE);


	/* Allow access to BKP Domain */
	PWR_BackupAccessCmd(ENABLE);
	/* Reset Backup Domain */


	if(set_rtc_src == RTC_LSI)
	{
		RCC_LSICmd(ENABLE);

		/* Wait till LSI is ready */
		while (RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET);
		/* Select the RTC Clock Source */
		RCC_RTCCLKConfig(RCC_RTCCLKSource_LSI);

		/* Enable RTC Clock */
		RCC_RTCCLKCmd(ENABLE);

		/* Wait for RTC registers synchronization */
		RTC_WaitForSynchro();

		/* Wait until last write operation on RTC registers has finished */
		RTC_WaitForLastTask();

		/* Enable the RTC Second */
		RTC_ITConfig(RTC_IT_SEC, ENABLE);

		/* Wait until last write operation on RTC registers has finished */
		RTC_WaitForLastTask();

		/* Set RTC prescaler: set RTC period to 1sec */
		RTC_SetPrescaler(37449); /* RTC period = RTCCLK/RTC_PR = (32.768 KHz)/(32767+1) */ //TODO: To be check the value

		/* Wait until last write operation on RTC registers has finished */
		RTC_WaitForLastTask();
	}
	else
	{

		/* Enable LSE */
		RCC_LSEConfig(RCC_LSE_ON);

		/* Wait till LSE is ready */
		while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET);

		/* Select LSE as RTC Clock Source */
		RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);

		/* Enable RTC Clock */
		RCC_RTCCLKCmd(ENABLE);

		/* Wait for RTC registers synchronization */
		RTC_WaitForSynchro();

		/* Wait until last write operation on RTC registers has finished */
		RTC_WaitForLastTask();

		/* Enable the RTC Second */
		RTC_ITConfig(RTC_IT_SEC, ENABLE);

		/* Wait until last write operation on RTC registers has finished */
		RTC_WaitForLastTask();

		/* Set RTC prescaler: set RTC period to 1sec */
		RTC_SetPrescaler(32767); /* RTC period = RTCCLK/RTC_PR = (32.768 KHz)/(32767+1) */

		/* Wait until last write operation on RTC registers has finished */
		RTC_WaitForLastTask();

	}
}// >> End of Rtc_Config

/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   RS
* @date     02-MAR-2021
* @brief    Initial Release
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.1
* @author   MK
* @date     14-OCT-2023
* @brief    Overall improvement done in each function
*           ---
*           ---
*
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
