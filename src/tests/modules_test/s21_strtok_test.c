/**
 * @file s21_strtok_test.c
 * @author Artemy Plokhikh (https://github.com/isiyar)
 * @brief Implementation function s21_strtok_test.
 * @version 0.1
 * @date 2024-12-29
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include_test/s21_strtok_test.h"

START_TEST(s21_strtok_1) {
  char str1[] = "Hello, world!";
  char str2[] = "Hello, world!";
  const char delim[] = " ";
  ck_assert_str_eq(s21_strtok(str1, delim), strtok(str2, delim));
}
END_TEST

START_TEST(s21_strtok_2) {
  char str1[] = "a,b,c";
  char str2[] = "a,b,c";
  const char delim[] = ",";
  ck_assert_str_eq(s21_strtok(str1, delim), strtok(str2, delim));
  ck_assert_str_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(s21_strtok_3) {
  char str1[] = "word";
  char str2[] = "word";
  const char delim[] = ",";
  ck_assert_str_eq(s21_strtok(str1, delim), strtok(str2, delim));
  ck_assert_ptr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(s21_strtok_4) {
  char str1[] = "|||word1|||word2||";
  char str2[] = "|||word1|||word2||";
  const char delim[] = "|";
  ck_assert_str_eq(s21_strtok(str1, delim), strtok(str2, delim));
  ck_assert_str_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(s21_strtok_5) {
  char str1[] = "";
  char str2[] = "";
  const char delim[] = ",";
  ck_assert_ptr_eq(s21_strtok(str1, delim), strtok(str2, delim));
}
END_TEST

START_TEST(s21_strtok_6) {
  char str1[] = ",,,";
  char str2[] = ",,,";
  const char delim[] = ",";
  ck_assert_ptr_eq(s21_strtok(str1, delim), strtok(str2, delim));
  ck_assert_ptr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(s21_strtok_7) {
  char str1[] = "word";
  char str2[] = "word";
  const char delim[] = " ";
  ck_assert_str_eq(s21_strtok(str1, delim), strtok(str2, delim));
  ck_assert_ptr_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(s21_strtok_8) {
  char str1[] = "word1 word2";
  char str2[] = "word1 word2";
  const char delim[] = " ";
  ck_assert_str_eq(s21_strtok(str1, delim), strtok(str2, delim));
  ck_assert_str_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

START_TEST(s21_strtok_9) {
  char str1[] = "one,two,three";
  char str2[] = "one,two,three";
  const char delim[] = ",";
  ck_assert_str_eq(s21_strtok(str1, delim), strtok(str2, delim));
  ck_assert_str_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
  ck_assert_str_eq(s21_strtok(NULL, delim), strtok(NULL, delim));
}
END_TEST

Suite *s21_strtok_case_1(void) {
  Suite *string = suite_create("\ns21_strtok (s21_strtok case 1)\n");

  TCase *tc_s21_strtok = tcase_create("s21_strtok  test");

  tcase_add_test(tc_s21_strtok, s21_strtok_1);
  tcase_add_test(tc_s21_strtok, s21_strtok_2);
  tcase_add_test(tc_s21_strtok, s21_strtok_3);
  tcase_add_test(tc_s21_strtok, s21_strtok_4);
  tcase_add_test(tc_s21_strtok, s21_strtok_5);
  tcase_add_test(tc_s21_strtok, s21_strtok_6);
  tcase_add_test(tc_s21_strtok, s21_strtok_7);
  tcase_add_test(tc_s21_strtok, s21_strtok_8);
  tcase_add_test(tc_s21_strtok, s21_strtok_9);

  suite_add_tcase(string, tc_s21_strtok);

  return string;
}
