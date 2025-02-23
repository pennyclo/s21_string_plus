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

#include "../include/s21_sprintf.h"

typedef struct {
  bool minus;
  bool plus;
  bool space;
  bool zero;
  bool sharp;
} flags_t;

typedef struct {
  flags_t flags;
  bool accur;
  int width;
  int accuracy;
  int length;
  char spec;
} format_t;

static int check_digit(const char c);
static int presence_point(const char c);
static int check_flags(const char c);
static const char *val_width(const char *format, format_t *form, va_list args);
static void bool_flags(format_t *form, const char *format);
static const char *val_accur(const char *format, format_t *form, va_list args);
static const char *val_length(const char *format, format_t *form);
static const char *val_specifier(const char *format, format_t *form);
static char *type_def(format_t *form, char *str, va_list args, int *crt,
                      char *start);
static char *format_char(format_t *form, char *str, va_list args, int *crt);
static char *format_d(format_t *form, char *str, va_list args);
static char *format_u(format_t *form, char *str, va_list args);
static char *format_o(format_t *form, char *str, va_list args);
static char *format_x(format_t *form, char *str, va_list args);
static int get_length_int(format_t *form, long long int num);
static char *form_bef_int(format_t *form, char *str, long long int *num,
                          int *arg_length, int *i);
static char *form_aft_int(format_t *form, char *str, int *arg_length, int *i);
static unsigned int decimal_to_octal(unsigned int decimal_num);
static char *format_string(format_t *form, char *str, va_list args, int *crt);
static char *write_wstring(wchar_t *wbuf, char *str, int *crt, format_t *form);
static char *write_string(char *buf, char *str, format_t *form);
static char *write_space(format_t *form, char *str, s21_size_t length);
static char *format_float(format_t *form, char *str, va_list args);
static char *process_float(char *str, format_t *form, va_list args,
                           long double *num);
static char *write_whole(long double *exp, double man, char *str,
                         format_t *form);
static char *write_fractional(long double *exp, char *str, format_t *form);
static char *write_width(char *str, format_t *form, char *start);
static char *format_e(format_t *form, char *str, va_list args);
static char *exp_coef(format_t *form, char *str, bool mantisa, int count,
                      bool zero);
static char *format_g(format_t *form, char *str, va_list args);
static char *processing_g(char *str, format_t *form);
static char *format_pointer(char *str, va_list args);
static void format_n(char *str, va_list args, char *start);
static void decimal_to_hex(unsigned int decimal, char *hex, int is_big);
static char *sign_int(format_t *form, long long *num, char *str);
static char *val_width_int(format_t *form, int *i, char *str, long long *num,
                           int *arg_length);

/**
 * @brief Formats and stores a series of characters and values into a string.
 *
 * This function formats data according to the provided format string and stores
 * the result into the buffer pointed to by `str`. It supports flags, width,
 * precision, length modifiers, and specifiers similar to the standard
 * `sprintf`.
 *
 * @param str Pointer to the buffer where the resulting string is stored.
 * @param format Format string that specifies how the data is formatted.
 * @param ... Variable arguments to be formatted according to the format string.
 * @return The number of characters written to the buffer (excluding the null
 * terminator). Returns -1 if an error occurs during formatting.
 */
int s21_sprintf(char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
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
      bool_flags(&form, format);
      ++format;
    }

    format = val_width(format, &form, args);

    if (presence_point(*format)) {
      form.accur = true;
      ++format;
      format = val_accur(format, &form, args);
    }

    format = val_length(format, &form);
    format = val_specifier(format, &form);

    str = type_def(&form, str, args, &crt, start);

    ++format;
  }

  *str = '\0';

  va_end(args);

  if (crt) {
    crt = (int)(str - start);
  } else {
    crt = -1;
  }

  return crt;
}

static int check_digit(const char c) { return (c >= '0' && c <= '9'); }

static int presence_point(const char c) { return c == '.'; }

static int check_flags(const char c) {
  char *flags = "-+#0 ";
  char ch[2] = {c, '\0'};
  return (s21_strcspn(ch, flags) == 0);
}

static const char *val_width(const char *format, format_t *form, va_list args) {
  if (*format != '*') {
    form->width = s21_atoi(format);
    while (check_digit(*format)) {
      ++format;
    }
  } else {
    form->width = va_arg(args, int);
    ++format;
  }

  return format;
}

