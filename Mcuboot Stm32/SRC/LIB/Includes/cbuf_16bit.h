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
* @file      cbuf_16bit.h
* @brief     16-bit Circular Buffer Routines
* @version   V1.0.0
* @author    MK
* @date      26-MAY-2022
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
* <h2><center>              (C) VOIDRON CO. 2022.               </center></h2>
*/
//=============================================================================


#ifndef CBUF_16BIT_H_
#define CBUF_16BIT_H_

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

//#############################################################################
//                             \V/ Include SectioN
//#############################################################################
#include "vdef_types.h"
#include "stdlib.h"
#include "string.h"

//#############################################################################
//                            \V/ Global DefineS
//#############################################################################
#define CBUF_MAX_SIZE                  (65536U)


//#############################################################################
//                            \V/ Global MacroS
//#############################################################################



//#############################################################################
//                           \V/ Global Data TypeS
//#############################################################################
typedef struct
{
	uint32_t wr_indx;
	uint32_t rd_indx;
	uint32_t size;
	uint16_t buffer[];
}cbuf_16bit_t;


//#############################################################################
//                            \V/ Global VariableS
//#############################################################################




//#############################################################################
//                        \V/ Global Function PrototypeS
//#############################################################################

//=============================================================================
//                         \V/ Cbuf16Bit_Enable
//=============================================================================
/*!
* @fn       bool_t Cbuf16Bit_Enable (int8_t *vtag_ptr)
* @brief    This function enables this library.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Enabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     26-MAY-2022
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Cbuf16Bit_Enable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ Cbuf16Bit_Disable
//=============================================================================
/*!
* @fn       bool_t Cbuf16Bit_Disable (int8_t *vtag_ptr)
* @brief    This function disables this library.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Disabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     26-MAY-2022
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Cbuf16Bit_Disable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ Cbuf16Bit_ClrBuf
//=============================================================================
/*!
* @fn       void Cbuf16Bit_ClrBuf (cbuf_16bit_t *cbuf_16bit_s_ptr)
* @brief    Cbuf16Bit_ClrBuf
* @param    *cbuf_16bit_s_ptr
* @retval   None
* @warning  Write function warning here
* @note     Write function notes here
* @author   MK
* @date     20-MAY-2022
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void Cbuf16Bit_ClrBuf (cbuf_16bit_t *cbuf_16bit_s_ptr);

//=============================================================================
//                         \V/ Cbuf16Bit_GetCap
//=============================================================================
/*!
* @fn       uint32_t Cbuf16Bit_GetCap (cbuf_16bit_t *cbuf_16bit_s_ptr)
* @brief    Get CBUF max data holding capacity.
* @param    *cbuf_16bit_s_ptr
* @retval   None
* @warning  None
* @note     cbuf_cap = cbuf_size - 1
* @author   MK
* @date     26-MAY-2022
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint32_t Cbuf16Bit_GetCap (cbuf_16bit_t *cbuf_16bit_s_ptr);

//=============================================================================
//                         \V/ Cbuf16Bit_GetFillSz
//=============================================================================
/*!
* @fn       uint32_t Cbuf16Bit_GetFillSz (uint32_t wr_indx,
*		                                  uint32_t rd_indx,
*							              uint32_t cbuf_sz)
* @brief    Cbuf16Bit_GetFillSz
* @param    wr_indx
* @param    rd_indx
* @param    cbuf_sz
* @retval   fill_sz
* @warning  None
* @note     None
* @author   MK
* @date     26-MAY-2022
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint32_t Cbuf16Bit_GetFillSz (uint32_t wr_indx,
									 uint32_t rd_indx,
									 uint32_t cbuf_sz);

//=============================================================================
//                         \V/ Cbuf16Bit_GetAvlSz
//=============================================================================
/*!
* @fn       uint32_t Cbuf16Bit_GetAvlSz (uint32_t wr_indx,
*		                                 uint32_t rd_indx,
*							             uint32_t cbuf_sz)
* @brief    Cbuf16Bit_GetAvlSz
* @param    wr_indx
* @param    rd_indx
* @param    cbuf_sz
* @retval   avl_sz
* @warning  None
* @note     None
* @author   MK
* @date     26-MAY-2022
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint32_t Cbuf16Bit_GetAvlSz (uint32_t wr_indx,
		                            uint32_t rd_indx,
		                            uint32_t cbuf_sz);

//=============================================================================
//                         \V/ Cbuf16Bit_WrData
//=============================================================================
/*!
* @fn       bool_t Cbuf16Bit_WrData (cbuf_16bit_t *cbuf_16bit_s_ptr,
*		                            void *in_data_ptr,
*						            uint32_t data_sz)
* @brief    Cbuf16Bit_WrData
* @param    *cbuf_16bit_s_ptr
* @param    *in_data_ptr
* @param    data_sz
* @retval   cbuf_full_err_f
* @warning  None
* @note     None
* @author   MK
* @date     26-MAY-2022
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Cbuf16Bit_WrData (cbuf_16bit_t *cbuf_16bit_s_ptr,
		                       void *in_data_ptr,
		                       uint32_t data_sz);

//=============================================================================
//                         \V/ Cbuf16Bit_RdData
//=============================================================================
/*!
* @fn       bool_t Cbuf16Bit_RdData (cbuf_16bit_t *cbuf_16bit_s_ptr,
*		                            void *op_data_ptr,
*						            uint32_t data_sz)
* @brief    Cbuf16Bit_RdData
* @param    *cbuf_16bit_s_ptr
* @param    *op_data_ptr
* @param    data_sz
* @retval   cbuf_empty_err_f
* @warning  None
* @note     None
* @author   MK
* @date     26-MAY-2022
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t Cbuf16Bit_RdData (cbuf_16bit_t *cbuf_16bit_s_ptr,
		                       void *op_data_ptr,
		                       uint32_t data_sz);


/*
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     26-MAY-2022
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
#endif // >> End of CBUF_16BIT_H_
/*! <h2><center>             (C) VOIDRON CO. 2022.            </center></h2> */
/*                        086 079 073 068 082 079 078                        */

