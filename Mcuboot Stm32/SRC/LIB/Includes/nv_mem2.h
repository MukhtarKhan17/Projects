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
* @file     nv_mem2.h
* @version  V1.0.6
* @brief    API Non-volatile Memory
*           + Memory Write
*           + Memory Read
* @author   MK
* @date     05-JAN-2024
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

#ifndef NV_MEM2_H_
#define NV_MEM2_H_

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "vdef_types.h"
#include "string.h"



/**
*==============================================================================
*                          	  \V/ Global DefineS
*==============================================================================
*/

// >> Can't change.Only for reference
#define NV_MEM2_DAT_MAX_SZ			  (1024U)





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

typedef enum
{
	MEM2_SIGN_SZ         	   = 1,
	MEM2_OPR_MODE_SZ	       = 1,
	MEM2_USER_LEVEL_SZ	       = 1,
	MEM2_ADMIN_PSWD_SZ	       = 2,
	MEM2_LOCAL_PSWD_SZ	       = 2,
	MEM2_TOTAL_ZONE_SZ         = 1,
	MEM2_ZONE_INDX_SZ          = 1,
	MEM2_BUZZ_CTRL_SZ          = 1,
	MEM2_RESERVE1_SZ           = 23,
	MEM2_ZONE01_NAME_SZ        = 15,
	MEM2_ZONE01_SENS_SZ        = 1,
	MEM2_ZONE01_AUTO_SZ        = 1,
	MEM2_ZONE01_CTRL_SZ        = 1,
	MEM2_ZONE02_NAME_SZ        = 15,
	MEM2_ZONE02_SENS_SZ        = 1,
	MEM2_ZONE02_AUTO_SZ        = 1,
	MEM2_ZONE02_CTRL_SZ        = 1,
	MEM2_ZONE03_NAME_SZ        = 15,
	MEM2_ZONE03_SENS_SZ        = 1,
	MEM2_ZONE03_AUTO_SZ        = 1,
	MEM2_ZONE03_CTRL_SZ        = 1,
	MEM2_ZONE04_NAME_SZ        = 15,
	MEM2_ZONE04_SENS_SZ        = 1,
	MEM2_ZONE04_AUTO_SZ        = 1,
	MEM2_ZONE04_CTRL_SZ        = 1,
	MEM2_ZONE05_NAME_SZ        = 15,
	MEM2_ZONE05_SENS_SZ        = 1,
	MEM2_ZONE05_AUTO_SZ        = 1,
	MEM2_ZONE05_CTRL_SZ        = 1,
	MEM2_ZONE06_NAME_SZ        = 15,
	MEM2_ZONE06_SENS_SZ        = 1,
	MEM2_ZONE06_AUTO_SZ        = 1,
	MEM2_ZONE06_CTRL_SZ        = 1,
	MEM2_ZONE07_NAME_SZ        = 15,
	MEM2_ZONE07_SENS_SZ        = 1,
	MEM2_ZONE07_AUTO_SZ        = 1,
	MEM2_ZONE07_CTRL_SZ        = 1,
	MEM2_ZONE08_NAME_SZ        = 15,
	MEM2_ZONE08_SENS_SZ        = 1,
	MEM2_ZONE08_AUTO_SZ        = 1,
	MEM2_ZONE08_CTRL_SZ        = 1,
	MEM2_ZONE09_NAME_SZ        = 15,
	MEM2_ZONE09_SENS_SZ        = 1,
	MEM2_ZONE09_AUTO_SZ        = 1,
	MEM2_ZONE09_CTRL_SZ        = 1,
	MEM2_ZONE10_NAME_SZ        = 15,
	MEM2_ZONE10_SENS_SZ        = 1,
	MEM2_ZONE10_AUTO_SZ        = 1,
	MEM2_ZONE10_CTRL_SZ        = 1,
	MEM2_ZONE11_NAME_SZ        = 15,
	MEM2_ZONE11_SENS_SZ        = 1,
	MEM2_ZONE11_AUTO_SZ        = 1,
	MEM2_ZONE11_CTRL_SZ        = 1,
	MEM2_ZONE12_NAME_SZ        = 15,
	MEM2_ZONE12_SENS_SZ        = 1,
	MEM2_ZONE12_AUTO_SZ        = 1,
	MEM2_ZONE12_CTRL_SZ        = 1,
	MEM2_ZONE13_NAME_SZ        = 15,
	MEM2_ZONE13_SENS_SZ        = 1,
	MEM2_ZONE13_AUTO_SZ        = 1,
	MEM2_ZONE13_CTRL_SZ        = 1,
	MEM2_ZONE14_NAME_SZ        = 15,
	MEM2_ZONE14_SENS_SZ        = 1,
	MEM2_ZONE14_AUTO_SZ        = 1,
	MEM2_ZONE14_CTRL_SZ        = 1,
	MEM2_ZONE15_NAME_SZ        = 15,
	MEM2_ZONE15_SENS_SZ        = 1,
	MEM2_ZONE15_AUTO_SZ        = 1,
	MEM2_ZONE15_CTRL_SZ        = 1,
	MEM2_ZONE16_NAME_SZ        = 15,
	MEM2_ZONE16_SENS_SZ        = 1,
	MEM2_ZONE16_AUTO_SZ        = 1,
	MEM2_ZONE16_CTRL_SZ        = 1,
	MEM2_ZONE17_NAME_SZ        = 15,
	MEM2_ZONE17_SENS_SZ        = 1,
	MEM2_ZONE17_AUTO_SZ        = 1,
	MEM2_ZONE17_CTRL_SZ        = 1,
	MEM2_ZONE18_NAME_SZ        = 15,
	MEM2_ZONE18_SENS_SZ        = 1,
	MEM2_ZONE18_AUTO_SZ        = 1,
	MEM2_ZONE18_CTRL_SZ        = 1,
	MEM2_ZONE19_NAME_SZ        = 15,
	MEM2_ZONE19_SENS_SZ        = 1,
	MEM2_ZONE19_AUTO_SZ        = 1,
	MEM2_ZONE19_CTRL_SZ        = 1,
	MEM2_ZONE20_NAME_SZ        = 15,
	MEM2_ZONE20_SENS_SZ        = 1,
	MEM2_ZONE20_AUTO_SZ        = 1,
	MEM2_ZONE20_CTRL_SZ        = 1,
	MEM2_ZONE21_NAME_SZ        = 15,
	MEM2_ZONE21_SENS_SZ        = 1,
	MEM2_ZONE21_AUTO_SZ        = 1,
	MEM2_ZONE21_CTRL_SZ        = 1,
	MEM2_ZONE22_NAME_SZ        = 15,
	MEM2_ZONE22_SENS_SZ        = 1,
	MEM2_ZONE22_AUTO_SZ        = 1,
	MEM2_ZONE22_CTRL_SZ        = 1,
	MEM2_ZONE23_NAME_SZ        = 15,
	MEM2_ZONE23_SENS_SZ        = 1,
	MEM2_ZONE23_AUTO_SZ        = 1,
	MEM2_ZONE23_CTRL_SZ        = 1,
	MEM2_ZONE24_NAME_SZ        = 15,
	MEM2_ZONE24_SENS_SZ        = 1,
	MEM2_ZONE24_AUTO_SZ        = 1,
	MEM2_ZONE24_CTRL_SZ        = 1,
	MEM2_CHKSM_SZ        	   = 1,
}nv_mem2_dat_sz_t;

