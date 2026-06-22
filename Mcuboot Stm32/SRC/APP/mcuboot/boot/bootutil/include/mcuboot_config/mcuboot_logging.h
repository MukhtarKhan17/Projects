/*
 * mcuboot_logging.h
 * Bare-metal logging configuration for MCUboot
 *
 * Replace the macros below with UART printf() if desired.
 */

#ifndef __MCUBOOT_LOGGING_H__
#define __MCUBOOT_LOGGING_H__

#ifdef __cplusplus
extern "C" {
#endif


#if(0)
#define MCUBOOT_LOG_ERR(_fmt, ...) \
  EXAMPLE_LOG("[ERR] " _fmt, ##__VA_ARGS__);
#define MCUBOOT_LOG_WRN(_fmt, ...) \
  EXAMPLE_LOG("[WRN] " _fmt, ##__VA_ARGS__);
#define MCUBOOT_LOG_INF(_fmt, ...) \
  EXAMPLE_LOG("[INF] " _fmt, ##__VA_ARGS__);
#define MCUBOOT_LOG_DBG(_fmt, ...) \
  EXAMPLE_LOG("[DBG] " _fmt, ##__VA_ARGS__);
#else
#define MCUBOOT_LOG_DBG(...)
#define MCUBOOT_LOG_INF(...)
#define MCUBOOT_LOG_WRN(...)
#define MCUBOOT_LOG_ERR(...)

#define MCUBOOT_LOG_MODULE_DECLARE(...)
#define MCUBOOT_LOG_MODULE_REGISTER(...)

#define EXAMPLE_LOG(...)
#endif


#ifdef __cplusplus
}
#endif

#endif /* __MCUBOOT_LOGGING_H__ */
