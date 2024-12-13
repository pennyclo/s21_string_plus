/**
 * @file s21_strchr.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strchr.
 * @version 1.0
 * @date 2024-12-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/s21_strchr.h"

/**
 * @brief Searches for the first occurrence of a character in a string.
 *
 * @param str Pointer to the null-terminated byte string to be scanned.
 * @param c Character to be located. The value is passed as an int, but it is
 * internally converted to a char.
 * @return A pointer to the first occurrence of the character @p c in the string
 * @p str, or @c S21_NULL if the character is not found. If @p c is a null
 * character, the function returns a pointer to the terminating null character
 * of @p str
 *
 * @note The function does not modify the string @p str.
 */
char *s21_strchr(const char *str, int c) {
  char *res = S21_NULL;

  if (*str) {
    int i = 0;
    int find = 0;

    for (; str[i] && !find; ++i) {
      if (str[i] == (char)c) {
        res = (char *)str + i;
        find = 1;
      }
    }

    if (*str == '\0' && !*res) {
      res = (char *)str + i;
    }
  }

  return res;
}
