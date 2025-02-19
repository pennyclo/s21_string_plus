/**
 * @file s21_insert.h
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Header file with function declaration s21_insert.
 * @version 1.0
 * @date 2025-02-19
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef SRC_INCLUDE_S21_INSERT_H_
#define SRC_INCLUDE_S21_INSERT_H_

#include <stdlib.h>

#include "include/common.h"
#include "include/s21_strlen.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index);

#endif  // SRC_INCLUDE_S21_INSERT_H_
