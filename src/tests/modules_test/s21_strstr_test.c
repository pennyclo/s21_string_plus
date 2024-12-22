/**
 * @file s21_strstr_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strstr_test.
 * @version 1.0
 * @date 2024-12-21
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include_test/s21_strstr_test.h"

START_TEST(s21_strstr_1) {
  const char *haystack = "hello world";
  const char *needle = "world";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_2) {
  const char *haystack = "hello world";
  const char *needle = "";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_3) {
  const char *haystack = "";
  const char *needle = "world";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_4) {
  const char *haystack = "";
  const char *needle = "";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_5) {
  const char *haystack = "hello world";
  const char *needle = "planet";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_6) {
  const char *haystack = "hello world";
  const char *needle = "worl";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_7) {
  const char *haystack = "hello world";
  const char *needle = "d";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_8) {
  const char *haystack = "hello world";
  const char *needle = "hello";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_9) {
  const char *haystack = "abcabcabc";
  const char *needle = "c";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_10) {
  const char *haystack = "exact";
  const char *needle = "exact";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_11) {
  const char *haystack = "short";
  const char *needle = "this is long";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_12) {
  const char *haystack = "abababab";
  const char *needle = "abab";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_13) {
  const char *haystack = "abc@#def$%^ghi";
  const char *needle = "@#def";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_14) {
  const char *haystack = "abc\0def";
  const char *needle = "def";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_15) {
  const char *haystack = "abcdef";
  const char *needle = "c\0";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_16) {
  const char *haystack = "";
  const char *needle = "";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_17) {
  const char *haystack = "hello world";
  const char *needle = " ";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_18) {
  const char *haystack = "     ";
  const char *needle = " ";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_19) {
  char haystack[1000];
  memset(haystack, 'a', 999);
  haystack[999] = '\0';
  const char *needle = "aaa";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_20) {
  char haystack[1000] = "abc";
  char needle[1000];
  memset(needle, 'a', 999);
  needle[999] = '\0';
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(s21_strstr_21) {
  const char *haystack = "abcabcabce";
  const char *needle = "ceec";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

Suite *s21_strstr_case_1(void) {
  Suite *string = suite_create("\ns21_strstr (s21_strstr case 1)\n");

  TCase *tc_s21_strstr = tcase_create("s21_strstr  test");

  tcase_add_test(tc_s21_strstr, s21_strstr_1);
  tcase_add_test(tc_s21_strstr, s21_strstr_2);
  tcase_add_test(tc_s21_strstr, s21_strstr_3);
  tcase_add_test(tc_s21_strstr, s21_strstr_4);
  tcase_add_test(tc_s21_strstr, s21_strstr_5);
  tcase_add_test(tc_s21_strstr, s21_strstr_6);
  tcase_add_test(tc_s21_strstr, s21_strstr_7);
  tcase_add_test(tc_s21_strstr, s21_strstr_8);
  tcase_add_test(tc_s21_strstr, s21_strstr_9);
  tcase_add_test(tc_s21_strstr, s21_strstr_10);
  tcase_add_test(tc_s21_strstr, s21_strstr_11);
  tcase_add_test(tc_s21_strstr, s21_strstr_12);
  tcase_add_test(tc_s21_strstr, s21_strstr_13);
  tcase_add_test(tc_s21_strstr, s21_strstr_14);
  tcase_add_test(tc_s21_strstr, s21_strstr_15);
  tcase_add_test(tc_s21_strstr, s21_strstr_16);
  tcase_add_test(tc_s21_strstr, s21_strstr_17);
  tcase_add_test(tc_s21_strstr, s21_strstr_18);
  tcase_add_test(tc_s21_strstr, s21_strstr_19);
  tcase_add_test(tc_s21_strstr, s21_strstr_20);
  tcase_add_test(tc_s21_strstr, s21_strstr_21);

  suite_add_tcase(string, tc_s21_strstr);

  return string;
}
