/**
 * @file s21_strncpy.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strncpy.
 * @version 1.0
 * @date 2024-12-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/s21_strncpy.h"

/**
 * @brief Copies up to n characters from the source string to the destination
 * string.
 *
 * @param dest A pointer to the destination string.
 * @param src A pointer to the source string.
 * @param n The maximum number of characters to copy.
 * @return char* A pointer to the destination string (dest).
 */
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;

  for (; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }

  for (; i < n; i++) {
    dest[i] = '\0';
  }

  return dest;
}
