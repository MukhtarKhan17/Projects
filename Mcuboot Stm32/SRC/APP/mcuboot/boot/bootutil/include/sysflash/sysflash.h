/*
 * sysflash.h
 *
 * STM32F103RE (512KB Flash)
 * MCUboot 2.4.0 Bare Metal
 */

#ifndef SYSFLASH_H
#define SYSFLASH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "flash_map_backend.h"

//! A user-defined identifier for different storage mediums
//! (i.e internal flash, external NOR flash, eMMC, etc)
#define FLASH_DEVICE_INTERNAL_FLASH 0

//! An arbitrarily high slot ID we will use to indicate that
//! there is not slot
#define FLASH_SLOT_DOES_NOT_EXIST 255

//! NB: MCUboot expects this define to exist but it's only used
//! if MCUBOOT_SWAP_USING_SCRATCH=1 is set
#define FLASH_AREA_IMAGE_SCRATCH FLASH_SLOT_DOES_NOT_EXIST

//! The slot we will use to track the bootloader allocation
#define FLASH_AREA_BOOTLOADER        FLASH_AREA_ID_BOOTLOADER

//! A mapping to primary and secondary/upgrade slot
//! given an image_index. We'll plan to use
#define FLASH_AREA_IMAGE_PRIMARY(i)  ((i) == 0 ? FLASH_AREA_ID_PRIMARY : FLASH_SLOT_DOES_NOT_EXIST)
#define FLASH_AREA_IMAGE_SECONDARY(i) ((i) == 0 ? FLASH_AREA_ID_SECONDARY : FLASH_SLOT_DOES_NOT_EXIST)

#ifdef __cplusplus
}
#endif

#endif /* SYSFLASH_H */
