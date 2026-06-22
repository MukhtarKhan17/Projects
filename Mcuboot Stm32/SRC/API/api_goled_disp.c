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
* @file     api_goled_disp.c
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

/**
*==============================================================================
*                             \V/ Include SectioN
*==============================================================================
*/
#include "api_goled_disp.h"


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


/**
*==============================================================================
*                              \V/ Local VariableS
*==============================================================================
*/
uint8_t CUSTOM_TIMER_SYMBOL[GOLED_CG_CHAR_DATA_SZ]        = {0x3C, 0x42, 0x5E, 0x52, 0x3C};
uint8_t CUSTOM_ALARM_SYMBOL[GOLED_CG_CHAR_DATA_SZ]        = {0x20, 0x3C, 0x7E, 0x3C, 0x20};
uint8_t CUSTOM_DOWN_ARROW_SYMBOL[GOLED_CG_CHAR_DATA_SZ]   = {0x30, 0x70, 0xF0, 0x70, 0x30};
uint8_t CUSTOM_UP_ARROW_SYMBOL[GOLED_CG_CHAR_DATA_SZ]     = {0x0C, 0x0E, 0x0F, 0x0E, 0x0C};
uint8_t CUSTOM_LEFT_ARROW_SYMBOL[GOLED_CG_CHAR_DATA_SZ]   = {0x3E, 0x3E, 0x1C, 0x08, 0x00};
uint8_t CUSTOM_RIGHT_ARROW_SYMBOL[GOLED_CG_CHAR_DATA_SZ]  = {0x00, 0x08, 0x1C, 0x3E, 0x3E};
uint8_t CUSTOM_TICK_SYMBOL[GOLED_CG_CHAR_DATA_SZ]         = {0x10, 0x20, 0x10, 0x08, 0x04};
uint8_t CUSTOM_DEG_CEL_SYMBOL[GOLED_CG_CHAR_DATA_SZ]      = {0x00, 0x00, 0x06, 0x06, 0x00};
uint8_t CUSTOM_WARN_SYMBOL[GOLED_CG_CHAR_DATA_SZ]         = {0xFF, 0x81, 0xAD, 0x81, 0xFF};
uint8_t CUSTOM_LOG_SYMBOL[GOLED_CG_CHAR_DATA_SZ]          = {0xF8, 0x8C, 0x86, 0x82, 0xFE};
uint8_t CUSTOM_WIFI_SYMBOL[GOLED_CG_CHAR_DATA_SZ]         = {0x04, 0x12, 0x4A, 0x12, 0x04};
uint8_t CUSTOM_DATA_TRANS_SYMBOL[GOLED_CG_CHAR_DATA_SZ]   = {0x04, 0x7E, 0x00, 0x7E, 0x20};
uint8_t CUSTOM_BLE_SYMBOL[GOLED_CG_CHAR_DATA_SZ]          = {0x44, 0x28, 0xFE, 0x92, 0x6C};
uint8_t CUSTOM_MID_DN_ARROW_SYMBOL[GOLED_CG_CHAR_DATA_SZ] = {0x0C, 0x1C, 0x3C, 0x1C, 0x0C};
uint8_t CUSTOM_MID_BI_ARROW_SYMBOL[GOLED_CG_CHAR_DATA_SZ] = {0x14, 0x36, 0x77, 0x36, 0x14};
uint8_t CUSTOM_MID_UP_ARROW_SYMBOL[GOLED_CG_CHAR_DATA_SZ] = {0x30, 0x38, 0x3C, 0x38, 0x30};
uint8_t CUSTOM_DASH_SYMBOL[GOLED_CG_CHAR_DATA_SZ]         = {0x00, 0x08, 0x08, 0x08, 0x00};
uint8_t CUSTOM_LEFT_POINTER_SYMBOL[GOLED_CG_CHAR_DATA_SZ] = {0x08, 0x08, 0x2A, 0x1C, 0x08};
uint8_t CUSTOM_RIGHT_POINTER_SYMBOL[GOLED_CG_CHAR_DATA_SZ]= {0x08, 0x1C, 0x2A, 0x08, 0x08};
uint8_t CUSTOM_ENTER_SYMBOL[GOLED_CG_CHAR_DATA_SZ]        = {0x20, 0x70, 0x20, 0x20, 0x3E};
uint8_t CUSTOM_BACK_SYMBOL[GOLED_CG_CHAR_DATA_SZ]         = {0x02, 0x27, 0x22, 0x22, 0x3E};

