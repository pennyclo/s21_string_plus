/**
 * @file s21_sprintf_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
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
  char format[] = "%lc";
  char ch = 'Ж';

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

  return string;
}