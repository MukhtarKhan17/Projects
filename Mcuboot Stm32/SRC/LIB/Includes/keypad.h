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
* @file      keypad.h
* @brief     API Keypad
* @version   V1.0.2
* @author    MK
* @date      28-JAN-2023
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


#ifndef KEYPAD_H_
#define KEYPAD_H_

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
#define KEY_BUFFER_SZ                  (10U) //10 Keys


//#############################################################################
//                            \V/ Global MacroS
//#############################################################################



//#############################################################################
//                           \V/ Global Data TypeS
//#############################################################################
typedef enum
{
	KEY_DETECT_ON_PRESS   = 0,
	KEY_DETECT_ON_RELEASE = 1
}key_detect_method_t;

typedef void (*KeypadGpioInitFptrT) (void);
typedef bool_t (*KeypadRdKeyStsFptrT) (uint8_t key_num);
typedef uint32_t (*KeypadGetTickMsFptrT) (void);
typedef bool_t (*KeypadChkTimeoutFptrT) (uint32_t *prvs_tick_tmr_ptr,
		                                 uint32_t tick_timeout_ms);

typedef struct
{
	KeypadGpioInitFptrT     GpioInit;
	KeypadRdKeyStsFptrT     RdKeySts;
	KeypadGetTickMsFptrT    GetTickMs;
	KeypadChkTimeoutFptrT   ChkTimeout;
	uint8_t  num_of_keys;
	uint32_t debounce_timeout_ms;
	uint32_t key_press_timeout_ms;
	key_detect_method_t key_detect_method;
}keypad_base_t;


//#############################################################################
//                            \V/ Global VariableS
//#############################################################################




//#############################################################################
//                        \V/ Global Function PrototypeS
//#############################################################################

//=============================================================================
//                         \V/ Keypad_Enable
//=============================================================================
/*!
* @fn       bool_t Keypad_Enable (int8_t *vtag_ptr)
* @brief    This function enables this library.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Enabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     26-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Keypad_Enable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ Keypad_Disable
//=============================================================================
/*!
* @fn       bool_t Keypad_Disable (int8_t *vtag_ptr)
* @brief    This function disables this library.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Disabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     26-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Keypad_Disable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ Function Information
//=============================================================================
/*!
* @fn       void Keypad_BaseInit (keypad_base_t set_keypad_base_s)
* @brief    Keypad_BaseInit
* @param    set_keypad_base_s
* @retval   None
* @warning  if any member of set_keypad_base_s is NULL then routine will not
*           move ahead. Remains in while loop.
* @note     None
* @author   MK
* @date     29-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void Keypad_BaseInit (keypad_base_t set_keypad_base_s);

//=============================================================================
//                         \V/ Keypad_ScanPrcs
//=============================================================================
/*!
* @fn       void Keypad_ScanPrcs (void)
* @brief    Keypad_ScanPrcs
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     26-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void Keypad_ScanPrcs(void);

//=============================================================================
//                         \V/ Keypad_ReadPressKey
//=============================================================================
/*!
* @fn       uint8_t Keypad_ReadPressKey (void)
* @brief    Keypad_ReadPressKey
* @param    None
* @retval   key_val
* @warning  None
* @note     None
* @author   MK
* @date     26-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint8_t Keypad_ReadPressKey (void);

//=============================================================================
//                         \V/ Keypad_PressKeyTimeout
//=============================================================================
/*!
* @fn       bool_t Keypad_PressKeyTimeout (void)
* @brief    Keypad_PressKeyTimeout
* @param    None
* @retval   key_press_timeout_f
* @warning  None
* @note     None
* @author   MK
* @date     28-JAN-2023
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Keypad_PressKeyTimeout (void);

//=============================================================================
//                         \V/ Keypad_ClrTimeoutFlag
//=============================================================================
/*!
* @fn       void Keypad_ClrTimeoutFlag (void)
* @brief    Keypad_ClrTimeoutFlag
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     28-JAN-2023
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void Keypad_ClrTimeoutFlag (void);

//=============================================================================
//                         \V/ Keypad_ClrKeyBuffer
//=============================================================================
/*!
* @fn       void Keypad_ClrKeyBuffer (void)
* @brief    Keypad_ClrKeyBuffer
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     28-JAN-2023
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void Keypad_ClrKeyBuffer (void);


/*
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     26-MAR-2021
* @brief    Initial Release
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.1
* @author   MK
* @date     29-APR-2021
* @brief    Following Function Removed
*           Keypad_SetFptr
*           Keypad_Init
*           Following Function Added
*           Keypad_BaseInit
*------------------------------------------------------------------------------
* @version  V1.0.2
* @author   MK
* @date     28-JAN-2023
* @brief    Following Functions Added
*           #Keypad_ReadPressKey
*           #Keypad_PressKeyTimeout
*           #Keypad_ClrTimeoutFlag
*           #Keypad_ClrKeyBuffer
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
#endif // >> End of KEYPAD_H_
/*! <h2><center>             (C) VOIDRON CO. 2023.            </center></h2> */
/*                        086 079 073 068 082 079 078                        */

