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
* @file      matrix_keypad.h
* @brief     API Matrix Keypad
* @version   V1.0.1
* @author    MK
* @date      27-OCT-2023
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
* <h2><center>                (C) VOIDRON CO. 2023.              </center></h2>
*/
//=============================================================================


#ifndef MATRIX_KEYPAD_H_
#define MATRIX_KEYPAD_H_

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

//#############################################################################
//                             \V/ Include SectioN
//#############################################################################
#include "vdef_types.h"
#include "string.h"
#include "stdlib.h"


//#############################################################################
//                            \V/ Global DefineS
//#############################################################################
//>> The following definition are for reference only. Changes will not affect result.

#define KEY_BUFFER_SZ                  (10U)   //10 Keys

#define KEY_ASCII_DC1                  (0x11U)
#define KEY_ASCII_DC2                  (0x12U)
#define KEY_ASCII_DC3                  (0x13U)
#define KEY_ASCII_DC4                  (0x14U)


//#############################################################################
//                            \V/ Global MacroS
//#############################################################################



//#############################################################################
//                           \V/ Global Data TypeS
//#############################################################################
typedef enum
{
	DETECT_ON_PRESS   = 0,
	DETECT_ON_RELEASE = 1
}detect_method_t;

typedef enum
{
	KEY_CODE_C1R1  = 0x0101U,
	KEY_CODE_C2R1  = 0x0201U,
	KEY_CODE_C3R1  = 0x0401U,
	KEY_CODE_C4R1  = 0x0801U,
	KEY_CODE_C1R2  = 0x0102U,
	KEY_CODE_C2R2  = 0x0202U,
	KEY_CODE_C3R2  = 0x0402U,
	KEY_CODE_C4R2  = 0x0802U,
	KEY_CODE_C1R3  = 0x0104U,
	KEY_CODE_C2R3  = 0x0204U,
	KEY_CODE_C3R3  = 0x0404U,
	KEY_CODE_C4R3  = 0x0804U,
	KEY_CODE_C1R4  = 0x0108U,
	KEY_CODE_C2R4  = 0x0208U,
	KEY_CODE_C3R4  = 0x0408U,
	KEY_CODE_C4R4  = 0x0808U,
}matrix_key_code_t;

typedef enum
{
	KEY_1    = '1', KEY_2 = '2', KEY_3    = '3', KEY_F1 = KEY_ASCII_DC1,
	KEY_4    = '4', KEY_5 = '5', KEY_6    = '6', KEY_F2 = KEY_ASCII_DC2,
	KEY_7    = '7', KEY_8 = '8', KEY_9    = '9', KEY_F3 = KEY_ASCII_DC3,
	KEY_ASTR = '*', KEY_0 = '0', KEY_HASH = '#', KEY_F4 = KEY_ASCII_DC4,
}matrix_key_ascii_t;


typedef void (*GpioInitFptrT) (void);
typedef void (*SelectLinesFptrT) (uint8_t set_val);
typedef uint8_t (*ReadLinesFptrT) (void);
typedef uint32_t (*GetTickMsFptrT) (void);
typedef bool_t (*ChkTimeoutFptrT) (uint32_t *prvs_tick_tmr_ptr,
		                           uint32_t tick_timeout_ms);

typedef struct
{
	GpioInitFptrT           GpioInit;
	SelectLinesFptrT        SelectLine;
	ReadLinesFptrT          ReadLine;
	GetTickMsFptrT          GetTickMs;
	ChkTimeoutFptrT         ChkTimeout;
	uint32_t                debounce_timeout_ms;
	uint32_t                press_timeout_ms;
	detect_method_t         detect_method;
}matrix_keypad_base_t;




//#############################################################################
//                            \V/ Global VariableS
//#############################################################################




//#############################################################################
//                        \V/ Global Function PrototypeS
//#############################################################################

//=============================================================================
//                         \V/ MatrixKeypad_Enable
//=============================================================================
/*!
* @fn       bool_t MatrixKeypad_Enable (int8_t *vtag_ptr)
* @brief    This function enables this library.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Enabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     16-OCT-2023
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t MatrixKeypad_Enable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ MatrixKeypad_Disable
//=============================================================================
/*!
* @fn       bool_t MatrixKeypad_Disable (int8_t *vtag_ptr)
* @brief    This function disables this library.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Disabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     16-OCT-2023
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t MatrixKeypad_Disable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void MatrixKeypad_BaseInit (matrix_keypad_base_t set_matrix_keypad_base_s)
* @brief    MatrixKeypad_BaseInit
* @param    set_matrix_keypad_base_s
* @retval   None
* @warning  if any member of set_matrix_keypad_base_s is NULL then routine will not
*           move ahead. Remains in while loop.
* @note     None
* @author   MK
* @date     16-OCT-2023
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void MatrixKeypad_BaseInit (matrix_keypad_base_t set_matrix_keypad_base_s);

//=============================================================================
//                         \V/ MatrixKeypad_ScanPrcs
//=============================================================================
/*!
* @fn       void MatrixKeypad_ScanPrcs (void)
* @brief    MatrixKeypad_ScanPrcs
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     16-OCT-2023
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void MatrixKeypad_ScanPrcs(void);

//=============================================================================
//                         \V/ MatrixKeypad_ReadKeyCode
//=============================================================================
/*!
* @fn       uint8_t MatrixKeypad_ReadKeyCode (void)
* @brief    MatrixKeypad_ReadKeyCode
* @param    None
* @retval   key_val
* @warning  None
* @note     key_code = 0 if no key pressed
* @author   MK
* @date     16-OCT-2023
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern matrix_key_code_t MatrixKeypad_ReadKeyCode (void);

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  uint8_t MatrixKeypad_ReadKeyAscii (void)
*==============================================================================
* @brief    MatrixKeypad_ReadKeyAscii
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
extern matrix_key_ascii_t MatrixKeypad_ReadKeyAscii (void);

//=============================================================================
//                         \V/ MatrixKeypad_PressKeyTimeout
//=============================================================================
/*!
* @fn       bool_t MatrixKeypad_PressKeyTimeout (void)
* @brief    MatrixKeypad_PressKeyTimeout
* @param    None
* @retval   key_press_timeout_f
* @warning  None
* @note     None
* @author   MK
* @date     16-OCT-2023
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t MatrixKeypad_PressKeyTimeout (void);

//=============================================================================
//                         \V/ MatrixKeypad_ClrTimeoutFlag
//=============================================================================
/*!
* @fn       void MatrixKeypad_ClrTimeoutFlag (void)
* @brief    MatrixKeypad_ClrTimeoutFlag
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     16-OCT-2023
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void MatrixKeypad_ClrTimeoutFlag (void);

//=============================================================================
//                         \V/ MatrixKeypad_ClrKeyBuffer
//=============================================================================
/*!
* @fn       void MatrixKeypad_ClrKeyBuffer (void)
* @brief    MatrixKeypad_ClrKeyBuffer
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     16-OCT-2023
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void MatrixKeypad_ClrKeyBuffer (void);


/*
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
* @author   MK
* @date     27-OCT-2023
* @brief    The following function added
* 			MatrixKeypad_ReadKeyAscii()
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.X.X
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
#endif // >> End of MATRIX_KEYPAD_H_
/*! <h2><center>             (C) VOIDRON CO. 2023.            </center></h2> */
/*                        086 079 073 068 082 079 078                        */

