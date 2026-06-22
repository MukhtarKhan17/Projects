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
* @file      hal_esp8266_io.h
* @brief     HAL ESP8266 IO Interface File
*            + Contains interface to control IOs
*            + GPIO Initialization
*            + Reset High/Low routine
*            + Enable/Disable routine
* @version   V1.0.0
* @author    MK
* @date      25-FEB-2021
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

#include "hal_esp8266_io.h"


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
* @fn       void Esp8266IO_GpioInit (void)
* @brief    Esp8266IO_GpioInit
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     25-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
void Esp8266IO_GpioInit (void)
{
	RCC_APB2PeriphClockCmd(ESP8266_IO_PORT_CLK, ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.GPIO_Pin = ESP8266_EN_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(ESP8266_EN_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = ESP8266_RST_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(ESP8266_RST_PORT, &GPIO_InitStruct);

	Esp8266IO_Disable();
	Esp8266IO_RstHigh();
}// >> End of Esp8266IO_GpioInit

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void Esp8266IO_RstHigh (void)
* @brief    Esp8266IO_RstHigh
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     25-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
void Esp8266IO_RstHigh (void)
{
	GPIO_SetBits(ESP8266_RST_PORT, ESP8266_RST_PIN);
}// >> End of Esp8266IO_RstHigh

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void Esp8266IO_RstLow (void)
* @brief    Esp8266IO_RstLow
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     25-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
void Esp8266IO_RstLow (void)
{
	GPIO_ResetBits(ESP8266_RST_PORT, ESP8266_RST_PIN);
}// >> End of Esp8266IO_RstLow

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void Esp8266IO_Enable (void)
* @brief    Esp8266IO_Enable
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     25-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
void Esp8266IO_Enable (void)
{
	GPIO_SetBits(ESP8266_EN_PORT, ESP8266_EN_PIN);
}// >> End of Esp8266IO_Enable

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void Esp8266IO_Disable (void)
* @brief    Esp8266IO_Disable
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     25-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
void Esp8266IO_Disable (void)
{
	GPIO_ResetBits(ESP8266_EN_PORT, ESP8266_EN_PIN);
}// >> End of Esp8266IO_Disable

/*
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     25-FEB-2021
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
