/**
 * @file s21_strncpy_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strncpy_test.
 * @version 1.0
 * @date 2024-12-16
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include_test/s21_strncpy_test.h"

#include <check.h>
#include <string.h>

#include "include/common.h"

START_TEST(s21_strncpy_1) {
  char src[] = "Hello, World!";
  char dest1[20] = {0};
  char dest2[20] = {0};
  s21_size_t n = 5;

  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_strncpy_2) {
  char src[] = "Exact length";
  char dest1[20] = {0};
  char dest2[20] = {0};
  s21_size_t n = 12;

  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_strncpy_3) {
  char src[] = "Short";
  char dest1[10] = {0};
  char dest2[10] = {0};
  s21_size_t n = 10;

  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);

  ck_assert_mem_eq(dest1, dest2, 10);
}
END_TEST

START_TEST(s21_strncpy_4) {
  char src[] = "";
  char dest1[10] = "abcdef";
  char dest2[10] = "abcdef";
  s21_size_t n = 6;

  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);

  ck_assert_mem_eq(dest1, dest2, 10);
}
END_TEST

START_TEST(s21_strncpy_5) {
  char src[] = "Nothing copied";
  char dest1[20] = "Original buffer";
  char dest2[20] = "Original buffer";
  s21_size_t n = 0;

  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);

  ck_assert_mem_eq(dest1, dest2, 20);
}
END_TEST

START_TEST(s21_strncpy_6) {
  char src[] = "With spaces in string";
  char dest1[30] = {0};
  char dest2[30] = {0};
  s21_size_t n = 10;

  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);

  ck_assert_mem_eq(dest1, dest2, 30);
}
END_TEST

START_TEST(s21_strncpy_7) {
  char src[] = "Line1\nLine2\tLine3";
  char dest1[25] = {0};
  char dest2[25] = {0};
  s21_size_t n = 18;

  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);

  ck_assert_mem_eq(dest1, dest2, 25);
}
END_TEST

START_TEST(s21_strncpy_8) {
  char src[] = "Null\0byte";
  char dest1[10] = {0};
  char dest2[10] = {0};
  s21_size_t n = 9;

  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);

  ck_assert_mem_eq(dest1, dest2, 10);
}
END_TEST

START_TEST(s21_strncpy_9) {
  char src[] = "This is a very long string for testing";
  char dest1[15] = {0};
  char dest2[15] = {0};
  s21_size_t n = 10;

  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);

  ck_assert_mem_eq(dest1, dest2, 15);
}
END_TEST

START_TEST(s21_strncpy_10) {
  char src[20] = "Self copy test";
  char dest[20];
  s21_size_t n = 15;

  strncpy(dest, src, n);
  s21_strncpy(dest, src, n);

  ck_assert_str_eq(dest, src);
}
END_TEST

START_TEST(s21_strncpy_11) {
  char src[] = "This string is too long";
  char dest1[10] = {0};
  char dest2[10] = {0};
  s21_size_t n = 9;

  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);

  ck_assert_mem_eq(dest1, dest2, 10);
}
END_TEST

START_TEST(s21_strncpy_12) {
  char src[] = "";
  char dest1[50] = {0};
  char dest2[50] = {0};
  s21_size_t n = 50;

  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);

  ck_assert_mem_eq(dest1, dest2, 50);
}
END_TEST

START_TEST(s21_strncpy_13) {
  char src[] = "";
  char dest1[1] = {0};
  char dest2[1] = {0};
  s21_size_t n = 0;

  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);

  ck_assert_mem_eq(dest1, dest2, 1);
}
END_TEST

START_TEST(s21_strncpy_14) {
  char src[] = "!@#$%^&*()_+";
  char dest1[15] = {0};
  char dest2[15] = {0};
  s21_size_t n = 12;

  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);

  ck_assert_mem_eq(dest1, dest2, 15);
}
END_TEST

START_TEST(s21_strncpy_15) {
  char src[] = "Replace me";
  char dest1[20] = "Old Data Here";
  char dest2[20] = "Old Data Here";
  s21_size_t n = 10;

  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);

  ck_assert_mem_eq(dest1, dest2, 20);
}
END_TEST

Suite *s21_strncpy_case_1(void) {
  Suite *string = suite_create("\ns21_strncpy (s21_strncpy case 1)\n");

  TCase *tc_s21_strncpy = tcase_create("s21_strncpy  test");

  tcase_add_test(tc_s21_strncpy, s21_strncpy_1);
  tcase_add_test(tc_s21_strncpy, s21_strncpy_2);
  tcase_add_test(tc_s21_strncpy, s21_strncpy_3);
  tcase_add_test(tc_s21_strncpy, s21_strncpy_4);
  tcase_add_test(tc_s21_strncpy, s21_strncpy_5);
  tcase_add_test(tc_s21_strncpy, s21_strncpy_6);
  tcase_add_test(tc_s21_strncpy, s21_strncpy_7);
  tcase_add_test(tc_s21_strncpy, s21_strncpy_8);
  tcase_add_test(tc_s21_strncpy, s21_strncpy_9);
  tcase_add_test(tc_s21_strncpy, s21_strncpy_10);
  tcase_add_test(tc_s21_strncpy, s21_strncpy_11);
  tcase_add_test(tc_s21_strncpy, s21_strncpy_12);
  tcase_add_test(tc_s21_strncpy, s21_strncpy_13);
  tcase_add_test(tc_s21_strncpy, s21_strncpy_14);
  tcase_add_test(tc_s21_strncpy, s21_strncpy_15);

  suite_add_tcase(string, tc_s21_strncpy);

  return string;
}
