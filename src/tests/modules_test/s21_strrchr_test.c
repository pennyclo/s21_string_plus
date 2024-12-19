/**
 * @file s21_strrchr_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strrchr_test.
 * @version 1.0
 * @date 2024-12-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include_test/s21_strrchr_test.h"

START_TEST(s21_strrchr_1) {
  const char *str = "hello world";
  char ch = 'o';
  ck_assert_ptr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}
END_TEST

START_TEST(s21_strrchr_2) {
  const char *str = "hello world";
  char ch = 'z';
  ck_assert_ptr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}
END_TEST

START_TEST(s21_strrchr_3) {
  const char *str = "hello";
  char ch = 'h';
  ck_assert_ptr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}
END_TEST

START_TEST(s21_strrchr_4) {
  const char *str = "hello";
  char ch = 'o';
  ck_assert_ptr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}
END_TEST

START_TEST(s21_strrchr_5) {
  const char *str = "a";
  char ch = 'a';
  ck_assert_ptr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}
END_TEST

START_TEST(s21_strrchr_6) {
  const char *str = "";
  char ch = 'a';
  ck_assert_ptr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}
END_TEST

START_TEST(s21_strrchr_7) {
  const char *str = "hello hello";
  char ch = 'l';
  ck_assert_ptr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}
END_TEST

START_TEST(s21_strrchr_8) {
  const char *str = "hello\0world";
  char ch = '\0';
  ck_assert_ptr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}
END_TEST

START_TEST(s21_strrchr_9) {
  const char *str = "abcdef";
  char ch = 'd';
  ck_assert_ptr_eq(s21_strrchr(str, ch), strrchr(str, ch));
}
END_TEST

Suite *s21_strrchr_case_1(void) {
  Suite *string = suite_create("\ns21_strrchr (s21_strrchr case 1)\n");

  TCase *tc_s21_strrchr = tcase_create("s21_strrchr  test");

  tcase_add_test(tc_s21_strrchr, s21_strrchr_1);
  tcase_add_test(tc_s21_strrchr, s21_strrchr_2);
  tcase_add_test(tc_s21_strrchr, s21_strrchr_3);
  tcase_add_test(tc_s21_strrchr, s21_strrchr_4);
  tcase_add_test(tc_s21_strrchr, s21_strrchr_5);
  tcase_add_test(tc_s21_strrchr, s21_strrchr_6);
  tcase_add_test(tc_s21_strrchr, s21_strrchr_7);
  tcase_add_test(tc_s21_strrchr, s21_strrchr_8);
  tcase_add_test(tc_s21_strrchr, s21_strrchr_9);

  suite_add_tcase(string, tc_s21_strrchr);

  return string;
}
