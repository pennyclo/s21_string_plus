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

#ifndef SRC_INCLUDE_S21_SPRINTF_H_
#define SRC_INCLUDE_S21_SPRINTF_H_

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>   // before delete
#include <stdlib.h>  // before delete
#include <string.h>
#include <wchar.h>

#include "include/common.h"
#include "include/s21_atoi.h"
#include "include/s21_memcpy.h"
#include "include/s21_memset.h"
#include "include/s21_strcat.h"
#include "include/s21_strcspn.h"

typedef struct {
  bool minus;
  bool plus;
} flags_t;

typedef struct {
  flags_t flags;
  int width;
  int accuracy;
  // char flag;
  int length;
  char spec;
} format_t;

int s21_sprintf(char *str, const char *format, ...);
int check_digit(const char c);
const char *value_width(const char *format, format_t *form, va_list arguments);
int presence_point(const char c);
const char *value_accuracy(const char *format, format_t *form,
                           va_list arguments);
int check_flags(const char c);
const char *value_lenght(const char *format, format_t *form);
const char *value_specifier(const char *format, format_t *form);
char *type_definition(format_t *form, char *str, va_list arguments);
char *format_char(format_t *form, char *str, va_list arguments);
char *format_int(format_t *form, char *str, va_list arguments);
void check_bool_flags(format_t *form, const char *format);

#endif  // SRC_INCLUDE_S21_SPRINTF_H_
