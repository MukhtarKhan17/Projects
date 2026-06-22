/*
*##############################################################################
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
*##############################################################################
*/
//=============================================================================
/*!
* @file      data_conv.h
* @brief     This file contains various general purpose data conversion routines
* @version   V1.0.0
* @author    MK
* @date      30-OCT-2019
* @remark    Designed & Developed by VOIDRON CO.
* @attention
*
* THIS CONTENT IS DESIGNED AND  DEVELOPED BY VOIDRON CO. UNATUHORISED  USED  IS
* PROHIBITED. CONTENT  OF  THIS  FILE  MAY  BE  UNPUBLISHED  OR   CONFIDENTIAL.
* SELLING  OR DISTRIBUTION  WILL  VOID  THE  LICENSE  AND  AGREEMENT  WITH  US.
* DOING  SO MAY LEAD TO  TAKE LEGAL  ACTION BY US  WHICH MAY RESULT IN PENALISE
* OFFENCE CHARGES ON YOU. DON'T  TRY TO MODIFY THE CONTENT OF THIS FILE, IT MAY
* GIVE  UNWANTED  RESULTS. IF  YOU  FIND  ANY TROUBLE  OR WANT  CHANGES  PLEASE
* CONTACT US.
*
* Email: contact@voidron.com
*
* <h2><center>             (C) VOIDRON CO. 2019-20.             </center></h2>
*/
//=============================================================================


#ifndef DATA_CONV_H_
#define DATA_CONV_H_

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

//#############################################################################
//                             \V/ Include SectioN
//#############################################################################

#include "vdef_types.h"
#include "string.h"

//#############################################################################
//                            \V/ Global DefineS
//#############################################################################



//#############################################################################
//                            \V/ Global MacroS
//#############################################################################



//#############################################################################
//                           \V/ Global Data TypeS
//#############################################################################



//#############################################################################
//                            \V/ Global VariableS
//#############################################################################




//#############################################################################
//                        \V/ Global Function PrototypeS
//#############################################################################

