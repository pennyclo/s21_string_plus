/**
 * @file s21_strcat_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief
 * @version 1.0
 * @date 2024-12-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include_test/s21_strcat_test.h"

#define BUFFER_SIZE 50

START_TEST(s21_strcat_1) {
  char dst1[BUFFER_SIZE] = "Hello, ";
  char dst2[BUFFER_SIZE] = "Hello, ";
  const char *src = "world";

  char *expected = strcat(dst1, src);
  char *result = s21_strcat(dst2, src);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strcat_2) {
  char dst1[BUFFER_SIZE] = "Hello, ";
  char dst2[BUFFER_SIZE] = "Hello, ";
  const char *src = "world";

  char *expected = strcat(dst1, src);
  char *result = s21_strcat(dst2, src);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

Suite *s21_strcat_case_1(void) {
  Suite *string = suite_create("\ns21_strcat (s21_strcat case 1)\n");

  TCase *tc_s21_strcat = tcase_create("s21_strcat  test");

  tcase_add_test(tc_s21_strcat, s21_strcat_1);
  tcase_add_test(tc_s21_strcat, s21_strcat_2);

  suite_add_tcase(string, tc_s21_strcat);

  return string;
}