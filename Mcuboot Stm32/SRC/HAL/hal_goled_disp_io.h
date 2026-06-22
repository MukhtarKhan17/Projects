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
* @file      hal_goled_disp_io.h
* @brief     HAL Graphic OLED Display IO Interface File
*            + Contains interface to control IOs
*            + GPIO Initialization
*            + Reset High/Low routine
*            + Enable/Disable routine
*            + Data/Command Read/Write routines
* @version   V1.0.0
* @author    MK
* @date      17-MAR-2021
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


#ifndef HAL_GOLED_DISP_IO_H_
#define HAL_GOLED_DISP_IO_H_

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

//#############################################################################
//                             \V/ Include SectioN
//#############################################################################
#include "vdef_types.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"


//#############################################################################
//                            \V/ Global DefineS
//#############################################################################
#define GOLED_DISP_CS_PORT_CLK	       (RCC_APB2Periph_GPIOB)
#define GOLED_DISP_CS_PORT		       (GPIOB)
#define GOLED_DISP_CS_PIN              (GPIO_Pin_7)

#define GOLED_DISP_RST_PORT_CLK	       (RCC_APB2Periph_GPIOC)
#define GOLED_DISP_RST_PORT		       (GPIOC)
#define GOLED_DISP_RST_PIN			   (GPIO_Pin_1)

#define GOLED_DISP_RD_PORT_CLK	       (RCC_APB2Periph_GPIOB)
#define GOLED_DISP_RD_PORT		       (GPIOB)
#define GOLED_DISP_RD_PIN              (GPIO_Pin_1)

#define GOLED_DISP_RW_PORT_CLK	       (RCC_APB2Periph_GPIOB)
#define GOLED_DISP_RW_PORT		       (GPIOB)
#define GOLED_DISP_RW_PIN              (GPIO_Pin_6)

#define GOLED_DISP_DC_PORT_CLK	       (RCC_APB2Periph_GPIOB)
#define GOLED_DISP_DC_PORT		       (GPIOB)
#define GOLED_DISP_DC_PIN              (GPIO_Pin_0)

#define GOLED_DISP_D0_PORT_CLK	       (RCC_APB2Periph_GPIOC)
#define GOLED_DISP_D0_PORT		       (GPIOC)
#define GOLED_DISP_D0_PIN              (GPIO_Pin_6)

#define GOLED_DISP_D1_PORT_CLK	       (RCC_APB2Periph_GPIOC)
#define GOLED_DISP_D1_PORT		       (GPIOC)
#define GOLED_DISP_D1_PIN              (GPIO_Pin_7)

#define GOLED_DISP_D2_PORT_CLK	       (RCC_APB2Periph_GPIOC)
#define GOLED_DISP_D2_PORT		       (GPIOC)
#define GOLED_DISP_D2_PIN              (GPIO_Pin_8)

#define GOLED_DISP_D3_PORT_CLK	       (RCC_APB2Periph_GPIOC)
#define GOLED_DISP_D3_PORT		       (GPIOC)
#define GOLED_DISP_D3_PIN              (GPIO_Pin_9)

#define GOLED_DISP_D4_PORT_CLK	       (RCC_APB2Periph_GPIOC)
#define GOLED_DISP_D4_PORT		       (GPIOC)
#define GOLED_DISP_D4_PIN              (GPIO_Pin_10)

#define GOLED_DISP_D5_PORT_CLK	       (RCC_APB2Periph_GPIOC)
#define GOLED_DISP_D5_PORT		       (GPIOC)
#define GOLED_DISP_D5_PIN              (GPIO_Pin_11)

#define GOLED_DISP_D6_PORT_CLK	       (RCC_APB2Periph_GPIOC)
#define GOLED_DISP_D6_PORT		       (GPIOC)
#define GOLED_DISP_D6_PIN              (GPIO_Pin_12)

#define GOLED_DISP_D7_PORT_CLK	       (RCC_APB2Periph_GPIOC)
#define GOLED_DISP_D7_PORT		       (GPIOC)
#define GOLED_DISP_D7_PIN              (GPIO_Pin_13)



//#############################################################################
//                            \V/ Global MacroS
//#############################################################################



//#############################################################################
//                           \V/ Global Data TypeS
//#############################################################################



//#############################################################################
//                            \V/ Global VariableS
//#############################################################################




//#############################################################################
//                        \V/ Global Function PrototypeS
//#############################################################################
extern void GoledDispIO_GpioInit (void);

extern void GoledDispIO_CsHigh (void);
extern void GoledDispIO_CsLow (void);

extern void GoledDispIO_RstHigh (void);
extern void GoledDispIO_RstLow (void);

extern void GoledDispIO_RdHigh (void);
extern void GoledDispIO_RdLow (void);

extern void GoledDispIO_WrHigh (void);
extern void GoledDispIO_WrLow (void);

extern void GoledDispIO_DcHigh (void);
extern void GoledDispIO_DcLow (void);

extern void GoledDispIO_WrDatBus (uint8_t wr_data);
extern uint8_t GoledDispIO_RdDatBus (void);

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
#endif // >> End of HAL_GOLED_DISP_IO_H_
/*! <h2><center>           (C) VOIDRON CO. 2020-21.           </center></h2> */
/*                        086 079 073 068 082 079 078                        */

