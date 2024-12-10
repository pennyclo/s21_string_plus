/**
 * @file s21_strncat_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strncat_test.
 * @version 1.0
 * @date 2024-12-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include_test/s21_strncat_test.h"

#include "include/common.h"

#ifdef STRNCAT
#define BUFFER_SIZE 50

START_TEST(s21_strncat_1) {
  char dst1[BUFFER_SIZE] = "Hello, ";
  char dst2[BUFFER_SIZE] = "Hello, ";
  const char *src = "world";
  s21_size_t n = 3;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_2) {
  char dst1[BUFFER_SIZE] = "DBMfnb08, ";
  char dst2[BUFFER_SIZE] = "DBMfnb08, ";
  const char *src = "LIFZCaB";
  s21_size_t n = 10;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_3) {
  char dst1[BUFFER_SIZE] = "Hello, ";
  char dst2[BUFFER_SIZE] = "Hello, ";
  const char *src = "world";
  s21_size_t n = 0;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_4) {
  char dst1[BUFFER_SIZE] = "";
  char dst2[BUFFER_SIZE] = "";
  const char *src = "world";
  s21_size_t n = 3;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_5) {
  char dst1[BUFFER_SIZE] = "Hello, ";
  char dst2[BUFFER_SIZE] = "Hello, ";
  const char *src = "";
  s21_size_t n = 3;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_6) {
  char dst1[BUFFER_SIZE] = "";
  char dst2[BUFFER_SIZE] = "";
  const char *src = "";
  s21_size_t n = 3;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_7) {
  char dst1[BUFFER_SIZE] = "Hello, ";
  char dst2[BUFFER_SIZE] = "Hello, ";
  const char *src = "world";
  s21_size_t n = 50;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_8) {
  char dst1[BUFFER_SIZE] = "Hello, ";
  char dst2[BUFFER_SIZE] = "Hello, ";
  const char *src = "world";
  s21_size_t n = 2;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_9) {
  char dst1[BUFFER_SIZE] = "Hello, ";
  char dst2[BUFFER_SIZE] = "Hello, ";
  const char *src = "world";
  s21_size_t n = 5;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_10) {
  char dst1[BUFFER_SIZE] = "Hello, ";
  char dst2[BUFFER_SIZE] = "Hello, ";
  const char *src = dst1 + 7;
  s21_size_t n = 3;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_11) {
  char dst1[BUFFER_SIZE] = "Goo\0dbye, ";
  char dst2[BUFFER_SIZE] = "Goo\0dbye, ";
  const char *src = "universe";
  s21_size_t n = 4;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_12) {
  char dst1[BUFFER_SIZE] = "Goo\ndbye, ";
  char dst2[BUFFER_SIZE] = "Goo\ndbye, ";
  const char *src = "universe";
  s21_size_t n = 10;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_13) {
  char dst1[BUFFER_SIZE] = "Goodbye, ";
  char dst2[BUFFER_SIZE] = "Goodbye, ";
  const char *src = "universe";
  s21_size_t n = 0;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_14) {
  char dst1[BUFFER_SIZE] = "";
  char dst2[BUFFER_SIZE] = "";
  const char *src = "universe";
  s21_size_t n = 4;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_15) {
  char dst1[BUFFER_SIZE] = "Goodbye, ";
  char dst2[BUFFER_SIZE] = "Goodbye, ";
  const char *src = "";
  s21_size_t n = 4;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_16) {
  char dst1[BUFFER_SIZE] = "";
  char dst2[BUFFER_SIZE] = "";
  const char *src = "";
  s21_size_t n = 4;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_17) {
  char dst1[BUFFER_SIZE] = "Goodbye, ";
  char dst2[BUFFER_SIZE] = "Goodbye, ";
  const char *src = "universe";
  s21_size_t n = 100;

  char *expected = strncat(dst1, src, n);
  char *result = strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_18) {
  char dst1[BUFFER_SIZE] = "Goodbye, ";
  char dst2[BUFFER_SIZE] = "Goodbye, ";
  const char *src = "universe";
  s21_size_t n = 2;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_19) {
  char dst1[BUFFER_SIZE] = "Goodbye, ";
  char dst2[BUFFER_SIZE] = "Goodbye, ";
  const char *src = "universe";
  s21_size_t n = 8;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

START_TEST(s21_strncat_20) {
  char dst1[BUFFER_SIZE] = "Goodbye, ";
  char dst2[BUFFER_SIZE] = "Goodbye, ";
  const char *src = dst1 + 9;
  s21_size_t n = 3;

  char *expected = strncat(dst1, src, n);
  char *result = s21_strncat(dst2, src, n);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}

Suite *s21_strncat_case_1(void) {
  Suite *string = suite_create("\ns21_strncat (s21_strncat case 1)\n");

  TCase *tc_s21_strncat = tcase_create("s21_strncat  test");

  tcase_add_test(tc_s21_strncat, s21_strncat_1);
  tcase_add_test(tc_s21_strncat, s21_strncat_2);
  tcase_add_test(tc_s21_strncat, s21_strncat_3);
  tcase_add_test(tc_s21_strncat, s21_strncat_4);
  tcase_add_test(tc_s21_strncat, s21_strncat_5);
  tcase_add_test(tc_s21_strncat, s21_strncat_6);
  tcase_add_test(tc_s21_strncat, s21_strncat_7);
  tcase_add_test(tc_s21_strncat, s21_strncat_8);
  tcase_add_test(tc_s21_strncat, s21_strncat_9);
  tcase_add_test(tc_s21_strncat, s21_strncat_10);
  tcase_add_test(tc_s21_strncat, s21_strncat_11);
  tcase_add_test(tc_s21_strncat, s21_strncat_12);
  tcase_add_test(tc_s21_strncat, s21_strncat_13);
  tcase_add_test(tc_s21_strncat, s21_strncat_14);
  tcase_add_test(tc_s21_strncat, s21_strncat_15);
  tcase_add_test(tc_s21_strncat, s21_strncat_16);
  tcase_add_test(tc_s21_strncat, s21_strncat_17);
  tcase_add_test(tc_s21_strncat, s21_strncat_18);
  tcase_add_test(tc_s21_strncat, s21_strncat_19);
  tcase_add_test(tc_s21_strncat, s21_strncat_20);

  suite_add_tcase(string, tc_s21_strncat);

  return string;
}
#endif  // STRNCAT
