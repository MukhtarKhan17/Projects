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
* @file      data_integrity.h
* @brief     This file contains routines to check or calculate checksum/CRC.
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


#ifndef DATA_INTEGRITY_H_
#define DATA_INTEGRITY_H_

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

#define CHKSM8_SIZE                    (1U)
#define CHKSM16_SIZE                   (2U)
#define CRC8_SIZE                      (1U)
#define CRC16_SIZE                     (2U)


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
//                         \V/ DatIntg_Enable
//=============================================================================
/*!
* @fn       bool_t DatIntg_Enable (int8_t *vtag_ptr)
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
extern bool_t DatIntg_Enable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ DatIntg_Disable
//=============================================================================
/*!
* @fn       bool_t DatIntg_Disable (int8_t *vtag_ptr)
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
extern bool_t DatIntg_Disable (int8_t *vtag_ptr);


//=============================================================================
//                         \V/ DatIntg_CalChksm8
//=============================================================================
/*!
* @fn       uint8_t DatIntg_CalChksm8(const void *ip_data, uint16_t data_len)
* @brief    This function calculate 8-bit 2's complement checksum.
* @param    *ip_data : i/p data pointer
* @param    data_len : Length of data
* @retval   8-bit Checksum Value
* @warning  Max data length is 2^16 bytes
* @note     None
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint8_t  DatIntg_CalChksm8(const void *ip_data, uint16_t data_len);

//=============================================================================
//                         \V/ DatIntg_CalChksm16
//=============================================================================
/*!
* @fn       uint16_t DatIntg_CalChksm16(const void *ip_data, uint32_t data_len)
* @brief    This function calculate 16-bit 2's complement checksum.
* @param    *ip_data : i/p data pointer
* @param    data_len : Length of data
* @retval   16-bit Checksum Value
* @warning  Max data length is 2^32 bytes
* @note     None
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint16_t DatIntg_CalChksm16(const void *ip_data, uint32_t data_len);


//=============================================================================
//                         \V/ DatIntg_CalCrc8
//=============================================================================
/*!
* @fn       uint8_t DatIntg_CalCrc8(const void *ip_data, uint16_t data_len)
* @brief    This function calculate 8-bit Polynomial CRC.
* @param    *ip_data : i/p data pointer
* @param    data_len : Length of data
* @retval   8-bit CRC Value
* @warning  Max data length is 2^16 bytes
* @note     None
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint8_t  DatIntg_CalCrc8(const void *ip_data, uint16_t data_len);

//=============================================================================
//                         \V/ DatIntg_CalCrc16
//=============================================================================
/*!
* @fn       uint16_t DatIntg_CalCrc16(const void *ip_data, uint32_t data_len)
* @brief    This function calculate 16-bit Polynomial CRC.
* @param    *ip_data : i/p data pointer
* @param    data_len : Length of data
* @retval   16-bit CRC Value
* @warning  Max data length is 2^32 bytes
* @note     None
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint16_t DatIntg_CalCrc16(const void *ip_data, uint32_t data_len);

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
#endif // >> End of DATA_INTEGRITY_H_

/*! <h2><center>           (C) VOIDRON CO. 2019-20.           </center></h2> */
/*                        086 079 073 068 082 079 078                        */

