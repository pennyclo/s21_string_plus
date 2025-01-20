/**
 * @file s21_atoi_test.c
 * @author Artemy Plokhikh (https://github.com/isiyar)
 * @brief Implementation function s21_atoi_test.
 * @version 0.1
 * @date 2025-01-19
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "tests/include_test/s21_atoi_test.h"

START_TEST(s21_atoi_1) {
  char str[] = "42";
  int correct_result = atoi(str);
  int atoi_result = s21_atoi(str);
  ck_assert_int_eq(correct_result, atoi_result);
}
END_TEST

START_TEST(s21_atoi_2) {
  char str[] = "-17";
  int correct_result = atoi(str);
  int atoi_result = s21_atoi(str);
  ck_assert_int_eq(correct_result, atoi_result);
}
END_TEST

START_TEST(s21_atoi_3) {
  char str[] = "000456";
  int correct_result = atoi(str);
  int atoi_result = s21_atoi(str);
  ck_assert_int_eq(correct_result, atoi_result);
}
END_TEST

START_TEST(s21_atoi_4) {
  char str[] = "2147483647";
  int correct_result = atoi(str);
  int atoi_result = s21_atoi(str);
  ck_assert_int_eq(correct_result, atoi_result);
}
END_TEST

START_TEST(s21_atoi_5) {
  char str[] = "-2147483648";
  int correct_result = atoi(str);
  int atoi_result = s21_atoi(str);
  ck_assert_int_eq(correct_result, atoi_result);
}
END_TEST

START_TEST(s21_atoi_6) {
  char str[] = "2147483649";
  int correct_result = atoi(str);
  int atoi_result = s21_atoi(str);
  ck_assert_int_eq(correct_result, atoi_result);
}
END_TEST

START_TEST(s21_atoi_7) {
  char str[] = "-2147483649";
  int correct_result = atoi(str);
  int atoi_result = s21_atoi(str);
  ck_assert_int_eq(correct_result, atoi_result);
}
END_TEST

START_TEST(s21_atoi_8) {
  char str[] = "abc123";
  int correct_result = atoi(str);
  int atoi_result = s21_atoi(str);
  ck_assert_int_eq(correct_result, atoi_result);
}
END_TEST

Suite *s21_atoi_case_1(void) {
  Suite *string = suite_create("\ns21_atoi (21_atoi case 1)\n");

  TCase *tc_21_atoi = tcase_create("21_atoi  test");

  tcase_add_test(tc_21_atoi, s21_atoi_1);
  tcase_add_test(tc_21_atoi, s21_atoi_2);
  tcase_add_test(tc_21_atoi, s21_atoi_3);
  tcase_add_test(tc_21_atoi, s21_atoi_4);
  tcase_add_test(tc_21_atoi, s21_atoi_5);
  tcase_add_test(tc_21_atoi, s21_atoi_6);
  tcase_add_test(tc_21_atoi, s21_atoi_7);
  tcase_add_test(tc_21_atoi, s21_atoi_8);

  suite_add_tcase(string, tc_21_atoi);

  return string;
}
