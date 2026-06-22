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
* @file     api_s25fl064l.h
* @version  V1.0.0
* @brief    API S25FL064L
*           ---
*           ---
*           ---
* @author   MK
* @date     18-SEP-2024
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

#ifndef API_S25FL064L_H_
#define API_S25FL064L_H_

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "vdef_types.h"
#include "s25fl064l.h"

#include "hal_s25fl064l_io.h"
#include "hal_spi2_stm32f103rx.h"

#include "api_sys_tick.h"


/**
*==============================================================================
*                          	  \V/ Global DefineS
*==============================================================================
*/

// Blocks Addresses
#define S25FL_BLOCK0_ADDR     (S25FL_BASE_ADDR + (0UL * S25FL_BLOCK_SZ))
#define S25FL_BLOCK1_ADDR     (S25FL_BASE_ADDR + (1UL * S25FL_BLOCK_SZ))
#define S25FL_BLOCK2_ADDR     (S25FL_BASE_ADDR + (2UL * S25FL_BLOCK_SZ))
#define S25FL_BLOCK3_ADDR     (S25FL_BASE_ADDR + (3UL * S25FL_BLOCK_SZ))

// Sectors Addresses
#define S25FL_SECT0_ADDR      (S25FL_BASE_ADDR + (0UL * S25FL_SECT_SZ))
#define S25FL_SECT1_ADDR      (S25FL_BASE_ADDR + (1UL * S25FL_SECT_SZ))
#define S25FL_SECT2_ADDR      (S25FL_BASE_ADDR + (2UL * S25FL_SECT_SZ))
#define S25FL_SECT3_ADDR      (S25FL_BASE_ADDR + (3UL * S25FL_SECT_SZ))

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
extern void S25fl064l_Init (void);
extern bool_t S25FL064L_ChkDevBusy (void);
extern uint32_t S25FL064L_RdDevId(void);

extern void S25FL064L_SectorEraseAddr (uint32_t sec_start_addr);
extern void S25FL064L_BlockEraseAddr (uint32_t block_start_addr);

extern void S25FL064L_SectorWrData (uint32_t start_addr,
									void *data_ptr,
									uint16_t data_sz);

extern void S25FL064L_SectorRdData (uint32_t start_addr,
									const void *data_ptr,
									uint16_t data_sz);

extern void S25FL064L_BlockWrData (uint32_t start_addr,
								   void *data_ptr,
								   uint16_t data_sz);

extern void S25FL064L_BlockRdData (uint32_t start_addr,
								   const void *data_ptr,
								   uint16_t data_sz);




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
#endif // >> End of API_S25FL064L_H_

