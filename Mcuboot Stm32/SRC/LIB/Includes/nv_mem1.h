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
* @file     nv_mem1.h
* @version  V1.0.6
* @brief    API Non-volatile Memory
*           + Memory Write
*           + Memory Read
* @author   MK
* @date     05-JAN-2024
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

#ifndef NV_MEM1_H_
#define NV_MEM1_H_

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
#define NV_MEM1_DAT_MAX_SZ			  (512U)





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
	MEM1_SIGN_SZ         	 = 1,
	MEM1_DEV_NAME_SZ         = 1,
	MEM1_DEV_SRNO_SZ         = 16,
	MEM1_AP_SSID_SZ          = 8,
	MEM1_AP_PSWD_SZ          = 8,
	MEM1_LOG_WR_INDX_SZ      = 2,
	MEM1_CHKSM_SZ        	 = 1,
}nv_mem1_dat_sz_t;

typedef enum
{
	MEM1_SIGN_ADDR           = (0),
	MEM1_DEV_NAME_ADDR       = (MEM1_SIGN_ADDR       + MEM1_SIGN_SZ),
	MEM1_DEV_SRNO_ADDR       = (MEM1_DEV_NAME_ADDR   + MEM1_DEV_NAME_SZ),
	MEM1_AP_SSID_ADDR        = (MEM1_DEV_SRNO_ADDR   + MEM1_DEV_SRNO_SZ),
	MEM1_AP_PSWD_ADDR        = (MEM1_AP_SSID_ADDR    + MEM1_AP_SSID_SZ),
	MEM1_LOG_WR_INDX_ADDR    = (MEM1_AP_PSWD_ADDR    + MEM1_AP_PSWD_SZ),
	MEM1_CHKSM_ADDR          = (NV_MEM1_DAT_MAX_SZ   - MEM1_CHKSM_SZ)
}nv_mem1_dat_addr_t;


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
}nv_mem1_base_t;

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
//                         \V/ NvMem1_Enable
//=============================================================================
/*!
* @fn       bool_t NvMem1_Enable (int8_t *vtag_ptr)
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
extern bool_t NvMem1_Enable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ NvMem1_Disable
//=============================================================================
/*!
* @fn       bool_t NvMem1_Disable (int8_t *vtag_ptr)
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
extern bool_t NvMem1_Disable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ NvMem1_BaseInit
//=============================================================================
/*!
* @fn       void NvMem1_BaseInit (nv_mem1_base_t set_nv_mem1_base_s)
* @brief    Link functions of Flash or Memory chip
* @param    set_nv_mem1_base_s
* @retval   None
* @warning  if any member of set_nv_mem1_base_s is NULL then routine will not
*           move ahead. Remains in while loop.
* @note     None
* @author   MK
* @date     27-FEB-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void NvMem1_BaseInit (nv_mem1_base_t set_nv_mem1_base_s);

//=============================================================================
//                         \V/ NvMem1_DataSignChk
//=============================================================================
/*!
* @fn       bool_t NvMem1_DataSignChk(void)
* @brief    NvMem1_DataSignChk
* @note     None
* @param    None
* @retval   nv_data_sign_f
* @author   MK
* @date     27-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*/
//=============================================================================
extern bool_t NvMem1_DataSignChk(void);

//=============================================================================
//                         \V/ NvMem1_Format
//=============================================================================
/*!
* @fn       void NvMem1_Format(void)
* @brief    NvMem1_Format
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     27-FEB-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*/
//=============================================================================
extern void NvMem1_Format(void);

//=============================================================================
//                         \V/ NvMem1_DataWr
//=============================================================================
/*!
* @fn       bool_t NvMem1_DataWr(nv_mem1_dat_addr_t data_addr,
*		                        const void *ip_data_ptr,
*		                        nv_mem1_dat_sz_t data_sz)
* @brief    NvMem1_DataWr
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
extern bool_t NvMem1_DataWr(nv_mem1_dat_addr_t data_addr,
		                   const void *ip_data_ptr,
		                   nv_mem1_dat_sz_t data_sz);

//=============================================================================
//                         \V/ NvMem1_DataRd
//=============================================================================
/*!
* @fn       bool_t NvMem1_DataRd(nv_mem1_dat_addr_t data_addr,
*		                       void *op_data_ptr,
*		                       nv_mem1_dat_sz_t data_sz)
* @brief    NvMem1_DataRd
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
extern bool_t NvMem1_DataRd(nv_mem1_dat_addr_t data_addr,
                           void *op_data_ptr,
                           nv_mem1_dat_sz_t data_sz);

//=============================================================================
//                         \V/ NvMem1_Save
//=============================================================================
/*!
* @fn       void NvMem1_Save(void)
* @brief    NvMem1_Save
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     10-JUN-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*/
//=============================================================================
extern void NvMem1_Save(void);

//=============================================================================
//                         \V/ NvMem1_LoadImage
//=============================================================================
/*!
* @fn       bool_t NvMem1_LoadImage(void)
* @brief    NvMem1_LoadImage
* @note     None
* @param    None
* @retval   error_f
* @author   MK
* @date     10-JUN-2021 // >>Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*/
//=============================================================================
extern bool_t NvMem1_LoadImage(void);

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
*           NvMem1_SetFptr
*           ---
*           Following Function Added
*           NvMem1_BaseInit
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.2
* @author   MK
* @date     26-MAY-2021
* @brief    NV_MEM1_DAT_MAX_SZ changed to 256B
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.3
* @author   MK
* @date     26-MAY-2021
* @brief    NV_MEM1_DAT_MAX_SZ changed to 512B
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.4
* @author   MK
* @date     10-JUN-2021
* @brief    - NV_MEM1_DAT_MAX_SZ changed to 256B
*           - NvMem1_Save function added
*           - File variants added
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.5
* @author   MK
* @date     10-JUN-2021
* @brief    - NV_MEM1_DAT_MAX_SZ changed to 256B
*           - NvMem1_Save function added
*           - File variants added
*           - nv_mem1_img_buf added
*           - NvMem1_DataRd modified
*------------------------------------------------------------------------------
* @version  V1.0.6
* @author   MK
* @date     05-JAN-2024
* @brief    NV_MEM1_DAT_MAX_SZ changed to 512B
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
#endif // >> End of NV_MEM1_H_

