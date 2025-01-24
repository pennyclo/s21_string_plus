/**
 * @file s21_sprintf.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @author Artemy Plokhikh (https://github.com/isiyar)
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
  int crt = 1;

  char *start = str;

  while (*format) {
    format_t form = {0};

    if (*format != '%') {
      *str++ = *format++;
      continue;
    } else {
      ++format;
    }

    while (check_flags(*format)) {
      check_bool_flags(&form, format);
      ++format;
    }

    format = value_width(format, &form, arguments);

    if (presence_point(*format)) {
      form.accur = true;
      ++format;
      format = value_accuracy(format, &form, arguments);
    }

    format = value_length(format, &form);
    format = value_specifier(format, &form);

    str = type_definition(&form, str, arguments, &crt);
    // printf("<%d>\n", form.width);
    // printf("<%d>\n", form.accuracy);
    // printf("<%c>\n", form.flag);
    // printf("<%c>\n", form.lenght);
    // printf("<%c>\n", form.spec);
  }

  *str = '\0';

  va_end(arguments);

  if (crt) {
    crt = (int)(str - start);
  } else {
    crt = -1;
  }

  return crt;
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

void check_bool_flags(format_t *form, const char *format) {
  switch (*format) {
    case '-':
      form->flags.minus = true;
      break;
    case '+':
      form->flags.plus = true;
      break;
    case ' ':
      form->flags.space = true;
      break;
    case '0':
      form->flags.zero = true;
      break;
  }
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

const char *value_length(const char *format, format_t *form) {
  char *lenght = "Llh";
  if (s21_strcspn(format, lenght) == 0) {
    form->length = *format;
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

char *type_definition(format_t *form, char *str, va_list arguments, int *crt) {
  switch (form->spec) {
    case 'c':
      str = format_char(form, str, arguments, crt);
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
    case 's':
      str = format_string(form, str, arguments, crt);
      break;
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

char *format_char(format_t *form, char *str, va_list arguments, int *crt) {
  if (!form->flags.minus) {
    str = write_space(form, str, 1);
  }

  if (form->length == 'l') {
    wchar_t big_c = va_arg(arguments, wchar_t);
    char tmp[MB_CUR_MAX];
    mbstate_t state;
    s21_memset(&state, 0, sizeof(state));

    s21_size_t len = wcrtomb(tmp, big_c, &state);
    if (!(len == (s21_size_t)-1)) {
      s21_memcpy(str, tmp, len);
      str += len;
    } else {
      *crt = 0;
    }

  } else {
    char c = (char)va_arg(arguments, int);
    *str++ = c;

    *str = '\0';
  }

  if (form->flags.minus) {
    str = write_space(form, str, 1);
  }

  return str;
}

char *format_int(format_t *form, char *str, va_list arguments) {
  long long num = va_arg(arguments, long long);
  int i = 1, arg_length = num >= 0 ? 0 : 1, temp = num;

  while (temp != 0) {
    arg_length++;
    temp /= 10;
  }

  switch (form->length) {
    case 'h':
      num = (short)num;
      break;
    case 'l':
      num = (long)num;
      break;
    default:
      num = (int)num;
      break;
  }

  if (form->flags.plus && num >= 0) {
    *str++ = '+';
  } else if (form->flags.space && num >= 0) {
    *str++ = ' ';
  } else if (num < 0) {
    *str++ = '-';
    num *= -1;
  }

  if (!form->flags.minus && num < pow(10, form->width - 1)) {
    char symb = ' ';

    if (form->flags.zero) {
      symb = '0';
    }
    while (i < form->width - arg_length) {
      *str++ = symb;
      ++i;
    }
  }

  for (int j = arg_length - 1; j >= 0; j--) {
    *(str + j) = num % 10 + '0';
    num /= 10;
  }

  str += arg_length;

  if (form->flags.minus) {
    while (i < form->width - arg_length) {
      *str++ = ' ';
      ++i;
    }
  }

  return str;
}

char *format_string(format_t *form, char *str, va_list arguments, int *crt) {
  if (form->length == 'l') {
    wchar_t *wbuf = va_arg(arguments, wchar_t *);

    if (wbuf == NULL) {
      s21_strcpy(str, "(null)");
      str += 6;
    } else {
      str = write_wide_string(wbuf, str, crt, form);
    }
  } else {
    char *buf = va_arg(arguments, char *);

    if (buf == NULL) {
      s21_strcpy(str, "(null)");
      str += 6;
    } else {
      str = write_string(buf, str, form);
    }
  }

  return str;
}

char *write_wide_string(wchar_t *wbuf, char *str, int *crt, format_t *form) {
  mbstate_t state;
  s21_memset(&state, 0, sizeof(state));

  const wchar_t *src = wbuf;
  s21_size_t len = wcsrtombs(NULL, &src, 0, &state);

  if (len == (s21_size_t)-1) {
    *crt = 0;
  } else {
    if (form->accur) {
      len = form->accuracy;
    } else {
      form->accuracy = len;
    }

    if (!form->flags.minus) {
      str = write_space(form, str, len);
    }

    src = wbuf;
    wcsrtombs(str, &src, len, &state);

    str[form->accuracy] = '\0';

    str += len;

    if (form->flags.minus) {
      str = write_space(form, str, len);
    }
  }

  return str;
}

char *write_string(char *buf, char *str, format_t *form) {
  s21_size_t len = s21_strlen(buf);

  if (form->accur) {
    len = form->accuracy;
  } else {
    form->accuracy = len;
  }

  if (!form->flags.minus) {
    str = write_space(form, str, len);
  }

  s21_strncpy(str, buf, form->accuracy);

  str += len;

  if (form->flags.minus) {
    str = write_space(form, str, len);
  }

  return str;
}

char *write_space(format_t *form, char *str, s21_size_t length) {
  if (form->width && form->width > (int)length) {
    for (s21_size_t i = 0; i < form->width - length; ++i) {
      *str++ = ' ';
    }
  }

  return str;
}