uint8_t CUSTOM_SOUND_SYMBOL[GOLED_CG_CHAR_DATA_SZ]        = {0x1C ,0x1C ,0x3E ,0x7F ,0x00};
uint8_t CUSTOM_SOUND_ON_SYMBOL[GOLED_CG_CHAR_DATA_SZ]     = {0x14 ,0x49 ,0x22 ,0x1C ,0x00};
uint8_t CUSTOM_SOUND_OFF_SYMBOL[GOLED_CG_CHAR_DATA_SZ]    = {0x14 ,0x08 ,0x14 ,0x00 ,0x00};

const uint8_t  VOIDRON_LOGO [] =
{
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0xFF , 0xFF , 0x03 , 0x03,
		0x33 , 0xF3 , 0xF3 , 0x83 , 0x03 , 0x13 , 0x73 , 0xF3,
		0xC3 , 0x03 , 0x03 , 0x33 , 0xF3 , 0xF3 , 0x83 , 0x03,
		0x13 , 0xF3 , 0xF3 , 0xC3 , 0x03 , 0x03 , 0x03 , 0x03,
		0x03 , 0x03 , 0x03 , 0x03 , 0x03 , 0x03 , 0x03 , 0x03,
		0x03 , 0x03 , 0x03 , 0x03 , 0x03 , 0x03 , 0x03 , 0x03,
		0x03 , 0x03 , 0x03 , 0xC3 , 0xF3 , 0xF3 , 0x13 , 0x03,
		0x83 , 0xF3 , 0xF3 , 0x33 , 0x03 , 0x03 , 0xE3 , 0xF3,
		0x73 , 0x13 , 0x03 , 0x83 , 0xF3 , 0xF3 , 0x33 , 0x03,
		0x03 , 0xFF , 0xFF , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0xFF , 0xFF , 0x00 , 0x00,
		0x00 , 0x01 , 0x07 , 0x3F , 0xFE , 0xF0 , 0xC0 , 0x03,
		0x1F , 0x7F , 0xF8 , 0xE0 , 0x01 , 0x07 , 0x3F , 0xFE,
		0xF0 , 0x80 , 0x03 , 0x1F , 0xFE , 0xF8 , 0xC0 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0xC0 , 0xF8 , 0xFE , 0x1F , 0x03 , 0xC0 , 0xF0 , 0xFE,
		0x3F , 0x07 , 0x01 , 0xE0 , 0xF8 , 0x7F , 0x0F , 0x03,
		0xC0 , 0xF0 , 0xFE , 0x3F , 0x07 , 0x01 , 0x00 , 0x00,
		0x00 , 0xFF , 0xFF , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0xFF , 0xFF , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x07 , 0x1F , 0xFE,
		0xF8 , 0xC0 , 0x03 , 0x0F , 0x7F , 0xFC , 0xE0 , 0x80,
		0x07 , 0x3F , 0xFE , 0xF0 , 0x80 , 0x03 , 0x1F , 0x7F,
		0xF8 , 0xE0 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0xE0 , 0xF8 , 0x7F,
		0x1F , 0x03 , 0xC0 , 0xF0 , 0xFE , 0x1F , 0x07 , 0x80,
		0xE0 , 0xFC , 0x7F , 0x0F , 0x01 , 0xC0 , 0xF8 , 0xFE,
		0x1F , 0x07 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0xFF , 0xFF , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0xFF , 0xFF , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x03 , 0x1F , 0x7F , 0xF8 , 0xE0 , 0x01 , 0x0F , 0x3F,
		0xFC , 0xF0 , 0x80 , 0x07 , 0x3F , 0xFE , 0xF0 , 0xC0,
		0x03 , 0x0F , 0x7F , 0xF8 , 0xE0 , 0x80 , 0x00 , 0x00,
		0x00 , 0x80 , 0xE0 , 0xFC , 0x7F , 0x0F , 0x03 , 0xC0,
		0xF8 , 0xFE , 0x1F , 0x03 , 0x80 , 0xF0 , 0xFC , 0x3F,
		0x0F , 0x01 , 0xE0 , 0xF8 , 0x7F , 0x1F , 0x03 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0xFF , 0xFF , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0xFF , 0xFF , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x03 , 0x0F , 0x7F , 0xFC , 0xE0,
		0x81 , 0x07 , 0x3F , 0xFC , 0xF0 , 0x80 , 0x03 , 0x1F,
		0xFE , 0xF8 , 0xC0 , 0x01 , 0x0F , 0x1F , 0x80 , 0xF0,
		0xFC , 0x3F , 0x0F , 0x01 , 0xE0 , 0xF8 , 0x7F , 0x1F,
		0x03 , 0x80 , 0xF0 , 0xFE , 0x3F , 0x07 , 0x81 , 0xE0,
		0xFC , 0x7F , 0x0F , 0x03 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0xFF , 0xFF , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0xFF , 0xFF , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x01 , 0x0F,
		0x3F , 0xFC , 0xF0 , 0x81 , 0x07 , 0x3F , 0xFE , 0xF0,
		0xC0 , 0x03 , 0x0F , 0x83 , 0xF0 , 0xFE , 0x3F , 0x07,
		0x01 , 0xE0 , 0xF8 , 0x7F , 0x0F , 0x03 , 0xC0 , 0xF0,
		0xFE , 0x3F , 0x07 , 0x80 , 0xF0 , 0xFC , 0x3F , 0x0F,
		0x01 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0xFF , 0xFF , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0xFF , 0xFF , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x01 , 0x07 , 0x3F , 0xFC , 0xF0 , 0x80 , 0x07,
		0xC1 , 0xF0 , 0xFE , 0x3F , 0x07 , 0x80 , 0xE0 , 0xFC,
		0x7F , 0x0F , 0x01 , 0xC0 , 0xF8 , 0xFE , 0x1F , 0x07,
		0x80 , 0xF0 , 0xFC , 0x3F , 0x07 , 0x01 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0xFF , 0xFF , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0xFF , 0xFF , 0xC0 , 0xC0,
		0xC0 , 0xC0 , 0xC0 , 0xC0 , 0xC0 , 0xC0 , 0xC0 , 0xC0,
		0xC0 , 0xC0 , 0xC0 , 0xC0 , 0xC0 , 0xC0 , 0xC0 , 0xC0,
		0xC0 , 0xC0 , 0xC0 , 0xC0 , 0xC1 , 0xC7 , 0xCF , 0xCE,
		0xCF , 0xC7 , 0xC0 , 0xC0 , 0xCC , 0xCF , 0xCF , 0xC1,
		0xC0 , 0xC8 , 0xCF , 0xCF , 0xC3 , 0xC0 , 0xC8 , 0xCE,
		0xCF , 0xC7 , 0xC1 , 0xC0 , 0xC0 , 0xC0 , 0xC0 , 0xC0,
		0xC0 , 0xC0 , 0xC0 , 0xC0 , 0xC0 , 0xC0 , 0xC0 , 0xC0,
		0xC0 , 0xC0 , 0xC0 , 0xC0 , 0xC0 , 0xC0 , 0xC0 , 0xC0,
		0xC0 , 0xFF , 0xFF , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00,
		0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00
};


