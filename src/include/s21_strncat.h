/**
 * @file s21_strncat.h
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Header file with function declaration s21_strncat.
 * @version 1.0
 * @date 2024-12-09
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef SRC_INCLUDE_S21_STRNCAT_H_
#define SRC_INCLUDE_S21_STRNCAT_H_

#include "include/common.h"
#include "include/s21_strlen.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n);

#endif  // SRC_INCLUDE_S21_STRNCAT_H_
