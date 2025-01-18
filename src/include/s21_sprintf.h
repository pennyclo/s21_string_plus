/**
 * @file s21_sprintf.h
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Header file with function declaration s21_sprintf.
 * @version 1.0
 * @date 2025-01-15
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef SRC_INCLUDE_S21_MEMSET_H_
#define SRC_INCLUDE_S21_MEMSET_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/common.h"

typedef struct {
  int width;
  int accuracy;
  char flag;
  int lenght;
  char spec;
} format_t;

int s21_sprintf(char *str, const char *format, ...);
int check_digit(char c);
void valid_width(const char *format, format_t *form);

#endif  // SRC_INCLUDE_S21_MEMSET_H_
