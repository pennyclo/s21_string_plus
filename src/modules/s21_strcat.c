/**
 * @file s21_strcat.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strcat.
 * @version 1.0
 * @date 2024-12-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/s21_strcat.h"

#include <stdio.h>
#include <string.h>
/**
 * @brief Concatenates two strings.
 *
 * @param dest
 * @param src
 * @return char*
 */
char *s21_strcat(char *dest, const char *src) {
  s21_size_t i = 0;
  s21_size_t dest_len = s21_strlen(dest);

  while (src[i] != '\0') {
    *(dest + dest_len + i) = *(src + i);
    i++;
  }

  dest[dest_len + i] = '\0';

  return dest;
}
