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
    case '#':
      form->flags.sharp = true;
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
  char *specifiers = "cdeEfgGosuxXpni%";

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
    case 'e':
      str = format_e(form, str, arguments);
      break;
    // case 'E':
    //   format_E(form, str);
    //   break;
    case 'f':
      str = format_float(form, str, arguments);
      break;
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
    case 'i':
      str = format_int(form, str, arguments);
      break;
    case '%':
      *str = '%';
      ++str;
      break;
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
  long long int num = va_arg(arguments, long long int);
  int i = 0, arg_length = num >= 0 ? 0 : 1;

  switch (form->length) {
    case 'h':
      num = (short)num;
      break;
    case 'l':
      num = (long int)num;
      break;
    default:
      num = (int)num;
      break;
  }

  long long temp = num;
  while (temp != 0) {
    arg_length++;
    temp /= 10;
  }

  if (form->flags.plus && num >= 0 &&
      (!form->accur || form->accuracy <= arg_length)) {
    *str++ = '+';
  } else if (form->flags.space && num >= 0 &&
             (!form->accur || form->accuracy <= arg_length)) {
    *str++ = ' ';
  } else if (num < 0 && (!form->accur || form->accuracy <= arg_length)) {
    *str++ = '-';
    num *= -1;
  }

  if (!form->flags.minus && num < pow(10, form->width - 1) &&
      (!form->accur || form->accuracy <= arg_length)) {
    char symb = ' ';

    if (form->flags.zero && !form->accur) {
      symb = '0';
    }
    while (i < form->width - arg_length) {
      *str++ = symb;
      ++i;
    }
  } else if (!form->flags.minus && form->accur && arg_length < form->accuracy) {
    if (form->width) {
      while (i < form->width - form->accuracy) {
        *str++ = ' ';
        ++i;
      }
      if (form->flags.plus && num >= 0) {
        *--str = '+';
        str++;
      } else if (num < 0) {
        *--str = '-';
        str++;
        num *= -1;
      }
      for (int j = 0; j < form->accuracy - arg_length; j++) {
        *str++ = '0';
      }
    } else {
      if (form->flags.plus && num >= 0) {
        *--str = '+';
        str++;
      } else if (num < 0) {
        *--str = '-';
        str++;
        num *= -1;
      }
      while (i < form->accuracy - arg_length) {
        *str++ = '0';
        ++i;
      }
    }
  }

  if (form->flags.minus && form->accur && form->accuracy > arg_length) {
    for (int j = 0; j < form->accuracy - arg_length; j++) {
      *str++ = '0';
      i++;
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

    if (wbuf == S21_NULL) {
      s21_strcpy(str, "(null)");
      str += 6;
    } else {
      str = write_wide_string(wbuf, str, crt, form);
    }
  } else {
    char *buf = va_arg(arguments, char *);

    if (buf == S21_NULL) {
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
    if (form->accur && form->accuracy <= (int)len) {
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

  if (form->accur && form->accuracy <= (int)len) {
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

char *format_float(format_t *form, char *str, va_list arguments) {
  long double num = 0, mantis = 0, exp = 0;
  char *start = str;

  str = processing_float(str, form, arguments, &num);
  exp = modfl(num, &mantis);
  str = write_whole(exp, mantis, str, form);
  str = write_width(str, form, start);

  return str;
}

char *processing_float(char *str, format_t *form, va_list arguments,
                       long double *num) {
  if (form->length == 'L') {
    *num = va_arg(arguments, long double);
  } else {
    *num = va_arg(arguments, double);
  }

  if (form->flags.plus && *num >= 0) {
    *str++ = '+';
  } else if (form->flags.space && *num >= 0) {
    *str++ = ' ';
  } else if (signbit(*num)) {
    *str++ = '-';
    *num = -*num;
  }

  if (!form->accur) {
    form->accuracy = 6;
  }

  return str;
}

char *write_whole(double exp, double man, char *str, format_t *form) {
  int i = 0;

  long long mantisa = (long long)man;

  if (mantisa == 0) {
    str[i++] = '0';
  } else {
    while (mantisa != 0) {
      str[i++] = (mantisa % 10) + '0';
      mantisa /= 10;
    }
  }

  int len = i;
  for (int j = 0; j < len / 2; j++) {
    char temp = str[j];
    str[j] = str[len - j - 1];
    str[len - j - 1] = temp;
  }

  if (form->accuracy || form->flags.sharp) {
    str[i++] = '.';
  }

  str = write_fractional(exp, &str[i], form);

  return str;
}

char *write_fractional(double exp, char *str, format_t *form) {
  double rounding_offset = 0.5 / pow(10, form->accuracy);
  exp += rounding_offset;

  for (int i = 0; i < form->accuracy; ++i) {
    exp *= 10;
    int digit = (int)exp;
    *str++ = digit + '0';
    exp -= digit;
  }

  return str;
}

char *write_width(char *str, format_t *form, char *start) {
  int len = (int)(str - start);
  char symb = ' ';

  if (form->flags.zero && !form->flags.minus) {
    symb = '0';
  }

  if (form->width > len) {
    int width = form->width - len;

    if (!form->flags.minus) {
      for (int i = len; i >= 0; --i) {
        start[i + width] = start[i];
      }

      for (int j = 0; j < width; ++j) {
        start[j] = symb;
      }

      if (form->flags.zero && start[width] == '-') {
        start[width] = '0';
        *start = '-';
      }
    } else {
      for (int i = 0; i < width; ++i) {
        start[len + i] = symb;
      }
    }

    str = start + form->width;
  }

  return str;
}

char *format_e(format_t *form, char *str, va_list arguments) {
  long double num = 0, mantis = 0, exp = 0;
  char *start = str;
  int count = 0;
  bool mantisa = true, zero = false;

  str = processing_float(str, form, arguments, &num);

  if (num == 0) {
    zero = true;
  } else if ((long long)num > 0) {
    while ((long long)num > 1) {
      num *= 0.1;
      count++;
    }
  } else {
    mantisa = false;

    while ((long long)num == 0) {
      num *= 10;
      count++;
    }
  }

  exp = modfl(num, &mantis);
  str = write_whole(exp, mantis, str, form);
  str = exp_coef(str, mantisa, count, zero);
  str = write_width(str, form, start);

  return str;
}

char *exp_coef(char *str, bool mantisa, int count, bool zero) {
  int i = 0;

  *str++ = 'e';

  if (mantisa) {
    *str++ = '+';
  } else {
    *str++ = '-';
  }

  if (count < 10) {
    *str++ = '0';
  }

  if (zero) {
    *str++ = '0';
  }

  while (count != 0) {
    str[i++] = (count % 10) + '0';
    count /= 10;
  }

  int len = i;
  for (int j = 0; j < len / 2; j++) {
    char temp = str[j];
    str[j] = str[len - j - 1];
    str[len - j - 1] = temp;
  }

  return &str[i];
}
