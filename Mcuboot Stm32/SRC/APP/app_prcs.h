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
* @file     app_prcs.h
* @version  V1.0.0
* @brief    Application Process
*           ---
*           ---
*           ---
* @author   MK
* @date     07-NOV-2023
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

#ifndef APP_PRCS_H_
#define APP_PRCS_H_

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

#include "hal_rs485_dir_io.h"
#include "hal_spi2_stm32f103rx.h"


#include "api_sys_tick.h"
#include "api_rs485_dir.h"
#include "api_uart_com1.h"
#include "api_uart_com2.h"
#include "api_uart_com3.h"
#include "api_can_com1.h"
#include "api_sts_led.h"
#include "api_esp8266.h"
#include "api_nv_mem1.h"
#include "api_nv_mem2.h"
#include "api_goled_disp.h"
#include "api_keypad.h"
#include "api_watchdog.h"
#include "api_buzzer.h"
#include "api_ctrl_sw.h"
#include "api_matrix_keypad.h"
#include "api_s25fl064l.h"
#include "api_nv_mem2.h"
#include "api_x_modem.h"
#include "error_indicator.h"
#include "data_base.h"
#include "pwr_up_prcs.h"
#include "disp_prcs.h"
#include "comm_prcs.h"
#include "web_host_prcs.h"





/**
*==============================================================================
*                          	  \V/ Global DefineS
*==============================================================================
*/
// >> 1. Global Constants


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
extern void App_LoopPrcs (void);
extern void App_TickPrcs (void);


/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     07-NOV-2023
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
#endif // >> End of APP_PRCS_H_

