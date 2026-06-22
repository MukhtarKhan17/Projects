#ifndef HAL_LOGGING_H
#define HAL_LOGGING_H

#include <stdio.h>

/* Disable logging */
#define LOG_DEBUG(...)
#define LOG_INFO(...)
#define LOG_WARN(...)
#define LOG_ERROR(...)

/* Or enable UART logging */
// #define LOG_DEBUG(...) printf(__VA_ARGS__)
// #define LOG_INFO(...)  printf(__VA_ARGS__)
// #define LOG_WARN(...)  printf(__VA_ARGS__)
// #define LOG_ERROR(...) printf(__VA_ARGS__)

#endif
