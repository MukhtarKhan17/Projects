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
* @file     api_log.c
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

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "api_log.h"




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

// Log ID description lookup table
const uint8_t LOG_ID_DESC_BUF[LOG_ID_CNT][LOG_DESC_SZ + NULL_CHAR_SZ] =
{
    "No Record      ", // 000
	"Power Up       ", // 001
	"Soft Reset     ", // 002
	"Hard Reset     ", // 003
};

static uint16_t log_wr_indx = 0;
static uint16_t log_rd_indx = 0;

/**
*==============================================================================
*                          \V/ Local Function PrototypeS
*==============================================================================
*/
static uint16_t Log_IndxDist (uint16_t wr_indx, uint16_t rd_indx);
static bool_t Log_DataWrite (uint16_t wr_indx, const log_data_t *log_data_ptr);
static bool_t Log_DataRead  (uint16_t rd_indx, log_data_t *log_data_ptr);

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Log_Init (void)
*==============================================================================
* @brief    Log_Init
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     23-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Log_Init (void)
{
	(void)NvMem1_DataRd(MEM1_LOG_WR_INDX_ADDR, &log_wr_indx, MEM1_LOG_WR_INDX_SZ);
	Log_AlignRdIndx();
}// >> End of Log_Init()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t Log_AppendRecord(const log_data_t *log_data_ptr)
*==============================================================================
* @brief    Log_AppendRecord
*           ---
*           ---
*           ---
* @note     None
* @param    *log_data_ptr
* @retval   error_f
* @author   MK
* @date     24-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t Log_AppendRecord(const log_data_t *log_data_ptr)
{
	bool_t error_f = FALSE;

	if((log_wr_indx >= LOG_INDX_MIN) && (log_wr_indx <= LOG_INDX_MAX))
	{
		error_f = Log_DataWrite(log_wr_indx, log_data_ptr);
		Log_UpdateWrIndx();
	}

	return(error_f);
}// >> End of Log_AppendRecord

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t Log_FetchRecord(log_data_t *log_data_ptr)
*==============================================================================
* @brief    bool_t Log_FetchRecord(log_data_t *log_data_ptr)
*           ---
*           ---
*           ---
* @note     None
* @param    *log_data_ptr
* @retval   error_f
* @author   MK
* @date     24-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t Log_FetchRecord(log_data_t *log_data_ptr)
{
	bool_t error_f = FALSE;

	if((log_rd_indx >= LOG_INDX_MIN) && (log_rd_indx <= LOG_INDX_MAX))
	{
		error_f = Log_DataRead(log_rd_indx, log_data_ptr);
	}

	return(error_f);
}// >> End of Log_FetchRecord

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  uint16_t Log_GetRecordSrNo (void)
*==============================================================================
* @brief    uint16_t Log_GetRecordSrNo (void)
*           ---
*           ---
*           ---
* @note     Range: 1 to (LOG_TOT_CAP - 1)
* @param    None
* @retval   record_sr_no
* @author   MK
* @date     24-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
uint16_t Log_GetRecordSrNo (void)
{
	uint16_t record_sr_no = 0;

	record_sr_no = Log_IndxDist(log_wr_indx, log_rd_indx);

	return(record_sr_no);
}// >> End of Log_GetRecordSrNo

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Log_EraseAllRecord (void)
*==============================================================================
* @brief    Log_EraseAllRecord
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     23-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Log_EraseAllRecord (void)
{
	S25FL064L_BlockEraseAddr(LOG_MEM_BASE_ADDR);
}// >> End of Log_EraseAllRecord()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Log_RstWrIndx(void)
*==============================================================================
* @brief    Log_RstWrIndx
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     24-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Log_RstWrIndx(void)
{
	log_wr_indx = LOG_INDX_MIN;
	(void)NvMem1_DataWr(MEM1_LOG_WR_INDX_ADDR, &log_wr_indx, MEM1_LOG_WR_INDX_SZ);
	NvMem1_Save();
}// >> End of Log_RstWrIndx

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Log_UpdateWrIndx(void)
*==============================================================================
* @brief    Log_UpdateWrIndx
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     24-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Log_UpdateWrIndx(void)
{
	uint32_t log_mem_addr = 0;

	log_wr_indx++;
	if(log_wr_indx > LOG_INDX_MAX)
	{
		log_wr_indx = LOG_INDX_MIN;
	}

	(void)NvMem1_DataWr(MEM1_LOG_WR_INDX_ADDR, &log_wr_indx, MEM1_LOG_WR_INDX_SZ);
	NvMem1_Save();

	// Clean up next sector if required
	log_mem_addr = (LOG_MEM_BASE_ADDR + ((uint32_t)log_wr_indx * LOG_DATA_SZ));
	if((log_mem_addr % S25FL_SECT_SZ) == 0) // If next sector start address
	{
		S25FL064L_SectorEraseAddr(log_mem_addr);
	}
}// >> End of Log_UpdateWrIndx

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Log_IncRdIndx(void)
*==============================================================================
* @brief    Log_IncRdIndx
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     24-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Log_IncRdIndx(void)
{
	uint16_t indx_dist = 0;

	indx_dist = Log_IndxDist(log_wr_indx, log_rd_indx);

	if(indx_dist != 1)
	{
		log_rd_indx++;
		if(log_rd_indx > LOG_INDX_MAX)
		{
			log_rd_indx = LOG_INDX_MIN;
		}
	}

}// >> End of Log_IncRdIndx

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Log_DecRdIndx(void)
*==============================================================================
* @brief    Log_DecRdIndx
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     24-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Log_DecRdIndx(void)
{
	uint16_t indx_dist = 0;

	indx_dist = Log_IndxDist(log_wr_indx, log_rd_indx);

	if(indx_dist != LOG_INDX_MAX)
	{
		log_rd_indx--;
		if(log_rd_indx > LOG_INDX_MAX)
		{
			log_rd_indx = LOG_INDX_MAX;
		}
	}
}// >> End of Log_DecRdIndx

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Log_AlignRdIndx(void)
*==============================================================================
* @brief    Log_AlignRdIndx
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     24-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Log_AlignRdIndx(void)
{
	if(log_wr_indx == LOG_INDX_MIN)
	{
		log_rd_indx = LOG_INDX_MAX;
	}
	else
	{
		log_rd_indx = (log_wr_indx - 1U);
	}
}// >> End of Log_AlignRdIndx

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Log_SetRecordSrNo(uint16_t record_num)
*==============================================================================
* @brief    Log_SetRecordSrNo
*           ---
*           ---
*           ---
* @note     None
* @param    record_num
* @retval   None
* @author   MK
* @date     24-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Log_SetRecordSrNo(uint16_t record_num)
{
	log_rd_indx  = (log_wr_indx - record_num);
	log_rd_indx &=  LOG_TOT_CAP_MASK;
}// >> End of Log_SetRecordSrNo

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  uint16_t Log_IndxDist (uint16_t wr_indx, uint16_t rd_indx)
*==============================================================================
* @brief    Log_IndxDist
*           ---
*           ---
*           ---
* @note     None
* @param    wr_indx
* @param    rd_indx
* @retval   indx_dist
* @author   MK
* @date     23-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
uint16_t Log_IndxDist (uint16_t wr_indx, uint16_t rd_indx)
{
	uint16_t indx_dist = 0;

	if(wr_indx >= rd_indx)
	{
		indx_dist = (wr_indx  - rd_indx);
	}
	else
	{
		indx_dist = ((LOG_TOT_CAP + wr_indx) - rd_indx);
	}

	return(indx_dist);

}// >> End of Log_IndxDist()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Log_DataWrite (uint16_t wr_indx, const log_data_t *log_data_ptr)
*==============================================================================
* @brief    Log_DataWrite
*           ---
*           ---
*           ---
* @note     None
* @param    wr_indx
* @param    *log_data_ptr
* @retval   error_f
* @author   MK
* @date     23-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t Log_DataWrite (uint16_t wr_indx, const log_data_t *log_data_ptr)
{
	bool_t error_f = FALSE;
	uint32_t log_mem_addr = 0;
	uint8_t log_mem_buf[LOG_DATA_SZ];
	uint8_t log_mem_chksm = 0;

	if((wr_indx >= LOG_INDX_MIN) && (wr_indx <= LOG_INDX_MAX))
	{
		log_mem_addr = (LOG_MEM_BASE_ADDR + ((uint32_t)wr_indx * LOG_DATA_SZ));

		(void)memset(log_mem_buf, 0, sizeof(log_mem_buf));

		log_mem_buf[0] = log_data_ptr->time_stamp.date;
		log_mem_buf[1] = log_data_ptr->time_stamp.month;
		(void)memcpy(&log_mem_buf[2], &log_data_ptr->time_stamp.year, sizeof(log_data_ptr->time_stamp.year));
		log_mem_buf[4] = log_data_ptr->time_stamp.hour;
		log_mem_buf[5] = log_data_ptr->time_stamp.min;
		log_mem_buf[6] = log_data_ptr->time_stamp.sec;
		log_mem_buf[7] = log_data_ptr->id;
		(void)memcpy(&log_mem_buf[8],  &log_data_ptr->para1, sizeof(log_data_ptr->para1));
		(void)memcpy(&log_mem_buf[12], &log_data_ptr->para2, sizeof(log_data_ptr->para2));
		(void)memcpy(&log_mem_buf[16], log_data_ptr->buffer, sizeof(log_data_ptr->buffer));

		log_mem_chksm = DatIntg_CalChksm8(log_mem_buf, (sizeof(log_mem_buf) - 1));
		log_mem_buf[LOG_DATA_SZ - 1U] = log_mem_chksm;

		S25FL064L_BlockWrData(log_mem_addr, log_mem_buf, sizeof(log_mem_buf));
	}
	else
	{
		error_f = TRUE;
	}

	return(error_f);
}// >> End of Log_DataWrite()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Log_DataRead (uint16_t rd_indx, log_data_t *log_data_ptr)
*==============================================================================
* @brief    Log_DataRead
*           ---
*           ---
*           ---
* @note     None
* @param    rd_indx
* @param    *log_data_ptr
* @retval   error_f
* @author   MK
* @date     23-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t Log_DataRead (uint16_t rd_indx, log_data_t *log_data_ptr)
{
	bool_t error_f = FALSE;
	uint32_t log_mem_addr = 0;
	uint8_t log_mem_buf[LOG_DATA_SZ];
	uint8_t log_mem_chksm = 0;

	if((rd_indx >= LOG_INDX_MIN) && (rd_indx <= LOG_INDX_MAX))
	{
		log_mem_addr = (LOG_MEM_BASE_ADDR + ((uint32_t)rd_indx * LOG_DATA_SZ));

		(void)memset(log_mem_buf, 0, sizeof(log_mem_buf));
		(void)memset(log_data_ptr, 0, sizeof(log_data_t));

		S25FL064L_BlockRdData(log_mem_addr, log_mem_buf, sizeof(log_mem_buf));

		log_mem_chksm = DatIntg_CalChksm8(log_mem_buf, sizeof(log_mem_buf));

		if(log_mem_chksm == 0)
		{
			log_data_ptr->time_stamp.date  = log_mem_buf[0];
			log_data_ptr->time_stamp.month = log_mem_buf[1];
			(void)memcpy(&log_data_ptr->time_stamp.year, &log_mem_buf[2], sizeof(log_data_ptr->time_stamp.year));
			log_data_ptr->time_stamp.hour = log_mem_buf[4];
			log_data_ptr->time_stamp.min  = log_mem_buf[5];
			log_data_ptr->time_stamp.sec  = log_mem_buf[6];
			log_data_ptr->id = log_mem_buf[7];
			(void)memcpy(&log_data_ptr->para1, &log_mem_buf[8], sizeof(log_data_ptr->para1));
			(void)memcpy(&log_data_ptr->para2, &log_mem_buf[12], sizeof(log_data_ptr->para2));
			(void)memcpy(&log_data_ptr->buffer, &log_mem_buf[16], sizeof(log_data_ptr->buffer));
		}
		else
		{
			error_f = TRUE;
		}
	}
	else
	{
		error_f = TRUE;
	}

	return(error_f);
}// >> End of Log_DataRead()


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
