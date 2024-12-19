/**
 * @file s21_strpbrk_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strpbrk_test.
 * @version 1.0
 * @date 2024-12-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include_test/s21_strpbrk_test.h"

START_TEST(s21_strpbrk_1) {
  const char *str1 = "";
  const char *str2 = "";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_2) {
  const char *str1 = "";
  const char *str2 = "abc";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_3) {
  const char *str1 = "hello";
  const char *str2 = "";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_4) {
  const char *str1 = "hello";
  const char *str2 = "h";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_5) {
  const char *str1 = "hello";
  const char *str2 = "el";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_6) {
  const char *str1 = "hello";
  const char *str2 = "o";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_7) {
  const char *str1 = "hello";
  const char *str2 = "xyz";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_8) {
  const char *str1 = "a";
  const char *str2 = "abc";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_9) {
  const char *str1 = "hello";
  const char *str2 = "o";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_10) {
  const char *str1 = "hello";
  const char *str2 = "lllllllo";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_11) {
  const char *str1 = "abc";
  const char *str2 = "abc";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_12) {
  const char *str1 = "hello123";
  const char *str2 = "!@#$%^&*";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_13) {
  const char *str1 = "hello@world";
  const char *str2 = "@";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_14) {
  const char *str1 = "     ";
  const char *str2 = "abc ";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_15) {
  const char *str1 = "!@#$%^&*()_+";
  const char *str2 = "^&";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_16) {
  const char *str1 = "hello";
  const char *str2 = "o";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_17) {
  const char *str1 = "Lorem ipsum dolor sit amet";
  const char *str2 = "aeiou";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

Suite *s21_strpbrk_case_1(void) {
  Suite *string = suite_create("\ns21_strpbrk (s21_strpbrk case 1)\n");

  TCase *tc_s21_strpbrk = tcase_create("s21_strpbrk  test");

  tcase_add_test(tc_s21_strpbrk, s21_strpbrk_1);
  tcase_add_test(tc_s21_strpbrk, s21_strpbrk_2);
  tcase_add_test(tc_s21_strpbrk, s21_strpbrk_3);
  tcase_add_test(tc_s21_strpbrk, s21_strpbrk_4);
  tcase_add_test(tc_s21_strpbrk, s21_strpbrk_5);
  tcase_add_test(tc_s21_strpbrk, s21_strpbrk_6);
  tcase_add_test(tc_s21_strpbrk, s21_strpbrk_7);
  tcase_add_test(tc_s21_strpbrk, s21_strpbrk_8);
  tcase_add_test(tc_s21_strpbrk, s21_strpbrk_9);
  tcase_add_test(tc_s21_strpbrk, s21_strpbrk_10);
  tcase_add_test(tc_s21_strpbrk, s21_strpbrk_11);
  tcase_add_test(tc_s21_strpbrk, s21_strpbrk_12);
  tcase_add_test(tc_s21_strpbrk, s21_strpbrk_13);
  tcase_add_test(tc_s21_strpbrk, s21_strpbrk_14);
  tcase_add_test(tc_s21_strpbrk, s21_strpbrk_15);
  tcase_add_test(tc_s21_strpbrk, s21_strpbrk_16);
  tcase_add_test(tc_s21_strpbrk, s21_strpbrk_17);

  suite_add_tcase(string, tc_s21_strpbrk);

  return string;
}
