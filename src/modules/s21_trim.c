/**
 * @file s21_trim.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_trim.
 * @version 1.0
 * @date 2025-02-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "include/s21_trim.h"

/**
 * @brief Removes leading and trailing characters specified in trim_chars from
 * the given string.
 *
 * @param src The input string to be trimmed.
 * @param trim_chars The set of characters to be removed from the beginning and
 * end of src.
 * @return void* A newly allocated trimmed string, or NULL if src is empty or
 * memory allocation fails.
 */
void *s21_trim(const char *src, const char *trim_chars) {
  char *tmp = S21_NULL;

  if (src) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t start = 0;
    s21_size_t end = 0;
    s21_size_t new_len = 0;

    while (start < src_len && s21_strchr(trim_chars, src[start]) != S21_NULL) {
      start++;
    }

    end = src_len - 1;

    while (end > start && s21_strchr(trim_chars, src[end]) != S21_NULL) {
      end--;
    }

    new_len = end - start + 1;

    char *result = (char *)malloc(new_len + 1);

    if (result != S21_NULL) {
      s21_strncpy(result, src + start, new_len);
      result[new_len] = '\0';
      tmp = result;
    }
  }

  return tmp;
}
