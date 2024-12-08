/**
 * @file s21_strlen.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strlen.
 * @version 1.0
 * @date 2024-12-07
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "include/s21_strlen.h"

/**
 * @brief Calculates the length of a C-style string.
 *
 * @param str A pointer to the null-terminated string.
 * @return s21_size_t (without taking into account the zero terminator).
 *
 * @note This function does not handle NULL input. Passing a NULL pointer will
 * result in undefined behavior. The caller is responsible for ensuring that the
 * input pointer is valid.
 */
s21_size_t s21_strlen(const char *str) {
  s21_size_t lenght = 0;

  while (*str) {
    lenght++;
    str++;
  }

  return lenght;
}
