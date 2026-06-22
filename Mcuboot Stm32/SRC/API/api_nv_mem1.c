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
* @file     api_nv_mem1.c
* @version  V1.0.0
* @brief    API NV-MEM1
*           ---
*           ---
*           ---
* @author   MK
* @date     27-FEB-2021
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "api_nv_mem1.h"


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
int8_t vTag_NvMem1_Key[] = "VOIDRON";

/**
*==============================================================================
*                          \V/ Local Function PrototypeS
*==============================================================================
*/



/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void NvMem1_Init (void)
*==============================================================================
* @brief    NvMem1_Init
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     27-FEB-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void NvMem1_Init (void)
{
	nv_mem1_base_t nv_mem1_base_s = {0};

	nv_mem1_base_s.pri_page_addr  = NV_MEM1_PRI_PAGE_ADDR;
	nv_mem1_base_s.sec_page_addr  = NV_MEM1_SEC_PAGE_ADDR;
	nv_mem1_base_s.page_sz        = NV_MEM1_PAGE_SZ;
	nv_mem1_base_s.mem_sign       = NV_MEM1_DAT_SIGN;
	nv_mem1_base_s.PageErase      = &Flash_PageErase;
	nv_mem1_base_s.PageWr         = &Flash_PageWrite;
	nv_mem1_base_s.PageRd         = &Flash_PageRead;
	NvMem1_BaseInit(nv_mem1_base_s);

	(void)NvMem1_Enable(vTag_NvMem1_Key);
	(void)NvMem1_LoadImage();

	if(FALSE == NvMem1_DataSignChk())
	{
		NvMem1_Format();
		NvMem1_SetDefault();
		NvMem1_Save();
//TODO:		Flash_EnableRdProtect();
	}

} // End of NvMem1_Init()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void NvMem1_SetDefault (void)
*==============================================================================
* @brief    NvMem1_SetDefault
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     27-FEB-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void NvMem1_SetDefault (void)
{
//	#define DFL_WIFI_AP_SSID_STR      "ABCv1-01"
//	#define DFL_WIFI_AP_PSWD_STR      "12345678"
//
//	(void)NvMem1_DataWr(MEM1_AP_SSID_ADDR, DFL_WIFI_AP_SSID_STR, MEM1_AP_SSID_SZ);
//	(void)NvMem1_DataWr(MEM1_AP_PSWD_ADDR, DFL_WIFI_AP_PSWD_STR, MEM1_AP_PSWD_SZ);

} // End of NvMem1_SetDefault()


/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     21-FEB-2021
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