//=============================================================================
//                         \V/ DataConv_Enable
//=============================================================================
/*!
* @fn       bool_t DataConv_Enable (int8_t *vtag_ptr)
* @brief    This function Lock lib functions.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Locked successfully)
* @warning  All other functions won't work properly without unlocking.
* @note     Correct vTag require to pass.
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t DataConv_Enable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ DataConv_Disable
//=============================================================================
/*!
* @fn       bool_t DataConv_Disable (int8_t *vtag_ptr)
* @brief    This function unlock lib functions.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if unlocked successfully)
* @warning  All other functions won't work properly without unlocking.
* @note     Correct vTag require to pass.
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t DataConv_Disable (int8_t *vtag_ptr);


//=============================================================================
//                         \V/ DataConv_AsciiToSevenSeg
//=============================================================================
/*!
* @fn       void DataConv_AsciiToSevenSeg (uint8_t *ip_ascii_buff_ptr,
*						                   uint8_t *op_seven_seg_ptr,
*						                   uint8_t data_len)
* @brief    This function converts ASCII to Seven Segment Display Data.
* @param    ip_ascii_buff_ptr : Pointer to input buffer
* @param    op_seven_seg_ptr : Pointer to output buffer
* @param    data_len : Total length of data to be converted.
* @warning  Output buffer size >= Input buffer size
* @note     None
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void DataConv_AsciiToSevenSeg (uint8_t *ip_ascii_buff_ptr,
						              uint8_t *op_seven_seg_ptr,
						              uint8_t data_len);

//=============================================================================
//                         \V/ DataConv_LtoA
//=============================================================================
/*!
* @fn       void DataConv_LtoA (uint64_t ip_value,
*		           			    void *op_buff_ptr,
*		                        uint8_t  ascii_digit_cnt,
*				                bool_t pre_fill_zero_en_f,
*		                        uint8_t decimal_places)
* @brief    This function converts Long value to ASCII
* @param    ip_value : Input Long Value
* @param    op_buff_ptr : Pointer to output buffer
* @param    ascii_digit_cnt : Total length of ASCII Digit to be converted.
* @param    pre_fill_zero_en_f : If TRUE Pre-Fills ASCII '0' else fills 0x00
* @param    decimal_places : Position Dot
* @warning  ASCII buffer must have sufficient space e.g.,32-bit requires
*           10 ASCII digit space. If dot enabled then 11 ASCII digit space requires.
* @note     Long value may go up to 64-bit.
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void DataConv_LtoA(uint64_t ip_value,
		                  void    *op_buff_ptr,
		                  uint8_t  ascii_digit_cnt,
				          bool_t   pre_fill_zero_en_f,
		                  uint8_t  decimal_places);

//=============================================================================
//                         \V/ DataConv_RevBits8
//=============================================================================
/*!
* @fn       uint8_t DataConv_RevBits8 (uint8_t in_data)
* @brief    This function converts ASCII to Seven Segment Display Data.
* @param    in_data : 8-bit Input Data
* @retval   op_data : Returns 8-bit Output Data
* @warning  Data gets truncated if more that 8-bit length passed.
* @note     Output will have mirrored value of input e.g., 0xA1 -> 0x85
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint8_t DataConv_RevBits8 (uint8_t in_data);


//=============================================================================
//                         \V/ DataConv_AsciiToHex8
//=============================================================================
/*!
* @fn       uint8_t DataConv_AsciiToHex8 (uint8_t in_ascii_msd,
*                                         uint8_t in_ascii_lsd)
* @brief    This function converts Two ASCII character to 1 byte Hex value
* @param    in_ascii_msd : 8-bit Input MSD ASCII Character
* @param    in_ascii_lsd : 8-bit Input LSD ASCII Character
* @retval   hex_byte : Returns 8-bit hex value
* @warning  Acceptable ASCII are 0-9 & A-F only
* @note     Output will be zero if ASCII character not in given range.
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint8_t DataConv_AsciiToHex8 (uint8_t in_ascii_msd, uint8_t in_ascii_lsd);

//=============================================================================
//                         \V/ DataConv_LEtoBE32
//=============================================================================
/*!
* @fn       uint32_t DataConv_LEtoBE32 (uint32_t in_data)
* @brief    This function converts little to big endian
* @param    in_data : 32-bit Input Data
* @retval   ret_val : Returns 32-bit Output Data
* @warning  None
* @note     e.g., 0xAABBCCDD -> 0xDDCCBBAA
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint32_t DataConv_LEtoBE32 (uint32_t in_data);

//=============================================================================
//                         \V/ DataConv_SwapNibble
//=============================================================================
/*!
* @fn       uint8_t DataConv_SwapNibble (uint8_t in_data)
* @brief    This function swap the nibble f byte.
* @param    in_data : 8-bit Input Data
* @retval   ret_val : Returns 8-bit Output Data
* @warning  None
* @note     e.g., 0xAB -> 0xBA
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint8_t DataConv_SwapNibble (uint8_t in_data);

//=============================================================================
//                         \V/ DataConv_UnpackToPackBCD
//=============================================================================
/*!
* @fn       uint8_t DataConv_UnpackToPackBCD (uint8_t in_bcd_msd,
*                                             uint8_t in_bcd_lsd)
* @brief    This function converts Two Unpack BCD to Pack BCD
* @param    in_bcd_msd : 8-bit Input MSD Unpack BCD
* @param    in_bcd_lsd : 8-bit Input LSD Unpack BCD
* @retval   ret_val : Returns 8-bit pack BCD
* @warning  Accept only BCD numbers
* @note     None
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint8_t DataConv_UnpackToPackBCD (uint8_t in_bcd_msd, uint8_t in_bcd_lsd);


/*
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     30-OCT-2019
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
#endif // >> End of DATA_CONV_H_

/*! <h2><center>           (C) VOIDRON CO. 2019-20.           </center></h2> */
/*                        086 079 073 068 082 079 078                        */

