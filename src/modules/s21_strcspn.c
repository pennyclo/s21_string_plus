/**
 * @file s21_strcspn.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strcspn.
 * @version 1.0
 * @date 2024-12-17
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/s21_strcspn.h"

/**
 * @brief Calculates the length of the initial segment of str1 that does not
 * contain any characters from str2.
 *
 * @param str1 Pointer to the first string (to be analyzed).
 * @param str2 Pointer to the second string (containing the set of characters to
 * search for).
 * @return s21_size_t The length of the initial segment of str1 that does not
 * contain any characters from str2.
 */
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  char tmp = 1;

  for (int i = 0; tmp != 0 && str1[i] != '\0'; ++i) {
    for (int j = 0; tmp != 0 && str2[j] != '\0'; ++j) {
      if (str1[i] == str2[j]) {
        tmp = 0;
      }
    }

    if (tmp) {
      ++res;
    }
  }

  return res;
}
