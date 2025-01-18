/**
 * @file s21_sprintf.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_sprintf.
 * @version 1.0
 * @date 2025-01-15
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "include/s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  format_t form = {0};
  char *buffer = str;

  va_list arguments;
  va_start(arguments, format);

  while (*format) {
    if (*format != '%') {
      *buffer++ = *format++;
      continue;
    } else {
      ++format;
    }

    if (check_digit(*format)) {
      valid_width(format, &form);
    }

    printf("<%d>\n", form.width);

    // if (presence_point(*format)) {
    //   valid_accuracy(format, form);
    // }

    // check_specidfier(*format, form);
  }

  va_end(arguments);

  return 0;
}

int check_digit(char c) { return (c >= '0' && c <= '9'); }

void valid_width(const char *format, format_t *form) {
  while (check_digit(*format)) {
    form->width = atoi(format);
  }
}