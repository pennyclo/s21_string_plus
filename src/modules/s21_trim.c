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
 * @brief
 *
 * @param src
 * @param trim_chars
 * @return void*
 */
void *s21_trim(const char *src, const char *trim_chars) {
  s21_size_t src_len = s21_strlen(src);
  s21_size_t start = 0;
  s21_size_t end = 0;
  s21_size_t new_len = 0;

  if (src_len) {
    while (start < src_len && s21_strchr(trim_chars, src[start]) != S21_NULL) {
      start++;
    }

    end = src_len - 1;

    while (end > start && s21_strchr(trim_chars, src[end]) != S21_NULL) {
      end--;
    }

    new_len = end - start + 1;
  }

  char *result = (char *)malloc(new_len + 1);
  if (!src_len) {
    result = S21_NULL;
  }

  if (result != S21_NULL) {
    s21_strncpy(result, src + start, new_len);
    result[new_len] = '\0';
  }

  return result;
}
