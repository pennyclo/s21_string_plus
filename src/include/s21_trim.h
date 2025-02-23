/**
 * @file s21_trim.h
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Header file with function declaration s21_trim.
 * @version 1.0
 * @date 2025-02-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef SRC_INCLUDE_S21_TRIM_H_
#define SRC_INCLUDE_S21_TRIM_H_

#include <stdlib.h>

#include "common.h"
#include "s21_strchr.h"
#include "s21_strlen.h"
#include "s21_strncpy.h"

void *s21_trim(const char *src, const char *trim_chars);

#endif  // SRC_INCLUDE_S21_TRIM_H_
