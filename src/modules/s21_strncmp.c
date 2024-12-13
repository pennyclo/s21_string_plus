/**
 * @file s21_strncmp.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strncmp.
 * @version 1.0
 * @date 2024-12-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/s21_strncmp.h"

/**
 * @brief Compares at most the first n bytes of two strings.
 *
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @param n   The maximum number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero if the first n
 * bytes of str1 is found, respectively, to be less than, to match, or be
 * greater than the first n bytes of str2.
 */
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  for (int i = 0; str1[i] && (str1[i] == str2[i] && i < (int)n); ++i) {
  }

  if (n) {
    res = *str1 - *str2;
  }

  return res;
}
