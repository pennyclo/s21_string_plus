/**
 * @file s21_memmove.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_memmove.
 * @version 1.0
 * @date 2024-12-30
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/s21_memmove.h"

/**
 * @brief Copies `n` bytes from the memory area `src` to the memory area `dest`,
 *        handling overlapping memory regions correctly.
 *
 * @param dest A pointer to the destination memory area where the bytes will be
 * copied.
 * @param src A pointer to the source memory area from where the bytes will be
 * copied.
 * @param n The number of bytes to copy.
 * @return void* A pointer to the destination memory area (`dest`).
 */
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;

  if (d < s || d >= s + n) {
    for (s21_size_t i = 0; i < n; ++i) {
      d[i] = s[i];
    }
  } else {
    for (s21_size_t i = n; i > 0; --i) {
      d[i - 1] = s[i - 1];
    }
  }

  return dest;
}
