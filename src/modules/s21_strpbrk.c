/**
 * @file s21_strpbrk.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strpbrk.
 * @version 1.0
 * @date 2024-12-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/s21_strncpy.h"

/**
 * @brief Searches the first occurrence of any character from the string `str2`
 *        in the string `str1`. Returns a pointer to the first matching
 *        character.
 *
 * @param str1 The string to be scanned.
 * @param str2 The string containing the characters to match in `str1`.
 * @return char* A pointer to the first occurrence of a character in `str1` that
 *         matches any character in `str2`. Returns `NULL` if no match is found.
 */
char *s21_strpbrk(const char *str1, const char *str2) {
  char tmp = 1;
  const char *res = S21_NULL;

  for (int i = 0; str1[i] && tmp; ++i) {
    for (int j = 0; str2[j] && tmp; ++j) {
      if (str1[i] == str2[j]) {
        tmp = 0;
        res = &str1[i];
      }
    }
  }

  return (char *)res;
}
