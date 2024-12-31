/**
 * @file s21_memset.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_memset.
 * @version 1.0
 * @date 2024-12-31
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/s21_memmove.h"

/**
 * @brief Fills the first `n` bytes of the memory area pointed to by `str` with
 * the constant byte `c`.
 *
 * @param str A pointer to the memory area to be filled.
 * @param c The value to be set (converted to an unsigned char).
 * @param n The number of bytes to fill.
 * @return void* A pointer to the memory area (`str`).
 */
void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *string = (unsigned char *)str;

  for (s21_size_t i = 0; i < n; ++i) {
    string[i] = (char)c;
  }

  return str;
}
