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
* @file     api_nv_mem2.c
* @version  V1.0.0
* @brief    API NV-MEM2
*           ---
*           ---
*           ---
* @author   MK
* @date     18-SEP-2024
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "api_nv_mem2.h"


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
static int8_t vTag_NvMem2_Key[] = "VOIDRON";
static uint8_t nv_mem2_bckup_buf[NV_MEM2_DAT_MAX_SZ];

/**
*==============================================================================
*                          \V/ Local Function PrototypeS
*==============================================================================
*/



/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void NvMem2_Init (void)
*==============================================================================
* @brief    NvMem2_Init
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
void NvMem2_Init (void)
{
	nv_mem2_base_t nv_mem2_base_s = {0};

	nv_mem2_base_s.pri_page_addr  = NV_MEM2_PRI_MAIN_PAGE_ADDR;
	nv_mem2_base_s.sec_page_addr  = NV_MEM2_SEC_MAIN_PAGE_ADDR;
	nv_mem2_base_s.page_sz        = NV_MEM2_PAGE_SZ;
	nv_mem2_base_s.mem_sign       = NV_MEM2_DAT_SIGN;
	nv_mem2_base_s.PageErase      = &S25FL064L_SectorEraseAddr;
	nv_mem2_base_s.PageWr         = &S25FL064L_SectorWrData;
	nv_mem2_base_s.PageRd         = &S25FL064L_SectorRdData;
	NvMem2_BaseInit(nv_mem2_base_s);

	(void)NvMem2_Enable(vTag_NvMem2_Key);
	(void)NvMem2_LoadImage();

	if(FALSE == NvMem2_DataSignChk())
	{
		NvMem2_Format();
		NvMem2_SetDefault();
		NvMem2_Save();
	}

} // End of NvMem2_Init()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void NvMem2_SetDefault (void)
*==============================================================================
* @brief    NvMem2_SetDefault
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
void NvMem2_SetDefault (void)
{
	#define DFL_OPR_MODE_VAL          (0U)
	#define DFL_USER_LEVEL_VAL        (0U)
	#define DFL_ADMIN_PSWD_VAL        (0U)
	#define DFL_LOCAL_PSWD_VAL        (1234U)
	#define DFL_TOTAL_ZONE_VAL        (24U)
	#define DFL_ZONE_INDX_VAL         (0U)
	#define DFL_LOG_WR_INDX_VAL       (0U)
	#define DFL_ZONE_NAME_VAL         "               "
	#define DFL_ZONE_SENS_VAL         (1U)
	#define DFL_ZONE_AUTO_VAL         (0U)
	#define DFL_ZONE_CTRL_VAL         (0U)
	#define DFL_BUZZ_CTRL_VAL         (1U)

	uint8_t  temp_var8  = 0;
	uint16_t temp_var16 = 0;
	uint8_t  temp_buf[15];

	(void)memset(temp_buf, 0, sizeof(temp_buf));

	// Default Operating Mode
	temp_var8 = DFL_OPR_MODE_VAL;
	(void)NvMem2_DataWr(MEM2_OPR_MODE_ADDR, &temp_var8, MEM2_OPR_MODE_SZ);

	// Default Access Level
	temp_var8 = DFL_USER_LEVEL_VAL;
	(void)NvMem2_DataWr(MEM2_USER_LEVEL_ADDR, &temp_var8, MEM2_USER_LEVEL_SZ);

	// Default Admin Passcode
	temp_var16 = DFL_ADMIN_PSWD_VAL;
	(void)NvMem2_DataWr(MEM2_ADMIN_PWSD_ADDR, &temp_var16, MEM2_ADMIN_PSWD_SZ);

	// Default Local Passcode
	temp_var16 = DFL_LOCAL_PSWD_VAL;
	(void)NvMem2_DataWr(MEM2_LOCAL_PWSD_ADDR, &temp_var16, MEM2_LOCAL_PSWD_SZ);

	// Default Total Zone
	temp_var8 = DFL_TOTAL_ZONE_VAL;
	(void)NvMem2_DataWr(MEM2_TOTAL_ZONE_ADDR, &temp_var8, MEM2_TOTAL_ZONE_SZ);

	// Default Zone Index
	temp_var8 = DFL_ZONE_INDX_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE_INDX_ADDR, &temp_var8, MEM2_ZONE_INDX_SZ);

	// Default Buzzer Ctrl
	temp_var8 = DFL_BUZZ_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_BUZZ_CTRL_ADDR, &temp_var8, MEM2_BUZZ_CTRL_SZ);

	//-------------------------------------------------------------------------

	// Default Zone-01 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE01_NAME_ADDR, &temp_buf, MEM2_ZONE01_NAME_SZ);

	// Default Zone-01 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE01_SENS_ADDR, &temp_var8, MEM2_ZONE01_SENS_SZ);

	// Default Zone-01 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE01_AUTO_ADDR, &temp_var8, MEM2_ZONE01_AUTO_SZ);

	// Default Zone-01 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE01_CTRL_ADDR, &temp_var8, MEM2_ZONE01_CTRL_SZ);

	//-------------------------------------------------------------------------

	// Default Zone-02 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE02_NAME_ADDR, &temp_buf, MEM2_ZONE02_NAME_SZ);

	// Default Zone-02 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE02_SENS_ADDR, &temp_var8, MEM2_ZONE02_SENS_SZ);

	// Default Zone-02 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE02_AUTO_ADDR, &temp_var8, MEM2_ZONE02_AUTO_SZ);

	// Default Zone-02 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE02_CTRL_ADDR, &temp_var8, MEM2_ZONE02_CTRL_SZ);

	//-------------------------------------------------------------------------

	// Default Zone-03 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE03_NAME_ADDR, &temp_buf, MEM2_ZONE03_NAME_SZ);

	// Default Zone-03 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE03_SENS_ADDR, &temp_var8, MEM2_ZONE03_SENS_SZ);

	// Default Zone-03 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE03_AUTO_ADDR, &temp_var8, MEM2_ZONE03_AUTO_SZ);

	// Default Zone-03 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE03_CTRL_ADDR, &temp_var8, MEM2_ZONE03_CTRL_SZ);

	//-------------------------------------------------------------------------

	// Default Zone-04 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE04_NAME_ADDR, &temp_buf, MEM2_ZONE04_NAME_SZ);

	// Default Zone-04 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE04_SENS_ADDR, &temp_var8, MEM2_ZONE04_SENS_SZ);

	// Default Zone-04 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE04_AUTO_ADDR, &temp_var8, MEM2_ZONE04_AUTO_SZ);

	// Default Zone-04 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE04_CTRL_ADDR, &temp_var8, MEM2_ZONE04_CTRL_SZ);

	//-------------------------------------------------------------------------

	// Default Zone-05 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE05_NAME_ADDR, &temp_buf, MEM2_ZONE05_NAME_SZ);

	// Default Zone-05 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE05_SENS_ADDR, &temp_var8, MEM2_ZONE05_SENS_SZ);

	// Default Zone-05 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE05_AUTO_ADDR, &temp_var8, MEM2_ZONE05_AUTO_SZ);

	// Default Zone-05 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE05_CTRL_ADDR, &temp_var8, MEM2_ZONE05_CTRL_SZ);

	//-------------------------------------------------------------------------

	// Default Zone-06 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE06_NAME_ADDR, &temp_buf, MEM2_ZONE06_NAME_SZ);

	// Default Zone-06 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE06_SENS_ADDR, &temp_var8, MEM2_ZONE06_SENS_SZ);

	// Default Zone-06 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE06_AUTO_ADDR, &temp_var8, MEM2_ZONE06_AUTO_SZ);

	// Default Zone-06 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE06_CTRL_ADDR, &temp_var8, MEM2_ZONE06_CTRL_SZ);

	//-------------------------------------------------------------------------

	// Default Zone-07 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE07_NAME_ADDR, &temp_buf, MEM2_ZONE07_NAME_SZ);

	// Default Zone-07 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE07_SENS_ADDR, &temp_var8, MEM2_ZONE07_SENS_SZ);

	// Default Zone-07 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE07_AUTO_ADDR, &temp_var8, MEM2_ZONE07_AUTO_SZ);

	// Default Zone-07 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE07_CTRL_ADDR, &temp_var8, MEM2_ZONE07_CTRL_SZ);

	//-------------------------------------------------------------------------

	// Default Zone-08 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE08_NAME_ADDR, &temp_buf, MEM2_ZONE08_NAME_SZ);

	// Default Zone-08 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE08_SENS_ADDR, &temp_var8, MEM2_ZONE08_SENS_SZ);

	// Default Zone-08 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE08_AUTO_ADDR, &temp_var8, MEM2_ZONE08_AUTO_SZ);

	// Default Zone-08 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE08_CTRL_ADDR, &temp_var8, MEM2_ZONE08_CTRL_SZ);

	//-------------------------------------------------------------------------

	// Default Zone-09 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE09_NAME_ADDR, &temp_buf, MEM2_ZONE09_NAME_SZ);

	// Default Zone-09 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE09_SENS_ADDR, &temp_var8, MEM2_ZONE09_SENS_SZ);

	// Default Zone-09 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE09_AUTO_ADDR, &temp_var8, MEM2_ZONE09_AUTO_SZ);

	// Default Zone-09 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE09_CTRL_ADDR, &temp_var8, MEM2_ZONE09_CTRL_SZ);


	//-------------------------------------------------------------------------

	// Default Zone-10 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE10_NAME_ADDR, &temp_buf, MEM2_ZONE10_NAME_SZ);

	// Default Zone-10 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE10_SENS_ADDR, &temp_var8, MEM2_ZONE10_SENS_SZ);

	// Default Zone-10 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE10_AUTO_ADDR, &temp_var8, MEM2_ZONE10_AUTO_SZ);

	// Default Zone-10 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE10_CTRL_ADDR, &temp_var8, MEM2_ZONE10_CTRL_SZ);


	//-------------------------------------------------------------------------

	// Default Zone-11 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE11_NAME_ADDR, &temp_buf, MEM2_ZONE11_NAME_SZ);

	// Default Zone-11 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE11_SENS_ADDR, &temp_var8, MEM2_ZONE11_SENS_SZ);

	// Default Zone-11 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE11_AUTO_ADDR, &temp_var8, MEM2_ZONE11_AUTO_SZ);

	// Default Zone-11 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE11_CTRL_ADDR, &temp_var8, MEM2_ZONE11_CTRL_SZ);


	//-------------------------------------------------------------------------

	// Default Zone-12 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE12_NAME_ADDR, &temp_buf, MEM2_ZONE12_NAME_SZ);

	// Default Zone-12 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE12_SENS_ADDR, &temp_var8, MEM2_ZONE12_SENS_SZ);

	// Default Zone-12 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE12_AUTO_ADDR, &temp_var8, MEM2_ZONE12_AUTO_SZ);

	// Default Zone-12 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE12_CTRL_ADDR, &temp_var8, MEM2_ZONE12_CTRL_SZ);

	//-------------------------------------------------------------------------

	// Default Zone-13 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE13_NAME_ADDR, &temp_buf, MEM2_ZONE13_NAME_SZ);

	// Default Zone-13 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE13_SENS_ADDR, &temp_var8, MEM2_ZONE13_SENS_SZ);

	// Default Zone-13 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE13_AUTO_ADDR, &temp_var8, MEM2_ZONE13_AUTO_SZ);

	// Default Zone-13 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE13_CTRL_ADDR, &temp_var8, MEM2_ZONE13_CTRL_SZ);

	//-------------------------------------------------------------------------

	// Default Zone-14 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE14_NAME_ADDR, &temp_buf, MEM2_ZONE14_NAME_SZ);

	// Default Zone-14 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE14_SENS_ADDR, &temp_var8, MEM2_ZONE14_SENS_SZ);

	// Default Zone-14 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE14_AUTO_ADDR, &temp_var8, MEM2_ZONE14_AUTO_SZ);

	// Default Zone-14 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE14_CTRL_ADDR, &temp_var8, MEM2_ZONE14_CTRL_SZ);

	//-------------------------------------------------------------------------

	// Default Zone-15 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE15_NAME_ADDR, &temp_buf, MEM2_ZONE15_NAME_SZ);

	// Default Zone-15 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE15_SENS_ADDR, &temp_var8, MEM2_ZONE15_SENS_SZ);

	// Default Zone-15 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE15_AUTO_ADDR, &temp_var8, MEM2_ZONE15_AUTO_SZ);

	// Default Zone-15 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE15_CTRL_ADDR, &temp_var8, MEM2_ZONE15_CTRL_SZ);

	//-------------------------------------------------------------------------

	// Default Zone-16 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE16_NAME_ADDR, &temp_buf, MEM2_ZONE16_NAME_SZ);

	// Default Zone-16 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE16_SENS_ADDR, &temp_var8, MEM2_ZONE16_SENS_SZ);

	// Default Zone-16 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE16_AUTO_ADDR, &temp_var8, MEM2_ZONE16_AUTO_SZ);

	// Default Zone-16 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE16_CTRL_ADDR, &temp_var8, MEM2_ZONE16_CTRL_SZ);

	//-------------------------------------------------------------------------

	// Default Zone-17 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE17_NAME_ADDR, &temp_buf, MEM2_ZONE17_NAME_SZ);

	// Default Zone-17 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE17_SENS_ADDR, &temp_var8, MEM2_ZONE17_SENS_SZ);

	// Default Zone-17 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE17_AUTO_ADDR, &temp_var8, MEM2_ZONE17_AUTO_SZ);

	// Default Zone-17 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE17_CTRL_ADDR, &temp_var8, MEM2_ZONE17_CTRL_SZ);

	//-------------------------------------------------------------------------

	// Default Zone-18 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE18_NAME_ADDR, &temp_buf, MEM2_ZONE18_NAME_SZ);

	// Default Zone-18 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE18_SENS_ADDR, &temp_var8, MEM2_ZONE18_SENS_SZ);

	// Default Zone-18 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE18_AUTO_ADDR, &temp_var8, MEM2_ZONE18_AUTO_SZ);

	// Default Zone-18 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE18_CTRL_ADDR, &temp_var8, MEM2_ZONE18_CTRL_SZ);

	//-------------------------------------------------------------------------

	// Default Zone-19 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE19_NAME_ADDR, &temp_buf, MEM2_ZONE19_NAME_SZ);

	// Default Zone-19 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE19_SENS_ADDR, &temp_var8, MEM2_ZONE19_SENS_SZ);

	// Default Zone-19 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE19_AUTO_ADDR, &temp_var8, MEM2_ZONE19_AUTO_SZ);

	// Default Zone-19 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE19_CTRL_ADDR, &temp_var8, MEM2_ZONE19_CTRL_SZ);

	//-------------------------------------------------------------------------

	// Default Zone-20 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE20_NAME_ADDR, &temp_buf, MEM2_ZONE20_NAME_SZ);

	// Default Zone-20 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE20_SENS_ADDR, &temp_var8, MEM2_ZONE20_SENS_SZ);

	// Default Zone-20 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE20_AUTO_ADDR, &temp_var8, MEM2_ZONE20_AUTO_SZ);

	// Default Zone-20 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE20_CTRL_ADDR, &temp_var8, MEM2_ZONE20_CTRL_SZ);

	//-------------------------------------------------------------------------

	// Default Zone-21 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE21_NAME_ADDR, &temp_buf, MEM2_ZONE21_NAME_SZ);

	// Default Zone-21 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE21_SENS_ADDR, &temp_var8, MEM2_ZONE21_SENS_SZ);

	// Default Zone-21 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE21_AUTO_ADDR, &temp_var8, MEM2_ZONE21_AUTO_SZ);

	// Default Zone-21 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE21_CTRL_ADDR, &temp_var8, MEM2_ZONE21_CTRL_SZ);


	//-------------------------------------------------------------------------

	// Default Zone-22 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE22_NAME_ADDR, &temp_buf, MEM2_ZONE22_NAME_SZ);

	// Default Zone-22 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE22_SENS_ADDR, &temp_var8, MEM2_ZONE22_SENS_SZ);

	// Default Zone-22 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE22_AUTO_ADDR, &temp_var8, MEM2_ZONE22_AUTO_SZ);

	// Default Zone-22 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE22_CTRL_ADDR, &temp_var8, MEM2_ZONE22_CTRL_SZ);


	//-------------------------------------------------------------------------

	// Default Zone-23 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE23_NAME_ADDR, &temp_buf, MEM2_ZONE23_NAME_SZ);

	// Default Zone-23 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE23_SENS_ADDR, &temp_var8, MEM2_ZONE23_SENS_SZ);

	// Default Zone-23 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE23_AUTO_ADDR, &temp_var8, MEM2_ZONE23_AUTO_SZ);

	// Default Zone-23 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE23_CTRL_ADDR, &temp_var8, MEM2_ZONE23_CTRL_SZ);


	//-------------------------------------------------------------------------

	// Default Zone-24 Name
	(void)memcpy(temp_buf, DFL_ZONE_NAME_VAL, sizeof(temp_buf));
	(void)NvMem2_DataWr(MEM2_ZONE24_NAME_ADDR, &temp_buf, MEM2_ZONE24_NAME_SZ);

	// Default Zone-24 Type
	temp_var8 = DFL_ZONE_SENS_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE24_SENS_ADDR, &temp_var8, MEM2_ZONE24_SENS_SZ);

	// Default Zone-24 Auto
	temp_var8 = DFL_ZONE_AUTO_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE24_AUTO_ADDR, &temp_var8, MEM2_ZONE24_AUTO_SZ);

	// Default Zone-24 Ctrl
	temp_var8 = DFL_ZONE_CTRL_VAL;
	(void)NvMem2_DataWr(MEM2_ZONE24_CTRL_ADDR, &temp_var8, MEM2_ZONE24_CTRL_SZ);

} // End of NvMem2_SetDefault()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t NvMem2_CreateBackup (void)
*==============================================================================
* @brief    NvMem2_CreateBackup
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   error_f
* @author   MK
* @date     13-OCT-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t NvMem2_CreateBackup (void)
{
	bool_t error_f = FALSE;
	uint16_t i = 0;

	(void)memset(nv_mem2_bckup_buf, 0, sizeof(nv_mem2_bckup_buf));

	// Restore primary page backup
	S25FL064L_SectorEraseAddr(NV_MEM2_PRI_BCKUP_PAGE_ADDR);
	S25FL064L_SectorRdData(NV_MEM2_PRI_BCKUP_PAGE_ADDR, &nv_mem2_bckup_buf, sizeof(nv_mem2_bckup_buf));
	for(i = 0; i < sizeof(nv_mem2_bckup_buf); i++)
	{
		if(nv_mem2_bckup_buf[i] != 0xFF)
		{
			error_f |= TRUE;
		}
	}
	S25FL064L_SectorRdData(NV_MEM2_PRI_MAIN_PAGE_ADDR,  &nv_mem2_bckup_buf, sizeof(nv_mem2_bckup_buf));
	S25FL064L_SectorWrData(NV_MEM2_PRI_BCKUP_PAGE_ADDR, &nv_mem2_bckup_buf, sizeof(nv_mem2_bckup_buf));
	S25FL064L_SectorRdData(NV_MEM2_PRI_BCKUP_PAGE_ADDR, &nv_mem2_bckup_buf, sizeof(nv_mem2_bckup_buf));

	// Restore secondary page backup
	S25FL064L_SectorEraseAddr(NV_MEM2_SEC_BCKUP_PAGE_ADDR);
	S25FL064L_SectorRdData(NV_MEM2_SEC_BCKUP_PAGE_ADDR, &nv_mem2_bckup_buf, sizeof(nv_mem2_bckup_buf));
	for(i = 0; i < sizeof(nv_mem2_bckup_buf); i++)
	{
		if(nv_mem2_bckup_buf[i] != 0xFF)
		{
			error_f |= TRUE;
		}
	}
	S25FL064L_SectorRdData(NV_MEM2_SEC_MAIN_PAGE_ADDR,  &nv_mem2_bckup_buf, sizeof(nv_mem2_bckup_buf));
	S25FL064L_SectorWrData(NV_MEM2_SEC_BCKUP_PAGE_ADDR, &nv_mem2_bckup_buf, sizeof(nv_mem2_bckup_buf));
	S25FL064L_SectorRdData(NV_MEM2_SEC_BCKUP_PAGE_ADDR, &nv_mem2_bckup_buf, sizeof(nv_mem2_bckup_buf));

	return(error_f);
}// End of NvMem2_CreateBackup()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t NvMem2_RestoreBackup (void)
*==============================================================================
* @brief    NvMem2_RestoreBackup
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   error_f
* @author   MK
* @date     13-OCT-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t NvMem2_RestoreBackup (void)
{
	bool_t error_f = FALSE;
	uint16_t i = 0;

	(void)memset(nv_mem2_bckup_buf, 0, sizeof(nv_mem2_bckup_buf));

	// Restore primary page backup
	S25FL064L_SectorEraseAddr(NV_MEM2_PRI_MAIN_PAGE_ADDR);
	S25FL064L_SectorRdData(NV_MEM2_PRI_MAIN_PAGE_ADDR, &nv_mem2_bckup_buf, sizeof(nv_mem2_bckup_buf));
	for(i = 0; i < sizeof(nv_mem2_bckup_buf); i++)
	{
		if(nv_mem2_bckup_buf[i] != 0xFF)
		{
			error_f |= TRUE;
		}
	}
	S25FL064L_SectorRdData(NV_MEM2_PRI_BCKUP_PAGE_ADDR,&nv_mem2_bckup_buf, sizeof(nv_mem2_bckup_buf));
	S25FL064L_SectorWrData(NV_MEM2_PRI_MAIN_PAGE_ADDR, &nv_mem2_bckup_buf, sizeof(nv_mem2_bckup_buf));
	S25FL064L_SectorRdData(NV_MEM2_PRI_MAIN_PAGE_ADDR, &nv_mem2_bckup_buf, sizeof(nv_mem2_bckup_buf));

	// Restore secondary page backup
	S25FL064L_SectorEraseAddr(NV_MEM2_SEC_MAIN_PAGE_ADDR);
	S25FL064L_SectorRdData(NV_MEM2_SEC_MAIN_PAGE_ADDR, &nv_mem2_bckup_buf, sizeof(nv_mem2_bckup_buf));
	for(i = 0; i < sizeof(nv_mem2_bckup_buf); i++)
	{
		if(nv_mem2_bckup_buf[i] != 0xFF)
		{
			error_f |= TRUE;
		}
	}
	S25FL064L_SectorRdData(NV_MEM2_SEC_BCKUP_PAGE_ADDR,&nv_mem2_bckup_buf, sizeof(nv_mem2_bckup_buf));
	S25FL064L_SectorWrData(NV_MEM2_SEC_MAIN_PAGE_ADDR, &nv_mem2_bckup_buf, sizeof(nv_mem2_bckup_buf));
	S25FL064L_SectorRdData(NV_MEM2_SEC_MAIN_PAGE_ADDR, &nv_mem2_bckup_buf, sizeof(nv_mem2_bckup_buf));

	return(error_f);

}// End of NvMem2_RestoreBackup()


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
