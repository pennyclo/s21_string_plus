/**
 * @file s21_to_upper_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_to_upper_test.
 * @version 1.0
 * @date 2025-02-19
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "tests/include_test/s21_to_upper_test.h"

START_TEST(s21_to_upper_1) {
  char src[] = "hello";
  char *result = s21_to_upper(src);

  ck_assert_str_eq(result, "HELLO");
  free(result);
}
END_TEST

START_TEST(s21_to_upper_2) {
  char src[] = "Hello, World!";
  char *result = s21_to_upper(src);

  ck_assert_str_eq(result, "HELLO, WORLD!");
  free(result);
}
END_TEST

START_TEST(s21_to_upper_3) {
  char src[] = "123abc!";
  char *result = s21_to_upper(src);

  ck_assert_str_eq(result, "123ABC!");
  free(result);
}
END_TEST

START_TEST(s21_to_upper_4) {
  char src[] = "MIXED Case";
  char *result = s21_to_upper(src);

  ck_assert_str_eq(result, "MIXED CASE");
  free(result);
}
END_TEST

START_TEST(s21_to_upper_5) {
  char src[] = "";
  char *result = s21_to_upper(src);

  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(s21_to_upper_6) {
  char src[] = "UPPERCASE";
  char *result = s21_to_upper(src);

  ck_assert_str_eq(result, "UPPERCASE");
  free(result);
}
END_TEST

START_TEST(s21_to_upper_7) {
  char src[] = "lowercase";
  char *result = s21_to_upper(src);

  ck_assert_str_eq(result, "LOWERCASE");
  free(result);
}
END_TEST

START_TEST(s21_to_upper_8) {
  char src[] = "1234567890";
  char *result = s21_to_upper(src);

  ck_assert_str_eq(result, "1234567890");
  free(result);
}
END_TEST

START_TEST(s21_to_upper_9) {
  char src[] = "symbols!@#$%^&*()";
  char *result = s21_to_upper(src);

  ck_assert_str_eq(result, "SYMBOLS!@#$%^&*()");
  free(result);
}
END_TEST

Suite *s21_to_upper_case_1(void) {
  Suite *string = suite_create("\ns21_to_upper (s21_to_upper case 1)\n");

  TCase *tc_s21_to_upper = tcase_create("s21_to_upper test");

  tcase_add_test(tc_s21_to_upper, s21_to_upper_1);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_2);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_3);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_4);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_5);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_6);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_7);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_8);
  tcase_add_test(tc_s21_to_upper, s21_to_upper_9);

  suite_add_tcase(string, tc_s21_to_upper);

  return string;
}