int8_t vTag_Ssd1309_Key[] = "VOIDRON";
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
* @fn  void GoledDisp_Init (void)
*==============================================================================
* @brief    GoledDisp_Init
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     22-MAR-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void GoledDisp_Init (void)
{
	static ssd1309_base_t set_ssd1309_base_s = {0};

	// >> SSD1309 Init
	set_ssd1309_base_s.GpioInit    = &GoledDispIO_GpioInit;
	set_ssd1309_base_s.CsHigh      = &GoledDispIO_CsHigh;
	set_ssd1309_base_s.CsLow       = &GoledDispIO_CsLow;
	set_ssd1309_base_s.RstHigh     = &GoledDispIO_RstHigh;
	set_ssd1309_base_s.RstLow      = &GoledDispIO_RstLow;
	set_ssd1309_base_s.RdHigh      = &GoledDispIO_RdHigh;
	set_ssd1309_base_s.RdLow       = &GoledDispIO_RdLow;
	set_ssd1309_base_s.WrHigh      = &GoledDispIO_WrHigh;
	set_ssd1309_base_s.WrLow       = &GoledDispIO_WrLow;
	set_ssd1309_base_s.DcHigh      = &GoledDispIO_DcHigh;
	set_ssd1309_base_s.DcLow       = &GoledDispIO_DcLow;
	set_ssd1309_base_s.WrDatBus    = &GoledDispIO_WrDatBus;
	set_ssd1309_base_s.DelayMs     = &SysTick_Delay;
	SSD1309_BaseInit(set_ssd1309_base_s);

	(void)SSD1309_Enable(vTag_Ssd1309_Key);
	SSD1309_DefaultConfig();
}// >> End of GoledDisp_Init

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void GoledDisp_Refresh (void)
*==============================================================================
* @brief    GoledDisp_Refresh
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     22-MAR-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void GoledDisp_Refresh (void)
{
	SSD1309_UpdatePrcs();
}// >> End of GoledDisp_Refresh

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void GoledDisp_Clear (void)
*==============================================================================
* @brief    GoledDisp_Clear
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     22-MAR-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void GoledDisp_Clear (void)
{
	SSD1309_BlankDisp();
}// >> End of GoledDisp_Clear

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void GoledDisp_Flash (void)
*==============================================================================
* @brief    GoledDisp_Flash
*           ---
*           ---
*           ---
* @note     None
* @param    None
* @retval   None
* @author   MK
* @date     22-MAR-2021 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void GoledDisp_Flash (void)
{
	SSD1309_FlashDisp();
}// >> End of GoledDisp_Flash

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t GoledDisp_WrTxtSmall(uint8_t line,
*						           uint8_t pos,
*		                           uint8_t *data_ptr,
*		                           uint8_t data_sz)
*==============================================================================
* @brief    GoledDisp_WrTxtSmall
*           ---
*           ---
*           ---
* @note     None
* @param    line (1 to 8)
* @param    pos  (1 to 21)
* @param   *data_ptr
* @param    data_sz
* @retval   error_f
* @author   MK
* @date     20-OCT-2023 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t GoledDisp_WrTxtSmall(uint8_t line,
						    uint8_t pos,
		                    uint8_t *data_ptr,
		                    uint8_t data_sz)
{
	bool_t error_f = FALSE;
	font_types_t font = FONT_TYPE_5x7;
	uint8_t str_buf[GOLED_5X7_CHAR_LINE_SZ + 1];
	uint8_t avl_char_sz = 0;

	if((line == 0)                        ||
	   (line > GOLED_MAX_LINE_COUNT)      ||
	   (pos  == 0)                        ||
	   (pos > GOLED_5X7_CHAR_LINE_SZ)     ||
	   (data_sz > GOLED_5X7_CHAR_LINE_SZ))
	{
		error_f = TRUE;
	}
	else
	{
		(void)memset(str_buf, 0, sizeof(str_buf));

		avl_char_sz = (GOLED_5X7_CHAR_LINE_SZ - pos + 1);
		if(data_sz < avl_char_sz)
		{
			(void)memcpy(str_buf, data_ptr, data_sz);
		}
		else
		{
			(void)memcpy(str_buf, data_ptr, avl_char_sz);
		}
		SSD1309_WrtTextPro(font, (line - 1), (pos - 1), str_buf, FALSE);
	}


	return(error_f);
}// >> End of GoledDisp_WrTxtSmall

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t GoledDisp_WrTxtMedium(uint8_t line,
*						            uint8_t pos,
*		                            uint8_t *data_ptr,
*		                            uint8_t data_sz)
*==============================================================================
* @brief    GoledDisp_WrTxtMedium
*           ---
*           ---
*           ---
* @note     None
* @param    line (1 to 8)
* @param    pos  (1 to 21)
* @param   *data_ptr
* @param    data_sz
* @retval   error_f
* @author   MK
* @date     20-OCT-2023 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t GoledDisp_WrTxtMedium(uint8_t line,
						     uint8_t pos,
		                     uint8_t *data_ptr,
		                     uint8_t data_sz)
{
	bool_t error_f = FALSE;
	font_types_t font = FONT_TYPE_10x14;
	uint8_t str_buf[GOLED_10X14_CHAR_LINE_SZ + 1];
	uint8_t avl_char_sz = 0;

	if((line == 0)                          ||
	   (line > GOLED_MAX_LINE_COUNT)        ||
	   (pos  == 0)                          ||
	   (pos  > GOLED_10X14_CHAR_LINE_SZ)    ||
	   (data_sz > GOLED_10X14_CHAR_LINE_SZ))
	{
		error_f = TRUE;
	}
	else
	{
		(void)memset(str_buf, 0, sizeof(str_buf));

		avl_char_sz = (GOLED_10X14_CHAR_LINE_SZ - pos + 1);
		if(data_sz < avl_char_sz)
		{
			(void)memcpy(str_buf, data_ptr, data_sz);
		}
		else
		{
			(void)memcpy(str_buf, data_ptr, avl_char_sz);
		}
		SSD1309_WrtTextPro(font, (line - 1), (pos - 1), str_buf, FALSE);
	}


	return(error_f);
}// >> End of GoledDisp_WrTxtMedium

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  bool_t GoledDisp_WrSymbolSmall(uint8_t line,
*						              uint8_t pos,
*		                              uint8_t *data_ptr,
*		                              uint8_t data_sz)
*==============================================================================
* @brief    GoledDisp_WrSymbolSmall
*           ---
*           ---
*           ---
* @note     None
* @param    line (1 to 8)
* @param    pos  (1 to 21)
* @param   *data_ptr
* @param    data_sz
* @retval   error_f
* @author   MK
* @date     22-OCT-2023 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
bool_t GoledDisp_WrSymbolSmall(uint8_t  line,
						       uint8_t  pos,
		                       uint8_t *data_ptr,
		                       uint8_t  data_sz)
{
	bool_t error_f = FALSE;
	font_types_t font = FONT_TYPE_5x7;
	uint8_t cg_char_buf[GOLED_CG_CHAR_DATA_SZ + 1];

	if((line == 0)                          ||
	   (line > GOLED_MAX_LINE_COUNT)        ||
	   (pos  == 0)                          ||
	   (pos  > GOLED_5X7_CHAR_LINE_SZ)      ||
	   (data_sz > GOLED_CG_CHAR_DATA_SZ))
	{
		error_f = TRUE;
	}
	else
	{
		(void)memset(cg_char_buf, 0, sizeof(cg_char_buf));

		if(data_sz < GOLED_CG_CHAR_DATA_SZ)
		{
			(void)memcpy(cg_char_buf, data_ptr, data_sz);
		}
		else
		{
			(void)memcpy(cg_char_buf, data_ptr, GOLED_CG_CHAR_DATA_SZ);
		}

		SSD1309_WrtCGChar(font, (line - 1), (pos - 1), cg_char_buf);
	}

	return(error_f);
}// >> End of GoledDisp_WrSymbolSmall

