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
* @file      crypto_rc4.h
* @brief     This file contains routines related to 128-bit RC4 Encryption
* @version   V1.0.0
* @author    MK
* @date      30-OCT-2019
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
* <h2><center>             (C) VOIDRON CO. 2019-20.             </center></h2>
*/
//=============================================================================


#ifndef CRYPTO_RC4_H_
#define CRYPTO_RC4_H_

#ifndef __VOIDRON__
#define __VOIDRON__
#endif

//#############################################################################
//                             \V/ Include SectioN
//#############################################################################

#include "vdef_types.h"
#include "string.h"


//#############################################################################
//                            \V/ Global DefineS
//#############################################################################

///RC4 Key length in bytes
#define RC4_KEY_SZ			    		(16U)

///RC4 user key length in bytes
#define RC4_USER_KEY_SZ					(RC4_KEY_SZ)


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

//=============================================================================
//                         \V/ CryptoRc4_Disable
//=============================================================================
/*!
* @fn       bool_t CryptoRc4_Disable (int8_t *vtag_ptr)
* @brief    This function unlock lib functions.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if unlocked successfully)
* @warning  All other functions won't work properly without unlocking.
* @note     Correct vTag require to pass.
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t CryptoRc4_Disable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ CryptoRc4_Enable
//=============================================================================
/*!
* @fn       bool_t CryptoRc4_Enable (int8_t *vtag_ptr)
* @brief    This function Lock lib functions.
* @param    *vtag_ptr (Pass vTag key buffer)
* @retval   error_f (Returns error_f = FALSE; if Locked successfully)
* @warning  All other functions won't work properly without unlocking.
* @note     Correct vTag require to pass.
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern bool_t CryptoRc4_Enable (int8_t *vtag_ptr);

//=============================================================================
//                         \V/ CryptoRc4_GenKeys
//=============================================================================
/*!
* @fn       void CryptoRc4_GenKeys(const uint8_t *user_key_ptr)
* @brief    This routine generate the main RC4 sub key. It is the main core
* 		    of RC4 algorithm. Internally it runs Key scheduling algorithm and
* 		    Pseudo random generation algorithm.
* @param    user_key_ptr  : use to hold the address of user key buffer
* @warning  None
* @note     It uses user key and private key to generate the output and
* 		    After run It modifies the sub_key_buff.
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void CryptoRc4_GenKeys(const uint8_t *user_key_ptr);

//=============================================================================
//                         \V/ CryptoRc4_Encrypt
//=============================================================================
/*!
* @fn       void CryptoRc4_Encrypt(void *data_ptr, uint8_t data_len)
* @brief    This function convert the plain data into encrypted data.
* 		    Input data can be variable, string or array.
* @param    data_ptr : pass the starting address of data
* @param    data_len : pass the data length in bytes
* @warning  None
* @note     Both DTE must have same private and user keys to perform
* 		    decryption
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void CryptoRc4_Encrypt(void *data_ptr, uint8_t data_len);

//=============================================================================
//                         \V/ CryptoRc4_Decrypt
//=============================================================================
/*!
* @fn       void CryptoRc4_Decrypt(void *data_ptr, uint8_t data_len)
* @brief    This function convert the encrypted data into plain data.
* 		    Input data can be variable, string or array.
* @param    data_ptr : pass the starting address of data
* @param    data_len : pass the data length in bytes
* @warning  None
* @note     Both DTE must have same private and user keys to perform
* 		    encryption & decryption
* @author   MK
* @date     30-OCT-2019
* @remark   Designed & Developed by VOIDRON CO.
*/
//=============================================================================
extern void CryptoRc4_Decrypt(void *data_ptr, uint8_t data_len);


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
#endif // >> End of CRYPTO_RC4_H_

/*! <h2><center>           (C) VOIDRON CO. 2019-20.           </center></h2> */
/*                        086 079 073 068 082 079 078                        */