static void bool_flags(format_t *form, const char *format) {
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

static const char *val_accur(const char *format, format_t *form, va_list args) {
  if (*format != '*') {
    form->accuracy = s21_atoi(format);
    while (check_digit(*format)) {
      ++format;
    }
  } else {
    form->accuracy = va_arg(args, int);
    ++format;
  }

  return format;
}

static const char *val_length(const char *format, format_t *form) {
  char *lenght = "Llh";
  if (s21_strcspn(format, lenght) == 0) {
    form->length = *format;
    ++format;
  }

  return format;
}

static const char *val_specifier(const char *format, format_t *form) {
  char *specifiers = "cdeEfgGosuxXpni%";

  if (s21_strcspn(format, specifiers) == 0) {
    form->spec = *format;
  } else {
    ++format;
    form->spec = *format;
  }

  return format;
}

static char *type_def(format_t *form, char *str, va_list args, int *crt,
                      char *start) {
  switch (form->spec) {
    case 'c':
      *crt = 1;
      str = format_char(form, str, args, crt);
      break;
    case 'd':
      *crt = 1;
      str = format_d(form, str, args);
      break;
    case 'e':
      *crt = 1;
      str = format_e(form, str, args);
      break;
    case 'E':
      *crt = 1;
      str = format_e(form, str, args);
      break;
    case 'f':
      *crt = 1;
      str = format_float(form, str, args);
      break;
    case 'g':
      *crt = 1;
      str = format_g(form, str, args);
      break;
    case 'G':
      *crt = 1;
      str = format_g(form, str, args);
      break;
    case 'o':
      *crt = 1;
      str = format_o(form, str, args);
      break;
    case 's':
      *crt = 1;
      str = format_string(form, str, args, crt);
      break;
    case 'u':
      *crt = 1;
      str = format_u(form, str, args);
      break;
    case 'x':
      *crt = 1;
      str = format_x(form, str, args);
      break;
    case 'X':
      *crt = 1;
      str = format_x(form, str, args);
      break;
    case 'p':
      *crt = 1;
      str = format_pointer(str, args);
      break;
    case 'n':
      *crt = 1;
      format_n(str, args, start);
      break;
    case 'i':
      *crt = 1;
      str = format_d(form, str, args);
      break;
    case '%':
      *crt = 1;
      *str = '%';
      ++str;
      break;
    default:
      *crt = 0;
      break;
  }

  return str;
}

static char *format_char(format_t *form, char *str, va_list args, int *crt) {
  if (!form->flags.minus) {
    str = write_space(form, str, 1);
  }

  if (form->length == 'l') {
    wchar_t big_c = va_arg(args, wchar_t);
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
    char c = (char)va_arg(args, int);
    *str++ = c;

    *str = '\0';
  }

  if (form->flags.minus) {
    str = write_space(form, str, 1);
  }

  return str;
}

static char *format_d(format_t *form, char *str, va_list args) {
  long long int num = va_arg(args, long long int);
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
  str = form_bef_int(form, str, &num, &arg_length, &i);

  int j = arg_length - 1;
  for (; j >= 0; j--) {
    *(str + j) = num % 10 + '0';
    num /= 10;
  }

  str += arg_length;

  str = form_aft_int(form, str, &arg_length, &i);

  return str;
}

static char *format_u(format_t *form, char *str, va_list args) {
  long long int num = va_arg(args, long long int);
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
  str = form_bef_int(form, str, &num, &arg_length, &i);

  int j = arg_length - 1;
  for (; j >= 0; j--) {
    *(str + j) = num % 10 + '0';
    num /= 10;
  }

  str += arg_length;

  str = form_aft_int(form, str, &arg_length, &i);

  return str;
}

static char *format_o(format_t *form, char *str, va_list args) {
  long long int num = va_arg(args, long long int);
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
  str = form_bef_int(form, str, &num, &arg_length, &i);

  int j = arg_length - 1;
  if (form->flags.sharp) {
    *(str + j) = '0';
  }
  for (; j >= 0; j--) {
    *(str + j) = num % 10 + '0';
    num /= 10;
  }

  str += arg_length;

  str = form_aft_int(form, str, &arg_length, &i);

  return str;
}

static char *format_x(format_t *form, char *str, va_list args) {
  long long int num = va_arg(args, long long int);
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
  str = form_bef_int(form, str, &num, &arg_length, &i);

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

  str = form_aft_int(form, str, &arg_length, &i);

  return str;
}

static int get_length_int(format_t *form, long long int num) {
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

static char *form_bef_int(format_t *form, char *str, long long int *num,
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
    str = val_width_int(form, i, str, num, arg_length);
  }

  if (form->flags.minus && form->accur && form->accuracy > *arg_length) {
    for (int j = 0; j < form->accuracy - *arg_length; j++) {
      *(str)++ = '0';
      (*i)++;
    }
  }

  return str;
}

static char *val_width_int(format_t *form, int *i, char *str, long long *num,
                           int *arg_length) {
  if (form->width) {
    while (*i < form->width - form->accuracy) {
      *(str)++ = ' ';
      ++(*i);
    }
    str = sign_int(form, num, str);

    for (int j = 0; j < form->accuracy - *arg_length; j++) {
      *(str)++ = '0';
    }
  } else {
    str = sign_int(form, num, str);
    while (*i < form->accuracy - *arg_length) {
      *(str)++ = '0';
      ++(*i);
    }
  }

  return str;
}

static char *sign_int(format_t *form, long long *num, char *str) {
  if (form->flags.plus && *num >= 0) {
    *--(str) = '+';
    str++;
  } else if (*num < 0) {
    *--(str) = '-';
    (str)++;
    *num *= -1;
  }

  return str;
}

static char *form_aft_int(format_t *form, char *str, int *arg_length, int *i) {
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

static unsigned int decimal_to_octal(unsigned int decimal_num) {
  unsigned int octal_num = 0, remainder, i = 1;

  while (decimal_num != 0) {
    remainder = decimal_num % 8;
    octal_num += remainder * i;
    i *= 10;
    decimal_num /= 8;
  }

  return octal_num;
}

static char *format_string(format_t *form, char *str, va_list args, int *crt) {
  if (form->length == 'l') {
    wchar_t *wbuf = va_arg(args, wchar_t *);

    if (wbuf == S21_NULL) {
      s21_strcpy(str, "(null)");
      str += 6;
    } else {
      str = write_wstring(wbuf, str, crt, form);
    }
  } else {
    char *buf = va_arg(args, char *);

    if (buf == S21_NULL) {
      s21_strcpy(str, "(null)");
      str += 6;
    } else {
      str = write_string(buf, str, form);
    }
  }

  return str;
}

static char *write_wstring(wchar_t *wbuf, char *str, int *crt, format_t *form) {
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

static char *write_string(char *buf, char *str, format_t *form) {
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

static char *write_space(format_t *form, char *str, s21_size_t length) {
  if (form->width && form->width > (int)length) {
    for (s21_size_t i = 0; i < form->width - length; ++i) {
      *str++ = ' ';
    }
  }

  return str;
}

static char *format_float(format_t *form, char *str, va_list args) {
  long double num = 0, mantis = 0, exp = 0;
  char *start = str;

  str = process_float(str, form, args, &num);
  exp = modfl(num, &mantis);
  str = write_whole(&exp, mantis, str, form);
  str = write_width(str, form, start);

  return str;
}

static char *process_float(char *str, format_t *form, va_list args,
                           long double *num) {
  if (form->length == 'L') {
    *num = va_arg(args, long double);
  } else {
    *num = va_arg(args, double);
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

static char *write_whole(long double *exp, double man, char *str,
                         format_t *form) {
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

static char *write_fractional(long double *exp, char *str, format_t *form) {
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

static char *write_width(char *str, format_t *form, char *start) {
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

static char *format_e(format_t *form, char *str, va_list args) {
  long double num = 0, mantis = 0, exp = 0;
  char *start = str;
  int count = 0;
  bool mantisa = true, zero = false;

  str = process_float(str, form, args, &num);

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

static char *exp_coef(format_t *form, char *str, bool mantisa, int count,
                      bool zero) {
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

static char *format_g(format_t *form, char *str, va_list args) {
  long double num = 0, mantis = 0, exp = 0;
  char *start = str;
  int count = 0;
  bool mantisa = true, zero = false;

  str = process_float(str, form, args, &num);

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

static char *processing_g(char *str, format_t *form) {
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

static char *format_pointer(char *str, va_list args) {
  uintptr_t address = va_arg(args, uintptr_t);
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
    s21_strcat(str, "(nil)");
    i = 5;
  }

  return &str[i++];
}

static void format_n(char *str, va_list args, char *start) {
  int count = (int)(str - start);
  int *argument = va_arg(args, int *);
  *argument = count;
}
