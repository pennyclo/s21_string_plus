/**
 * @file s21_strncat.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strncat.
 * @version 1.0
 * @date 2024-12-09
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "include/s21_strncat.h"

/**
 * @brief Concatenates a specified number of characters from one string to
 * another.
 *
 * @param dest
 * @param src
 * @param n
 * @return char*
 */
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  s21_size_t dest_len = s21_strlen(dest);

  while (i < n && src[i] != '\0') {
    *(dest + dest_len + i) = *(src + i);
    i++;
  }

  dest[dest_len + i] = '\0';

  return dest;
}
