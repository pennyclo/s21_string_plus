/**
 * @file s21_to_upper.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_to_upper.
 * @version 1.0
 * @date 2025-02-14
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "include/s21_to_upper.h"

/**
 * @brief Converts all characters in a string to uppercase.
 *
 * The function takes a string and returns a new string where all lowercase
 * letters are converted to uppercase. Other characters remain unchanged. Memory
 * for the new string is allocated dynamically and must be freed by the caller.
 *
 * @param str The input string to be converted.
 * @return void* Pointer to the new string with uppercase characters.
 */
void *s21_to_upper(const char *str) {
  char *string = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
  char *start = string;

  if (string && str) {
    while (*str) {
      if (*str >= 'a' && *str <= 'z') {
        *string = *str - 32;
      } else {
        *string = *str;
      }

      ++str;
      ++string;
    }
  } else {
    free(string);
    start = S21_NULL;
  }

  return start;
}
