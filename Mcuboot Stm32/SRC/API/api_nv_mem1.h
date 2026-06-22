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
* @file     api_nv_mem1.h
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

#ifndef API_NV_MEM1_H_
#define API_NV_MEM1_H_

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "vdef_types.h"
#include "hal_flash_stm32f103rx.h"
#include "nv_mem1.h"



/**
*==============================================================================
*                          	  \V/ Global DefineS
*==============================================================================
*/
// Flash Page Related
#define NV_MEM1_PRI_PAGE_ADDR            (FLASH_PAGE_254_ADDR)
#define NV_MEM1_SEC_PAGE_ADDR            (FLASH_PAGE_255_ADDR)
#define NV_MEM1_PAGE_SZ                  (FLASH_PAGE_SIZE)

//NvMem API Related
#define NV_MEM1_DAT_SIGN                    (0xA1)


#if(NV_MEM_DAT_MAX_SZ > NV_MEM1_PAGE_SZ)
#error "NV_MEM_DAT_MAX_SZ should be less than or equal to NV_MEM1_PAGE_SZ"
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
extern void NvMem1_Init (void);

extern bool_t NvMem1_DataRd(nv_mem1_dat_addr_t data_addr,
                            void *op_data_ptr,
                            nv_mem1_dat_sz_t data_sz);

extern bool_t NvMem1_DataWr(nv_mem1_dat_addr_t data_addr,
		                    const void *ip_data_ptr,
		                    nv_mem1_dat_sz_t data_sz);

extern void NvMem1_Save(void);
extern bool_t NvMem1_LoadImage(void);
extern void NvMem1_SetDefault (void);

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
#endif // >> End of API_NV_MEM1_H_

