/**
 * @file s21_memchr.h
 * @author Artemy Plokhikh (https://github.com/isiyar)
 * @brief Header file with function declaration s21_memchr.
 * @version 0.1
 * @date 2025-01-12
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef SRC_INCLUDE_S21_MEMCHR_H_
#define SRC_INCLUDE_S21_MEMCHR_H_

#include "include/common.h"

void *s21_memchr(const void *str, int c, s21_size_t n);

#endif  // SRC_INCLUDE_S21_MEMCHR_H_