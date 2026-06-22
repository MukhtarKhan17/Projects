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
* @file      s25fl064l.h
* @brief     API of SPI Flash S25FL064L
* @version   V1.0.1
* @author    MK
* @date      13-JUN-2021
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
* <h2><center>             (C) VOIDRON CO. 2020-21.             </center></h2>
*/
//=============================================================================


#ifndef S25FL064L_H_
#define S25FL064L_H_

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

//#############################################################################
//                             \V/ Include SectioN
//#############################################################################
#include "vdef_types.h"
#include "string.h"
#include "stdlib.h"


//#############################################################################
//                            \V/ Global DefineS
//#############################################################################
// >> The following definitions are for reference only. Any Changes will not effect.

// >> Generic Cypress SPI Flash Command
#define S25FL_WR_CMD                   (0x02) // Memory Write Command
#define S25FL_RD_CMD                   (0x03) // Memory Read Command
#define S25FL_FRD_CMD                  (0x0B) // Memory Read Command
#define S25FL_WREN_CMD                 (0x06) // Write Enable Command
#define S25FL_WRDI_CMD                 (0x04) // Write Disable Command
#define S25FL_WRSR_CMD                 (0x01) // Write Status Register
#define S25FL_RDSR_CMD                 (0x05) // Read Status Register
#define S25FL_RDSR1_CMD                (0x05) // Read Status Register1
#define S25FL_RDSR2_CMD                (0x07) // Read Status Register2
#define S25FL_RDAR_CMD                 (0x65) // Read Any Register
#define S25FL_SE_CMD                   (0x20) // Sector Erase Command
#define S25FL_BE_CMD                   (0xD8) // Block Erase Command
#define S25FL_CE_CMD                   (0x60) // Chip Erase Command
#define S25FL_RDID_CMD             	   (0x9F) // Read Device ID
#define S25FL_FAST_RDID_CMD            (0x99) // Fast Read Device ID

/*RDAR read any register address definition*/
// Non-Volatile Status and Configuration Registers
#define    SR1NV         (0x00000000)
#define    CR1NV         (0x00000002)
#define    CR2NV         (0x00000003)
#define    CR3NV         (0x00000004)
#define    CR4NV         (0x00000005)
#define    NVDLP         (0x00000005)

//Volatile Status and Configuration Registers
#define    SR2V          (0x00800001)
#define    CR1V          (0x00800002)
#define    CR2V          (0x00800003)
#define    CR3V          (0x00800004)
#define    CR4V          (0x00800005)
#define    VDLP          (0x00800005)

// >> Memory Space Sizes
#define S25FL_PAGE_SZ         (0x100U)       // 256B
#define S25FL_SECT_SZ         (0x1000U)      // 4096B
#define S25FL_BLOCK_SZ        (0x10000U)     // 64KB = 64 x 1024 bytes
#define S25FL_064L_SZ         (0x00800000UL) // 8192MB

#define S25FL_TOTAL_SECT      (S25FL_064L_SZ / S25FL_SECT_SZ)  // Sector Range is 0 to 2047(TOTAL_SECT-1)
#define S25FL_TOTAL_BLOCK     (S25FL_064L_SZ / S25FL_BLOCK_SZ) // Block  Range is 0 to 127(TOTAL_BLOCK-1)

// >> Address Space of 8192KB
#define S25FL_BASE_ADDR       (0x00000000UL)
#define S25FL_LAST_ADDR       (S25FL_064L_SZ - 1UL)


//#############################################################################
//                            \V/ Global MacroS
//#############################################################################



//#############################################################################
//                           \V/ Global Data TypeS
//#############################################################################
typedef void (*S25fl064lSpiInitFptrT) (void);
typedef void (*S25fl064lGpioInitFptrT) (void);
typedef void (*S25fl064lCsHighFptrT) (void);
typedef void (*S25fl064lCsLowFptrT) (void);
typedef void (*S25fl064lRstHighFptrT) (void);
typedef void (*S25fl064lRstLowFptrT) (void);
typedef void (*S25fl064lWpHighFptrT) (void);
typedef void (*S25fl064lWpLowFptrT) (void);
typedef uint8_t (*S25fl064lSpiTxRxDatFptrT) (uint8_t tx_data);
typedef void (*S25fl064lDelayMsFptrT) (uint32_t delay_ms);
typedef uint32_t (*S25fl064lGetTickMsFptrT) (void);
typedef bool_t (*CS25fl064lChkTimeoutFptrT) (uint32_t *prvs_tick_tmr_ptr,
		                                    uint32_t tick_timeout_ms);

typedef struct
{
	S25fl064lSpiInitFptrT      SpiInit;
	S25fl064lGpioInitFptrT     GpioInit;
	S25fl064lCsHighFptrT       CsHigh;
	S25fl064lCsLowFptrT        CsLow;
	S25fl064lRstHighFptrT      RstHigh;
	S25fl064lRstLowFptrT       RstLow;
	S25fl064lWpHighFptrT       WpHigh;
	S25fl064lWpLowFptrT        WpLow;
	S25fl064lSpiTxRxDatFptrT   SpiTxRxDat;
	S25fl064lDelayMsFptrT      DelayMs;
	S25fl064lGetTickMsFptrT    GetTickMs;
	CS25fl064lChkTimeoutFptrT  ChkTimeout;
}s25fl064l_base_t;

//#############################################################################
//                            \V/ Global VariableS
//#############################################################################




