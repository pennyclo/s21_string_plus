/**
 * @file s21_strcmp.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strcmp.
 * @version 1.0
 * @date 2024-12-11
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/s21_strcmp.h"
/**
 * @brief Compares two strings.
 *
 * @param str1 Pointer to the first null-terminated byte string to be compared.
 * @param str2 Pointer to the second null-terminated byte string to be compared.
 * @return An integer less than, equal to, or greater than zero if @p str1 is
 * found, respectively, to be less than, to match, or be greater than @p str2.
 *
 * @note The function does not modify the strings @p str1 and @p str2.
 */
int s21_strcmp(const char *str1, const char *str2) {
  for (; *str1 && (*str1 == *str2); str1++, str2++) {
  }
  return *str1 - *str2;
}
