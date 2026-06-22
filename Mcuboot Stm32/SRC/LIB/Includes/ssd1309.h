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
* @file      ssd1309.h
* @brief     API of Graphic OLED Display Controller SSD1309
* @version   V1.0.2
* @author    MK
* @date      23-OCT-2024
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


#ifndef SSD1309_H_
#define SSD1309_H_

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
#define COL_VAL_MAX                             (128U)
#define ROW_VAL_MAX                             (64U)
#define BITS_PER_PAGE                           (8U)
#define PAGE_VAL_MAX                            (ROW_VAL_MAX / BITS_PER_PAGE)

#define DFLT_COL_START_ADDR                     (0x00U)
#define DFLT_COL_END_ADDR                       (0x7FU)
#define DFLT_ROW_START_ADDR                     (0x00U)
#define DFLT_ROW_END_ADDR                       (0x3FU)
#define DFLT_PG_START_ADDR                      (0x00U)
#define DFLT_PG_END_ADDR                        (0x07U)
#define DFLT_MUX_RATIO_MIN                      (0x0FU)
#define DFLT_MUX_RATIO_MAX                      (0x3FU)
#define DFLT_CLK_VAL_MIN                        (0x00U)
#define DFLT_CLK_VAL_MAX                        (0x0FU)
#define DFLT_PHASE_PERIOD_MIN                   (0x01U)
#define DFLT_PHASE_PERIOD_MAX                   (0x0FU)


//#############################################################################
//                            \V/ Global MacroS
//#############################################################################



//#############################################################################
//                           \V/ Global Data TypeS
//#############################################################################
typedef void (*Ssd1309GpioInitFptrT) (void);
typedef void (*Ssd1309CsHighFptrT) (void);
typedef void (*Ssd1309CsLowFptrT) (void);
typedef void (*Ssd1309RstHighFptrT) (void);
typedef void (*Ssd1309RstLowFptrT) (void);
typedef void (*Ssd1309RdHighFptrT) (void);
typedef void (*Ssd1309RdLowFptrT) (void);
typedef void (*Ssd1309WrHighFptrT) (void);
typedef void (*Ssd1309WrLowFptrT) (void);
typedef void (*Ssd1309DcHighFptrT) (void);
typedef void (*Ssd1309DcLowFptrT) (void);
typedef void (*Ssd1309WrDatBusFptrT) (uint8_t wr_data);
typedef void (*Ssd1309DelayMsFptrT) (uint32_t delay_ms);

typedef struct
{
	Ssd1309GpioInitFptrT     GpioInit;
	Ssd1309CsHighFptrT       CsHigh;
	Ssd1309CsLowFptrT        CsLow;
	Ssd1309RstHighFptrT      RstHigh;
	Ssd1309RstLowFptrT       RstLow;
	Ssd1309RdHighFptrT       RdHigh;
	Ssd1309RdLowFptrT        RdLow;
	Ssd1309WrHighFptrT       WrHigh;
	Ssd1309WrLowFptrT        WrLow;
	Ssd1309DcHighFptrT       DcHigh;
	Ssd1309DcLowFptrT        DcLow;
	Ssd1309WrDatBusFptrT     WrDatBus;
	Ssd1309DelayMsFptrT      DelayMs;
}ssd1309_base_t;

typedef enum
{
    DISP_RAM_CONTENT = 0,
    DISP_ENTIRE_ON   = 1
}entire_disp_on_t;

typedef enum
{
    DISP_POLARITY_NORMAL   = 0,
	DISP_POLARITY_INVERSE  = 1
}disp_polarity_sel_t;

typedef enum
{
    DISP_OFF = 0,
    DISP_ON  = 1
}disp_ctrl_t;

typedef enum
{
    HORZ_ADDR_MODE = 0,
    VERT_ADDR_MODE = 1,
    PAGE_ADDR_MODE = 2
}mem_addr_mode_t;

typedef enum
{
    VCOMH_DESEL_LEVEL_0p64 = 0,
	VCOMH_DESEL_LEVEL_0p78 = 1,
	VCOMH_DESEL_LEVEL_0p84 = 2
}vcomh_deselect_level_t;

