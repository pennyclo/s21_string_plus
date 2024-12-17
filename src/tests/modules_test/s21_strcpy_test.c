/**
 * @file s21_strcpy_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strcpy_test.
 * @version 1.0
 * @date 2024-12-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include_test/s21_strcpy_test.h"

START_TEST(s21_strcpy_1) {
  char src[] = "Hello, world!";
  char dest[50];
  char *result = s21_strcpy(dest, src);

  ck_assert_str_eq(result, dest);
  ck_assert_ptr_eq(result, dest);
  ck_assert_str_eq(dest, src);
}
END_TEST

START_TEST(s21_strcpy_2) {
  char src[] = "";
  char dest[50];
  char *result = s21_strcpy(dest, src);

  ck_assert_str_eq(result, dest);
  ck_assert_ptr_eq(result, dest);
  ck_assert_str_eq(dest, src);
}
END_TEST

START_TEST(s21_strcpy_3) {
  char src_dest[50] = "Test";
  char *result = s21_strcpy(src_dest, src_dest);

  ck_assert_str_eq(src_dest, "Test");
  ck_assert_ptr_eq(result, src_dest);
}
END_TEST

START_TEST(s21_strcpy_4) {
  char src[1024];
  for (int i = 0; i < 1023; ++i) {
    src[i] = 'a';
  }
  src[1023] = '\0';
  char dest[1024];
  char *result = s21_strcpy(dest, src);

  ck_assert_str_eq(result, dest);
  ck_assert_ptr_eq(result, dest);
  ck_assert_str_eq(dest, src);
}
END_TEST

START_TEST(s21_strcpy_5) {
  char dest[50];
  char *src = "\n";
  char *result = s21_strcpy(dest, src);

  ck_assert_str_eq(result, dest);
  ck_assert_ptr_eq(result, dest);
  ck_assert_str_eq(dest, src);
}
END_TEST

START_TEST(s21_strcpy_6) {
  char src[] = "Test";
  char dest[] = "test";
  char *result = s21_strcpy(dest, src);

  ck_assert_str_eq(result, "Test");
  ck_assert_str_eq(result, src);
}
END_TEST

START_TEST(s21_strcpy_7) {
  char src[] = "Line1\nLine2\tEnd";
  char dest[50] = {0};
  char *result = s21_strcpy(dest, src);

  ck_assert_str_eq(result, dest);
  ck_assert_str_eq(dest, src);
  ck_assert_ptr_eq(result, dest);
}
END_TEST

START_TEST(s21_strcpy_8) {
  char src[] = "This is a string with spaces and punctuation.";
  char dest[100];
  char *result = s21_strcpy(dest, src);

  ck_assert_str_eq(result, dest);
  ck_assert_str_eq(dest, src);
  ck_assert_ptr_eq(result, dest);
}
END_TEST

START_TEST(s21_strcpy_9) {
  char src[] = "This is a long string";
  char dest[30];
  char *result = s21_strcpy(dest, src);

  ck_assert_str_eq(result, dest);
  ck_assert_ptr_eq(result, dest);
  ck_assert_str_eq(dest, src);
}
END_TEST

START_TEST(s21_strcpy_10) {
  char src[] = "\0";
  char dest[100];
  char *result = s21_strcpy(dest, src);

  ck_assert_str_eq(result, dest);
  ck_assert_ptr_eq(result, dest);
  ck_assert_str_eq(dest, src);
}
END_TEST

Suite *s21_strcpy_case_1(void) {
  Suite *string = suite_create("\ns21_strcpy (s21_strcpy case 1)\n");

  TCase *tc_s21_strcpy = tcase_create("s21_strcpy  test");

  tcase_add_test(tc_s21_strcpy, s21_strcpy_1);
  tcase_add_test(tc_s21_strcpy, s21_strcpy_2);
  tcase_add_test(tc_s21_strcpy, s21_strcpy_3);
  tcase_add_test(tc_s21_strcpy, s21_strcpy_4);
  tcase_add_test(tc_s21_strcpy, s21_strcpy_5);
  tcase_add_test(tc_s21_strcpy, s21_strcpy_6);
  tcase_add_test(tc_s21_strcpy, s21_strcpy_7);
  tcase_add_test(tc_s21_strcpy, s21_strcpy_8);
  tcase_add_test(tc_s21_strcpy, s21_strcpy_9);
  tcase_add_test(tc_s21_strcpy, s21_strcpy_10);

  suite_add_tcase(string, tc_s21_strcpy);

  return string;
}
