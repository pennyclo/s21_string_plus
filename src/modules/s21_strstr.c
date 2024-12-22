/**
 * @file s21_strstr.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strstr.
 * @version 1.0
 * @date 2024-12-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/s21_strstr.h"

/**
 * @brief Finds the first occurrence of the substring `needle` in the string
 * `haystack`.
 *
 * @param haystack The string to be searched.
 * @param needle The substring to find in `haystack`.
 * @return char* A pointer to the beginning of the first occurrence of `needle`
 * in `haystack`, or `NULL` if `needle` is not found.
 */
char *s21_strstr(const char *haystack, const char *needle) {
  char *res = S21_NULL;
  char match = 0;

  if (needle[0] == '\0') {
    res = (char *)haystack;
  } else {
    for (int i = 0; haystack[i] && !match; ++i) {
      if (haystack[i] == needle[0]) {
        int k = i;
        match = 1;

        for (int j = 0; needle[j] && match; ++j, ++k) {
          if (haystack[k] != needle[j]) {
            match = 0;
          }
        }
      }

      if (match) {
        res = (char *)haystack + i;
      }
    }
  }

  return res;
}
