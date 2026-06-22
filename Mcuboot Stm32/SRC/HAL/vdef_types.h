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
* @file      vdef_types.h
* @brief     This file contains customized general purpose defines and data types
* @version   V1.0.2
* @author    MK
* @date      21-FEB-2021
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
* <h2><center>             (C) VOIDRON CO. 2019-21.             </center></h2>
*/
//=============================================================================


#ifndef __VDEF_TYPES_H_
#define __VDEF_TYPES_H_

#ifndef __VOIDRON__
#define __VOIDRON__          
#endif

//=============================================================================
//                             \V/ Include SectioN
//=============================================================================



//=============================================================================
//                            \V/ Global DefineS
//=============================================================================

#ifndef	TRUE
#define TRUE	             (1U)
#endif


#ifndef	FALSE
#define FALSE	             (0U)
#endif


#ifndef	NULL
#define NULL	             (0)
#endif

#ifndef	NULL_CHAR_SZ
#define NULL_CHAR_SZ        (1U)
#endif

#ifndef int8_t
typedef signed char          int8_t;
#endif

#ifndef int16_t
typedef signed short int     int16_t;
#endif

#ifndef int32_t
typedef signed long     	 int32_t;
#endif

#ifndef int64_t
typedef signed long long     int64_t;
#endif


#ifndef uint8_t
typedef unsigned char        uint8_t;
#endif

#ifndef uint16_t
typedef unsigned short int   uint16_t;
#endif

#ifndef uint32_t
typedef unsigned long   	 uint32_t;
#endif

#ifndef uint64_t
typedef unsigned long long   uint64_t;
#endif

#ifndef float32_t
typedef float                float32_t;
#endif

#ifndef float64_t
typedef double               float64_t;
#endif

#ifndef bool_t
typedef unsigned char        bool_t;
#endif


//=============================================================================
//                            \V/ Global MacroS
//=============================================================================



//=============================================================================
//                           \V/ Global Data TypeS
//=============================================================================




//=============================================================================
//                            \V/ Global VariableS
//=============================================================================


//=============================================================================
//                        \V/ Global Function PrototypeS
//=============================================================================



/*
*##############################################################################
*                             \V/ File HistorY
*##############################################################################
* @version  V1.0.0
* @author   MK
* @date     30-OCT-2019
* @brief    Initial Release
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.1
* @author   MK
* @date     26-JAN-2021
* @brief    Bug_Fix-1: "typedef void (*FuncPtr) (void)" removed. As function
*           pointer cannot be generalized
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.0.2
* @author   MK
* @date     21-FEB-2021
* @brief    Complete file updated.
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
* @version  V1.X.X
* @author   MK
* @date     DD-MMM-YYYY
* @brief    ---
*           ---
*           ---
*           ---
*------------------------------------------------------------------------------
*##############################################################################
*================================End of FilE===================================
*##############################################################################
*/
#endif // >> End of __VDEF_TYPES_H_

/*! <h2><center>           (C) VOIDRON CO. 2019-21.           </center></h2> */
/*                        086 079 073 068 082 079 078                        */