typedef enum
{
    MAP_COL0_TO_COL127   = 0,
	MAP_COL127_TO_COL0   = 1,
}col_map_t;

typedef enum
{
    MAP_ROW0_TO_ROW7   = 0,
	MAP_ROW7_TO_ROW0   = 1,
}row_map_t;

typedef enum
{
	FONT_TYPE_5x7,
	FONT_TYPE_10x14,
	FONT_TYPE_20x28
}font_types_t;


//#############################################################################
//                            \V/ Global VariableS
//#############################################################################




//#############################################################################
//                        \V/ Global Function PrototypeS
//#############################################################################

//=============================================================================
//                         \V/ SSD1309_Enable
//=============================================================================
/*!
* @fn       bool_t SSD1309_Enable (int8_t *vtag_ptr)
* @brief    This function enables this library.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Enabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t SSD1309_Enable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ SSD1309_Disable
//=============================================================================
/*!
* @fn       bool_t SSD1309_Disable (int8_t *vtag_ptr)
* @brief    This function disables this library.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Disabled successfully)
* @warning  All other functions won't work properly without Enabling.
* @note     Correct vTag require to pass.
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t SSD1309_Disable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ SSD1309_BaseInit
//=============================================================================
/*!
* @fn       void SSD1309_BaseInit (ssd1309_base_t set_ssd1309_base_s)
* @brief    SSD1309_BaseInit
* @param    set_ssd1309_base_s
* @retval   None
* @warning  if any member of set_ssd1309_base_s is NULL then routine will not
*           move ahead. Remains in while loop.
* @note     None
* @author   MK
* @date     29-APR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_BaseInit (ssd1309_base_t set_ssd1309_base_s);

//=============================================================================
//                         \V/ SSD1309_DefaultConfig
//=============================================================================
/*!
* @fn       void SSD1309_DefaultConfig (void)
* @brief    SSD1309_DefaultConfig
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     21-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_DefaultConfig (void);

//=============================================================================
//                         \V/ SSD1309_Rst
//=============================================================================
/*!
* @fn       void SSD1309_Rst (void)
* @brief    SSD1309_Rst
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_Rst (void);

//=============================================================================
//                         \V/ SSD1309_WrCmd
//=============================================================================
/*!
* @fn       void SSD1309_WrCmd (uint8_t wr_cmd)
* @brief    SSD1309_WrCmd
* @param    wr_cmd
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_WrCmd (uint8_t wr_cmd);

//=============================================================================
//                         \V/ SSD1309_WrDat
//=============================================================================
/*!
* @fn       void SSD1309_WrDat (uint8_t wr_dat)
* @brief    SSD1309_WrDat
* @param    wr_dat
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_WrDat (uint8_t wr_dat);

//=============================================================================
//                         \V/ SSD1309_SetContrast
//=============================================================================
/*!
* @fn       void SSD1309_SetContrast (uint8_t set_contrast)
* @brief    SSD1309_SetContrast
* @param    set_contrast
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_SetContrast (uint8_t set_contrast);

//=============================================================================
//                         \V/ SSD1309_EntireDispON
//=============================================================================
/*!
* @fn       void SSD1309_EntireDispON (entire_disp_on_t entire_disp_on)
* @brief    SSD1309_EntireDispON
* @param    entire_disp_on
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_EntireDispON (entire_disp_on_t entire_disp_on);


//=============================================================================
//                         \V/ SSD1309_SetDispPolarity
//=============================================================================
/*!
* @fn       void SSD1309_SetDispPolarity (disp_polarity_sel_t disp_polarity_sel)
* @brief    SSD1309_SetDispPolarity
* @param    disp_polarity_sel
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_SetDispPolarity (disp_polarity_sel_t disp_polarity_sel);

//=============================================================================
//                         \V/ SSD1309_SetDispPolarity
//=============================================================================
/*!
* @fn       void SSD1309_SetDispCtrl (disp_ctrl_t disp_ctrl
* @brief    SSD1309_SetDispCtrl
* @param    disp_ctrl
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_SetDispCtrl (disp_ctrl_t disp_ctrl);

//=============================================================================
//                         \V/ SSD1309_SetStartCol
//=============================================================================
/*!
* @fn       void SSD1309_SetStartCol (uint8_t start_col)
* @brief    SSD1309_SetStartCol
* @param    start_col
* @retval   None
* @warning  None
* @note     Range: DISP_COL_START_ADDR <= start_col <= DISP_COL_END_ADDR
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_SetStartCol (uint8_t start_col);

//=============================================================================
//                         \V/ SSD1309_SetColAddr
//=============================================================================
/*!
* @fn       void SSD1309_SetColAddr (uint8_t col_start, uint8_t col_end)
* @brief    SSD1309_SetColAddr
* @param    col_start
* @param    col_end
* @retval   None
* @warning  None
* @note     Range: DISP_COL_START_ADDR <= col_start <= DISP_COL_END_ADDR,
*                  DISP_COL_START_ADDR <= col_end   <= DISP_COL_END_ADDR,
*                  col_start <= col_end
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_SetColAddr (uint8_t col_start, uint8_t col_end);

//=============================================================================
//                         \V/ SSD1309_SetStartPg
//=============================================================================
/*!
* @fn       void SSD1309_SetStartPg (uint8_t strt_pg_addr)
* @brief    SSD1309_SetPgAddr
* @param    strt_pg_addr
* @retval   None
* @warning  None
* @note     Range : 0 to 7d;
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_SetStartPg (uint8_t strt_pg_addr);

//=============================================================================
//                         \V/ SSD1309_SetPgAddr
//=============================================================================
/*!
* @fn       void SSD1309_SetPgAddr (uint8_t pg_start, uint8_t pg_end)
* @brief    SSD1309_SetPgAddr
* @param    pg_start
* @param    pg_end
* @retval   None
* @warning  None
* @note     Range : 0 to 7d;
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_SetPgAddr (uint8_t pg_start, uint8_t pg_end);

//=============================================================================
//                         \V/ SSD1309_SetMemAddrMode
//=============================================================================
/*!
* @fn       void SSD1309_SetMemAddrMode (mem_addr_mode_t mem_addr_mode)
* @brief    SSD1309_SetMemAddrMode
* @param    mem_addr_mode
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_SetMemAddrMode (mem_addr_mode_t mem_addr_mode);

//=============================================================================
//                         \V/ SSD1309_SetStartLine
//=============================================================================
/*!
* @fn       void SSD1309_SetStartLine (uint8_t start_line)
* @brief    SSD1309_SetStartLine
* @param    start_line
* @retval   None
* @warning  None
* @note     Range: DISP_ROW_START_ADDR <= start_line <= DISP_ROW_END_ADDR
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_SetStartLine (uint8_t start_line);

//=============================================================================
//                         \V/ SSD1309_SetMuxRatio
//=============================================================================
/*!
* @fn       void SSD1309_SetMuxRatio (uint8_t mux_ratio)
* @brief    SSD1309_SetMuxRatio
* @param    mux_ratio
* @retval   None
* @warning  None
* @note     Range: DISP_MUX_RATIO_MIN <= mux_ratio <= DISP_MUX_RATIO_MAX
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_SetMuxRatio (uint8_t mux_ratio);

//=============================================================================
//                         \V/ SSD1309_SetDispOffset
//=============================================================================
/*!
* @fn       void SSD1309_SetDispOffset (uint8_t disp_offset)
* @brief    SSD1309_SetDispOffset
* @param    disp_offset
* @retval   None
* @warning  None
* @note     Range: DISP_ROW_START_ADDR <= disp_offset <= DISP_ROW_END_ADDR
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_SetDispOffset (uint8_t disp_offset);

//=============================================================================
//                         \V/ SSD1309_SetDispClk
//=============================================================================
/*!
* @fn       void SSD1309_SetDispClk (uint8_t disp_osc_freq, uint8_t disp_clk_div_ratio)
* @brief    SSD1309_SetDispClk
* @param    disp_clk_div_ratio
* @param    disp_osc_freq
* @retval   None
* @warning  None
* @note     Range: clk_val_min <= disp_clk_div_ratio, disp_osc_freq <= clk_val_max
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_SetDispClk (uint8_t disp_osc_freq, uint8_t disp_clk_div_ratio);

//=============================================================================
//                         \V/ SSD1309_SetPreChgPeriod
//=============================================================================
/*!
* @fn       void SSD1309_SetPreChgPeriod (uint8_t phase2_period, uint8_t phase1_period)
* @brief    SSD1309_SetPreChgPeriod
* @param    phase1_period
* @param    phase2_period
* @retval   None
* @warning  None
* @note     Range: phase_period_min <= phase1_period, phase2_period <= phase_period_max
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_SetPreChgPeriod (uint8_t phase2_period, uint8_t phase1_period);

//=============================================================================
//                         \V/ SSD1309_SetVcomh
//=============================================================================
/*!
* @fn       void SSD1309_SetVcomh (vcomh_deselect_level_t vcomh_deselect_level)
* @brief    SSD1309_SetVcomh
* @param    vcomh_deselect_level
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_SetVcomh (vcomh_deselect_level_t vcomh_deselect_level);

//=============================================================================
//                         \V/ SSD1309_SetVcomh
//=============================================================================
/*!
* @fn       void SSD1309_SetColMap (col_map_t set_col_map)
* @brief    SSD1309_SetColMap
* @param    set_col_map
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_SetColMap (col_map_t set_col_map);

//=============================================================================
//                         \V/ SSD1309_SetVcomh
//=============================================================================
/*!
* @fn       void SSD1309_SetRowMap (row_map_t set_row_map)
* @brief    SSD1309_SetRowMap
* @param    set_row_map
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     17-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_SetRowMap (row_map_t set_row_map);

//=============================================================================
//                         \V/ SSD1309_ClrRam
//=============================================================================
/*!
* @fn       void SSD1309_ClrRam (void)
* @brief    SSD1309_ClrRam
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     21-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_ClrRam (void);

//=============================================================================
//                         \V/ SSD1309_LoadImage
//=============================================================================
/*!
* @fn       void SSD1309_LoadImage(const uint8_t *image_data_ptr)
* @brief    SSD1309_LoadImage
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     21-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_LoadImage(const uint8_t *image_data_ptr);

//=============================================================================
//                         \V/ SSD1309_Update
//=============================================================================
/*!
* @fn       void SSD1309_Update(void)
* @brief    SSD1309_Update
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     21-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_Update(void);

//=============================================================================
//                         \V/ SSD1309_UpdatePrcs
//=============================================================================
/*!
* @fn       bool_t SSD1309_UpdatePrcs(void)
* @brief    SSD1309_UpdatePrcs
* @param    None
* @retval   None
* @warning  None
* @note     Updates Page by page
* @author   MK
* @date     21-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t SSD1309_UpdatePrcs(void);

//=============================================================================
//                         \V/ SSD1309_BlankDisp
//=============================================================================
/*!
* @fn       void SSD1309_BlankDisp(void)
* @brief    SSD1309_BlankDisp
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     21-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_BlankDisp(void);

//=============================================================================
//                         \V/ SSD1309_FlashDisp
//=============================================================================
/*!
* @fn       void SSD1309_FlashDisp(void)
* @brief    SSD1309_FlashDisp
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     21-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_FlashDisp(void);

//=============================================================================
//                         \V/ SSD1309_InvertDisp
//=============================================================================
/*!
* @fn       void SSD1309_InvertDisp(void)
* @brief    SSD1309_InvertDisp
* @param    None
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     21-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_InvertDisp(void);

//=============================================================================
//                         \V/ SSD1309_DrawXLine
//=============================================================================
/*!
* @fn       void SSD1309_DrawXLine(const uint8_t x1, const uint8_t x2, const uint8_t y)
* @brief    SSD1309_DrawXLine
* @param    x1
* @param    x2
* @param    y
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     21-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_DrawXLine(uint8_t x1, uint8_t x2, const uint8_t y);

//=============================================================================
//                         \V/ SSD1309_DrawYLine
//=============================================================================
/*!
* @fn       void SSD1309_DrawYLine(uint8_t y1, uint8_t y2, const uint8_t x)
* @brief    SSD1309_DrawYLine
* @param    y1
* @param    y2
* @param    x
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     21-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_DrawYLine(uint8_t y1, uint8_t y2, const uint8_t x);

//=============================================================================
//                         \V/ SSD1309_DrawRect
//=============================================================================
/*!
* @fn       void SSD1309_DrawRect(const uint8_t x_origin, const uint8_t y_origin,
*		                          const uint8_t width, const uint8_t height)
* @brief    SSD1309_DrawRect
* @param    x_origin
* @param    y_origin
* @param    width
* @param    height
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     21-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_DrawRect(const uint8_t x_origin, const uint8_t y_origin,
		                     const uint8_t width, const uint8_t height);

//=============================================================================
//                         \V/ SSD1309_WrtText
//=============================================================================
/*!
* @fn       void SSD1309_WrtText(font_types_t font_type,
		                         uint8_t address,
		                         uint8_t *ascii_str_ptr)
* @brief    SSD1309_WrtText
* @param    font_type = FONT_TYPE_5x7, FONT_TYPE_10x14
* @param    address = address of character on LCD
* @param    ascii_str_ptr = Null terminated character string
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     21-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_WrtText(font_types_t font_type,
		                    uint8_t address,
		                    uint8_t *ascii_str_ptr);

//=============================================================================
//                         \V/ SSD1309_WrtTextPro
//=============================================================================
/*!
* @fn       void SSD1309_WrtTextPro(font_types_t font_type,
*		                            uint8_t pg_no,
*		                            uint8_t char_pos,
*		                            uint8_t *ascii_str_ptr,
*		                            bool_t invert_on_f)
* @brief    SSD1309_WrtTextPro
* @param    font_type = FONT_TYPE_5x7, FONT_TYPE_10x14
* @param    pg_no = Row number
* @param    char_pos = column position
* @param    ascii_str_ptr = Null terminated character string
* @param    invert_on_f : invert if TRUE
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     21-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_WrtTextPro(font_types_t font_type,
		                       uint8_t pg_no,
		                       uint8_t char_pos,
		                       uint8_t *ascii_str_ptr,
		                       bool_t invert_on_f);

//=============================================================================
//                         \V/ SSD1309_MoveCursor
//=============================================================================
/*!
* @fn void SSD1309_MoveCursor(font_types_t font_type,
*		                      uint8_t pg_no,
*		                      uint8_t char_pos,
*		                      bool_t cursor_visible_f)
* @brief    SSD1309_MoveCursor
* @param    font_type = FONT_TYPE_5x7, FONT_TYPE_10x14
* @param    pg_no = Row number
* @param    char_pos = column position
* @param    cursor_visible_f : Visible if TRUE
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     21-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_MoveCursor(font_types_t font_type,
		                       uint8_t pg_no,
		                       uint8_t char_pos,
		                       bool_t cursor_visible_f);

//=============================================================================
//                         \V/ SSD1309_WrtCGChar
//=============================================================================
/*!
* @fn       void SSD1309_WrtCGChar(font_types_t font_type,
		                           uint8_t pg_no,
		                           uint8_t char_pos,
		                           uint8_t *cg_char_ptr)
* @brief    SSD1309_WrtCGChar
* @param    font_type = FONT_TYPE_5x7, FONT_TYPE_10x14, FONT_TYPE_20x28
* @param    pg_no = Row number
* @param    char_pos = column position
* @param    cg_char_ptr : pointer to binary value of characters to be displayed.
* @retval   None
* @warning  None
* @note     None
* @author   MK
* @date     21-MAR-2021
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void SSD1309_WrtCGChar(font_types_t font_type,
		                      uint8_t pg_no,
		                      uint8_t char_pos,
		                      uint8_t *cg_char_ptr);

/*
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     17-MAR-2021
* @brief    Initial Release
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.1
* @author   MK
* @date     29-APR-2021
* @brief    Following Function Removed
*           SSD1309_SetFptr
*           SSD1309_Init
*           Following Function Added
*           SSD1309_BaseInit
*           SSD1309_DefaultConfig
*------------------------------------------------------------------------------
* @version  V1.0.2
* @author   MK
* @date     23-OCT-2024
* @brief    Changes on following made
*           const uint8_t FONT_5X7[][5]
*           const uint8_t FONT_10X14[][10]
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
#endif // >> End of SSD1309_H_
/*! <h2><center>           (C) VOIDRON CO. 2020-21.           </center></h2> */
/*                        086 079 073 068 082 079 078                        */

