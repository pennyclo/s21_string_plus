/**
 * @file s21_strncmp_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strncmp_test.
 * @version 1.0
 * @date 2024-12-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include_test/s21_strncmp_test.h"

START_TEST(s21_strncmp_1) {
  const char *str1 = "This is a longer string";
  const char *str2 = "This is a";
  s21_size_t n = 4;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_2) {
  char str1[] = "abcdefg";
  char str2[] = "abcdefg";
  s21_size_t n = 7;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
  n = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
  n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_3) {
  char str1[] = "abcdefg";
  char str2[] = "abcdefh";
  s21_size_t n = 6;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_4) {
  char str1[] = "abcdefg";
  char *str2 = "bbcdefg";
  s21_size_t n = 7;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
  n = 1;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_5) {
  char str1[] = "abc";
  char str2[] = "abcdefg";
  s21_size_t n = 4;  // n > strlen(str1)
  ck_assert_int_ne(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
  n = 7;
  ck_assert_int_ne(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_6) {
  char str1[] = "";
  char str2[] = "abc";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
  ck_assert_int_eq(s21_strncmp(str2, str1, n), strncmp(str2, str1, n));
  ck_assert_int_eq(s21_strncmp(str1, str1, n), strncmp(str1, str1, n));
}
END_TEST

START_TEST(s21_strncmp_7) {
  char str1[] = "abc\0def";
  char str2[] = "abc";
  s21_size_t n = 4;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
  n = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
  n = 7;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_8) {
  char str1[] = "abc";
  char str2[] = "def";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_9) {
  char *str1 = "abc";
  char str2[] = "def";
  s21_size_t n = 1000;  // Large value
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_10) {
  char str1[] = "abc";
  char *str2 = "";
  s21_size_t n = 3;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

Suite *s21_strncmp_case_1(void) {
  Suite *string = suite_create("\ns21_strncmp (s21_strncmp case 1)\n");

  TCase *tc_s21_strncmp = tcase_create("s21_strncmp  test");

  tcase_add_test(tc_s21_strncmp, s21_strncmp_1);
  tcase_add_test(tc_s21_strncmp, s21_strncmp_2);
  tcase_add_test(tc_s21_strncmp, s21_strncmp_3);
  tcase_add_test(tc_s21_strncmp, s21_strncmp_4);
  tcase_add_test(tc_s21_strncmp, s21_strncmp_5);
  tcase_add_test(tc_s21_strncmp, s21_strncmp_6);
  tcase_add_test(tc_s21_strncmp, s21_strncmp_7);
  tcase_add_test(tc_s21_strncmp, s21_strncmp_8);
  tcase_add_test(tc_s21_strncmp, s21_strncmp_9);
  tcase_add_test(tc_s21_strncmp, s21_strncmp_10);

  suite_add_tcase(string, tc_s21_strncmp);

  return string;
}
