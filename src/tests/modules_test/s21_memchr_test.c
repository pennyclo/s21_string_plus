/**
 * @file s21_memchr_test.c
 * @author Artemy Plokhikh (https://github.com/isiyar)
 * @brief Implementation function s21_memchr_test.
 * @version 0.1
 * @date 2025-01-12
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "tests/include_test/s21_memchr_test.h"

START_TEST(s21_memchr_1) {
  char str[] = "Hello, world!";
  int c = 'o';
  s21_size_t n = 14;
  void *s21_result = s21_memchr(str, c, n);
  void *result = memchr(str, c, n);
  ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(s21_memchr_2) {
  char str[] = "Hello, world!";
  int c = 'd';
  s21_size_t n = 13;
  void *s21_result = s21_memchr(str, c, n);
  void *result = memchr(str, c, n);
  ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(s21_memchr_3) {
  char str[] = "Test";
  int c = 'T';
  s21_size_t n = 4;
  void *s21_result = s21_memchr(str, c, n);
  void *result = memchr(str, c, n);
  ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(s21_memchr_4) {
  char str[] = "Empty string";
  int c = 'y';
  s21_size_t n = 12;
  void *s21_result = s21_memchr(str, c, n);
  void *result = memchr(str, c, n);
  ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(s21_memchr_5) {
  char str[] = "";
  int c = 'a';
  s21_size_t n = 0;
  void *s21_result = s21_memchr(str, c, n);
  void *result = memchr(str, c, n);
  ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(s21_memchr_6) {
  char str[] = "Test";
  int c = 'e';
  s21_size_t n = 2;
  void *s21_result = s21_memchr(str, c, n);
  void *result = memchr(str, c, n);
  ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(s21_memchr_7) {
  char str[] = "Test";
  int c = 'o';
  s21_size_t n = 4;
  void *s21_result = s21_memchr(str, c, n);
  void *result = memchr(str, c, n);
  ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(s21_memchr_8) {
  char str[] = "Test";
  int c = 'E';
  s21_size_t n = 4;
  void *s21_result = s21_memchr(str, c, n);
  void *result = memchr(str, c, n);
  ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(s21_memchr_9) {
  char str[] = "Test";
  int c = 'x';
  s21_size_t n = 4;
  void *s21_result = s21_memchr(str, c, n);
  void *result = memchr(str, c, n);
  ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(s21_memchr_10) {
  char str[] = "Test";
  int c = 't';
  s21_size_t n = 4;
  void *s21_result = s21_memchr(str, c, n);
  void *result = memchr(str, c, n);
  ck_assert_ptr_eq(s21_result, result);
}
END_TEST

Suite *s21_memchr_case_1(void) {
  Suite *string = suite_create("\ns21_memchr (s21_memchr case 1)\n");

  TCase *tc_s21_memchr = tcase_create("s21_memchr  test");

  tcase_add_test(tc_s21_memchr, s21_memchr_1);
  tcase_add_test(tc_s21_memchr, s21_memchr_2);
  tcase_add_test(tc_s21_memchr, s21_memchr_3);
  tcase_add_test(tc_s21_memchr, s21_memchr_4);
  tcase_add_test(tc_s21_memchr, s21_memchr_5);
  tcase_add_test(tc_s21_memchr, s21_memchr_6);
  tcase_add_test(tc_s21_memchr, s21_memchr_7);
  tcase_add_test(tc_s21_memchr, s21_memchr_8);
  tcase_add_test(tc_s21_memchr, s21_memchr_9);
  tcase_add_test(tc_s21_memchr, s21_memchr_10);

  suite_add_tcase(string, tc_s21_memchr);

  return string;
}
