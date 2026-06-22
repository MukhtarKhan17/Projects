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
* @file     api_log.h
* @version  V1.0.0
* @brief    API LOG
*           ---
*           ---
*           ---
* @author   GC/MK
* @date     24-SEP-2024
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

#ifndef API_LOG_H_
#define API_LOG_H_

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "vdef_types.h"

#include "api_clock.h"
#include "api_sys_tick.h"
#include "api_data_integrity.h"
#include "api_s25fl064l.h"
#include "api_nv_mem1.h"


/**
*==============================================================================
*                          	  \V/ Global DefineS
*==============================================================================
*/
#define LOG_MEM_BASE_ADDR         (S25FL_BLOCK1_ADDR)
#define LOG_MEM_MAX_SZ            (S25FL_BLOCK_SZ)     // 64KB

#define LOG_DATA_SZ               (32U) // In bytes
#define LOG_TOT_CAP               (LOG_MEM_MAX_SZ / LOG_DATA_SZ) // Number of  Logs
#define LOG_INDX_MIN              (0U)
#define LOG_INDX_MAX              (LOG_TOT_CAP - 1U)

#define LOG_ID_CNT                (4U)
#define LOG_DESC_SZ               (15U)
#define LOG_BUFF_SZ               (15U)
#define LOG_TOT_CAP_MASK          (0x07FFU) // For (LOG_TOT_CAP - 1)


// All Logs IDs
#define LOG_ID_PWR_UP             (1U)
#define LOG_ID_SOFT_RST           (2U)
#define LOG_ID_HARD_RST           (3U)


/**
*==============================================================================
*                          	  \V/ Global MacroS
*==============================================================================
*/
// >> 1. Global Macros

/**
*==============================================================================
*                           \V/ Global Data TypeS
*==============================================================================
*/

typedef struct // LOG_DATA_SZ = log_data_t + Checksum = 32B
{
	clock_db_t   time_stamp;           // Date & Time Stamp
	uint8_t      id;                   // Log ID
	uint32_t     para1;                // Log Parameter-1
	uint32_t     para2;                // Log Parameter-2
	uint8_t      buffer[LOG_BUFF_SZ];  // Log Data Buffer
}log_data_t;


/**
*==============================================================================
*                            \V/ Global VariableS
*==============================================================================
*/
extern const uint8_t LOG_ID_DESC_BUF[LOG_ID_CNT][LOG_DESC_SZ + NULL_CHAR_SZ];

/**
*==============================================================================
*                        \V/ Global Function PrototypeS
*==============================================================================
*/
extern void Log_Init(void);

extern bool_t Log_AppendRecord(const log_data_t *log_data_ptr);
extern bool_t Log_FetchRecord(log_data_t *log_data_ptr);
extern uint16_t Log_GetRecordSrNo (void);
extern void Log_SetRecordSrNo(uint16_t record_num);

extern void Log_EraseAllRecord (void);

extern void Log_RstWrIndx(void);
extern void Log_UpdateWrIndx(void);

extern void Log_IncRdIndx(void);
extern void Log_DecRdIndx(void);
extern void Log_AlignRdIndx(void);






/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   GC/MK
* @date     24-SEP-2024
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
#endif // >> End of API_LOG_H_

