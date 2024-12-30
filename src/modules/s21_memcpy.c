/**
 * @file s21_memcpy.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_memcpy.
 * @version 1.0
 * @date 2024-12-30
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/s21_memcpy.h"

/**
 * @brief Copies `n` bytes from the memory area `src` to the memory area `dest`.
 *
 * @param dest A pointer to the destination memory area where the bytes will be
 * copied.
 * @param src A pointer to the source memory area from where the bytes will be
 * copied.
 * @param n The number of bytes to copy.
 * @return void* A pointer to the destination memory area (`dest`).
 */
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;

  for (s21_size_t i = 0; i < n; ++i) {
    d[i] = s[i];
  }

  return dest;
}
