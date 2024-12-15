/**
 * @file s21_strchr_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strchr_test.
 * @version 1.0
 * @date 2024-12-10
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "tests/include_test/s21_strchr_test.h"

#define BUFFER_SIZE 1024

START_TEST(s21_strchr_1) {
  char dst[BUFFER_SIZE] = "Hello, world";
  int ch = 'w';

  comparison_func(dst, ch);
}

START_TEST(s21_strchr_2) {
  char dst[BUFFER_SIZE] = "world";
  char ch = 'w';

  comparison_func(dst, ch);
}

START_TEST(s21_strchr_3) {
  char dst[BUFFER_SIZE] = "Hello, w";
  char ch = 'w';

  comparison_func(dst, ch);
}

START_TEST(s21_strchr_4) {
  char dst[BUFFER_SIZE] = "Hello, world";
  char ch = 'x';

  comparison_func(dst, ch);
}

START_TEST(s21_strchr_5) {
  char dst[BUFFER_SIZE] = "";
  char ch = 'x';

  comparison_func(dst, ch);
}

START_TEST(s21_strchr_6) {
  char dst[BUFFER_SIZE] = "\n";
  char ch = '\n';

  comparison_func(dst, ch);
}

START_TEST(s21_strchr_7) {
  char dst[BUFFER_SIZE] = "Hello\0world";
  char ch = 'o';

  comparison_func(dst, ch);
}

START_TEST(s21_strchr_8) {
  char large_string[10000];
  memset(large_string, 'a', sizeof(large_string) - 1);
  large_string[sizeof(large_string) - 1] = '\0';
  char dst[BUFFER_SIZE];
  strcpy(dst, large_string);  // not implemented yet
  strcpy(dst, large_string);  // not implemented yet
  char ch = 'a';

  comparison_func(dst, ch);
}

START_TEST(s21_strchr_9) {
  const char str[] = "\0";  // Empty string
  int c = 'a';              // Character NOT present in empty string.
  char *result = s21_strchr(str, c);
  ck_assert_ptr_null(
      result);  // Standard strchr behavior is to return NULL, even if empty.
}

void comparison_func(char *dst, int ch) {
  char *expected = strchr(dst, ch);
  char *result = s21_strchr(dst, ch);
  if (expected && result) {
    ck_assert_str_eq(result, expected);
  } else {
    ck_assert_ptr_eq(result, expected);
  }
}

Suite *s21_strchr_case_1(void) {
  Suite *string = suite_create("\ns21_strchr (s21_strchr case 1)\n");

  TCase *tc_s21_strchr = tcase_create("s21_strchr  test");

  tcase_add_test(tc_s21_strchr, s21_strchr_1);
  tcase_add_test(tc_s21_strchr, s21_strchr_2);
  tcase_add_test(tc_s21_strchr, s21_strchr_3);
  tcase_add_test(tc_s21_strchr, s21_strchr_4);
  tcase_add_test(tc_s21_strchr, s21_strchr_5);
  tcase_add_test(tc_s21_strchr, s21_strchr_6);
  tcase_add_test(tc_s21_strchr, s21_strchr_7);
  tcase_add_test(tc_s21_strchr, s21_strchr_8);
  tcase_add_test(tc_s21_strchr, s21_strchr_9);

  suite_add_tcase(string, tc_s21_strchr);

  return string;
}
