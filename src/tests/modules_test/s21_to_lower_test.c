/**
 * @file s21_to_lower_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_to_lower_test.
 * @version 1.0
 * @date 2025-02-19
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "../include_test/s21_to_lower_test.h"

START_TEST(s21_to_lower_1) {
  char src[] = "HELLO";
  char *result = s21_to_lower(src);

  ck_assert_str_eq(result, "hello");
  free(result);
}
END_TEST

START_TEST(s21_to_lower_2) {
  char src[] = "Hello, World!";
  char *result = s21_to_lower(src);

  ck_assert_str_eq(result, "hello, world!");
  free(result);
}
END_TEST

START_TEST(s21_to_lower_3) {
  char src[] = "123ABC!";
  char *result = s21_to_lower(src);

  ck_assert_str_eq(result, "123abc!");
  free(result);
}
END_TEST

START_TEST(s21_to_lower_4) {
  char src[] = "MIXED Case";
  char *result = s21_to_lower(src);

  ck_assert_str_eq(result, "mixed case");
  free(result);
}
END_TEST

START_TEST(s21_to_lower_5) {
  char src[] = "";
  char *result = s21_to_lower(src);

  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(s21_to_lower_6) {
  char src[] = "lowercase";
  char *result = s21_to_lower(src);

  ck_assert_str_eq(result, "lowercase");
  free(result);
}
END_TEST

START_TEST(s21_to_lower_7) {
  char src[] = "UPPERCASE";
  char *result = s21_to_lower(src);

  ck_assert_str_eq(result, "uppercase");
  free(result);
}
END_TEST

START_TEST(s21_to_lower_8) {
  char src[] = "1234567890";
  char *result = s21_to_lower(src);

  ck_assert_str_eq(result, "1234567890");
  free(result);
}
END_TEST

START_TEST(s21_to_lower_9) {
  char src[] = "SYMBOLS!@#$%^&*()";
  char *result = s21_to_lower(src);

  ck_assert_str_eq(result, "symbols!@#$%^&*()");
  free(result);
}
END_TEST

Suite *s21_to_lower_case_1(void) {
  Suite *string = suite_create("\ns21_to_lower (s21_to_lower case 1)\n");

  TCase *tc_s21_to_lower = tcase_create("s21_to_lower test");

  tcase_add_test(tc_s21_to_lower, s21_to_lower_1);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_2);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_3);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_4);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_5);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_6);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_7);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_8);
  tcase_add_test(tc_s21_to_lower, s21_to_lower_9);

  suite_add_tcase(string, tc_s21_to_lower);

  return string;
}
