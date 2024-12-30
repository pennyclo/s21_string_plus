/**
 * @file s21_memcpy.h
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Header file with function declaration s21_memcpy.
 * @version 1.0
 * @date 2024-12-30
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_S21_MEMCPY_H_
#define SRC_INCLUDE_S21_MEMCPY_H_

#include "include/common.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n);

#endif  // SRC_INCLUDE_S21_MEMCPY_H_
