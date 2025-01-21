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

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>   // before delete
#include <stdlib.h>  // before delete
#include <string.h>

#include "include/common.h"
#include "include/s21_atoi.h"
#include "include/s21_strcat.h"
#include "include/s21_strcspn.h"

typedef struct {
  int width;
  int accuracy;
  char flag;
  int lenght;
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

#endif  // SRC_INCLUDE_S21_MEMSET_H_
