/**
 * @file s21_insert.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_insert.
 * @version 1.0
 * @date 2025-02-19
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "include/s21_insert.h"

/**
 * @brief Inserts the string `str` into the string `src` at the specified index.
 *
 * The function creates a new string where the contents of `str` are inserted
 * into `src` starting at the index `start_index`. If the index is out of bounds
 * of the length of `src` or if `src` is an empty string, the function returns
 * `S21_NULL`. The allocated memory for the new string must be freed by the
 * caller.
 *
 * @param src The source string into which `str` will be inserted.
 * @param str The string to be inserted into `src`.
 * @param start_index The index in `src` at which `str` will be inserted.
 * @return A pointer to the new string with the insertion result. Returns
 * `S21_NULL` on error.
 */
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t len_src = s21_strlen(src);
  s21_size_t len_str = s21_strlen(str);
  s21_size_t len_string = len_src + len_str;

  char *string = (char *)calloc(len_string + 1, sizeof(char));
  char *start = string;

  if (len_src >= start_index && string) {
    int i = 0;

    while (*src != '\0' || *str != '\0') {
      if (i < (int)start_index) {
        *string++ = *src++;
      } else if (*str != '\0') {
        *string++ = *str++;
      } else {
        *string++ = *src++;
      }

      ++i;
    }
  } else {
    free(string);
    start = S21_NULL;
  }

  return start;
}