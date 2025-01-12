/**
 * @file s21_memcmp_test.c
 * @author Artemy Plokhikh (https://github.com/isiyar)
 * @brief Implementation function s21_memcmp_test.
 * @version 0.1
 * @date 2025-01-12
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "tests/include_test/s21_memcmp_test.h"

START_TEST(s21_memcmp_1) {
  int s21_result = s21_memcmp("hello", "hello", 5);
  int result = memcmp("hello", "hello", 5);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_memcmp_2) {
  int s21_result = s21_memcmp("hello", "world", 5);
  int result = memcmp("hello", "world", 5);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_memcmp_3) {
  int s21_result = s21_memcmp("world", "hello", 5);
  int result = memcmp("world", "hello", 5);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_memcmp_4) {
  int s21_result = s21_memcmp("hello", "hello", 1);
  int result = memcmp("hello", "hello", 1);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_memcmp_5) {
  int s21_result = s21_memcmp("", "", 0);
  int result = memcmp("", "", 0);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_memcmp_6) {
  int s21_result = s21_memcmp("\0", "\0", 1);
  int result = memcmp("\0", "\0", 1);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_memcmp_7) {
  int s21_result = s21_memcmp("\0", "\1", 1);
  int result = memcmp("\0", "\1", 1);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_memcmp_8) {
  int s21_result = s21_memcmp("\1", "\0", 1);
  int result = memcmp("\1", "\0", 1);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_memcmp_9) {
  int s21_result = s21_memcmp("\0\0\0", "\0\0\1", 2);
  int result = memcmp("\0\0\0", "\0\0\1", 2);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(s21_memcmp_10) {
  int s21_result = s21_memcmp("\0\0\0", "\0\0\1", 3);
  int result = memcmp("\0\0\0", "\0\0\1", 3);
  ck_assert_int_eq(s21_result, result);
}
END_TEST

Suite *s21_memcmp_case_1(void) {
  Suite *string = suite_create("\ns21_memcmp (s21_memcmp case 1)\n");

  TCase *tc_s21_memcmp = tcase_create("s21_memcmp  test");

  tcase_add_test(tc_s21_memcmp, s21_memcmp_1);
  tcase_add_test(tc_s21_memcmp, s21_memcmp_2);
  tcase_add_test(tc_s21_memcmp, s21_memcmp_3);
  tcase_add_test(tc_s21_memcmp, s21_memcmp_4);
  tcase_add_test(tc_s21_memcmp, s21_memcmp_5);
  tcase_add_test(tc_s21_memcmp, s21_memcmp_6);
  tcase_add_test(tc_s21_memcmp, s21_memcmp_7);
  tcase_add_test(tc_s21_memcmp, s21_memcmp_8);
  tcase_add_test(tc_s21_memcmp, s21_memcmp_9);
  tcase_add_test(tc_s21_memcmp, s21_memcmp_10);

  suite_add_tcase(string, tc_s21_memcmp);

  return string;
}
