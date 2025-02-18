/**
 * @file s21_sprintf.h
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @author Artemy Plokhikh (https://github.com/isiyar)
 * @brief Header file with function declaration s21_sprintf.
 * @version 1.0
 * @date 2025-01-15
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef SRC_INCLUDE_S21_SPRINTF_H_
#define SRC_INCLUDE_S21_SPRINTF_H_

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <wchar.h>

#include "include/common.h"
#include "include/s21_atoi.h"
#include "include/s21_memcpy.h"
#include "include/s21_memmove.h"
#include "include/s21_memset.h"
#include "include/s21_strcat.h"
#include "include/s21_strcpy.h"
#include "include/s21_strcspn.h"
#include "include/s21_strncpy.h"

int s21_sprintf(char *str, const char *format, ...);

#endif  // SRC_INCLUDE_S21_SPRINTF_H_