/**
*==============================================================================
*                         \V/ Function Information
*------------------------------------------------------------------------------
* @fn  void GoledDisp_LoadImage (const uint8_t *image_data_ptr)
*==============================================================================
* @brief    GoledDisp_LoadImage
*           ---
*           ---
*           ---
* @note     None
* @param   *image_data_ptr
* @retval   None
* @author   MK
* @date     20-OCT-2023 // >> Enter Last Change Date
* @remark   Designed & Developed by Voidron Co.
*==============================================================================
*/
void GoledDisp_LoadImage (const uint8_t *image_data_ptr)
{
	SSD1309_LoadImage(image_data_ptr);
}// >> End of GoledDisp_LoadImage

/**
 *==============================================================================
 *                         \V/ Function Information
 *------------------------------------------------------------------------------
 * @fn  void EnterZoneL3_PromptScreen(uint8_t prompt_code)
 *==============================================================================
 * @brief    EnterZoneL3_PromptScreen
 *           ---
 *           ---
 *           ---
 * @note     None
 * @param    prompt_code
 * @retval   None
 * @author   MK
 * @date     20-OCT-2023
 * @remark   Designed & Developed by Voidron Co.
 *==============================================================================
 */
void GoledDisp_LoadPrompt(goled_prompt_msg_t goled_prompt_msg)
{
	uint8_t wr_pos = 1;


	if(goled_prompt_msg == PROMPT_SUCCESS)
	{
		wr_pos = 3;
		GoledDisp_WrTxtMedium(GOLED_LINE_4, wr_pos, (uint8_t*)"Success!", strlen("Success!"));
	}
	else if(goled_prompt_msg == PROMPT_INVALID)
	{
		wr_pos = 3;
		GoledDisp_WrTxtMedium(GOLED_LINE_4, wr_pos, (uint8_t*)"Invalid!", strlen("Invalid!"));
	}
	else if(goled_prompt_msg == PROMPT_SAVED)
	{
		wr_pos = 4;
		GoledDisp_WrTxtMedium(GOLED_LINE_4, wr_pos, (uint8_t*)"Saved!", strlen("Saved!"));
	}
	else if(goled_prompt_msg == PROMPT_MISMATCH)
	{
		wr_pos = 2;
		GoledDisp_WrTxtMedium(GOLED_LINE_4, wr_pos, (uint8_t*)"Mismatch!", strlen("Mismatch!"));
	}
	else if(goled_prompt_msg == PROMPT_ERROR)
	{
		wr_pos = 4;
		GoledDisp_WrTxtMedium(GOLED_LINE_4, wr_pos, (uint8_t*)"Error!", strlen("Error!"));
	}
	else if(goled_prompt_msg == PROMPT_DENIED)
	{
		wr_pos = 3;
		GoledDisp_WrTxtMedium(GOLED_LINE_4, wr_pos, (uint8_t*)"Denied!", strlen("Denied!"));
	}
	else if(goled_prompt_msg == PROMPT_NOMEM)
	{
		wr_pos = 3;
		GoledDisp_WrTxtMedium(GOLED_LINE_4, wr_pos, (uint8_t*)"No Mem!", strlen("No Mem!"));
	}
	else
	{
		// Nothing
	}

}// >> End of GoledDisp_LoadPrompt


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
