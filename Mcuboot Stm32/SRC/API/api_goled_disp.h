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
* @file     api_goled_disp.h
* @version  V1.0.0
* @brief    API GOLED Display
*           ---
*           ---
*           ---
* @author   MK
* @date     22-MAR-2021
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/

#ifndef API_GOLED_DISP_H_
#define API_GOLED_DISP_H_

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "vdef_types.h"
#include "hal_goled_disp_io.h"
#include "ssd1309.h"
#include "api_sys_tick.h"
/**
*==============================================================================
*                          	  \V/ Global DefineS
*==============================================================================
*/
#define GOLED_5X7_CHAR_LINE_SZ               (21U)
#define GOLED_10X14_CHAR_LINE_SZ             (10U)
#define GOLED_CG_CHAR_DATA_SZ                (5U)
#define GOLED_MAX_LINE_COUNT                 (8U)

#define GOLED_LINE_1                         (1U)
#define GOLED_LINE_2                         (2U)
#define GOLED_LINE_3                         (3U)
#define GOLED_LINE_4                         (4U)
#define GOLED_LINE_5                         (5U)
#define GOLED_LINE_6                         (6U)
#define GOLED_LINE_7                         (7U)
#define GOLED_LINE_8                         (8U)


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
	PROMPT_SUCCESS = 0,
	PROMPT_INVALID,
	PROMPT_SAVED,
	PROMPT_MISMATCH,
	PROMPT_ERROR,
	PROMPT_DENIED,
	PROMPT_NOMEM,
}goled_prompt_msg_t;

/**
*==============================================================================
*                            \V/ Global VariableS
*==============================================================================
*/
extern uint8_t CUSTOM_TIMER_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_ALARM_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_DOWN_ARROW_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_UP_ARROW_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_RIGHT_ARROW_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_LEFT_ARROW_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_DEG_CEL_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_WARN_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_LOG_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_WIFI_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_DATA_TRANS_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_BLE_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_TICK_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_MID_DN_ARROW_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_MID_UP_ARROW_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_MID_BI_ARROW_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_DASH_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_LEFT_POINTER_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_RIGHT_POINTER_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_ENTER_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_BACK_SYMBOL[GOLED_CG_CHAR_DATA_SZ];

extern uint8_t CUSTOM_SOUND_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_SOUND_ON_SYMBOL[GOLED_CG_CHAR_DATA_SZ];
extern uint8_t CUSTOM_SOUND_OFF_SYMBOL[GOLED_CG_CHAR_DATA_SZ];


extern const uint8_t VOIDRON_LOGO[];

/**
*==============================================================================
*                        \V/ Global Function PrototypeS
*==============================================================================
*/
extern void GoledDisp_Init (void);
extern void GoledDisp_Refresh (void);
extern void GoledDisp_Clear (void);
extern void GoledDisp_Flash (void);

extern bool_t GoledDisp_WrTxtSmall(uint8_t line,
								   uint8_t pos,
								   uint8_t *data_ptr,
								   uint8_t data_sz);

extern bool_t GoledDisp_WrTxtMedium(uint8_t line,
								    uint8_t pos,
								    uint8_t *data_ptr,
								    uint8_t data_sz);

extern bool_t GoledDisp_WrSymbolSmall(uint8_t line,
								      uint8_t pos,
								      uint8_t *data_ptr,
								      uint8_t data_sz);

extern void GoledDisp_LoadImage(const uint8_t *image_data_ptr);
extern void GoledDisp_LoadPrompt(uint8_t prompt_code);

/**
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     22-MAR-2021
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
#endif // >> End of API_GOLED_DISP_H_

