// mcu_port.c

#include <string.h>
#include <stdlib.h>

#include "flash_map_backend/flash_map_backend.h"
#include "os/os_heap.h"
#include "sysflash/sysflash.h"

#include "hal/logging.h"

#include "stm32f10x.h"
#include "stm32f10x_flash.h"


#define BOOTLOADER_SIZE                         (32U  * 1024U)
#define APPLICATION_SIZE                        (128U * 1024U)
#define FLASH_BASE_ADDR                         (0x08000000UL)
#define BOOTLOADER_START_ADDRESS                (FLASH_BASE_ADDR + 0x00000000UL)
#define APPLICATION_PRIMARY_START_ADDRESS       (BOOTLOADER_START_ADDRESS + BOOTLOADER_SIZE)
#define APPLICATION_SECONDARY_START_ADDRESS     (APPLICATION_PRIMARY_START_ADDRESS + APPLICATION_SIZE)

#define FLASH_SECTOR_SIZE                       (2048U)
#define VALIDATE_PROGRAM_OP                     (0)

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

static const struct flash_area bootloader =
{
  .fa_id = FLASH_AREA_BOOTLOADER,
  .fa_device_id = FLASH_DEVICE_INTERNAL_FLASH,
  .fa_off = BOOTLOADER_START_ADDRESS,
  .fa_size = BOOTLOADER_SIZE,
};

static const struct flash_area primary_img0 =
{
  .fa_id = FLASH_AREA_IMAGE_PRIMARY(0),
  .fa_device_id = FLASH_DEVICE_INTERNAL_FLASH,
  .fa_off = APPLICATION_PRIMARY_START_ADDRESS,
  .fa_size = APPLICATION_SIZE,
};

static const struct flash_area secondary_img0 =
{
  .fa_id = FLASH_AREA_IMAGE_SECONDARY(0),
  .fa_device_id = FLASH_DEVICE_INTERNAL_FLASH,
  .fa_off = APPLICATION_SECONDARY_START_ADDRESS,
  .fa_size = APPLICATION_SIZE,
};

static const struct flash_area *s_flash_areas[] =
{
  &bootloader,
  &primary_img0,
  &secondary_img0,
};

static const struct flash_area *prv_lookup_flash_area(uint8_t id)
{
  for (size_t i = 0; i < ARRAY_SIZE(s_flash_areas); i++)
  {
    const struct flash_area *area = s_flash_areas[i];

    if (id == area->fa_id)
    {
      return area;
    }
  }
  return NULL;
}


int flash_area_open(uint8_t id, const struct flash_area **area_outp)
{
//  MCUBOOT_LOG_DBG("%s: ID=%d", __func__, (int)id);

	if (area_outp == NULL)
	{
	    return -1;
	}

	const struct flash_area *area = prv_lookup_flash_area(id);

	*area_outp = area;

	return area ? 0 : -1;
}

void flash_area_close(const struct flash_area *fa)
{
  // no cleanup to do for this flash part
}

int flash_area_read(const struct flash_area *fa, uint32_t off, void *dst, uint32_t len)
{
  if (fa->fa_device_id != FLASH_DEVICE_INTERNAL_FLASH)
  {
    return -1;
  }

  if (off > fa->fa_size || len > (fa->fa_size - off))
  {
      return -1;
  }

  const uint32_t end_offset = off + len;

  if (end_offset > fa->fa_size)
  {
//    MCUBOOT_LOG_ERR("%s: Out of Bounds (0x%x vs 0x%x)", __func__, end_offset, fa->fa_size);
    return -1;
  }

  // internal flash is memory mapped so just dereference the address
  void *addr = (void *)(fa->fa_off + off);
  memcpy(dst, addr, len);

  return 0;
}

int flash_area_write(const struct flash_area *fa,
                     uint32_t off,
                     const void *src,
                     uint32_t len)
{
    uint16_t value;
    const uint8_t *p = (const uint8_t *)src;
    uint32_t addr;

    if (fa->fa_device_id != FLASH_DEVICE_INTERNAL_FLASH)
    {
        return -1;
    }

    /* Bounds check */
    if ((off + len) > fa->fa_size)
    {
        return -1;
    }

    addr = fa->fa_off + off;

    FLASH_Unlock();

    while (len > 0)
    {
        if (len >= 2)
        {
            /* Little-endian half-word */
            value = ((uint16_t)p[1] << 8) | p[0];
            p += 2;
            len -= 2;
        }
        else
        {
            /* Pad the last byte with erased value (0xFF) */
            value = ((uint16_t)0xFF << 8) | p[0];
            p++;
            len--;
        }

        if (FLASH_ProgramHalfWord(addr, value) != FLASH_COMPLETE)
        {
        	FLASH_Lock();
            return -1;
        }

        addr += 2;
    }

    FLASH_Lock();

#if VALIDATE_PROGRAM_OP
    if (memcmp((const void *)(fa->fa_off + off), src, (addr - (fa->fa_off + off))) != 0)
    {
        assert(0);
    }
#endif

    return 0;
}

