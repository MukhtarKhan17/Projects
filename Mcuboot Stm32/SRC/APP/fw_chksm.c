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
* @file     fw_chksm.c
* @version  V1.0.0
* @brief    Firmware Checksum Routines
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
#include "fw_chksm.h"


/**
*==============================================================================
*                          	   \V/ Local DefineS
*==============================================================================
*/
#define MEM_CHKSM_SECTION		 __attribute__((section(".fw_chksm_sec")))


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
//This variables are linked with linker file
extern uint32_t _FW_START_ADDR;
extern uint32_t _FW_END_ADDR;

uint32_t fw_start_address = (uint32_t)(&_FW_START_ADDR);
uint32_t fw_end_address   = (uint32_t)(&_FW_END_ADDR);


//--> Firmware checksum should match with this value
MEM_CHKSM_SECTION const uint16_t FW_CHKSM_DEF_VAL =  56219;

static uint16_t calc_fw_chksm = 0;
static bool_t fw_chksm_err_f = FALSE;
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
* @fn  void FwChksm_Init (void)
*==============================================================================
* @brief    FwChksm_Init
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
void FwChksm_Init (void)
{
	uint16_t fw_block_size = fw_end_address - fw_start_address;

	uint8_t *fw_start_ptr = (uint8_t *)fw_start_address;

	calc_fw_chksm = DatIntg_CalChksm16(fw_start_ptr, fw_block_size);

	if(memcmp(&FW_CHKSM_DEF_VAL , &calc_fw_chksm, sizeof(calc_fw_chksm)) != 0)
    {
		fw_chksm_err_f = TRUE;
		ErrStat_SetFlag(SYSTEM_ERRS, FW_CHKSM_ERR);
    }
}// >> End of FwChksm_Init

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  uint16_t FwChksm_GetCalcChksm (void)
*==============================================================================
* @brief    FwChksm_GetCalcChksm
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   calc_fw_chksm
* @author   MK
* @date     28-FEB-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
uint16_t FwChksm_GetCalcChksm (void)
{
	return(calc_fw_chksm);
}// >> End of FwChksm_GetCalcChksm

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t FwChksm_GetErrFlag(void)
*==============================================================================
* @brief    FwChksm_GetErrFlag
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   fw_chksm_err_f
* @author   MK
* @date     28-FEB-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t FwChksm_GetErrFlag(void)
{
	return(fw_chksm_err_f);
}// End of FwChksm_GetErrFlag



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
