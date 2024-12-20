/**
 * @file s21_strspn.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strspn.
 * @version 1.0
 * @date 2024-12-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/s21_strspn.h"

/**
 * @brief Calculates the length of the initial segment of `str1` consisting
 * entirely of characters found in `str2`.
 *
 * @param str1 The string to be scanned.
 * @param str2 The string containing the set of characters to match.
 * @return s21_size_t The length of the initial segment of `str1` containing
 * only characters from `str2`.
 */
s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  char tmp = 0;

  for (int i = 0; tmp != 2 && str1[i]; ++i) {
    tmp = 1;

    for (int j = 0; tmp && str2[j]; ++j) {
      if (str1[i] == str2[j]) {
        tmp = 0;
      }
    }

    if (!tmp) {
      ++res;
    } else {
      tmp = 2;
    }
  }

  return res;
}
