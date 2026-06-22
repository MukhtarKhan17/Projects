/*
 * flash_map_backend.h
 *
 * STM32F103 Bare-metal Flash Map Backend
 * MCUboot 2.4.0
 */

#ifndef FLASH_MAP_BACKEND_H
#define FLASH_MAP_BACKEND_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

/*--------------------------------------------------------------------
 * Flash Area IDs
 *-------------------------------------------------------------------*/
#define FLASH_AREA_ID_BOOTLOADER   0
#define FLASH_AREA_ID_PRIMARY      1
#define FLASH_AREA_ID_SECONDARY    2

/*--------------------------------------------------------------------
 * Flash Sector Description
 *-------------------------------------------------------------------*/
struct flash_sector
{
    uint32_t fs_off;      /* Offset within flash device */
    uint32_t fs_size;     /* Size of sector/page */
};

/*--------------------------------------------------------------------
 * Flash Area Description
 *-------------------------------------------------------------------*/
struct flash_area
{
    uint8_t  fa_id;        /* Area ID */

    uint8_t  fa_device_id; /* Always 0 for STM32 internal flash */

    uint16_t pad16;

    uint32_t fa_off;       /* Absolute flash offset */

    uint32_t fa_size;      /* Area size */
};

/*--------------------------------------------------------------------
 * Open / Close
 *-------------------------------------------------------------------*/
int flash_area_open(uint8_t id,
                    const struct flash_area **fa_outp);

void flash_area_close(const struct flash_area *fa);

/*--------------------------------------------------------------------
 * Read / Write / Erase
 *-------------------------------------------------------------------*/
int flash_area_read(const struct flash_area *fa,
                    uint32_t off,
                    void *dst,
                    uint32_t len);

int flash_area_write(const struct flash_area *fa,
                     uint32_t off,
                     const void *src,
                     uint32_t len);

int flash_area_erase(const struct flash_area *fa,
                     uint32_t off,
                     uint32_t len);

/*--------------------------------------------------------------------
 * Alignment
 *-------------------------------------------------------------------*/
size_t flash_area_align(const struct flash_area *fa);

/*--------------------------------------------------------------------
 * Erased value
 *-------------------------------------------------------------------*/
uint8_t flash_area_erased_val(const struct flash_area *fa);

/*--------------------------------------------------------------------
 * Size query
 *-------------------------------------------------------------------*/
uint32_t flash_area_get_size(const struct flash_area *fa);

/*--------------------------------------------------------------------
 * Sector enumeration
 * Required by MCUboot 2.4.0
 *-------------------------------------------------------------------*/
int flash_area_get_sectors(int fa_id,
                           uint32_t *count,
                           struct flash_sector *sectors);

/*--------------------------------------------------------------------
 * Utility
 *-------------------------------------------------------------------*/
int flash_area_id_from_image_slot(int slot);
int flash_area_id_from_multi_image_slot(int image_index, int slot);
int flash_area_id_to_image_slot(int area_id);
uint32_t flash_area_get_off(const struct flash_area *fa);
uint8_t flash_area_get_device_id(const struct flash_area *fa);
uint32_t flash_sector_get_off(const struct flash_sector *fs);
uint32_t flash_sector_get_size(const struct flash_sector *fs);
int flash_area_get_sector(const struct flash_area *fa, uint32_t off, struct flash_sector *sector);
int flash_area_to_sectors(int fa_id, int *cnt, struct flash_sector *sectors);
uint8_t flash_area_get_id(const struct flash_area *fa);


#ifdef __cplusplus
}
#endif

#endif /* FLASH_MAP_BACKEND_H */
