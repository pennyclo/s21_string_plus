/**
 * @file s21_strcat_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strcat_test.
 * @version 1.0
 * @date 2024-12-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include_test/s21_strcat_test.h"

#define BUFFER_SIZE 1024

START_TEST(s21_strcat_1) {
  char dst1[BUFFER_SIZE] = "Hello, ";
  char dst2[BUFFER_SIZE] = "Hello, ";
  const char *src = "world";

  char *expected = strcat(dst1, src);
  char *result = s21_strcat(dst2, src);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(s21_strcat_2) {
  char dst1[BUFFER_SIZE] = "Yk0(CuOG(s+O@M";
  char dst2[BUFFER_SIZE] = "Yk0(CuOG(s+O@M";
  const char *src = "pV1Mof)";

  char *expected = strcat(dst1, src);
  char *result = s21_strcat(dst2, src);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(s21_strcat_3) {
  char dst1[BUFFER_SIZE] = "w4qAIOkF7";
  char dst2[BUFFER_SIZE] = "w4qAIOkF7";
  const char *src = "BjOsKEs";

  char *expected = strcat(dst1, src);
  char *result = s21_strcat(dst2, src);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(s21_strcat_4) {
  char dst1[BUFFER_SIZE] = "cd!_7kEJa%ey6I4nM";
  char dst2[BUFFER_SIZE] = "cd!_7kEJa%ey6I4nM";
  const char *src = "r+";

  char *expected = strcat(dst1, src);
  char *result = s21_strcat(dst2, src);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(s21_strcat_5) {
  char dst1[BUFFER_SIZE] = "ABh";
  char dst2[BUFFER_SIZE] = "ABh";
  const char *src = " G245hUf";

  char *expected = strcat(dst1, src);
  char *result = s21_strcat(dst2, src);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(s21_strcat_6) {
  char dst1[BUFFER_SIZE] = "";
  char dst2[BUFFER_SIZE] = "";
  const char *src = "Hello";

  char *expected = strcat(dst1, src);
  char *result = s21_strcat(dst2, src);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(s21_strcat_7) {
  char dst1[BUFFER_SIZE] = "ABh";
  char dst2[BUFFER_SIZE] = "ABh";
  const char *src = "";

  char *expected = strcat(dst1, src);
  char *result = s21_strcat(dst2, src);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(s21_strcat_8) {
  char dst1[BUFFER_SIZE] = "";
  char dst2[BUFFER_SIZE] = "";
  const char *src = " ";

  char *expected = strcat(dst1, src);
  char *result = s21_strcat(dst2, src);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(s21_strcat_9) {
  char dst1[BUFFER_SIZE] = "";
  char dst2[BUFFER_SIZE] = "";
  const char *src = "";

  char *expected = strcat(dst1, src);
  char *result = s21_strcat(dst2, src);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(s21_strcat_10) {
  char dst1[BUFFER_SIZE] =
      "This is a very long string to test the functionality of strcat.";
  char dst2[BUFFER_SIZE] =
      "This is a very long string to test the functionality of strcat.";
  char src[] = " This is another long string to append.";

  char *expected = strcat(dst1, src);
  char *result = s21_strcat(dst2, src);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(s21_strcat_11) {
  char dst1[BUFFER_SIZE] = "Hello\0World";
  char dst2[BUFFER_SIZE] = "Hello\0World";
  char src[] = "!";

  char *expected = strcat(dst1, src);
  char *result = s21_strcat(dst2, src);
  ck_assert_str_eq(result, expected);
  ck_assert_mem_eq(dst1, dst2, strlen(dst1) + 1);
}
END_TEST

START_TEST(s21_strcat_12) {
  char dst1[11] = "123456789";
  char dst2[11] = "123456789";
  char src[] = "a";

  char *result = s21_strcat(dst2, src);
  char *expected = strcat(dst1, src);
  ck_assert_str_eq(result, expected);

  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(s21_strcat_13) {
  char dst1[BUFFER_SIZE] = "\n, ";
  char dst2[BUFFER_SIZE] = "\n, ";
  const char *src = "\0!";

  char *expected = strcat(dst1, src);
  char *result = s21_strcat(dst2, src);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(s21_strcat_14) {
  char dst1[BUFFER_SIZE] = "a";
  char dst2[BUFFER_SIZE] = "a";
  const char *src = "b";

  char *expected = strcat(dst1, src);
  char *result = s21_strcat(dst2, src);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

START_TEST(s21_strcat_15) {
  char dst1[BUFFER_SIZE] = "";
  char dst2[BUFFER_SIZE] = "";
  const char *src = "";

  char *expected = strcat(dst1, src);
  char *result = s21_strcat(dst2, src);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);

  dst1[0] = '\0';
  dst2[0] = '\0';
  src = "test";
  expected = strcat(dst1, src);
  result = s21_strcat(dst2, src);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);

  dst1[0] = 't';
  dst1[1] = 'e';
  dst1[2] = 's';
  dst1[3] = 't';
  dst1[4] = '\0';
  dst2[0] = 't';
  dst2[1] = 'e';
  dst2[2] = 's';
  dst2[3] = 't';
  dst2[4] = '\0';
  src = "";
  expected = strcat(dst1, src);
  result = s21_strcat(dst2, src);
  ck_assert_str_eq(result, expected);
  ck_assert_str_eq(dst1, dst2);
}
END_TEST

Suite *s21_strcat_case_1(void) {
  Suite *string = suite_create("\ns21_strcat (s21_strcat case 1)\n");

  TCase *tc_s21_strcat = tcase_create("s21_strcat  test");

  tcase_add_test(tc_s21_strcat, s21_strcat_1);
  tcase_add_test(tc_s21_strcat, s21_strcat_2);
  tcase_add_test(tc_s21_strcat, s21_strcat_3);
  tcase_add_test(tc_s21_strcat, s21_strcat_4);
  tcase_add_test(tc_s21_strcat, s21_strcat_5);
  tcase_add_test(tc_s21_strcat, s21_strcat_6);
  tcase_add_test(tc_s21_strcat, s21_strcat_7);
  tcase_add_test(tc_s21_strcat, s21_strcat_8);
  tcase_add_test(tc_s21_strcat, s21_strcat_9);
  tcase_add_test(tc_s21_strcat, s21_strcat_10);
  tcase_add_test(tc_s21_strcat, s21_strcat_11);
  tcase_add_test(tc_s21_strcat, s21_strcat_13);
  tcase_add_test(tc_s21_strcat, s21_strcat_14);
  tcase_add_test(tc_s21_strcat, s21_strcat_15);

#ifndef TEST
#define TEST
  tcase_add_test(tc_s21_strcat, s21_strcat_12);
#endif

  suite_add_tcase(string, tc_s21_strcat);

  return string;
}
