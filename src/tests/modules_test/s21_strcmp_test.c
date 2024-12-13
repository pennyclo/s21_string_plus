/**
 * @file s21_strcmp_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strcmp_test.
 * @version 1.0
 * @date 2024-12-10
 *
 * @copyright Copyright (c) 2024
 */

#include "tests/include_test/s21_strcmp_test.h"

START_TEST(s21_strcmp_1) {
  const char *str1 = "Hello, world";
  const char *str2 = "Hello, world";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}

START_TEST(s21_strcmp_2) {
  const char *str1 = "Hello, world";
  const char *str2 = "hello, world";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}

START_TEST(s21_strcmp_3) {
  const char *str1 = "world";
  const char *str2 = "Hello, world";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}

START_TEST(s21_strcmp_4) {
  const char *str1 = "Hello, world";
  const char *str2 = "Hello, world!";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}

START_TEST(s21_strcmp_5) {
  const char *str1 = "";
  const char *str2 = "";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}

START_TEST(s21_strcmp_6) {
  const char *str1 = "A";
  const char *str2 = "a";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}

START_TEST(s21_strcmp_7) {
  const char *str1 = "12345";
  const char *str2 = "123456";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}

START_TEST(s21_strcmp_8) {
  const char *str1 = "123456";
  const char *str2 = "12345";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}

START_TEST(s21_strcmp_9) {
  const char *str1 = "a";
  const char *str2 = "b";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}

START_TEST(s21_strcmp_10) {
  const char *str1 = "a";
  const char *str2 = "b";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}

START_TEST(s21_strcmp_11) {
  const char *str1 = "abc";
  const char *str2 = "abc";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}

START_TEST(s21_strcmp_12) {
  const char *str1 = "Hello, world";
  const char *str2 = "";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}

START_TEST(s21_strcmp_13) {
  const char *str1 = "a\0b";
  const char *str2 = "a";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}

START_TEST(s21_strcmp_14) {
  const char *str1 = "tesT";
  const char *str2 = "test";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}

START_TEST(s21_strcmp_15) {
  const char *str1 = "This is a longer string";
  const char *str2 = "This is a";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}

Suite *s21_strcmp_case_1(void) {
  Suite *string = suite_create("\ns21_strcmp (s21_strcmp case 1)\n");

  TCase *tc_s21_strcmp = tcase_create("s21_strcmp  test");

  tcase_add_test(tc_s21_strcmp, s21_strcmp_1);
  tcase_add_test(tc_s21_strcmp, s21_strcmp_2);
  tcase_add_test(tc_s21_strcmp, s21_strcmp_3);
  tcase_add_test(tc_s21_strcmp, s21_strcmp_4);
  tcase_add_test(tc_s21_strcmp, s21_strcmp_5);
  tcase_add_test(tc_s21_strcmp, s21_strcmp_6);
  tcase_add_test(tc_s21_strcmp, s21_strcmp_7);
  tcase_add_test(tc_s21_strcmp, s21_strcmp_8);
  tcase_add_test(tc_s21_strcmp, s21_strcmp_9);
  tcase_add_test(tc_s21_strcmp, s21_strcmp_10);
  tcase_add_test(tc_s21_strcmp, s21_strcmp_11);
  tcase_add_test(tc_s21_strcmp, s21_strcmp_12);
  tcase_add_test(tc_s21_strcmp, s21_strcmp_13);
  tcase_add_test(tc_s21_strcmp, s21_strcmp_14);
  tcase_add_test(tc_s21_strcmp, s21_strcmp_15);

  suite_add_tcase(string, tc_s21_strcmp);

  return string;
}
