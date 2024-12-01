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

#include "tests/include/s21_strcat_test.h"

START_TEST(s21_strcat_1) {
  int num_1 = 5;
  int num_2 = 10;
  int sum = num_1 + num_2;

  int expected = 15;

  ck_assert_int_eq(sum, expected);
}

Suite *s21_strcat_case_1(void) {
  Suite *string = suite_create("\ns21_strcat (s21_strcat case 1)\n");

  TCase *tc_s21_strcat = tcase_create("s21_strcat  test");

  tcase_add_test(tc_s21_strcat, s21_strcat_1);

  suite_add_tcase(string, tc_s21_strcat);

  return string;
}