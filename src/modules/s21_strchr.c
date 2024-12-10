/**
 * @file s21_strchr.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strchr.
 * @version 1.0
 * @date 2024-12-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/s21_strchr.h"

char *s21_strchr(const char *str, int c) {
  char *res = s21_NULL;
  int i = 0;

  if (*str) {
    while (str[i]) {
      if (str[i] == (char)c) {
        res = (char *)str + i;
        break;
      }
      ++i;
    }

    if (*str == '\0' && !*res) {
      res = (char *)str + i;
    }
  }

  return res;
}
