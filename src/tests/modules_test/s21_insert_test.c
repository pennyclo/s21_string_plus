/**
 * @file s21_insert_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_insert_test.
 * @version 1.0
 * @date 2025-02-20
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "../include_test/s21_insert_test.h"

START_TEST(s21_insert_1) {
  char src[] = "Hello, world!";
  char str[] = " beautiful";
  size_t pos = 6;
  char *result = s21_insert(src, str, pos);

  ck_assert_str_eq(result, "Hello, beautiful world!");
  free(result);
}
END_TEST

START_TEST(s21_insert_2) {
  char src[] = "StartEnd";
  char str[] = " Middle";
  size_t pos = 5;
  char *result = s21_insert(src, str, pos);

  ck_assert_str_eq(result, "Start MiddleEnd");
  free(result);
}
END_TEST

START_TEST(s21_insert_3) {
  char src[] = "InsertHere";
  char str[] = "_";
  size_t pos = 6;
  char *result = s21_insert(src, str, pos);

  ck_assert_str_eq(result, "Insert_Here");
  free(result);
}
END_TEST

START_TEST(s21_insert_4) {
  char src[] = "ABCDEFG";
  char str[] = "123";
  size_t pos = 3;
  char *result = s21_insert(src, str, pos);

  ck_assert_str_eq(result, "ABC123DEFG");
  free(result);
}
END_TEST

START_TEST(s21_insert_5) {
  char src[] = "Edge";
  char str[] = "Case";
  size_t pos = 0;
  char *result = s21_insert(src, str, pos);

  ck_assert_str_eq(result, "CaseEdge");
  free(result);
}
END_TEST

START_TEST(s21_insert_6) {
  char src[] = "Last";
  char str[] = "Word";
  size_t pos = 4;
  char *result = s21_insert(src, str, pos);

  ck_assert_str_eq(result, "LastWord");
  free(result);
}
END_TEST

START_TEST(s21_insert_7) {
  char src[] = "Middle";
  char str[] = "";
  size_t pos = 3;
  char *result = s21_insert(src, str, pos);

  ck_assert_str_eq(result, "Middle");
  free(result);
}
END_TEST

START_TEST(s21_insert_8) {
  char src[] = "Insert at end";
  char str[] = "!!!";
  size_t pos = 13;
  char *result = s21_insert(src, str, pos);

  ck_assert_str_eq(result, "Insert at end!!!");
  free(result);
}
END_TEST

START_TEST(s21_insert_9) {
  char src[] = "Hello";
  char str[] = " world";
  size_t pos = 100;
  char *result = s21_insert(src, str, pos);

  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(s21_insert_10) {
  char src[] = "";
  char str[] = "Insert";
  size_t pos = 0;
  char *result = s21_insert(src, str, pos);

  ck_assert_str_eq(result, "Insert");
  free(result);
}
END_TEST

Suite *s21_insert_case_1(void) {
  Suite *string = suite_create("\ns21_insert (s21_insert case 1)\n");

  TCase *tc_s21_insert = tcase_create("s21_insert test");

  tcase_add_test(tc_s21_insert, s21_insert_1);
  tcase_add_test(tc_s21_insert, s21_insert_2);
  tcase_add_test(tc_s21_insert, s21_insert_3);
  tcase_add_test(tc_s21_insert, s21_insert_4);
  tcase_add_test(tc_s21_insert, s21_insert_5);
  tcase_add_test(tc_s21_insert, s21_insert_6);
  tcase_add_test(tc_s21_insert, s21_insert_7);
  tcase_add_test(tc_s21_insert, s21_insert_8);
  tcase_add_test(tc_s21_insert, s21_insert_9);
  tcase_add_test(tc_s21_insert, s21_insert_10);

  suite_add_tcase(string, tc_s21_insert);

  return string;
}