typedef enum
{
	MEM2_SIGN_ADDR            = (0),

	MEM2_OPR_MODE_ADDR        = (MEM2_SIGN_ADDR         + MEM2_SIGN_SZ),
	MEM2_USER_LEVEL_ADDR      = (MEM2_OPR_MODE_ADDR     + MEM2_OPR_MODE_SZ),
	MEM2_ADMIN_PWSD_ADDR      = (MEM2_USER_LEVEL_ADDR   + MEM2_USER_LEVEL_SZ),
	MEM2_LOCAL_PWSD_ADDR      = (MEM2_ADMIN_PWSD_ADDR   + MEM2_ADMIN_PSWD_SZ),
	MEM2_TOTAL_ZONE_ADDR      = (MEM2_LOCAL_PWSD_ADDR   + MEM2_LOCAL_PSWD_SZ),
	MEM2_ZONE_INDX_ADDR       = (MEM2_TOTAL_ZONE_ADDR   + MEM2_TOTAL_ZONE_SZ),
	MEM2_BUZZ_CTRL_ADDR       = (MEM2_TOTAL_ZONE_ADDR   + MEM2_TOTAL_ZONE_SZ),
	MEM2_RESERVE1_ADDR        = (MEM2_BUZZ_CTRL_ADDR    + MEM2_BUZZ_CTRL_SZ),

	MEM2_ZONE01_NAME_ADDR     = (MEM2_RESERVE1_ADDR     + MEM2_RESERVE1_SZ),
	MEM2_ZONE01_SENS_ADDR     = (MEM2_ZONE01_NAME_ADDR  + MEM2_ZONE01_NAME_SZ),
	MEM2_ZONE01_AUTO_ADDR     = (MEM2_ZONE01_SENS_ADDR  + MEM2_ZONE01_SENS_SZ),
	MEM2_ZONE01_CTRL_ADDR     = (MEM2_ZONE01_AUTO_ADDR  + MEM2_ZONE01_AUTO_SZ),

	MEM2_ZONE02_NAME_ADDR     = (MEM2_ZONE01_CTRL_ADDR  + MEM2_ZONE01_CTRL_SZ),
	MEM2_ZONE02_SENS_ADDR     = (MEM2_ZONE02_NAME_ADDR  + MEM2_ZONE01_NAME_SZ),
	MEM2_ZONE02_AUTO_ADDR     = (MEM2_ZONE02_SENS_ADDR  + MEM2_ZONE01_SENS_SZ),
	MEM2_ZONE02_CTRL_ADDR     = (MEM2_ZONE02_AUTO_ADDR  + MEM2_ZONE01_AUTO_SZ),

	MEM2_ZONE03_NAME_ADDR     = (MEM2_ZONE02_CTRL_ADDR  + MEM2_ZONE02_CTRL_SZ),
	MEM2_ZONE03_SENS_ADDR     = (MEM2_ZONE03_NAME_ADDR  + MEM2_ZONE03_NAME_SZ),
	MEM2_ZONE03_AUTO_ADDR     = (MEM2_ZONE03_SENS_ADDR  + MEM2_ZONE03_SENS_SZ),
	MEM2_ZONE03_CTRL_ADDR     = (MEM2_ZONE03_AUTO_ADDR  + MEM2_ZONE03_AUTO_SZ),

	MEM2_ZONE04_NAME_ADDR     = (MEM2_ZONE03_CTRL_ADDR  + MEM2_ZONE03_CTRL_SZ),
	MEM2_ZONE04_SENS_ADDR     = (MEM2_ZONE04_NAME_ADDR  + MEM2_ZONE04_NAME_SZ),
	MEM2_ZONE04_AUTO_ADDR     = (MEM2_ZONE04_SENS_ADDR  + MEM2_ZONE04_SENS_SZ),
	MEM2_ZONE04_CTRL_ADDR     = (MEM2_ZONE04_AUTO_ADDR  + MEM2_ZONE04_AUTO_SZ),

	MEM2_ZONE05_NAME_ADDR     = (MEM2_ZONE04_CTRL_ADDR  + MEM2_ZONE04_CTRL_SZ),
	MEM2_ZONE05_SENS_ADDR     = (MEM2_ZONE05_NAME_ADDR  + MEM2_ZONE05_NAME_SZ),
	MEM2_ZONE05_AUTO_ADDR     = (MEM2_ZONE05_SENS_ADDR  + MEM2_ZONE05_SENS_SZ),
	MEM2_ZONE05_CTRL_ADDR     = (MEM2_ZONE05_AUTO_ADDR  + MEM2_ZONE05_AUTO_SZ),

	MEM2_ZONE06_NAME_ADDR     = (MEM2_ZONE05_CTRL_ADDR  + MEM2_ZONE05_CTRL_SZ),
	MEM2_ZONE06_SENS_ADDR     = (MEM2_ZONE06_NAME_ADDR  + MEM2_ZONE06_NAME_SZ),
	MEM2_ZONE06_AUTO_ADDR     = (MEM2_ZONE06_SENS_ADDR  + MEM2_ZONE06_SENS_SZ),
	MEM2_ZONE06_CTRL_ADDR     = (MEM2_ZONE06_AUTO_ADDR  + MEM2_ZONE06_AUTO_SZ),

	MEM2_ZONE07_NAME_ADDR     = (MEM2_ZONE06_CTRL_ADDR  + MEM2_ZONE06_CTRL_SZ),
	MEM2_ZONE07_SENS_ADDR     = (MEM2_ZONE07_NAME_ADDR  + MEM2_ZONE07_NAME_SZ),
	MEM2_ZONE07_AUTO_ADDR     = (MEM2_ZONE07_SENS_ADDR  + MEM2_ZONE07_SENS_SZ),
	MEM2_ZONE07_CTRL_ADDR     = (MEM2_ZONE07_AUTO_ADDR  + MEM2_ZONE07_AUTO_SZ),

	MEM2_ZONE08_NAME_ADDR     = (MEM2_ZONE07_CTRL_ADDR  + MEM2_ZONE07_CTRL_SZ),
	MEM2_ZONE08_SENS_ADDR     = (MEM2_ZONE08_NAME_ADDR  + MEM2_ZONE08_NAME_SZ),
	MEM2_ZONE08_AUTO_ADDR     = (MEM2_ZONE08_SENS_ADDR  + MEM2_ZONE08_SENS_SZ),
	MEM2_ZONE08_CTRL_ADDR     = (MEM2_ZONE08_AUTO_ADDR  + MEM2_ZONE08_AUTO_SZ),

	MEM2_ZONE09_NAME_ADDR     = (MEM2_ZONE08_CTRL_ADDR  + MEM2_ZONE08_CTRL_SZ),
	MEM2_ZONE09_SENS_ADDR     = (MEM2_ZONE09_NAME_ADDR  + MEM2_ZONE09_NAME_SZ),
	MEM2_ZONE09_AUTO_ADDR     = (MEM2_ZONE09_SENS_ADDR  + MEM2_ZONE09_SENS_SZ),
	MEM2_ZONE09_CTRL_ADDR     = (MEM2_ZONE09_AUTO_ADDR  + MEM2_ZONE09_AUTO_SZ),

	MEM2_ZONE10_NAME_ADDR     = (MEM2_ZONE09_CTRL_ADDR  + MEM2_ZONE09_CTRL_SZ),
	MEM2_ZONE10_SENS_ADDR     = (MEM2_ZONE10_NAME_ADDR  + MEM2_ZONE10_NAME_SZ),
	MEM2_ZONE10_AUTO_ADDR     = (MEM2_ZONE10_SENS_ADDR  + MEM2_ZONE10_SENS_SZ),
	MEM2_ZONE10_CTRL_ADDR     = (MEM2_ZONE10_AUTO_ADDR  + MEM2_ZONE10_AUTO_SZ),

	MEM2_ZONE11_NAME_ADDR     = (MEM2_ZONE10_CTRL_ADDR  + MEM2_ZONE10_CTRL_SZ),
	MEM2_ZONE11_SENS_ADDR     = (MEM2_ZONE11_NAME_ADDR  + MEM2_ZONE11_NAME_SZ),
	MEM2_ZONE11_AUTO_ADDR     = (MEM2_ZONE11_SENS_ADDR  + MEM2_ZONE11_SENS_SZ),
	MEM2_ZONE11_CTRL_ADDR     = (MEM2_ZONE11_AUTO_ADDR  + MEM2_ZONE11_AUTO_SZ),

	MEM2_ZONE12_NAME_ADDR     = (MEM2_ZONE11_CTRL_ADDR  + MEM2_ZONE11_CTRL_SZ),
	MEM2_ZONE12_SENS_ADDR     = (MEM2_ZONE12_NAME_ADDR  + MEM2_ZONE12_NAME_SZ),
	MEM2_ZONE12_AUTO_ADDR     = (MEM2_ZONE12_SENS_ADDR  + MEM2_ZONE12_SENS_SZ),
	MEM2_ZONE12_CTRL_ADDR     = (MEM2_ZONE12_AUTO_ADDR  + MEM2_ZONE12_AUTO_SZ),

	MEM2_ZONE13_NAME_ADDR     = (MEM2_ZONE12_CTRL_ADDR  + MEM2_ZONE12_CTRL_SZ),
	MEM2_ZONE13_SENS_ADDR     = (MEM2_ZONE13_NAME_ADDR  + MEM2_ZONE13_NAME_SZ),
	MEM2_ZONE13_AUTO_ADDR     = (MEM2_ZONE13_SENS_ADDR  + MEM2_ZONE13_SENS_SZ),
	MEM2_ZONE13_CTRL_ADDR     = (MEM2_ZONE13_AUTO_ADDR  + MEM2_ZONE13_AUTO_SZ),

	MEM2_ZONE14_NAME_ADDR     = (MEM2_ZONE13_CTRL_ADDR  + MEM2_ZONE13_CTRL_SZ),
	MEM2_ZONE14_SENS_ADDR     = (MEM2_ZONE14_NAME_ADDR  + MEM2_ZONE14_NAME_SZ),
	MEM2_ZONE14_AUTO_ADDR     = (MEM2_ZONE14_SENS_ADDR  + MEM2_ZONE14_SENS_SZ),
	MEM2_ZONE14_CTRL_ADDR     = (MEM2_ZONE14_AUTO_ADDR  + MEM2_ZONE14_AUTO_SZ),

	MEM2_ZONE15_NAME_ADDR     = (MEM2_ZONE14_CTRL_ADDR  + MEM2_ZONE14_CTRL_SZ),
	MEM2_ZONE15_SENS_ADDR     = (MEM2_ZONE15_NAME_ADDR  + MEM2_ZONE15_NAME_SZ),
	MEM2_ZONE15_AUTO_ADDR     = (MEM2_ZONE15_SENS_ADDR  + MEM2_ZONE15_SENS_SZ),
	MEM2_ZONE15_CTRL_ADDR     = (MEM2_ZONE15_AUTO_ADDR  + MEM2_ZONE15_AUTO_SZ),

	MEM2_ZONE16_NAME_ADDR     = (MEM2_ZONE15_CTRL_ADDR  + MEM2_ZONE15_CTRL_SZ),
	MEM2_ZONE16_SENS_ADDR     = (MEM2_ZONE16_NAME_ADDR  + MEM2_ZONE16_NAME_SZ),
	MEM2_ZONE16_AUTO_ADDR     = (MEM2_ZONE16_SENS_ADDR  + MEM2_ZONE16_SENS_SZ),
	MEM2_ZONE16_CTRL_ADDR     = (MEM2_ZONE16_AUTO_ADDR  + MEM2_ZONE16_AUTO_SZ),

	MEM2_ZONE17_NAME_ADDR     = (MEM2_ZONE16_CTRL_ADDR  + MEM2_ZONE16_CTRL_SZ),
	MEM2_ZONE17_SENS_ADDR     = (MEM2_ZONE17_NAME_ADDR  + MEM2_ZONE17_NAME_SZ),
	MEM2_ZONE17_AUTO_ADDR     = (MEM2_ZONE17_SENS_ADDR  + MEM2_ZONE17_SENS_SZ),
	MEM2_ZONE17_CTRL_ADDR     = (MEM2_ZONE17_AUTO_ADDR  + MEM2_ZONE17_AUTO_SZ),

	MEM2_ZONE18_NAME_ADDR     = (MEM2_ZONE17_CTRL_ADDR  + MEM2_ZONE17_CTRL_SZ),
	MEM2_ZONE18_SENS_ADDR     = (MEM2_ZONE18_NAME_ADDR  + MEM2_ZONE18_NAME_SZ),
	MEM2_ZONE18_AUTO_ADDR     = (MEM2_ZONE18_SENS_ADDR  + MEM2_ZONE18_SENS_SZ),
	MEM2_ZONE18_CTRL_ADDR     = (MEM2_ZONE18_AUTO_ADDR  + MEM2_ZONE18_AUTO_SZ),

	MEM2_ZONE19_NAME_ADDR     = (MEM2_ZONE18_CTRL_ADDR  + MEM2_ZONE18_CTRL_SZ),
	MEM2_ZONE19_SENS_ADDR     = (MEM2_ZONE19_NAME_ADDR  + MEM2_ZONE19_NAME_SZ),
	MEM2_ZONE19_AUTO_ADDR     = (MEM2_ZONE19_SENS_ADDR  + MEM2_ZONE19_SENS_SZ),
	MEM2_ZONE19_CTRL_ADDR     = (MEM2_ZONE19_AUTO_ADDR  + MEM2_ZONE19_AUTO_SZ),

	MEM2_ZONE20_NAME_ADDR     = (MEM2_ZONE19_CTRL_ADDR  + MEM2_ZONE19_CTRL_SZ),
	MEM2_ZONE20_SENS_ADDR     = (MEM2_ZONE20_NAME_ADDR  + MEM2_ZONE20_NAME_SZ),
	MEM2_ZONE20_AUTO_ADDR     = (MEM2_ZONE20_SENS_ADDR  + MEM2_ZONE20_SENS_SZ),
	MEM2_ZONE20_CTRL_ADDR     = (MEM2_ZONE20_AUTO_ADDR  + MEM2_ZONE20_AUTO_SZ),

	MEM2_ZONE21_NAME_ADDR     = (MEM2_ZONE20_CTRL_ADDR  + MEM2_ZONE20_CTRL_SZ),
	MEM2_ZONE21_SENS_ADDR     = (MEM2_ZONE21_NAME_ADDR  + MEM2_ZONE21_NAME_SZ),
	MEM2_ZONE21_AUTO_ADDR     = (MEM2_ZONE21_SENS_ADDR  + MEM2_ZONE21_SENS_SZ),
	MEM2_ZONE21_CTRL_ADDR     = (MEM2_ZONE21_AUTO_ADDR  + MEM2_ZONE21_AUTO_SZ),

	MEM2_ZONE22_NAME_ADDR     = (MEM2_ZONE21_CTRL_ADDR  + MEM2_ZONE21_CTRL_SZ),
	MEM2_ZONE22_SENS_ADDR     = (MEM2_ZONE22_NAME_ADDR  + MEM2_ZONE22_NAME_SZ),
	MEM2_ZONE22_AUTO_ADDR     = (MEM2_ZONE22_SENS_ADDR  + MEM2_ZONE22_SENS_SZ),
	MEM2_ZONE22_CTRL_ADDR     = (MEM2_ZONE22_AUTO_ADDR  + MEM2_ZONE22_AUTO_SZ),

	MEM2_ZONE23_NAME_ADDR     = (MEM2_ZONE22_CTRL_ADDR  + MEM2_ZONE22_CTRL_SZ),
	MEM2_ZONE23_SENS_ADDR     = (MEM2_ZONE23_NAME_ADDR  + MEM2_ZONE23_NAME_SZ),
	MEM2_ZONE23_AUTO_ADDR     = (MEM2_ZONE23_SENS_ADDR  + MEM2_ZONE23_SENS_SZ),
	MEM2_ZONE23_CTRL_ADDR     = (MEM2_ZONE23_AUTO_ADDR  + MEM2_ZONE23_AUTO_SZ),

	MEM2_ZONE24_NAME_ADDR     = (MEM2_ZONE23_CTRL_ADDR  + MEM2_ZONE23_CTRL_SZ),
	MEM2_ZONE24_SENS_ADDR     = (MEM2_ZONE24_NAME_ADDR  + MEM2_ZONE24_NAME_SZ),
	MEM2_ZONE24_AUTO_ADDR     = (MEM2_ZONE24_SENS_ADDR  + MEM2_ZONE24_SENS_SZ),
	MEM2_ZONE24_CTRL_ADDR     = (MEM2_ZONE24_AUTO_ADDR  + MEM2_ZONE24_AUTO_SZ),

	MEM2_CHKSM_ADDR           = (NV_MEM2_DAT_MAX_SZ   - MEM2_CHKSM_SZ)
}nv_mem2_dat_addr_t;


