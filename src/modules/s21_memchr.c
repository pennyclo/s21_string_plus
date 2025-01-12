/**
 * @file s21_memchr.c
 * @author Artemy Plokhikh (https://github.com/isiyar)
 * @brief Implementation function s21_memchr.
 * @version 0.1
 * @date 2025-01-12
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "include/s21_memchr.h"

/**
 * @brief Searches for the first occurrence of the character c (unsigned type)
 * in the first n bytes of the string pointed to by the str argument.
 *
 * @param str A pointer to the string being searched for.
 * @param c A desired character.
 * @param n The number of bytes searched.
 * @return void* A pointer to the first occurrence of the character.
 */
void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *s = (const unsigned char *)str;
  unsigned char u_c = (unsigned char)c;
  void *ptr = S21_NULL;

  for (s21_size_t i = 0; i < n && !ptr; i++) {
    if (s[i] == u_c) {
      ptr = &str[i];
    }
  }

  return ptr;
}