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
* @file     api_s25fl064l.c
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

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "api_s25fl064l.h"


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
int8_t vTag_S25fl064l_Key[] = "VOIDRON";

/**
*==============================================================================
*                          \V/ Local Function PrototypeS
*==============================================================================
*/



/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void S25fl064l_Init (void)
*==============================================================================
* @brief    S25fl064l_Init
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     18-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void S25fl064l_Init (void)
{
	s25fl064l_base_t s25fl064l_base_s = {0};

	s25fl064l_base_s.SpiInit     = &Spi2_MasterInit;
	s25fl064l_base_s.GpioInit    = &S25fl064lIO_GpioInit;
	s25fl064l_base_s.CsHigh      = &Spi2_MasterSetCsHigh;;
	s25fl064l_base_s.CsLow       = &Spi2_MasterSetCsLow;;
	s25fl064l_base_s.RstHigh     = &S25fl064lIO_SetRstHigh;
	s25fl064l_base_s.RstLow      = &S25fl064lIO_SetRstLow;
	s25fl064l_base_s.WpHigh      = &S25fl064lIO_SetWpHigh;
	s25fl064l_base_s.WpLow       = &S25fl064lIO_SetWpLow;
	s25fl064l_base_s.SpiTxRxDat  = &Spi2_MasterTxRxByte;
	s25fl064l_base_s.DelayMs     = &SysTick_Delay;
	s25fl064l_base_s.GetTickMs   = &SysTick_GetTickTmrVal;
	s25fl064l_base_s.ChkTimeout  = &SysTick_CheckTimeOut;
	S25FL064L_BaseInit(s25fl064l_base_s);

	(void)S25FL064L_Enable(vTag_S25fl064l_Key);

	S25FL064L_DevInit();

}// >> End of S25fl064l_Init()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void S25FL064L_SectorEraseAddr (uint32_t sec_start_addr)
*==============================================================================
* @brief    S25FL064L_SectorEraseAddr
*           ---
*           ---
*           ---
* @note     sec_start_addr
* @param    None
* @retval   None
* @author   MK
* @date     18-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void S25FL064L_SectorEraseAddr (uint32_t sec_start_addr)
{
	uint16_t sect_num = 0;

	sect_num = (sec_start_addr / S25FL_SECT_SZ);

	if(sect_num < S25FL_TOTAL_SECT)
	{
		(void)S25FL064L_SectorErase(sect_num);
	}

}// >> End of S25FL064L_SectorEraseAddr()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void S25FL064L_BlockEraseAddr (uint32_t block_start_addr)
*==============================================================================
* @brief    S25FL064L_BlockEraseAddr
*           ---
*           ---
*           ---
* @note     block_start_addr
* @param    None
* @retval   None
* @author   MK
* @date     18-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void S25FL064L_BlockEraseAddr (uint32_t block_start_addr)
{
	uint8_t block_num = 0;

	block_num = (block_start_addr / S25FL_BLOCK_SZ);

	if(block_num < S25FL_TOTAL_BLOCK)
	{
		(void)S25FL064L_BlockErase(block_num);
	}

}// >> End of S25FL064L_BlockEraseAddr()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void S25FL064L_SectorWrData (uint32_t start_addr,
*		                            void *data_ptr,
*		                            uint16_t data_sz)
*==============================================================================
* @brief    S25FL064L_SectorWrData
*           ---
*           ---
*           ---
* @note     None
* @param    start_addr
* @param    *data_ptr
* @param    data_sz
* @retval   None
* @author   MK
* @date     18-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void S25FL064L_SectorWrData (uint32_t start_addr,
		                     void *data_ptr,
		                     uint16_t data_sz)
{
	uint8_t *dat_ptr = (uint8_t *)data_ptr;

	(void)S25FL064L_WrData(start_addr, dat_ptr, data_sz);
}// >> End of S25FL064L_SectorWrData()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void S25FL064L_SectorRdData (uint32_t start_addr,
*		                            const void *data_ptr,
*		                            uint16_t data_sz)
*==============================================================================
* @brief    S25FL064L_SectorRdData
*           ---
*           ---
*           ---
* @note     None
* @param    start_addr
* @param    *data_ptr
* @param    data_sz
* @retval   None
* @author   MK
* @date     18-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void S25FL064L_SectorRdData (uint32_t start_addr,
		                     const void *data_ptr,
		                     uint16_t data_sz)
{
	uint8_t *dat_ptr = (uint8_t *)data_ptr;

	(void)S25FL064L_RdData(start_addr, dat_ptr, data_sz);
}// >> End of S25FL064L_SectorRdData()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void S25FL064L_BlockWrData (uint32_t start_addr,
*		                            void *data_ptr,
*		                            uint16_t data_sz)
*==============================================================================
* @brief    S25FL064L_BlockWrData
*           ---
*           ---
*           ---
* @note     None
* @param    start_addr
* @param    *data_ptr
* @param    data_sz
* @retval   None
* @author   MK
* @date     18-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void S25FL064L_BlockWrData (uint32_t start_addr,
		                    void *data_ptr,
		                    uint16_t data_sz)
{
	uint8_t *dat_ptr = (uint8_t *)data_ptr;

	(void)S25FL064L_WrData(start_addr, dat_ptr, data_sz);
}// >> End of S25FL064L_BlockWrData()

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void S25FL064L_BlockRdData (uint32_t start_addr,
*		                           const void *data_ptr,
*		                           uint16_t data_sz)
*==============================================================================
* @brief    S25FL064L_BlockRdData
*           ---
*           ---
*           ---
* @note     None
* @param    start_addr
* @param    *data_ptr
* @param    data_sz
* @retval   None
* @author   MK
* @date     18-SEP-2024 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void S25FL064L_BlockRdData (uint32_t start_addr,
		                    const void *data_ptr,
		                    uint16_t data_sz)
{
	uint8_t *dat_ptr = (uint8_t *)data_ptr;

	(void)S25FL064L_RdData(start_addr, dat_ptr, data_sz);
}// >> End of S25FL064L_BlockRdData()

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
