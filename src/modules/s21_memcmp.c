/**
 * @file s21_memcmp.c
 * @author Artemy Plokhikh (https://github.com/isiyar)
 * @brief Implementation function s21_memcmp.
 * @version 0.1
 * @date 2025-01-12
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "include/s21_memcmp.h"

/**
 * @brief Compares the first n bytes of str1 and str2.
 * @param str1 First memory area.
 * @param str2 Second memory area
 * @param n The number of bytes searched.
 * @return int A value of zero indicates that the contents of both memory blocks
 * are equal. A value greater than zero indicates that the first memory block -
 * memptr1 is larger than the memory block - memptr2, and a value less than zero
 * indicates the opposite.
 */
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  unsigned char *s1 = (unsigned char *)str1;
  unsigned char *s2 = (unsigned char *)str2;
  int result = 0;

  for (s21_size_t i = 0; i < n && !result; i++) {
    if (s1[i] > s2[i])
      result = 1;
    else if (s1[i] < s2[i])
      result = -1;
  }

  return result;
}