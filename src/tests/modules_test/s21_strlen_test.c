/**
 * @file s21_strcat_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strlen_test.
 * @version 1.0
 * @date 2024-12-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include_test/s21_strlen_test.h"

START_TEST(s21_strlen_1) {
  const char *str = "";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_2) {
  const char *str = "a";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_3) {
  const char *str = "hello";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_4) {
  const char *str = "hello\0world";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_5) {
  const char *str = "hello\nworld";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_6) {
  char str[1024];
  for (int i = 0; i < 1024; ++i) {
    str[i] = 'a';
  }
  str[1023] = '\0';
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_7) {
  const char *str = "\0";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_8) {
  const char *str = "\n";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_9) {
  const char *str = "   hello";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_10) {
  const char *str = "hello   ";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_11) {
  char str[10];
  for (int i = 0; i < 10; ++i) {
    str[i] = 'a';
  }
  str[9] = '\0';

  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_12) {
  char str[10] = "      ";
  str[7] = '\0';
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_13) {
  char str[10] = "abc\0def";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite *s21_strlen_case_1(void) {
  Suite *string = suite_create("\ns21_strlen (s21_strlen case 1)\n");

  TCase *tc_s21_strlen = tcase_create("s21_strlen  test");

  tcase_add_test(tc_s21_strlen, s21_strlen_1);
  tcase_add_test(tc_s21_strlen, s21_strlen_2);
  tcase_add_test(tc_s21_strlen, s21_strlen_3);
  tcase_add_test(tc_s21_strlen, s21_strlen_4);
  tcase_add_test(tc_s21_strlen, s21_strlen_5);
  tcase_add_test(tc_s21_strlen, s21_strlen_6);
  tcase_add_test(tc_s21_strlen, s21_strlen_7);
  tcase_add_test(tc_s21_strlen, s21_strlen_8);
  tcase_add_test(tc_s21_strlen, s21_strlen_9);
  tcase_add_test(tc_s21_strlen, s21_strlen_10);
  tcase_add_test(tc_s21_strlen, s21_strlen_11);
  tcase_add_test(tc_s21_strlen, s21_strlen_12);
  tcase_add_test(tc_s21_strlen, s21_strlen_13);

  suite_add_tcase(string, tc_s21_strlen);

  return string;
}
