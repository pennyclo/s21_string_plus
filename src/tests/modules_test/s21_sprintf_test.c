/**
 * @file s21_sprintf_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @author Artemy Plokhikh (https://github.com/isiyar)
 * @brief Implementation function s21_sprintf_test.
 * @version 1.0
 * @date 2025-01-15
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "tests/include_test/s21_sprintf_test.h"

#include <wchar.h>

START_TEST(s21_sprintf_char_1) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%c";
  char ch = 'a';

  int res_sprintf = sprintf(buffer_sprintf, format, ch);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_char_2) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%c%c%c%c%c%c    %c%c";
  char ch = 'a';

  int res_sprintf =
      sprintf(buffer_sprintf, format, ch, ch, ch, ch, ch, ch, ch, ch);
  int res_s21_sprintf =
      s21_sprintf(buffer_s21_sprintf, format, ch, ch, ch, ch, ch, ch, ch, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_char_3) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%c%c%c%c%c%c";
  char ch = 'a';

  int res_sprintf = sprintf(buffer_sprintf, format, ch, ch, ch, ch, ch, ch, ch);
  int res_s21_sprintf =
      s21_sprintf(buffer_s21_sprintf, format, ch, ch, ch, ch, ch, ch, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_char_4) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%12c%-50c";
  char ch = 'a';

  int res_sprintf = sprintf(buffer_sprintf, format, ch, ch);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, ch, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_char_5) {
  char buffer_sprintf[2000000] = {0};
  char buffer_s21_sprintf[2000000] = {0};
  char format[] = "%1999999c";
  char ch = 'a';

  int res_sprintf = sprintf(buffer_sprintf, format, ch, ch);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, ch, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_char_6) {
  char buffer_sprintf[2000000] = {0};
  char buffer_s21_sprintf[2000000] = {0};
  char format[] = "%-1999999c";
  char ch = 'a';

  int res_sprintf = sprintf(buffer_sprintf, format, ch, ch);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, ch, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_char_7) {
  char buffer_sprintf[10] = {0};
  char buffer_s21_sprintf[10] = {0};
  char format[] = "%0c";
  char ch = 'F';

  int res_sprintf = sprintf(buffer_sprintf, format, ch);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_char_8) {
  char buffer_sprintf[10] = {0};
  char buffer_s21_sprintf[10] = {0};
  char format[] = "";
  char ch = 'a';

  int res_sprintf = sprintf(buffer_sprintf, format, ch);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_char_9) {
  char buffer_sprintf[20] = {0};
  char buffer_s21_sprintf[20] = {0};
  char format[] = "Hello \t %c \0";
  char ch = 'b';

  int res_sprintf = sprintf(buffer_sprintf, format, ch);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_char_10) {
  char buffer_sprintf[20] = {0};
  char buffer_s21_sprintf[20] = {0};
  char format[] = "Hello, w12314.1";
  char ch = 'b';

  int res_sprintf = sprintf(buffer_sprintf, format, ch);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_string_1) {
  char buffer_sprintf[20] = {0};
  char buffer_s21_sprintf[20] = {0};
  char format[] = "%s";
  char *ch = "Hello";

  int res_sprintf = sprintf(buffer_sprintf, format, ch);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_string_2) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%s%s%s";
  char *ch = "abcdefg";

  int res_sprintf = sprintf(buffer_sprintf, format, ch, ch, ch);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, ch, ch, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_string_3) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%-10s%10.3s%.s";
  char *ch = "abcdefg";

  int res_sprintf = sprintf(buffer_sprintf, format, ch, ch, ch);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, ch, ch, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_string_4) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%-10s";
  char *ch = "abcdefg";

  int res_sprintf = sprintf(buffer_sprintf, format, ch);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_string_5) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%.13s";
  char *ch = "abcdefg";

  int res_sprintf = sprintf(buffer_sprintf, format, ch);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_string_6) {
  char buffer_sprintf[10000] = {0};
  char buffer_s21_sprintf[10000] = {0};
  char format[] = "%.13s";
  char *ch =
      "This is an example of a long string that contains a multitude of words "
      "and characters to demonstrate how a text occupying a significant amount "
      "of space might look. Such text can be used for testing various "
      "functions, such as character counting, line wrapping, or processing "
      "large volumes of data. It can also serve as a placeholder or sample "
      "content for development and debugging purposes.";

  int res_sprintf = sprintf(buffer_sprintf, format, ch);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_string_7) {
  char buffer_sprintf[10] = {0};
  char buffer_s21_sprintf[10] = {0};
  char format[] = "%s";
  char *ch = "\t\v\0";

  int res_sprintf = sprintf(buffer_sprintf, format, ch);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_string_8) {
  char buffer_sprintf[10] = {0};
  char buffer_s21_sprintf[10] = {0};
  char format[] = "%s";
  char *ch = S21_NULL;

  int res_sprintf = sprintf(buffer_sprintf, format, ch);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_string_9) {
  char buffer_sprintf[10] = {0};
  char buffer_s21_sprintf[10] = {0};
  char format[] = "%1s";
  char *ch = "Hello";

  int res_sprintf = sprintf(buffer_sprintf, format, ch);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_string_10) {
  char buffer_sprintf[20] = {0};
  char buffer_s21_sprintf[20] = {0};
  char format[] = "%1s%.3s";
  char *ch = "Hello";

  int res_sprintf = sprintf(buffer_sprintf, format, ch, ch);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, ch, ch);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_1) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%f";
  float num = 123.456;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_2) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%.2f";
  float num = 123.456;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_3) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%10.3f";
  float num = 123.456;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_4) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%-10.3f";
  float num = 123.456;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_5) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%*f";
  float num = -123.456;

  int res_sprintf = sprintf(buffer_sprintf, format, 30, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, 30, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_6) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%f";
  float num = 0.0;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_7) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%f";
  float num = 123456789.123456789;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_8) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%.0f";
  float num = 123.456;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_9) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%f";
  float num = 0.000001;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_10) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%f";
  float num = -0.000001;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_11) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%.f";
  float num = -0.000001;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_12) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%0.20f";
  float num = 123.456;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_13) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%0.20f";
  float num = -123.456;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_14) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%+0.20Lf";
  long double num = -123.4566543;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_15) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%+0.20Lf";
  long double num = 1233.4566543;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_16) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "% 0.20Lf";
  long double num = 1233.4566543;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_17) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "% 0.20Lf";
  long double num = -1233.4566543;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_18) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%#.*Lf";
  long double num = -1233.4566543;

  int res_sprintf = sprintf(buffer_sprintf, format, 20, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, 20, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_19) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%#.f";
  float num = -0.000001;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_20) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%-0.50Lf";
  long double num = 1233.4566543;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_float_21) {
  char buffer_sprintf[100] = {0};
  char buffer_s21_sprintf[100] = {0};
  char format[] = "%050Lf";
  long double num = -1233.4566543;

  int res_sprintf = sprintf(buffer_sprintf, format, num);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, num);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

START_TEST(s21_sprintf_int_1) {
  char buffer_sprintf[20] = {0};
  char buffer_s21_sprintf[20] = {0};
  char format[] = "%d %d";
  int x = 123;

  int res_sprintf = sprintf(buffer_sprintf, format, x, x);
  int res_s21_sprintf = s21_sprintf(buffer_s21_sprintf, format, x, x);

  ck_assert_str_eq(buffer_sprintf, buffer_s21_sprintf);
  ck_assert_int_eq(res_sprintf, res_s21_sprintf);
}
END_TEST

Suite *s21_sprintf_case_1(void) {
  Suite *string = suite_create("\ns21_sprintf (s21_sprintf case 1)\n");

  TCase *tc_s21_sprintf_char = tcase_create("s21_sprintf char test");
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_char_1);
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_char_2);
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_char_3);
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_char_4);
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_char_5);
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_char_6);
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_char_7);
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_char_8);
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_char_9);
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_char_10);
  suite_add_tcase(string, tc_s21_sprintf_char);

  TCase *tc_s21_sprintf_string = tcase_create("s21_sprintf string test");
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_string_1);
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_string_2);
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_string_3);
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_string_4);
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_string_5);
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_string_6);
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_string_7);
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_string_8);
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_string_9);
  tcase_add_test(tc_s21_sprintf_char, s21_sprintf_string_10);
  suite_add_tcase(string, tc_s21_sprintf_string);

  TCase *tc_s21_sprintf_float = tcase_create("s21_sprintf float test");
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_1);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_2);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_3);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_4);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_5);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_6);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_7);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_8);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_9);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_10);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_11);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_12);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_13);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_14);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_15);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_16);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_17);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_18);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_19);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_20);
  tcase_add_test(tc_s21_sprintf_float, s21_sprintf_float_21);
  suite_add_tcase(string, tc_s21_sprintf_float);

  TCase *tc_s21_sprintf_int = tcase_create("s21_sprintf int test");
  tcase_add_test(tc_s21_sprintf_int, s21_sprintf_int_1);

  suite_add_tcase(string, tc_s21_sprintf_int);

  return string;
}
