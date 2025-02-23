/**
 * @file s21_trim_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_trim_test.
 * @version 1.0
 * @date 2025-02-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "../include_test/s21_trim_test.h"

START_TEST(s21_trim_1) {
  char src[] = "   Hello, world!   ";
  char trim_chars[] = " ";
  char *result = s21_trim(src, trim_chars);

  ck_assert_str_eq(result, "Hello, world!");
  free(result);
}
END_TEST

START_TEST(s21_trim_2) {
  char src[] = "*****Trimmed Text*****";
  char trim_chars[] = "*";
  char *result = s21_trim(src, trim_chars);

  ck_assert_str_eq(result, "Trimmed Text");
  free(result);
}
END_TEST

START_TEST(s21_trim_3) {
  char src[] = "NoTrimNeeded";
  char trim_chars[] = " ";
  char *result = s21_trim(src, trim_chars);

  ck_assert_str_eq(result, "NoTrimNeeded");
  free(result);
}
END_TEST

START_TEST(s21_trim_4) {
  char src[] = "123456789Test123456789";
  char trim_chars[] = "123456789";
  char *result = s21_trim(src, trim_chars);

  ck_assert_str_eq(result, "Test");
  free(result);
}
END_TEST

START_TEST(s21_trim_5) {
  char src[] = "\t\n Trim this! \n\t";
  char trim_chars[] = " \t\n";
  char *result = s21_trim(src, trim_chars);

  ck_assert_str_eq(result, "Trim this!");
  free(result);
}
END_TEST

START_TEST(s21_trim_6) {
  char src[] = "&&&&Keep_Middle&&&&";
  char trim_chars[] = "&";
  char *result = s21_trim(src, trim_chars);

  ck_assert_str_eq(result, "Keep_Middle");
  free(result);
}
END_TEST

START_TEST(s21_trim_7) {
  char src[] = "++++";
  char trim_chars[] = "+";
  char *result = s21_trim(src, trim_chars);

  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(s21_trim_8) {
  char src[] = " Only start trim";
  char trim_chars[] = " ";
  char *result = s21_trim(src, trim_chars);

  ck_assert_str_eq(result, "Only start trim");
  free(result);
}
END_TEST

START_TEST(s21_trim_9) {
  char src[] = "End trim only   ";
  char trim_chars[] = " ";
  char *result = s21_trim(src, trim_chars);

  ck_assert_str_eq(result, "End trim only");
  free(result);
}
END_TEST

START_TEST(s21_trim_10) {
  char *src = S21_NULL;
  char trim_chars[] = " ";
  char *result = s21_trim(src, trim_chars);

  ck_assert_ptr_eq(result, S21_NULL);
  free(result);
}
END_TEST

Suite *s21_trim_case_1(void) {
  Suite *string = suite_create("\ns21_trim (s21_trim case 1)\n");

  TCase *tc_s21_trim = tcase_create("s21_trim test");

  tcase_add_test(tc_s21_trim, s21_trim_1);
  tcase_add_test(tc_s21_trim, s21_trim_2);
  tcase_add_test(tc_s21_trim, s21_trim_3);
  tcase_add_test(tc_s21_trim, s21_trim_4);
  tcase_add_test(tc_s21_trim, s21_trim_5);
  tcase_add_test(tc_s21_trim, s21_trim_6);
  tcase_add_test(tc_s21_trim, s21_trim_7);
  tcase_add_test(tc_s21_trim, s21_trim_8);
  tcase_add_test(tc_s21_trim, s21_trim_9);
  tcase_add_test(tc_s21_trim, s21_trim_10);

  suite_add_tcase(string, tc_s21_trim);

  return string;
}
