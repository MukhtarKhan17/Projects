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
* @file     error_indicator.c
* @version  V1.0.0 <Update version of this file>
* @brief    Error Indicator Routines
*           ---
*           ---
*           ---
* @author   MK
* @date     28-FEB-2021
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "error_indicator.h"


/**
*==============================================================================
*                          	   \V/ Local DefineS
*==============================================================================
*/
//--> (5 * 1ms) = 5 ms
#define LOAD_ERR_TIMEOUT      		    (5U)

//--> (50 * 1ms) = 50 ms
#define START_ON_LED_TIMEOUT  			(50U)
//--> (300 * 1ms) = 300 ms
#define START_OFF_LED_TIMEOUT 			(300U)
//--> (500 * 1ms) = 500 ms
#define MSB_ERROR_TIMEOUT     			(500U)
//--> (1500 * 1ms) = 1.5 sec
#define SPACE_TIMEOUT   	  			(1500U)
//--> (500 * 1ms) = 500 ms
#define LSB_TO_START_TIMEOUT  			(500U)


#define START_BLINK_COUNT     			(20U)
#define UPPER_NIBBLE		  			(0xF0)
#define LOWER_NIBBLE		  			(0x0F)


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
uint16_t error_led_timer   	 		 = LOAD_ERR_TIMEOUT;
bool_t is_error_led_timeout 	     = FALSE;
bool_t is_err_indicator_en           = FALSE;
/**
*==============================================================================
*                          \V/ Local Function PrototypeS
*==============================================================================
*/
static void ErrInd_LoadErrors(uint8_t *error_buff_ptr, uint8_t *error_cnt_ptr);
static void ErrInd_SetErrLEDTimeout(uint16_t error_led_timeout);
static void ErrInd_LEDHandler(void);


/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Init (void)
*==============================================================================
* @brief    Init
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     28-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
* @fn void ErrInd_Init(void)
*==============================================================================
* @brief   ErrInd_Init
*          ---
*          ---
*          ---
* @note    None
* @param   None
* @retval  None
* @author  MK
* @date    30-MAR-2015 // >>Enter Last Change Date
*==============================================================================
*/
void ErrInd_Init(void)
{
	StsLed_Init();
	ErrInd_Enable();
}// End of ErrIndi_Init

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void ErrInd_LEDHandler(void)
*==============================================================================
* @brief    Routine to Indicate Error on LED.
*           ---
*           ---
*           ---
* @note     This is ISR routine. It get supposed to call in system tick ISR
* @param    None
* @retval   None
* @author   MK
* @date     28-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void ErrInd_LEDHandler(void)
{
	typedef enum
	{
		LOAD_ERROR, START_ON, START_OFF, MSB_ERROR_BYTE,
		SPACE, LSB_ERROR_BYTE
	}err_led_handler_state;

	static err_led_handler_state my_err_led_handler_state = LOAD_ERROR;
	static uint8_t blink_counter = 0;
	static uint8_t error_cntr = 0;
	static uint8_t error_value_buff[MAX_ERROR_CNT];

	if(TRUE == ErrInd_IsEnable())
	{
		switch(my_err_led_handler_state)
		{
			case LOAD_ERROR:
				if(error_cntr == 0)
				{
					//--> ErrInd_LoadErrors
					ErrInd_LoadErrors(error_value_buff, &error_cntr);
				}
				else
				{
					error_cntr--;
				}
				blink_counter = START_BLINK_COUNT;
				StsLed_TurnOff();
				ErrInd_SetErrLEDTimeout(START_ON_LED_TIMEOUT);
				my_err_led_handler_state = START_ON;
				break;

			case START_ON:
				blink_counter--;
				if(blink_counter == 0)
				{
					if(error_cntr == 0)
					{
						StsLed_TurnOn();
						ErrInd_SetErrLEDTimeout(LOAD_ERR_TIMEOUT);
						my_err_led_handler_state = LOAD_ERROR;
					}
					else
					{
						StsLed_TurnOff();
						ErrInd_SetErrLEDTimeout(START_OFF_LED_TIMEOUT);
						my_err_led_handler_state = START_OFF;
					}
				}
				else
				{
					StsLed_Toggle();
					ErrInd_SetErrLEDTimeout(START_ON_LED_TIMEOUT);
				}
				break;

			case START_OFF:
				StsLed_TurnOn();
				blink_counter = (error_value_buff[(error_cntr - 1)] & UPPER_NIBBLE);
				blink_counter = (blink_counter >> 4) * 2;
				ErrInd_SetErrLEDTimeout(MSB_ERROR_TIMEOUT);
				my_err_led_handler_state = MSB_ERROR_BYTE;
				break;

			case MSB_ERROR_BYTE:
				blink_counter--;
				if(blink_counter == 0)
				{
					StsLed_TurnOff();
					ErrInd_SetErrLEDTimeout(SPACE_TIMEOUT);
					my_err_led_handler_state = SPACE;
				}
				else
				{
					StsLed_Toggle();
					ErrInd_SetErrLEDTimeout(MSB_ERROR_TIMEOUT);
				}
				break;

			case SPACE:
				StsLed_TurnOn();
				blink_counter = ((error_value_buff[(error_cntr - 1)] & LOWER_NIBBLE)* 2);
				ErrInd_SetErrLEDTimeout(MSB_ERROR_TIMEOUT);
				my_err_led_handler_state = LSB_ERROR_BYTE;
				break;

			case LSB_ERROR_BYTE:
				blink_counter--;
				if(blink_counter == 0)
				{
					StsLed_TurnOff();
					ErrInd_SetErrLEDTimeout(LSB_TO_START_TIMEOUT);
					my_err_led_handler_state = LOAD_ERROR;
				}
				else
				{
					StsLed_Toggle();
					ErrInd_SetErrLEDTimeout(MSB_ERROR_TIMEOUT);
				}
				break;

			default:
				StsLed_TurnOn();
				ErrInd_SetErrLEDTimeout(LOAD_ERR_TIMEOUT);
				my_err_led_handler_state = LOAD_ERROR;
				break;
		}
	}
}// End of ErrIndi_LEDHandler

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void ErrInd_Enable(void)
*==============================================================================
* @brief    ErrInd_Enable
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     28-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void ErrInd_Enable(void)
{
	is_err_indicator_en = TRUE;
}// End of ErrInd_Enable


