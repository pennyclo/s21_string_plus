/**
 * @file s21_to_lower.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_to_lower.
 * @version 1.0
 * @date 2025-02-19
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "include/s21_to_lower.h"

/**
 * @brief Converts all uppercase letters in a string to lowercase.
 *
 * The function takes a string and returns a new string where all uppercase
 * letters are converted to lowercase. Other characters remain unchanged. Memory
 * for the new string is allocated dynamically and must be freed by the caller.
 *
 * @param str The input string to be converted.
 * @return void* Pointer to the new string with lowercase characters.
 */
void *s21_to_lower(const char *str) {
  char *string = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
  char *start = string;

  while (*str) {
    if (*str >= 'A' && *str <= 'Z') {
      *string = *str + 32;
    } else {
      *string = *str;
    }

    ++str;
    ++string;
  }

  return start;
}
