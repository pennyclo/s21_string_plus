/**
 * @file s21_strrchr.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strrchr.
 * @version 1.0
 * @date 2024-12-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/s21_strrchr.h"

/**
 * @brief Locates the last occurrence of the character `c` in the string `str`.
 *
 * @param str The string to be searched.
 * @param c The character to locate in the string.
 * @return char* A pointer to the last occurrence of `c` in `str`, or `NULL` if
 * the character is not found.
 */
char *s21_strrchr(const char *str, int c) {
  char *res = S21_NULL;

  s21_size_t i = s21_strlen(str);
  char find = 1;

  for (; (int)i >= 0 && find; --i) {
    if (str[i] == (char)c) {
      res = (char *)str + i;
      find = 0;
    }
  }

  return res;
}
