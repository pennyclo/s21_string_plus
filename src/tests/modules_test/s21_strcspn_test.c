/**
 * @file s21_strcspn_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strcspn_test.
 * @version 1.0
 * @date 2024-12-17
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include_test/s21_strcspn_test.h"

START_TEST(s21_strcspn_1) {
  const char *str1 = "";
  const char *str2 = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_2) {
  const char *str1 = "";
  const char *str2 = "abc";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_3) {
  const char *str1 = "abc";
  const char *str2 = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_4) {
  const char *str1 = "hello";
  const char *str2 = "xyz";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_5) {
  const char *str1 = "hello";
  const char *str2 = "h";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_6) {
  const char *str1 = "hello";
  const char *str2 = "l";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_7) {
  const char *str1 = "hello";
  const char *str2 = "o";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_8) {
  const char *str1 = "abcdefg";
  const char *str2 = "cdef";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_9) {
  const char *str1 = "abc";
  const char *str2 = "abc";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_10) {
  const char *str1 = "abcdefghijklmnopqrstuvwxyz";
  const char *str2 = "mnop";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_11) {
  const char *str1 = "hello, world!";
  const char *str2 = ",!";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_12) {
  const char *str1 = "12345";
  const char *str2 = "67890";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_13) {
  const char *str1 = "Hel\nlo\t, wo\0rld";
  const char *str2 = "\t,";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_14) {
  const char *str1 = "abc\0def";
  const char *str2 = "d";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_15) {
  const char *str1 = "abc\0def";
  const char *str2 = "xyz";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

Suite *s21_strcspn_case_1(void) {
  Suite *string = suite_create("\ns21_strcspn (s21_strcspn case 1)\n");

  TCase *tc_s21_strcspn = tcase_create("s21_strcspn  test");

  tcase_add_test(tc_s21_strcspn, s21_strcspn_1);
  tcase_add_test(tc_s21_strcspn, s21_strcspn_2);
  tcase_add_test(tc_s21_strcspn, s21_strcspn_3);
  tcase_add_test(tc_s21_strcspn, s21_strcspn_4);
  tcase_add_test(tc_s21_strcspn, s21_strcspn_5);
  tcase_add_test(tc_s21_strcspn, s21_strcspn_6);
  tcase_add_test(tc_s21_strcspn, s21_strcspn_7);
  tcase_add_test(tc_s21_strcspn, s21_strcspn_8);
  tcase_add_test(tc_s21_strcspn, s21_strcspn_9);
  tcase_add_test(tc_s21_strcspn, s21_strcspn_10);
  tcase_add_test(tc_s21_strcspn, s21_strcspn_11);
  tcase_add_test(tc_s21_strcspn, s21_strcspn_12);
  tcase_add_test(tc_s21_strcspn, s21_strcspn_13);
  tcase_add_test(tc_s21_strcspn, s21_strcspn_14);
  tcase_add_test(tc_s21_strcspn, s21_strcspn_15);

  suite_add_tcase(string, tc_s21_strcspn);

  return string;
}