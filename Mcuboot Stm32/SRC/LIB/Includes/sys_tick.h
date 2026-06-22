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
* @file      sys_tick.h
* @brief     This is System Tick module. It uses device timer to generate
*            consistent tick which must be configured at 1ms.
*@par        The routine in this file helps perform various operation such as:
*               1. Calculating function calling time.
*               2. Calling time critical process.
*               3. Generating delays or delay operation.
*               4. Measuring system Up time.
*               5. Restarting the system.

* @version   V1.0.3
* @author    MK
* @date      29-APR-2021
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
* <h2><center>             (C) VOIDRON CO. 2019-21.             </center></h2>
*/
//=============================================================================


#ifndef SYS_TICK_H_
#define SYS_TICK_H_

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

//#############################################################################
//                             \V/ Include SectioN
//#############################################################################

#include "vdef_types.h"
#include "string.h"

//#############################################################################
//                            \V/ Global DefineS
//#############################################################################



//#############################################################################
//                            \V/ Global MacroS
//#############################################################################



//#############################################################################
//                           \V/ Global Data TypeS
//#############################################################################

//typedef void (*vFptr)(void);

typedef void (*SysRstFptrT)(void);
typedef void (*AppPrcsFptrT)(void);

typedef struct
{
	SysRstFptrT    SysReset;
	AppPrcsFptrT   AppPrcs;
}sys_tick_base_t;


//#############################################################################
//                            \V/ Global VariableS
//#############################################################################



//#############################################################################
//                        \V/ Global Function PrototypeS
//#############################################################################

//=============================================================================
//                         \V/ SysTick_Enable
//=============================================================================
/*!
* @fn       bool_t SysTick_Enable (int8_t *vtag_ptr)
* @brief    This function enables lib functions.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Enabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t SysTick_Enable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ SysTick_Disable
//=============================================================================
/*!
* @fn       bool_t SysTick_Disable (int8_t *vtag_ptr)
* @brief    This function Disable lib functions.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Disabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t SysTick_Disable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ SysTick_BaseInit
//=============================================================================
/*!
* @fn       void SysTick_BaseInit (sys_tick_base_t set_sys_tick_base_s)
* @brief    SysTick_BaseInit
* @param    set_sys_tick_base_s
* @retval   None
* @warning  if any member of set_sys_tick_base_s is NULL then routine will not
*           move ahead. Remains in while loop.
* @note     None
* @author   MK
* @date     29-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SysTick_BaseInit (sys_tick_base_t set_sys_tick_base_s);

//=============================================================================
//                         \V/ SysTick_GetTickTmrVal
//=============================================================================
/*!
* @fn       uint32_t SysTick_GetTickTmrVal(void)
* @brief    Write the function description here
* @retval   tick_cntr_ms
* @warning  None
* @note     None
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint32_t SysTick_GetTickTmrVal(void);

//=============================================================================
//                         \V/ SysTick_CheckTimeOut
//=============================================================================
/*!
* @fn       bool_t SysTick_CheckTimeOut(uint32_t *prvs_tick_tmr_ptr,
*                                       uint32_t tick_timeout_ms)
* @brief    This function compare current call time with last called time and
*           if gap is greater than tick_timeout_ms then returns TRUE flag.
* @param    prvs_tick_tmr_ptr : Pointer to variable which holds last tick time.
* @param    tick_timeout_ms : Timeout to which previous will be tick compared.
* @retval   tick_timeout_f : Returns TRUE if timeout.
* @warning  prvs_tick_tmr_ptr pointing to variable must be static.
* @note     Timeout will be in ms only if linked tick timer value is 1ms.
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t SysTick_CheckTimeOut(uint32_t *prvs_tick_tmr_ptr,
		                           uint32_t tick_timeout_ms);

//=============================================================================
//                            \V/ SysTick_Delay
//=============================================================================
/*!
* @fn       void SysTick_Delay(uint32_t delay_ms)
* @brief    This function generates fixed delay in multiple of 1ms.
* @param    delay_ms : Value in milliseconds
* @warning  This function hold the control for delay_ms. Loop call may get
*           affected.
* @note     Timeout will be in ms only if linked tick timer value is 1ms.
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SysTick_Delay(uint32_t delay_ms);

//=============================================================================
//                            \V/ SysTick_SysReset
//=============================================================================
/*!
* @fn       void SysTick_SysReset(uint32_t delay_ms)
* @brief    This function perform System Reset post delay_ms.
* @param    delay_ms : Value in milliseconds
* @warning  None
* @note     Timeout will be in ms only if linked tick timer value is 1ms.
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SysTick_SysReset(uint32_t delay_ms);

//=============================================================================
//                            \V/ SysTick_GetSysUpTime
//=============================================================================
/*!
* @fn       uint32_t SysTick_GetSysUpTime(void)
* @brief    This function returns system up time in ms.
* @retval   sys_up_timer_secs : Value in Seconds
* @warning  None
* @note     Timeout will be in ms only if linked tick timer value is 1ms.
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint32_t SysTick_GetSysUpTime(void);

//=============================================================================
//                        \V/ SysTick_TmrIsrPrcs
//=============================================================================
/*!
* @fn       void SysTick_TmrIsrPrcs(void)
* @brief    This function must be linked or called in timer ISR.
* @warning  None
* @note     Any device timer can be used which is capable of generating precise
*           1ms interrupt.
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SysTick_TmrIsrPrcs(void);

/*
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     30-OCT-2019
* @brief    Initial Release
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.1
* @author   MK
* @date     26-JAN-2021
* @brief    Bug Fix-1:
*           1. FuncPtr replaced with vFptr
*           2. SysTick_SysLinkReset name & argument modified to SysTick_SysResetPtr
*           3. SysTick_LinkAppPrcs name & argument modified to SysTick_AppPrcsPtr
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.2
* @author   MK
* @date     22-APR-2021
* @brief    Following function removed
*           + SysTick_SysResetPtr
*           + SysTick_AppPrcsPtr
*
*           Following function removed
*           + SysTick_BaseInit
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.3
* @author   MK
* @date     29-APR-2021
* @brief    Following function removed
*           + SysTick_SetFptr
*
*           Following function Added
*           + SysTick_BaseInit
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
#endif // >> End of SYS_TICK_H_

/*! <h2><center>           (C) VOIDRON CO. 2019-21.           </center></h2> */
/*                        086 079 073 068 082 079 078                        */

