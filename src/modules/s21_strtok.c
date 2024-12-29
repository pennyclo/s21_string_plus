/**
 * @file s21_strtok.c
 * @author Artemy Plokhikh (https://github.com/isiyar)
 * @brief Implementation function s21_strtok.
 * @version 0.1
 * @date 2024-12-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/s21_strtok.h"

char *s21_strtok(char *str, const char *delim) {
  static char *prev_pos = S21_NULL;
  char *token;

  if (str == S21_NULL) {
    str = prev_pos;
  }
  str += s21_strspn(str, delim);

  if (*str == '\0') {
    prev_pos = S21_NULL;
    token = S21_NULL;
  } else {
    token = str;
    str = s21_strpbrk(str, delim);
    if (str != S21_NULL) {
      *str++ = '\0';
      prev_pos = str;
    } else {
      prev_pos = S21_NULL;
    }
  }

  return token;
}