//#############################################################################
//                        \V/ Global Function PrototypeS
//#############################################################################

//=============================================================================
//                         \V/ S25FL064L_Enable
//=============================================================================
/*!
* @fn       bool_t S25FL064L_Enable (int8_t *vtag_ptr)
* @brief    This function enables this library.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Enabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     29-MAY-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t S25FL064L_Enable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ S25FL064L_Disable
//=============================================================================
/*!
* @fn       bool_t S25FL064L_Disable (int8_t *vtag_ptr)
* @brief    This function disables this library.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Disabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     29-MAY-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t S25FL064L_Disable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ S25FL064L_BaseInit
//=============================================================================
/*!
* @fn       void S25FL064L_BaseInit (s25fl064l_base_t set_s25fl064l_base_s)
* @brief    S25FL064L_BaseInit
* @param    set_s25fl064l_base_s
* @retval   None
* @warning  if any member of set_s25fl064l_base_s is NULL then routine will not
*           move ahead. Remains in while loop.
* @note     None
* @author   MK
* @date     29-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void S25FL064L_BaseInit (s25fl064l_base_t set_s25fl064l_base_s);

//=============================================================================
//                         \V/ S25FL064L_DevInit
//=============================================================================
/*!
* @fn       void S25FL064L_DevInit (void)
* @brief    S25FL064L_DevInit
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     29-MAY-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void S25FL064L_DevInit (void);

//=============================================================================
//                         \V/ S25FL064L_WrEnable
//=============================================================================
/*!
* @fn       void S25FL064L_WrEnable (void)
* @brief    S25FL064L_WrEnable
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     29-MAY-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void S25FL064L_WrEnable (void);

//=============================================================================
//                         \V/ S25FL064L_WrDisable
//=============================================================================
/*!
* @fn       void S25FL064L_WrDisable (void)
* @brief    S25FL064L_WrDisable
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     29-MAY-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void S25FL064L_WrDisable (void);

//=============================================================================
//                         \V/ S25FL064L_ChkDevBusy
//=============================================================================
/*!
* @fn       bool_t S25FL064L_ChkDevBusy (void)
* @brief    S25FL064L_ChkDevBusy
* @param    None
* @retval   error_f
* @warning  None
* @note     None
* @author   MK
* @date     29-MAY-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t S25FL064L_ChkDevBusy (void);

//=============================================================================
//                         \V/ S25FL064L_RdDevId
//=============================================================================
/*!
* @fn       uint32_t S25FL064L_RdDevId(void)
* @brief    S25FL064L_RdDevId
* @param    None
* @retval   dev_id
* @warning  None
* @note     None
* @author   MK
* @date     13-JUN-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern uint32_t S25FL064L_RdDevId(void);

//=============================================================================
//                         \V/ S25FL064L_SectorErase
//=============================================================================
/*!
* @fn       bool_t S25FL064L_SectorErase (uint16_t sect_num)
* @brief    S25FL064L_SectorErase
* @param    sect_num
* @retval   error_f
* @warning  None
* @note     Size is 4KB
* @author   MK
* @date     29-MAY-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t S25FL064L_SectorErase (uint16_t sect_num);

//=============================================================================
//                         \V/ S25FL064L_BlockErase
//=============================================================================
/*!
* @fn       bool_t S25FL064L_BlockErase (uint8_t block_num)
* @brief    S25FL064L_BlockErase
* @param    block_num
* @retval   error_f
* @warning  None
* @note     Size is 64KB
* @author   MK
* @date     29-MAY-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t S25FL064L_BlockErase (uint8_t block_num);

//=============================================================================
//                         \V/ S25FL064L_ChipErase
//=============================================================================
/*!
* @fn       void S25FL064L_ChipErase (void)
* @brief    S25FL064L_ChipErase
* @param    None
* @retval   None
* @warning  None
* @note     Size is 8192KB
* @author   MK
* @date     29-MAY-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void S25FL064L_ChipErase (void);


//=============================================================================
//                         \V/ S25FL064L_RdData
//=============================================================================
/*!
* @fn       bool_t S25FL064L_RdData (uint32_t start_addr, uint8_t *data_ptr,
*                                    uint32_t data_sz)
* @brief    S25FL064L_RdData
* @param    start_addr
* @param    *data_ptr
* @param    data_sz
* @retval   error_f
* @warning  None
* @note     None
* @author   MK
* @date     29-MAY-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t S25FL064L_RdData (uint32_t start_addr, uint8_t *data_ptr,
		                        uint32_t data_sz);

//=============================================================================
//                         \V/ S25FL064L_WrData
//=============================================================================
/*!
* @fn       bool_t S25FL064L_WrData (uint32_t start_addr, uint8_t *data_ptr,
*                                  uint32_t data_sz)
* @brief    S25FL064L_WrData
* @param    start_addr
* @param    *data_ptr
* @param    data_sz
* @retval   error_f
* @warning  None
* @note     None
* @author   MK
* @date     29-MAY-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t S25FL064L_WrData (uint32_t start_addr, uint8_t *data_ptr,
		                        uint32_t data_sz);





/*
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     29-MAY-2021
* @brief    Initial Release
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.1
* @author   MK
* @date     13-JUN-2021
* @brief    - Function S25FL064L_RdDevId added
*           - Bug Fixes: while loop with Timeouts
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
#endif // >> End of S25FL064L_H_
/*! <h2><center>           (C) VOIDRON CO. 2020-21.           </center></h2> */
/*                        086 079 073 068 082 079 078                        */