typedef void (*NvMemPageEraseFptrT) (uint32_t page_addr);

typedef void (*NvMemPageWrFptrT) (uint32_t page_addr,
                                  void *data_ptr,
                                  uint16_t data_sz);

typedef void (*NvMemPageRdFptrT) (uint32_t page_addr,
	   	                          const void *data_ptr,
                                  uint16_t data_sz);

typedef struct
{
	uint32_t                 pri_page_addr;
	uint32_t                 sec_page_addr;
	uint32_t                 page_sz;
	uint8_t                  mem_sign;
	NvMemPageEraseFptrT      PageErase;
	NvMemPageWrFptrT         PageWr;
	NvMemPageRdFptrT         PageRd;
}nv_mem2_base_t;

/**
*==============================================================================
*                            \V/ Global VariableS
*==============================================================================
*/

/**
*==============================================================================
*                        \V/ Global Function PrototypeS
*==============================================================================
*/

//=============================================================================
//                         \V/ NvMem2_Enable
//=============================================================================
/*!
* @fn       bool_t NvMem2_Enable (int8_t *vtag_ptr)
* @brief    This function enables this library.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Enabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     26-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t NvMem2_Enable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ NvMem2_Disable
//=============================================================================
/*!
* @fn       bool_t NvMem2_Disable (int8_t *vtag_ptr)
* @brief    This function disables this library.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Disabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     26-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t NvMem2_Disable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ NvMem2_BaseInit
//=============================================================================
/*!
* @fn       void NvMem2_BaseInit (nv_mem2_base_t set_nv_mem2_base_s)
* @brief    Link functions of Flash or Memory chip
* @param    set_nv_mem2_base_s
* @retval   None
* @warning  if any member of set_nv_mem2_base_s is NULL then routine will not
*           move ahead. Remains in while loop.
* @note     None
* @author   MK
* @date     27-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void NvMem2_BaseInit (nv_mem2_base_t set_nv_mem2_base_s);

//=============================================================================
//                         \V/ NvMem2_DataSignChk
//=============================================================================
/*!
* @fn       bool_t NvMem2_DataSignChk(void)
* @brief    NvMem2_DataSignChk
* @note     None
* @param    None
* @retval   nv_data_sign_f
* @author   MK
* @date     27-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*/
//=============================================================================
extern bool_t NvMem2_DataSignChk(void);

