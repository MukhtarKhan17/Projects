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
* @{ <h2><center>           (C) VOIDRON CO. 2023.          </center></h2> @}
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
* @file     hal_flash_stm32f103rx.c
* @version  V1.0.0
* @brief    HAL Flash Routines
*           + Flash Page Write
*           + Flash Page Read
*           + Flash Page Erase
* @author   MK
* @date     27-FEB-2021
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "hal_flash_stm32f103rx.h"


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
// >> Declare Local Variables Here.

/**
*==============================================================================
*                          \V/ Local Function PrototypeS
*==============================================================================
*/
// >> Declare Local Function Prototypes Here.


/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Flash_PageErase(uint32_t page_addr)
*==============================================================================
* @brief    Flash_PageErase
*           ---
*           ---
*           ---
* @note     None
* @param    page_addr
* @retval   void
* @author   MK
* @date     27-FEB-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Flash_PageErase(uint32_t page_addr)
{
	FLASH_UnlockBank1();
	FLASH_ErasePage(page_addr);
	FLASH_LockBank1();
}//End of Flash_PageErase()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Flash_PageWrite(uint32_t page_addr,
*		                    void *data_ptr,
*		                    uint16_t size)
*==============================================================================
* @brief    Flash_PageWrite
*           ---
*           ---
*           ---
* @note     None
* @param    page_addr
* @param    *data_ptr
* @param    data_sz
* @retval   flash_sts
* @author   MK
* @date     27-FEB-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Flash_PageWrite(uint32_t page_addr,
		             void *data_ptr,
		             uint16_t data_sz)
{
	uint16_t byte_cntr  = 0;
	uint8_t temp_var8   = 0;
	uint16_t temp_var16 = 0;

	FLASH_UnlockBank1();

	for(byte_cntr = 0; byte_cntr < data_sz; (byte_cntr += 2))
	{
		temp_var8 = *(const uint8_t*)data_ptr++;
		temp_var16  = *(const uint8_t*)data_ptr++;
		temp_var16 = ((temp_var16 << 8) | temp_var8);

		(void)FLASH_ProgramHalfWord(page_addr, temp_var16);
		page_addr += 2;
	}

	FLASH_LockBank1();
}// End of Flash_PageWrite()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Flash_PageRead(uint32_t page_addr,
*		                   const void *data_ptr,
*		                   uint16_t data_sz)
*==============================================================================
* @brief    Flash_PageRead
*           ---
*           ---
*           ---
* @note     None
* @param    page_addr
* @param    *data_ptr
* @param    data_sz
* @retval   None
* @author   MK
* @date     27-FEB-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Flash_PageRead(uint32_t page_addr,
		           const void *data_ptr,
		           uint16_t data_sz)
{
	uint32_t *flash_addr_ptr = NULL ;

	flash_addr_ptr = (uint32_t*)page_addr;
	(void)memcpy((void *)data_ptr, flash_addr_ptr, data_sz);

}// End of Flash_PageRead()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Flash_EnableRdProtect(void)
*==============================================================================
* @brief    Flash_EnableRdProtect
*           ---
*           ---
*           ---
* @note     Flash Read Protection
* @retval   None
* @author   MK
* @date     23-DEC-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Flash_EnableRdProtect(void)
{
	FLASH_Unlock();
	FLASH_ReadOutProtection(ENABLE);
	FLASH_Lock();
}// End of Flash_EnableRdProtect()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void Flash_DisableRdProtect(void)
*==============================================================================
* @brief    Flash_DisableRdProtect
*           ---
*           ---
*           ---
* @note     Flash Read Protection
* @retval   None
* @author   MK
* @date     23-DEC-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void Flash_DisableRdProtect(void)
{
	FLASH_Unlock();
	FLASH_ReadOutProtection(DISABLE);
	FLASH_Lock();
}// End of Flash_DisableRdProtect()
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
