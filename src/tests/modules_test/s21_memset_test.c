/**
 * @file s21_memset_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_memset_test.
 * @version 1.0
 * @date 2024-12-31
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include_test/s21_memset_test.h"

START_TEST(s21_memset_1) {
  char str1[50] = "Hello, World!";
  char str2[50] = "Hello, World!";
  ck_assert_mem_eq(memset(str1, 'A', 5), s21_memset(str2, 'A', 5), 50);
}
END_TEST

START_TEST(s21_memset_2) {
  char str1[50] = "Test case for memset.";
  char str2[50] = "Test case for memset.";
  ck_assert_mem_eq(memset(str1, 0, 10), s21_memset(str2, 0, 10), 50);
}
END_TEST

START_TEST(s21_memset_3) {
  char str1[50] = "";
  char str2[50] = "";
  ck_assert_mem_eq(memset(str1, 'B', 0), s21_memset(str2, 'B', 0), 50);
}
END_TEST

START_TEST(s21_memset_4) {
  char str1[50] = "Single character test.";
  char str2[50] = "Single character test.";
  ck_assert_mem_eq(memset(str1, 'C', 1), s21_memset(str2, 'C', 1), 50);
}
END_TEST

START_TEST(s21_memset_5) {
  char str1[50] = "Edge case testing memset.";
  char str2[50] = "Edge case testing memset.";
  ck_assert_mem_eq(memset(str1, 'D', 22), s21_memset(str2, 'D', 22), 50);
}
END_TEST

START_TEST(s21_memset_6) {
  char str1[50] = "Filling the entire array.";
  char str2[50] = "Filling the entire array.";
  ck_assert_mem_eq(memset(str1, 'E', 50), s21_memset(str2, 'E', 50), 50);
}
END_TEST

START_TEST(s21_memset_7) {
  char str1[50] = "";
  char str2[50] = "";
  ck_assert_mem_eq(memset(str1, 'Z', 0), s21_memset(str2, 'Z', 0), 50);
}
END_TEST

START_TEST(s21_memset_8) {
  char str1[100] = {0};
  char str2[100] = {0};
  ck_assert_mem_eq(memset(str1, 'F', 25), s21_memset(str2, 'F', 25), 100);
}
END_TEST

START_TEST(s21_memset_9) {
  char str1[50] = "Testing memset with repeated fills.";
  char str2[50] = "Testing memset with repeated fills.";

  memset(str1, 'X', 10);
  s21_memset(str2, 'X', 10);

  memset(str1 + 5, 'Y', 10);
  s21_memset(str2 + 5, 'Y', 10);

  ck_assert_mem_eq(str1, str2, 50);
}
END_TEST

START_TEST(s21_memset_10) {
  char str1[50] = "Testing with special characters: @$#.";
  char str2[50] = "Testing with special characters: @$#.";
  ck_assert_mem_eq(memset(str1, '@', 30), s21_memset(str2, '@', 30), 50);
}
END_TEST

START_TEST(s21_memset_11) {
  char str1[50] = "Null terminator handling test.";
  char str2[50] = "Null terminator handling test.";
  memset(str1 + 5, '\0', 10);
  s21_memset(str2 + 5, '\0', 10);
  ck_assert_mem_eq(str1, str2, 50);
}
END_TEST

START_TEST(s21_memset_12) {
  char str1[50] = "Complete zeroing out.";
  char str2[50] = "Complete zeroing out.";
  ck_assert_mem_eq(memset(str1, 0, sizeof(str1)),
                   s21_memset(str2, 0, sizeof(str2)), 50);
}
END_TEST

START_TEST(s21_memset_13) {
  char str1[50] = "Partial memset check.";
  char str2[50] = "Partial memset check.";

  memset(str1 + 5, 'G', 5);
  s21_memset(str2 + 5, 'G', 5);

  ck_assert_mem_eq(str1, str2, 50);
}
END_TEST

START_TEST(s21_memset_14) {
  char str1[1] = {'A'};
  char str2[1] = {'A'};
  ck_assert_mem_eq(memset(str1, 'Z', 1), s21_memset(str2, 'Z', 1), 1);
}
END_TEST

START_TEST(s21_memset_15) {
  char str1[1000] = {0};
  char str2[1000] = {0};
  ck_assert_mem_eq(memset(str1, 'K', 999), s21_memset(str2, 'K', 999), 1000);
}
END_TEST

Suite *s21_memset_case_1(void) {
  Suite *string = suite_create("\ns21_memset (s21_memset case 1)\n");

  TCase *tc_s21_memset = tcase_create("s21_memset  test");

  tcase_add_test(tc_s21_memset, s21_memset_1);
  tcase_add_test(tc_s21_memset, s21_memset_2);
  tcase_add_test(tc_s21_memset, s21_memset_3);
  tcase_add_test(tc_s21_memset, s21_memset_4);
  tcase_add_test(tc_s21_memset, s21_memset_5);
  tcase_add_test(tc_s21_memset, s21_memset_6);
  tcase_add_test(tc_s21_memset, s21_memset_7);
  tcase_add_test(tc_s21_memset, s21_memset_8);
  tcase_add_test(tc_s21_memset, s21_memset_9);
  tcase_add_test(tc_s21_memset, s21_memset_10);
  tcase_add_test(tc_s21_memset, s21_memset_11);
  tcase_add_test(tc_s21_memset, s21_memset_12);
  tcase_add_test(tc_s21_memset, s21_memset_13);
  tcase_add_test(tc_s21_memset, s21_memset_14);
  tcase_add_test(tc_s21_memset, s21_memset_15);

  suite_add_tcase(string, tc_s21_memset);

  return string;
}