//=============================================================================
//                         \V/ NvMem2_Format
//=============================================================================
/*!
* @fn       void NvMem2_Format(void)
* @brief    NvMem2_Format
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     27-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*/
//=============================================================================
extern void NvMem2_Format(void);

//=============================================================================
//                         \V/ NvMem2_DataWr
//=============================================================================
/*!
* @fn       bool_t NvMem2_DataWr(nv_mem2_dat_addr_t data_addr,
*		                        const void *ip_data_ptr,
*		                        nv_mem2_dat_sz_t data_sz)
* @brief    NvMem2_DataWr
* @note     None
* @param    data_addr
* @param    *ip_data_ptr
* @param    data_sz
* @retval   error_f
* @author   MK
* @date     27-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*/
//=============================================================================
extern bool_t NvMem2_DataWr(nv_mem2_dat_addr_t data_addr,
		                   const void *ip_data_ptr,
		                   nv_mem2_dat_sz_t data_sz);

//=============================================================================
//                         \V/ NvMem2_DataRd
//=============================================================================
/*!
* @fn       bool_t NvMem2_DataRd(nv_mem2_dat_addr_t data_addr,
*		                       void *op_data_ptr,
*		                       nv_mem2_dat_sz_t data_sz)
* @brief    NvMem2_DataRd
* @note     None
* @param    data_addr
* @param    *op_data_ptr
* @param    data_sz
* @retval   error_f
* @author   MK
* @date     10-JUN-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*/
//=============================================================================
extern bool_t NvMem2_DataRd(nv_mem2_dat_addr_t data_addr,
                           void *op_data_ptr,
                           nv_mem2_dat_sz_t data_sz);

