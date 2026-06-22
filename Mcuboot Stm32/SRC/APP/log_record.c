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
* @{ <h2><center>            (C) VOIDRON CO. 2024             </center></h2> @}
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
* @file     log_record.c
* @version  V1.0.0
* @brief    Log Record
*           ---
*           ---
*           ---
* @author   MK
* @date     02-OCT-2024
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "log_record.h"


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


/**
*==============================================================================
*                              \V/ Local VariableS
*==============================================================================
*/
// >> Declare Local Variables Here.

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
* @fn  void LogRecord_PwrUp (void)
*==============================================================================
* @brief    LogRecord_PwrUp
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     02-OCT-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void LogRecord_PwrUp (void)
{
	log_data_t temp_log_data_s;
	clock_db_t temp_clock_db_s;

	(void)memset(&temp_log_data_s, 0, sizeof(temp_log_data_s));
	(void)memset(&temp_clock_db_s, 0, sizeof(temp_clock_db_s));

	Clock_GetDataBase(&temp_clock_db_s);
	temp_log_data_s.time_stamp  = temp_clock_db_s;
	temp_log_data_s.id = LOG_ID_PWR_UP;
	temp_log_data_s.para1 = 0;
	temp_log_data_s.para2 = 0;
	(void)memcpy(temp_log_data_s.buffer, "None", strlen("None"));
	(void)Log_AppendRecord(&temp_log_data_s);

}// >> End of LogRecord_PwrUp

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void LogRecord_SoftRst (void)
*==============================================================================
* @brief    LogRecord_SoftRst
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     02-OCT-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void LogRecord_SoftRst (void)
{
	log_data_t temp_log_data_s;
	clock_db_t temp_clock_db_s;

	(void)memset(&temp_log_data_s, 0, sizeof(temp_log_data_s));
	(void)memset(&temp_clock_db_s, 0, sizeof(temp_clock_db_s));

	Clock_GetDataBase(&temp_clock_db_s);
	temp_log_data_s.time_stamp  = temp_clock_db_s;
	temp_log_data_s.id = LOG_ID_SOFT_RST;
	temp_log_data_s.para1 = 0;
	temp_log_data_s.para2 = 0;
	(void)memcpy(temp_log_data_s.buffer, "None", strlen("None"));
	(void)Log_AppendRecord(&temp_log_data_s);

}// >> End of LogRecord_SoftRst

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void LogRecord_HardRst (void)
*==============================================================================
* @brief    LogRecord_HardRst
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     02-OCT-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void LogRecord_HardRst (void)
{
	log_data_t temp_log_data_s;
	clock_db_t temp_clock_db_s;

	(void)memset(&temp_log_data_s, 0, sizeof(temp_log_data_s));
	(void)memset(&temp_clock_db_s, 0, sizeof(temp_clock_db_s));

	Clock_GetDataBase(&temp_clock_db_s);
	temp_log_data_s.time_stamp  = temp_clock_db_s;
	temp_log_data_s.id = LOG_ID_HARD_RST;
	temp_log_data_s.para1 = 0;
	temp_log_data_s.para2 = 0;
	(void)memcpy(temp_log_data_s.buffer, "None", strlen("None"));
	(void)Log_AppendRecord(&temp_log_data_s);

}// >> End of LogRecord_HardRst

/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     07-NOV-2023
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
