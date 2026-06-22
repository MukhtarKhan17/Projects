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
* @file     api_error_status.h
* @version  V1.0.0
* @brief    API ERROR STATUS
*           ---
*           ---
*           ---
* @author   MK
* @date     28-FEB-2021
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

#ifndef API_ERROR_STATUS_H_
#define API_ERROR_STATUS_H_

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
#define MAX_ERR_TYPE_CNT               (2U)
#define ALL_ERR_STAT_SIZE              (MAX_ERR_TYPE_CNT)


// >> System Errors
#define SYSTEM_ERRS                    (ERR_TYPE0)
#define FW_CHKSM_ERR                   (ERR_BIT0)


// >> WIFI related errors
#define WIFI_ERRS                      (ERR_TYPE1)
#define WIFI_COMM_ERR                  (ERR_BIT0)
#define WIFI_CONFIG_ERR                (ERR_BIT1)
#define WIFI_MAC_RD_ERR                (ERR_BIT2)
#define WIFI_AP_CONN_ERR               (ERR_BIT3)
#define WIFI_STA_IP_ERR                (ERR_BIT4)




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
	ERR_TYPE0  = 0,
	ERR_TYPE1  = 1,
}error_type_t;

typedef enum
{
	ERR_BIT0  = 0,
	ERR_BIT1  = 1,
	ERR_BIT2  = 2,
	ERR_BIT3  = 3,
	ERR_BIT4  = 4,
	ERR_BIT5  = 5,
	ERR_BIT6  = 6,
	ERR_BIT7  = 7,
}error_bit_num_t;

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
extern void ErrStat_Init(void);
extern void ErrStat_SetFlag(error_type_t error_type,
		                   error_bit_num_t error_bit_num);
extern void ErrStat_ClrFlag(error_type_t error_type,
		                   error_bit_num_t error_bit_num);
extern bool_t ErrStat_GetFlag(error_type_t error_type,
                             error_bit_num_t error_bit_num);
extern void ErrStat_GetAll(void *data_ptr, uint8_t data_size);



/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     28-FEB-2021
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
#endif // >> End of API_ERROR_STATUS_H_

