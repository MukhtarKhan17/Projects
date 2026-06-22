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
* @{ <h2><center>            (C) VOIDRON CO. 2023             </center></h2> @}
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
* @file     hal_matrix_keypad_io.c
* @version  V1.0.0
* @brief    HAL Matrix Keypad IO
*           ---
*           ---
*           ---
* @author   MK
* @date     16-OCT-2023
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "hal_matrix_keypad_io.h"


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


/**
*==============================================================================
*                          \V/ Local Function PrototypeS
*==============================================================================
*/
// >> Declare Local Function Prototypes Here.


/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void MatrixKeypadIO_GpioInit (void)
*==============================================================================
* @brief    MatrixKeypadIO_GpioInit
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     16-OCT-2023 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void MatrixKeypadIO_GpioInit (void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;

	// Rows as read lines
	RCC_APB2PeriphClockCmd(KEYPAD_ROW_PORT_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = (KEYPAD_R1_PIN | KEYPAD_R2_PIN | KEYPAD_R3_PIN | KEYPAD_R4_PIN);
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(KEYPAD_ROW_PORT, &GPIO_InitStructure);

	// Columns as select lines
	RCC_APB2PeriphClockCmd(KEYPAD_COL_PORT_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin   = (KEYPAD_C1_PIN | KEYPAD_C2_PIN | KEYPAD_C3_PIN | KEYPAD_C4_PIN);
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(KEYPAD_COL_PORT, &GPIO_InitStructure);
} // End of MatrixKeypadIO_GpioInit()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void MatrixKeypadIO_SelectLine (uint8_t sel_val)
*==============================================================================
* @brief    MatrixKeypadIO_SelectLine
*           ---
*           ---
*           ---
* @note     None
* @param    sel_val
* @retval   None
* @author   MK
* @date     16-OCT-2023 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void MatrixKeypadIO_SelectLine (uint8_t sel_val)
{
	// Select line C1
	if((sel_val & 0x01U) == 0x01U)
	{
		GPIO_ResetBits(KEYPAD_COL_PORT, KEYPAD_C1_PIN);
	}
	else
	{
		GPIO_SetBits(KEYPAD_COL_PORT, KEYPAD_C1_PIN);
	}

	// Select line C2
	if((sel_val & 0x02U) == 0x02U)
	{
		GPIO_ResetBits(KEYPAD_COL_PORT, KEYPAD_C2_PIN);
	}
	else
	{
		GPIO_SetBits(KEYPAD_COL_PORT, KEYPAD_C2_PIN);
	}

	// Select line C3
	if((sel_val & 0x04U) == 0x04U)
	{
		GPIO_ResetBits(KEYPAD_COL_PORT, KEYPAD_C3_PIN);
	}
	else
	{
		GPIO_SetBits(KEYPAD_COL_PORT, KEYPAD_C3_PIN);
	}

	// Select line C4
	if((sel_val & 0x08U) == 0x08U)
	{
		GPIO_ResetBits(KEYPAD_COL_PORT, KEYPAD_C4_PIN);
	}
	else
	{
		GPIO_SetBits(KEYPAD_COL_PORT, KEYPAD_C4_PIN);
	}
} // >> End of MatrixKeypadIO_SelectLine()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  uint8_t MatrixKeypadIO_ReadLine (void)
*==============================================================================
* @brief    MatrixKeypadIO_ReadLine
*           ---
*           ---
*           ---
* @note     None
* @param    sel_val
* @retval   None
* @author   MK
* @date     16-OCT-2023 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
uint8_t MatrixKeypadIO_ReadLine (void)
{
	uint8_t rd_line_val = 0;

	rd_line_val |= GPIO_ReadInputDataBit(KEYPAD_ROW_PORT, KEYPAD_R4_PIN);
	rd_line_val  = (rd_line_val << 1U);
	rd_line_val |= GPIO_ReadInputDataBit(KEYPAD_ROW_PORT, KEYPAD_R3_PIN);
	rd_line_val  = (rd_line_val << 1U);
	rd_line_val |= GPIO_ReadInputDataBit(KEYPAD_ROW_PORT, KEYPAD_R2_PIN);
	rd_line_val  = (rd_line_val << 1U);
	rd_line_val |= GPIO_ReadInputDataBit(KEYPAD_ROW_PORT, KEYPAD_R1_PIN);

	rd_line_val |= 0xF0U;
	rd_line_val  = ~rd_line_val;

	return(rd_line_val);
} // >> End of MatrixKeypadIO_ReadLine()


/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     16-OCT-2023
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