//=============================================================================
//                         \V/ NvMem2_Save
//=============================================================================
/*!
* @fn       void NvMem2_Save(void)
* @brief    NvMem2_Save
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     10-JUN-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*/
//=============================================================================
 void NvMem2_Save(void);

 //=============================================================================
 //                         \V/ NvMem2_LoadImage
 //=============================================================================
 /*!
 * @fn       bool_t NvMem2_LoadImage(void)
 * @brief    NvMem2_LoadImage
 * @note     None
 * @param    None
 * @retval   error_f
 * @author   MK
 * @date     10-JUN-2021 // >>Enter Last Change Date
 * @remark   Designed & Developed by Voidron Co.
 */
 //=============================================================================
 extern bool_t NvMem2_LoadImage(void);

/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     27-FEB-2021
* @brief    Initial Release
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.1
* @author   MK
* @date     29-APR-2021
* @brief    Following Function Removed
*           NvMem2_SetFptr
*           ---
*           Following Function Added
*           NvMem2_BaseInit
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.2
* @author   MK
* @date     26-MAY-2021
* @brief    NV_MEM2_DAT_MAX_SZ changed to 256B
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.3
* @author   MK
* @date     26-MAY-2021
* @brief    NV_MEM2_DAT_MAX_SZ changed to 512B
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.4
* @author   MK
* @date     10-JUN-2021
* @brief    - NV_MEM2_DAT_MAX_SZ changed to 256B
*           - NvMem2_Save function added
*           - File variants added
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.5
* @author   MK
* @date     10-JUN-2021
* @brief    - NV_MEM2_DAT_MAX_SZ changed to 256B
*           - NvMem2_Save function added
*           - File variants added
*           - nv_mem2_img_buf added
*           - NvMem2_DataRd modified
*------------------------------------------------------------------------------
* @version  V1.0.6
* @author   MK
* @date     05-JAN-2024
* @brief    NV_MEM2_DAT_MAX_SZ changed to 1024B
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
// >> 086 079 073 068 082 079 078
#endif // >> End of NV_MEM2_H_

