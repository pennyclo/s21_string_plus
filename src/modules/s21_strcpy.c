/**
 * @file s21_strcpy.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strcpy.
 * @version 1.0
 * @date 2024-12-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/s21_strcpy.h"

/**
 * @brief Copies the string pointed to by src, including the terminating null
 * byte ('\0'), to the buffer pointed to by dest.
 *
 * @param dest Pointer to the destination buffer where the string will be
 * copied. Must have enough space to store the string.
 * @param src  Pointer to the null-terminated source string to be copied.
 * @return     A pointer to the destination string (dest).
 */
char *s21_strcpy(char *dest, const char *src) {
  s21_size_t i = 0;

  for (; src[i] != '\0'; ++i) {
    dest[i] = src[i];
  }

  dest[i] = '\0';

  return dest;
}
