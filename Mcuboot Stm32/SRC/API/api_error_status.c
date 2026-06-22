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
* @file     api_error_status.c
* @version  V1.0.0
* @brief    API ERROR STATUS
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
#include "api_error_status.h"


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
static uint8_t err_stat_array[MAX_ERR_TYPE_CNT];
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
* @fn  void ErrStat_Init (void)
*==============================================================================
* @brief    ErrStat_Init
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     28-FEB-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void ErrStat_Init(void)
{
	//Clear All errors
	(void)memset(err_stat_array, 0, sizeof(err_stat_array));
}// ErrStat_Init

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void ErrStat_SetFlag(error_type_t error_type,
*                           error_bit_num_t error_bit_num)
*==============================================================================
* @brief    ErrStat_SetFlag
*           ---
*           ---
*           ---
* @note     None
* @param    error_type
* @param    error_bit_num
* @retval   error_stat_f
* @author   MK
* @date     28-FEB-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void ErrStat_SetFlag(error_type_t error_type, error_bit_num_t error_bit_num)
{
	if(error_type < MAX_ERR_TYPE_CNT)
	{
		err_stat_array[error_type] |= ((uint8_t)1U << error_bit_num);
	}
}// ErrStat_SetFlag

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t ErrStat_ClrFlag(error_type_t error_type,
*                             error_bit_num_t error_bit_num)
*==============================================================================
* @brief    ErrStat_ClrFlag
*           ---
*           ---
*           ---
* @note     None
* @param    error_type
* @param    error_bit_num
* @retval   error_stat_f
* @author   MK
* @date     28-FEB-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void ErrStat_ClrFlag(error_type_t error_type, error_bit_num_t error_bit_num)
{
	if(error_type < MAX_ERR_TYPE_CNT)
	{
		err_stat_array[error_type] &= ~((uint8_t)1U << error_bit_num);
	}
}// ErrStat_ClrFlag

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t ErrStat_GetFlag(error_type_t error_type,
*                             error_bit_num_t error_bit_num)
*==============================================================================
* @brief    ErrStat_GetFlag
*           ---
*           ---
*           ---
* @note     None
* @param    error_type
* @param    error_bit_num
* @retval   error_stat_f
* @author   MK
* @date     28-FEB-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t ErrStat_GetFlag(error_type_t error_type, error_bit_num_t error_bit_num)
{
	bool_t error_stat_f = FALSE;

	if(error_type < MAX_ERR_TYPE_CNT)
	{
		if((err_stat_array[error_type] & ((uint8_t)1 << error_bit_num)) != 0)
		{
			error_stat_f = TRUE;
		}
	}
	return(error_stat_f);
}//End of ErrStat_GetFlag

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void ErrStat_GetAll(void *data_ptr, uint8_t data_size)
*==============================================================================
* @brief    ErrStat_GetAll
*           ---
*           ---
*           ---
* @note     None
* @param    *data_ptr
* @param    data_size
* @retval   None
* @author   MK
* @date     28-FEB-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void ErrStat_GetAll(void *data_ptr, uint8_t data_size)
{
	if(data_size <= ALL_ERR_STAT_SIZE)
	{
		(void)memcpy(data_ptr, err_stat_array, data_size);
	}
}//End of ErrStat_GetAll

/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     DD-MMM-YYYY
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