int flash_area_erase(const struct flash_area *fa, uint32_t off, uint32_t len)
{
  if (fa->fa_device_id != FLASH_DEVICE_INTERNAL_FLASH)
  {
    return -1;
  }

  /* Bounds check */
  if ((off + len) > fa->fa_size)
  {
      return -1;
  }

  if ((len % FLASH_SECTOR_SIZE) != 0 || (off % FLASH_SECTOR_SIZE) != 0)
  {
//    MCUBOOT_LOG_ERR("%s: Not aligned on sector Offset: 0x%x Length: 0x%x", __func__, (int)off, (int)len);
    return -1;
  }

  const uint32_t start_addr = fa->fa_off + off;
//  MCUBOOT_LOG_DBG("%s: Addr: 0x%08x Length: %d", __func__, (int)start_addr, (int)len);

  FLASH_Unlock();


  for (uint32_t addr = start_addr;
       addr < (start_addr + len);
       addr += FLASH_SECTOR_SIZE)
  {
      if (FLASH_ErasePage(addr) != FLASH_COMPLETE)
      {
          FLASH_Lock();
          return -1;
      }
  }

  FLASH_Lock();

#if VALIDATE_PROGRAM_OP
  for (size_t i = 0; i < len; i++) {
    uint8_t *val = (void *)(start_addr + i);
    if (*val != 0xff) {
      MCUBOOT_LOG_ERR("%s: Erase at 0x%x Failed", __func__, (int)val);
      assert(0);
    }
  }
#endif

  return 0;
}

size_t flash_area_align(const struct flash_area *fa)
{
	// the smallest unit a flash write can occur along.
	// Note: Image trailers will be scaled by this size
	return 2;
}

uint8_t flash_area_erased_val(const struct flash_area *area)
{
  return 0xff;
}

int flash_area_get_sectors(int fa_id, uint32_t *count,
                           struct flash_sector *sectors)
{
  const struct flash_area *fa = prv_lookup_flash_area(fa_id);

  if (fa == NULL)
  {
      return -1;
  }

  if (fa->fa_device_id != FLASH_DEVICE_INTERNAL_FLASH)
  {
    return -1;
  }

  // All sectors for the NRF52 are the same size
  const size_t sector_size = FLASH_SECTOR_SIZE;
  uint32_t total_count = 0;

  for (size_t off = 0; off < fa->fa_size; off += sector_size)
  {
    // Note: Offset here is relative to flash area, not device
    sectors[total_count].fs_off = off;
    sectors[total_count].fs_size = sector_size;
    total_count++;
  }

  *count = total_count;
  return 0;
}

int flash_area_id_from_multi_image_slot(int image_index, int slot)
{
    switch (slot)
    {
      case 0:
        return FLASH_AREA_IMAGE_PRIMARY(image_index);

      case 1:
        return FLASH_AREA_IMAGE_SECONDARY(image_index);
    }

//    MCUBOOT_LOG_ERR("Unexpected Request: image_index=%d, slot=%d", image_index, slot);
    return -1; /* flash_area_open will fail on that */
}

int flash_area_id_from_image_slot(int slot)
{
  return flash_area_id_from_multi_image_slot(0, slot);
}

uint32_t flash_area_get_off(const struct flash_area *fa)
{
    return fa->fa_off;
}

uint8_t flash_area_get_device_id(const struct flash_area *fa)
{
    return fa->fa_device_id;
}

uint32_t flash_area_get_size(const struct flash_area *fa)
{
    return fa->fa_size;
}

uint32_t flash_sector_get_off(const struct flash_sector *fs)
{
    return fs->fs_off;
}

uint32_t flash_sector_get_size(const struct flash_sector *fs)
{
    return fs->fs_size;
}

int flash_area_get_sector(const struct flash_area *fa, uint32_t off, struct flash_sector *sector)
{
    sector->fs_off = (off / FLASH_SECTOR_SIZE) * FLASH_SECTOR_SIZE;
    sector->fs_size = FLASH_SECTOR_SIZE;

    return 0;
}

int flash_area_to_sectors(int fa_id, int *cnt, struct flash_sector *sectors)
{
    uint32_t count = *cnt;

    int rc = flash_area_get_sectors(fa_id,
                                    &count,
                                    sectors);

    *cnt = (int)count;

    return rc;
}

uint8_t flash_area_get_id(const struct flash_area *fa)
{
    return fa->fa_id;
}

void example_assert_handler(const char *file, int line)
{

#if(0)
  EXAMPLE_LOG("ASSERT: File: %s Line: %d", file, line);
  __builtin_trap();
#else
  (void)file;
  (void)line;
//  __BKPT(0);

  while (1);
#endif


}
