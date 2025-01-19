/**
 * @file s21_atoi.c
 * @author Artemy Plokhikh (https://github.com/isiyar)
 * @brief Implementation function s21_atoi.
 * @version 0.1
 * @date 2025-01-19
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "include/s21_atoi.h"

/**
 * @brief Converts the string pointed to by the str parameter into a value of
 * int type. The string must contain a valid entry of an integer. Otherwise 0 is
 * returned.
 * @param str A pointer to the string to be converted.
 * @return int Integer obtained after converting the string str.
 */
int s21_atoi(char *s) {
  int result, sign = 1;
  long long n = 0;

  if (s[0] == '-' || s[0] == '+') {
    sign = s[0] == '-' ? -1 : 1;
    s++;
  }

  while (*s >= '0' && *s <= '9') {
    n = n * 10 + (*s - '0');
    s++;
  }

  if (n > INT_MAX) {
    result = sign == 1 ? INT_MAX : INT_MIN;
  } else {
    result = (int)(n * sign);
  }

  return result;
}