/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void ErrInd_Disable(void)
*==============================================================================
* @brief    ErrInd_Disable
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     28-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void ErrInd_Disable(void)
{
	StsLed_TurnOff();
	is_err_indicator_en = FALSE;
}// End of ErrInd_Disable

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t ErrInd_IsEnable(void)
*==============================================================================
* @brief    ErrInd_IsEnable
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   is_err_indicator_en
* @author   MK
* @date     28-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t ErrInd_IsEnable(void)
{
	return(is_err_indicator_en);
}// End of ErrInd_IsEnable

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void ErrInd_LoadErrors(uint8_t *error_buff_ptr, uint8_t *error_cnt_ptr)
*==============================================================================
* @brief    Routine to Load All Errors.
*           ---
*           ---
*           ---
* @note     None
* @param    *error_buff_ptr
* @param    *error_cnt_ptr
* @retval   error_buff_ptr, error_cnt_ptr
* @author   MK
* @date     28-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void ErrInd_LoadErrors(uint8_t *error_buff_ptr, uint8_t *error_cnt_ptr)
{
	uint8_t t_error_cntr = 0;

	if(ErrStat_GetFlag(SYSTEM_ERRS, FW_CHKSM_ERR) == TRUE)
	{
		*error_buff_ptr++ = FW_CHKSM_ERR_CODE;
		t_error_cntr++;
	}

	if(ErrStat_GetFlag(WIFI_ERRS, WIFI_CONFIG_ERR) == TRUE)
	{
		*error_buff_ptr++ = WIFI_CONFIG_ERR_CODE;
		t_error_cntr++;
	}

	if(ErrStat_GetFlag(WIFI_ERRS, WIFI_COMM_ERR) == TRUE)
	{
		*error_buff_ptr++ = WIFI_COMM_ERR_CODE;
		t_error_cntr++;
	}

	//--> set error count value
	*error_cnt_ptr = t_error_cntr;
}// End of ErrInd_LoadErrors

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void ErrInd_TickIsrPrcs (void)
*==============================================================================
* @brief    ErrInd_TickIsrPrcs
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     28-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void ErrInd_TickIsrPrcs (void)
{
	//--> Call Error Led Handler
	if(0 == error_led_timer)
	{
		ErrInd_LEDHandler();
	}
	else
	{
		error_led_timer--;
	}
}// End of ErrInd_TickIsrPrcs

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void ErrInd_SetErrLEDTimeout(uint16_t error_led_timeout)
*==============================================================================
* @brief    Set Error LED Timeout value.
*           ---
*           ---
*           ---
* @note     None
* @param    error_led_timeout : Timeout Value of Error LED.
* @retval   None
* @author   MK
* @date     28-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void ErrInd_SetErrLEDTimeout(uint16_t error_led_timeout)
{
	error_led_timer = error_led_timeout;
}// End of ErrInd_SetErrLEDTimeout

/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     28-FEB-2021
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
