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
* @file     api_nv_mem2.h
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

#ifndef API_NV_MEM2_H_
#define API_NV_MEM2_H_

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "vdef_types.h"
#include "nv_mem2.h"
#include "api_s25fl064l.h"



/**
*==============================================================================
*                          	  \V/ Global DefineS
*==============================================================================
*/
// Flash Page Related
#define NV_MEM2_PRI_MAIN_PAGE_ADDR       (S25FL_SECT0_ADDR)
#define NV_MEM2_SEC_MAIN_PAGE_ADDR       (S25FL_SECT1_ADDR)
#define NV_MEM2_PRI_BCKUP_PAGE_ADDR      (S25FL_SECT2_ADDR)
#define NV_MEM2_SEC_BCKUP_PAGE_ADDR      (S25FL_SECT3_ADDR)

#define NV_MEM2_PAGE_SZ                  (S25FL_SECT_SZ)    // 4KB

//NvMem API Related
#define NV_MEM2_DAT_SIGN                 (0xA2)


#if(NV_MEM_DAT_MAX_SZ > NV_MEM2_PAGE_SZ)
#error "NV_MEM_DAT_MAX_SZ should be less than or equal to NV_MEM2_PAGE_SZ"
#endif

#if((NV_MEM_DAT_MAX_SZ % 2) != 0)
#error "NV_MEM_DAT_MAX_SZ should be multiple of half word or 2 bytes"
#endif

/**
*==============================================================================
*                          	  \V/ Global MacroS
*==============================================================================
*/


/**
*==============================================================================
*                           \V/ Global Data TypeS
*==============================================================================
*/
// >> Declare global user data types here. Example typedef, structure & union.

/**
*==============================================================================
*                            \V/ Global VariableS
*==============================================================================
*/
// >> Declare Global Variables Here.

/**
*==============================================================================
*                        \V/ Global Function PrototypeS
*==============================================================================
*/
extern void NvMem2_Init (void);
extern bool_t NvMem2_DataSignChk(void);

extern bool_t NvMem2_DataRd(nv_mem2_dat_addr_t data_addr,
                            void *op_data_ptr,
                            nv_mem2_dat_sz_t data_sz);

extern bool_t NvMem2_DataWr(nv_mem2_dat_addr_t data_addr,
		                    const void *ip_data_ptr,
		                    nv_mem2_dat_sz_t data_sz);

extern void NvMem2_Save(void);
extern bool_t NvMem2_LoadImage(void);
extern void NvMem2_SetDefault (void);
extern bool_t NvMem2_CreateBackup (void);
extern bool_t NvMem2_RestoreBackup (void);

/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     18-SEP-2024
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
#endif // >> End of API_NV_MEM2_H_

