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
* @file     api_data_conv.h
* @version  V1.0.0
* @brief    API Data Conversion
*           ---
*           ---
*           ---
* @author   MK
* @date     29-APR-2021
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

#ifndef API_DATA_CONV_H_
#define API_DATA_CONV_H_

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "vdef_types.h"
#include "data_conv.h"



/**
*==============================================================================
*                          	  \V/ Global DefineS
*==============================================================================
*/


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
extern void DataConv_Init (void);

extern void DataConv_AsciiToSevenSeg (uint8_t *ip_ascii_buff_ptr,
						              uint8_t *op_seven_seg_ptr,
						              uint8_t data_len);

extern void DataConv_LtoA(uint64_t ip_value,
		                  void    *op_buff_ptr,
		                  uint8_t  ascii_digit_cnt,
				          bool_t   pre_fill_zero_en_f,
		                  uint8_t  decimal_places);

extern uint8_t DataConv_RevBits8 (uint8_t in_data);
extern uint8_t DataConv_AsciiToHex8 (uint8_t in_ascii_msd, uint8_t in_ascii_lsd);
extern uint32_t DataConv_LEtoBE32 (uint32_t in_data);
extern uint8_t DataConv_SwapNibble (uint8_t in_data);
extern uint8_t DataConv_UnpackToPackBCD (uint8_t in_bcd_msd, uint8_t in_bcd_lsd);
extern uint8_t DataConv_NibbleToAscii (uint8_t nibble);

/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     29-APR-2021
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
#endif // >> End of API_DATA_CONV_H_

