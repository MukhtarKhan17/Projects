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
* @file      clock.h
* @brief     This file provides single 32-bit counter based clock routines.
* @note      Time format supported 24 Hours
* @version   V1.0.1
* @author    MK
* @date      16-OCT-2023
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
* <h2><center>               (C) VOIDRON CO. 2023                </center></h2>
*/
//=============================================================================


#ifndef CLOCK_H_
#define CLOCK_H_

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
#define	CLOCK_START_YEAR                (2000U) // 01-JAN-2000 & 12:00AM
#define CLOCK_END_YEAR                  (2136U) // 31-DEC-2136 & 11:59AM


//#############################################################################
//                            \V/ Global MacroS
//#############################################################################



//#############################################################################
//                           \V/ Global Data TypeS
//#############################################################################

//typedef void (*vFptr)(void);

typedef void (*SetCounterFptrT)(uint32_t set_val);
typedef uint32_t (*GetCounterFptrT)(void);

typedef struct
{
	SetCounterFptrT   SetCounter;
	GetCounterFptrT   GetCounter;
}clock_base_t;


typedef struct
{
    uint16_t  	year;
    uint8_t 	month;
    uint8_t 	date;
    uint8_t 	hour;
    uint8_t 	min;
    uint8_t 	sec;
}clock_db_t;


//#############################################################################
//                            \V/ Global VariableS
//#############################################################################



//#############################################################################
//                        \V/ Global Function PrototypeS
//#############################################################################

//=============================================================================
//                         \V/ Clock_Enable
//=============================================================================
/*!
* @fn       bool_t Clock_Enable (int8_t *vtag_ptr)
* @brief    This function enables lib functions.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Enabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     14-OCT-2023
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Clock_Enable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ Clock_Disable
//=============================================================================
/*!
* @fn       bool_t Clock_Disable (int8_t *vtag_ptr)
* @brief    This function Disable lib functions.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Disabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     14-OCT-2023
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Clock_Disable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ Clock_BaseInit
//=============================================================================
/*!
* @fn       void Clock_BaseInit (clock_base_t set_clock_base_s)
* @brief    Clock_BaseInit
* @param    set_clock_base_s
* @retval   None
* @warning  if any member of set_clock_base_s is NULL then routine will not
*           move ahead. Remains in while loop.
* @note     None
* @author   MK
* @date     29-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void Clock_BaseInit (clock_base_t set_clock_base_s);

//=============================================================================
//                         \V/ Clock_SetDataBase
//=============================================================================
/*!
* @fn       bool_t Clock_SetDataBase(clock_db_t *clock_db_ptr)
* @brief    Clock_SetDataBase
* @param    *clock_db_ptr
* @retval   error_f
* @warning  None
* @note     None
* @author   MK
* @date     14-OCT-2023
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Clock_SetDataBase(clock_db_t *clock_db_ptr);

//=============================================================================
//                         \V/ Clock_GetDataBase
//=============================================================================
/*!
* @fn       bool_t Clock_GetDataBase(clock_db_t *clock_db_ptr)
* @brief    Clock_GetDataBase
* @param    *clock_db_ptr
* @retval   error_f
* @warning  None
* @note     None
* @author   MK
* @date     14-OCT-2023
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Clock_GetDataBase(clock_db_t *clock_db_ptr);

//=============================================================================
//                         \V/ Clock_ValidateDate
//=============================================================================
/*!
* @fn       bool_t Clock_ValidateDate(clock_db_t *clock_db_ptr)
* @brief    Clock_ValidateDate
* @param    *clock_db_ptr
* @retval   valid_date_f
* @warning  None
* @note     None
* @author   MK
* @date     14-OCT-2023
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Clock_ValidateDate(clock_db_t *clock_db_ptr);

//=============================================================================
//                         \V/ Clock_ValidateTime
//=============================================================================
/*!
* @fn       bool_t Clock_ValidateTime(clock_db_t *clock_db_ptr)
* @brief    Clock_ValidateTime
* @param    *clock_db_ptr
* @retval   valid_time_f
* @warning  None
* @note     None
* @author   MK
* @date     14-OCT-2023
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Clock_ValidateTime(clock_db_t *clock_db_ptr);

//=============================================================================
//                         \V/ Clock_ChkLeapYear
//=============================================================================
/*!
* @fn       bool_t Clock_ChkLeapYear(uint16_t year)
* @brief    Clock_ChkLeapYear
* @param    year
* @retval   leap_year_f
* @warning  None
* @note     None
* @author   MK
* @date     14-OCT-2023
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Clock_ChkLeapYear(uint16_t year);


/*
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     14-OCT-2013
* @brief    Initial Release
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.1
* @author   MK
* @date     16-OCT-2023
* @brief    Bug fixes in Clock_GetDataBase -> 01-JAN-2000, 00:00
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
#endif // >> End of CLOCK_H_

/*! <h2><center>             (C) VOIDRON CO. 2023             </center></h2> */
/*                        086 079 073 068 082 079 078                        */

