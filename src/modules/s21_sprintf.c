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
  va_list arguments;
  va_start(arguments, format);

  while (*format) {
    format_t form = {0};

    if (*format != '%') {
      *str++ = *format++;
      continue;
    } else {
      ++format;
    }

    if (check_flags(*format)) {
      form.flag = *format;
      ++format;
    }

    format = value_width(format, &form, arguments);

    if (presence_point(*format)) {
      ++format;
      format = value_accuracy(format, &form, arguments);
    }

    format = value_lenght(format, &form);
    format = value_specifier(format, &form);

    str = type_definition(&form, str, arguments);
    // printf("<%d>\n", form.width);
    // printf("<%d>\n", form.accuracy);
    // printf("<%c>\n", form.flag);
    // printf("<%c>\n", form.lenght);
    // printf("<%c>\n", form.spec);
  }

  va_end(arguments);

  return 0;
}

int check_digit(const char c) { return (c >= '0' && c <= '9'); }

int presence_point(const char c) { return c == '.'; }

int check_flags(const char c) {
  char *flags = "-+#0 ";
  char ch[2] = {c, '\0'};
  return (s21_strcspn(ch, flags) == 0);
}

const char *value_width(const char *format, format_t *form, va_list arguments) {
  if (*format != '*') {
    form->width = s21_atoi(format);
    while (check_digit(*format)) {
      ++format;
    }
  } else {
    form->width = va_arg(arguments, int);
    ++format;
  }

  return format;
}

const char *value_accuracy(const char *format, format_t *form,
                           va_list arguments) {
  if (*format != '*') {
    form->accuracy = s21_atoi(format);
    while (check_digit(*format)) {
      ++format;
    }
  } else {
    form->accuracy = va_arg(arguments, int);
    ++format;
  }

  return format;
}

const char *value_lenght(const char *format, format_t *form) {
  char *lenght = "Llh";
  if (s21_strcspn(format, lenght) == 0) {
    form->lenght = *format;
    ++format;
  }

  return format;
}

const char *value_specifier(const char *format, format_t *form) {
  char *specifiers = "cdeEfgGosuxXpni";

  if (s21_strcspn(format, specifiers) == 0) {
    form->spec = *format;
    ++format;
  }

  return format;
}

char *type_definition(format_t *form, char *str, va_list arguments) {
  switch (form->spec) {
    case 'c':
      str = format_char(form, str, arguments);
      break;
    case 'd':
      str = format_int(form, str, arguments);
      break;
      // case 'e':
      //   format_e(form, str);
      //   break;
      // case 'E':
      //   format_E(form, str);
      //   break;
      // case 'f':
      //   format_float(form, str);
      //   break;
      // case 'g':
      //   format_g(form, str);
      //   break;
      // case 'G':
      //   format_G(form, str);
      //   break;
      // case 'o':
      //   format_o(form, str);
      //   break;
      // case 's':
      //   format_string(form, str);
      //   break;
      // case 'u':
      //   format_u(form, str);
      //   break;
      // case 'x':
      //   format_x(form, str);
      //   break;
      // case 'X':
      //   format_X(form, str);
      //   break;
      // case 'p':
      //   format_p(form, str);
      //   break;
      // case 'n':
      //   format_n(form, str);
      //   break;
      // case 'i':
      //   format_i(form, str);
      //   break;
  }

  return str;
}

char *format_char(format_t *form, char *str, va_list arguments) {
  char c = va_arg(arguments, int);
  int i = 1;

  while (i < form->width) {
    *str++ = ' ';
    ++i;
  }

  if (form->lenght == 'l') {
    char big_ch[100];

    big_ch[0] = va_arg(arguments, wchar_t);
    s21_strcat(str, big_ch);
  } else {
    *str = c;
  }

  ++str;

  return str;
}

char *format_int(format_t *form, char *str, va_list arguments) {
  int num = va_arg(arguments, int);

  while (num) {
    *str++ = (num % 10) + '0';
    num = num / 10;
  }

  ++str;

  return str;
}
