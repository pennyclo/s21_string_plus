/**
 * @file s21_strtok.c
 * @author Artemy Plokhikh (https://github.com/isiyar)
 * @brief Implementation function s21_strtok.
 * @version 1.0
 * @date 2024-12-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/s21_strtok.h"

#include <string.h>
/**
 * @brief Splits a string into tokens based on the specified delimiters.
 *
 * @param str The string to tokenize. Pass `NULL` to continue tokenizing the
 * previous string.
 * @param delim A null-terminated string containing the delimiter characters.
 * @return char* A pointer to the next token, or `NULL` if no more tokens are
 * found.
 */
char *s21_strtok(char *str, const char *delim) {
  static char *prev_pos = S21_NULL;
  char *token;

  if (str == S21_NULL) {
    str = prev_pos;
  }
  str += strspn(str, delim);

  if (*str == '\0') {
    prev_pos = S21_NULL;
    token = S21_NULL;
  } else {
    token = str;
    str = strpbrk(str, delim);
    if (str != S21_NULL) {
      *str++ = '\0';
      prev_pos = str;
    } else {
      prev_pos = S21_NULL;
    }
  }

  return token;
}
