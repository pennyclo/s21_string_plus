/**
 * @file s21_strspn_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strspn_test.
 * @version 1.0
 * @date 2024-12-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include_test/s21_strspn_test.h"

START_TEST(s21_strspn_1) {
  const char *str = "abcde12345";
  const char *accept = "abcde";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_2) {
  const char *str = "abcdef";
  const char *accept = "abcdef";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_3) {
  const char *str = "abcdef";
  const char *accept = "12345";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_4) {
  const char *str = "abcdef";
  const char *accept = "";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_5) {
  const char *str = "";
  const char *accept = "abcdef";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_6) {
  const char *str = "";
  const char *accept = "";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_7) {
  const char *str = "abcdef";
  const char *accept = "a";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_8) {
  const char *str = "abc123def";
  const char *accept = "abc";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_9) {
  const char *str = "abc123c";
  const char *accept = "aaabbbccc";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_10) {
  const char *str = "123abc";
  const char *accept = "abc";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_11) {
  const char *str = "abc\0def";
  const char *accept = "abcdef";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_12) {
  const char *str = "abcdef";
  const char *accept = "\0";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_13) {
  const char *str = "123abcde";
  const char *accept = "abcd";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_14) {
  const char *str = "aaaaabcde";
  const char *accept = "a";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_15) {
  const char *str = "abcdabcd";
  const char *accept = "abcd";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_16) {
  const char *str = "abc123";
  const char *accept =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_17) {
  const char *str = "    leading spaces";
  const char *accept = " ";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_18) {
  const char *str = "abcd1234";
  const char *accept = "abcd";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_19) {
  const char *str = "aaaaaaaaaaaaaaaaaaaaaaaaaaabcdef";
  const char *accept = "a";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_20) {
  const char *str = "a";
  const char *accept =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_21) {
  const char *str = "@#$%abc";
  const char *accept = "@#$%";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_22) {
  const char *str = "";
  const char *accept = "";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_23) {
  const char *str = "abc\0def";
  const char *accept = "abcdef";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_24) {
  const char *str = "abcdef";
  const char *accept = "abc\0def";
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

START_TEST(s21_strspn_25) {
  char str[1000], accept[1000];
  memset(str, 'a', 999);     // before implementation my func.
  memset(accept, 'a', 999);  // before implementation my func.
  str[999] = '\0';
  accept[999] = '\0';
  ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

Suite *s21_strspn_case_1(void) {
  Suite *string = suite_create("\ns21_strspn (s21_strspn case 1)\n");

  TCase *tc_s21_strspn = tcase_create("s21_strspn  test");

  tcase_add_test(tc_s21_strspn, s21_strspn_1);
  tcase_add_test(tc_s21_strspn, s21_strspn_2);
  tcase_add_test(tc_s21_strspn, s21_strspn_3);
  tcase_add_test(tc_s21_strspn, s21_strspn_4);
  tcase_add_test(tc_s21_strspn, s21_strspn_5);
  tcase_add_test(tc_s21_strspn, s21_strspn_6);
  tcase_add_test(tc_s21_strspn, s21_strspn_7);
  tcase_add_test(tc_s21_strspn, s21_strspn_8);
  tcase_add_test(tc_s21_strspn, s21_strspn_9);
  tcase_add_test(tc_s21_strspn, s21_strspn_10);
  tcase_add_test(tc_s21_strspn, s21_strspn_11);
  tcase_add_test(tc_s21_strspn, s21_strspn_12);
  tcase_add_test(tc_s21_strspn, s21_strspn_13);
  tcase_add_test(tc_s21_strspn, s21_strspn_14);
  tcase_add_test(tc_s21_strspn, s21_strspn_15);
  tcase_add_test(tc_s21_strspn, s21_strspn_16);
  tcase_add_test(tc_s21_strspn, s21_strspn_17);
  tcase_add_test(tc_s21_strspn, s21_strspn_18);
  tcase_add_test(tc_s21_strspn, s21_strspn_19);
  tcase_add_test(tc_s21_strspn, s21_strspn_20);
  tcase_add_test(tc_s21_strspn, s21_strspn_21);
  tcase_add_test(tc_s21_strspn, s21_strspn_22);
  tcase_add_test(tc_s21_strspn, s21_strspn_23);
  tcase_add_test(tc_s21_strspn, s21_strspn_24);
  tcase_add_test(tc_s21_strspn, s21_strspn_25);

  suite_add_tcase(string, tc_s21_strspn);

  return string;
}
