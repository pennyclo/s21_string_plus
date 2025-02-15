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

static char *format_pointer(char *str, va_list arguments);
static void format_n(char *str, va_list arguments, char *start);
static void decimal_to_hex(unsigned int decimal, char *hex, int is_big);

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

    str = type_definition(&form, str, arguments, &crt, start);
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

char *type_definition(format_t *form, char *str, va_list arguments, int *crt,
                      char *start) {
  switch (form->spec) {
    case 'c':
      str = format_char(form, str, arguments, crt);
      break;
    case 'd':
      str = format_d(form, str, arguments);
      break;
    case 'e':
      str = format_e(form, str, arguments);
      break;
    case 'E':
      str = format_e(form, str, arguments);
      break;
    case 'f':
      str = format_float(form, str, arguments);
      break;
    case 'g':
      str = format_g(form, str, arguments);
      break;
    case 'G':
      str = format_g(form, str, arguments);
      break;
    case 'o':
      str = format_o(form, str, arguments);
      break;
    case 's':
      str = format_string(form, str, arguments, crt);
      break;
    case 'u':
      str = format_u(form, str, arguments);
      break;
    case 'x':
      str = format_x(form, str, arguments);
      break;
    case 'X':
      str = format_x(form, str, arguments);
      break;
    case 'p':
      str = format_pointer(str, arguments);
      break;
    case 'n':
      format_n(str, arguments, start);
      break;
    case 'i':
      str = format_d(form, str, arguments);
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

char *format_d(format_t *form, char *str, va_list arguments) {
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

  arg_length += get_length_int(form, num);
  str = formating_before_int(form, str, &num, &arg_length, &i);

  int j = arg_length - 1;
  for (; j >= 0; j--) {
    *(str + j) = num % 10 + '0';
    num /= 10;
  }

  str += arg_length;

  str = formating_after_int(form, str, &num, &arg_length, &i);

  return str;
}

char *format_u(format_t *form, char *str, va_list arguments) {
  long long int num = va_arg(arguments, long long int);
  int i = 0, arg_length = num >= 0 ? 0 : 1;

  switch (form->length) {
    case 'h':
      num = (unsigned short)num;
      break;
    case 'l':
      num = (unsigned long int)num;
      break;
    default:
      num = (unsigned int)num;
      break;
  }

  arg_length += get_length_int(form, num);
  str = formating_before_int(form, str, &num, &arg_length, &i);

  int j = arg_length - 1;
  for (; j >= 0; j--) {
    *(str + j) = num % 10 + '0';
    num /= 10;
  }

  str += arg_length;

  str = formating_after_int(form, str, &num, &arg_length, &i);

  return str;
}

char *format_o(format_t *form, char *str, va_list arguments) {
  long long int num = va_arg(arguments, long long int);
  int i = 0, arg_length = num >= 0 ? 0 : 1;

  switch (form->length) {
    case 'h':
      num = (unsigned short)num;
      break;
    case 'l':
      num = (unsigned long int)num;
      break;
    default:
      num = (unsigned int)num;
      break;
  }

  num = decimal_to_octal(num);
  if (form->flags.sharp) {
    arg_length++;
  }

  arg_length += get_length_int(form, num);
  str = formating_before_int(form, str, &num, &arg_length, &i);

  int j = arg_length - 1;
  if (form->flags.sharp) {
    *(str + j) = '0';
  }
  for (; j >= 0; j--) {
    *(str + j) = num % 10 + '0';
    num /= 10;
  }

  str += arg_length;

  str = formating_after_int(form, str, &num, &arg_length, &i);

  return str;
}

char *format_x(format_t *form, char *str, va_list arguments) {
  long long int num = va_arg(arguments, long long int);
  char hex[256] = {0};
  int i = 0, arg_length = num >= 0 ? 0 : 1;

  switch (form->length) {
    case 'h':
      num = (unsigned short)num;
      break;
    case 'l':
      num = (unsigned long int)num;
      break;
    default:
      num = (unsigned int)num;
      break;
  }

  decimal_to_hex(num, hex, form->spec == 'X');
  if (form->flags.sharp) {
    arg_length += 2;
  }

  arg_length += s21_strlen(hex);
  str = formating_before_int(form, str, &num, &arg_length, &i);

  int j = arg_length - 1;
  int j_lim = 0;
  if (form->flags.sharp) {
    *(str) = '0';
    *(str + 1) = form->spec;
    j_lim = 2;
  }
  int h_i = s21_strlen(hex) - 1;
  for (; j >= j_lim; j--) {
    *(str + j) = hex[h_i];
    h_i--;
  }

  str += arg_length;

  str = formating_after_int(form, str, &num, &arg_length, &i);

  return str;
}

int get_length_int(format_t *form, long long int num) {
  int arg_length = 0;

  long long temp = num;
  if (!temp && form->spec != 'o') {
    arg_length++;
  }
  while (temp != 0) {
    arg_length++;
    temp /= 10;
  }

  return arg_length;
}

char *formating_before_int(format_t *form, char *str, long long int *num,
                           int *arg_length, int *i) {
  if (form->flags.plus && *num >= 0 &&
      (!form->accur || form->accuracy <= *arg_length)) {
    *(str)++ = '+';
  } else if (form->flags.space && *num >= 0 &&
             (!form->accur || form->accuracy <= *arg_length)) {
    *(str)++ = ' ';
  } else if (*num < 0 && (!form->accur || form->accuracy <= *arg_length)) {
    *(str)++ = '-';
    *num *= -1;
  }

  if (!form->flags.minus && *num < pow(10, form->width - 1) &&
      (!form->accur || form->accuracy <= *arg_length)) {
    char symb = ' ';

    if (form->flags.zero && !form->accur) {
      symb = '0';
    }
    while (*i < form->width - *arg_length) {
      *(str)++ = symb;
      ++(*i);
    }
  } else if (!form->flags.minus && form->accur &&
             *arg_length < form->accuracy) {
    if (form->width) {
      while (*i < form->width - form->accuracy) {
        *(str)++ = ' ';
        ++(*i);
      }
      if (form->flags.plus && *num >= 0) {
        *--(str) = '+';
        str++;
      } else if (*num < 0) {
        *--(str) = '-';
        (str)++;
        *num *= -1;
      }
      for (int j = 0; j < form->accuracy - *arg_length; j++) {
        *(str)++ = '0';
      }
    } else {
      if (form->flags.plus && *num >= 0) {
        *--(str) = '+';
        (str)++;
      } else if (*num < 0) {
        *--(str) = '-';
        (str)++;
        *num *= -1;
      }
      while (*i < form->accuracy - *arg_length) {
        *(str)++ = '0';
        ++(*i);
      }
    }
  }

  if (form->flags.minus && form->accur && form->accuracy > *arg_length) {
    for (int j = 0; j < form->accuracy - *arg_length; j++) {
      *(str)++ = '0';
      (*i)++;
    }
  }

  return str;
}

char *formating_after_int(format_t *form, char *str, long long int *num,
                          int *arg_length, int *i) {
  if (form->flags.minus) {
    while (*i < form->width - *arg_length) {
      *str++ = ' ';
      ++(*i);
    }
  }

  return str;
}

static void decimal_to_hex(unsigned int decimal, char *hex, int is_big) {
  if (decimal == 0) {
    hex[0] = '0';
  } else {
    char temp[256];
    int remainder, index = 0;

    while (decimal > 0) {
      remainder = decimal % 16;
      if (remainder < 10) {
        temp[index] = remainder + '0';
      } else {
        if (is_big) {
          temp[index] = remainder - 10 + 'A';
        } else {
          temp[index] = remainder - 10 + 'a';
        }
      }
      index++;
      decimal /= 16;
    }

    for (int i = index - 1; i >= 0; i--) {
      hex[index - 1 - i] = temp[i];
    }
  }
}

unsigned int decimal_to_octal(unsigned int decimal_num) {
  unsigned int octal_num = 0, remainder, i = 1;

  while (decimal_num != 0) {
    remainder = decimal_num % 8;
    octal_num += remainder * i;
    i *= 10;
    decimal_num /= 8;
  }

  return octal_num;
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
  str = write_whole(&exp, mantis, str, form);
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

char *write_whole(long double *exp, double man, char *str, format_t *form) {
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

  if ((form->accuracy) || form->flags.sharp) {
    str[i++] = '.';
  }

  str = write_fractional(exp, &str[i], form);

  return str;
}

char *write_fractional(long double *exp, char *str, format_t *form) {
  double rounding_offset = 0.5 / pow(10, form->accuracy);
  *exp += rounding_offset;

  for (int i = 0; i < form->accuracy; ++i) {
    *exp *= 10;
    int digit = (int)*exp;
    *str++ = digit + '0';
    *exp -= digit;
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
  str = write_whole(&exp, mantis, str, form);
  str = exp_coef(form, str, mantisa, count, zero);
  str = write_width(str, form, start);

  return str;
}

char *exp_coef(format_t *form, char *str, bool mantisa, int count, bool zero) {
  int i = 0;

  if (form->spec == 'e' || form->spec == 'g') {
    *str++ = 'e';
  } else if (form->spec == 'E' || form->spec == 'G') {
    *str++ = 'E';
  }

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

char *format_g(format_t *form, char *str, va_list arguments) {
  long double num = 0, mantis = 0, exp = 0;
  char *start = str;
  int count = 0;
  bool mantisa = true, zero = false;

  str = processing_float(str, form, arguments, &num);

  long double num_float = num;

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

  if (count > 4 || (form->accuracy - count) <= 0) {
    form->accuracy -= 1;
    exp = modfl(num, &mantis);
    str = write_whole(&exp, mantis, str, form);
    str = processing_g(str, form);
    str = exp_coef(form, str, mantisa, count, zero);
    str = write_width(str, form, start);
  } else {
    if (mantisa) {
      form->accuracy -= ++count;
    }
    exp = modfl(num_float, &mantis);
    str = write_whole(&exp, mantis, str, form);
    str = processing_g(str, form);
    str = write_width(str, form, start);
  }

  return str;
}

char *processing_g(char *str, format_t *form) {
  if (!form->flags.sharp) {
    while (*--str == '0' || *str == '.') {
      if (*(str + 1) == '.') {
        break;
      }
    }

    str++;
  }

  return str;
}

static char *format_pointer(char *str, va_list arguments) {
  uintptr_t address = va_arg(arguments, uintptr_t);
  const char hex_digits[] = "0123456789abcdef";
  int i = 0;

  if (address) {
    str[i++] = '0';
    str[i++] = 'x';

    int shift = (sizeof(uintptr_t) * 8) - 4;
    while (shift >= 0 && ((address >> shift) & 0xF) == 0) {
      shift -= 4;
    }

    while (shift >= 0) {
      int digit = (address >> shift) & 0xF;
      str[i++] = hex_digits[digit];
      shift -= 4;
    }

  } else {
    strcat(str, "(nil)");
    i = 5;
  }

  return &str[i++];
}

static void format_n(char *str, va_list arguments, char *start) {
  int count = (int)(str - start);
  int *argument = va_arg(arguments, int *);
  *argument = count;
}
