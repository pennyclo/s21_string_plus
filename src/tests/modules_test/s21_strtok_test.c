/**
 * @file s21_strtok_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief
 * @version 1.0
 * @date 2024-12-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include_test/s21_strtok_test.h"

START_TEST(s21_strtok_1) {
  char str[] = "apple,banana,cherry";
  char *delim = ",";
  char *expected[] = {"apple", "banana", "cherry"};
  char *token, *token_sample;
  int i = 0;

  token = s21_strtok(str, delim);
  token_sample = strtok(str, delim);
  while (token != NULL && token_sample != NULL) {
    ck_assert_str_eq(token, token_sample);
    ck_assert_str_eq(token, expected[i++]);
    token = strtok(NULL, delim);
    token_sample = strtok(NULL, delim);
  }
  ck_assert_ptr_eq(token, token_sample);
}
END_TEST

START_TEST(s21_strtok_2) {
  char str[] = "Hello, world!";
  const char delim[] = " ,!";
  char *result_std = strtok(str, delim);
  char *result_s21 = s21_strtok(str, delim);
  while (result_std && result_s21) {
    ck_assert_str_eq(result_s21, result_std);
    result_std = strtok(S21_NULL, delim);
    result_s21 = s21_strtok(S21_NULL, delim);
  }
  ck_assert_ptr_eq(result_std, result_s21);
}
END_TEST

START_TEST(s21_strtok_3) {
  char str[] = "";
  const char delim[] = ",";
  ck_assert_ptr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(s21_strtok_4) {
  char str[] = "HelloWorld";
  const char delim[] = ",";
  char *result_std = strtok(str, delim);
  char *result_s21 = s21_strtok(str, delim);
  ck_assert_str_eq(result_s21, result_std);
  ck_assert_ptr_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
}
END_TEST

START_TEST(s21_strtok_5) {
  char str[] = ",,,";
  const char delim[] = ",";
  char *result_std = strtok(str, delim);
  char *result_s21 = s21_strtok(str, delim);
  ck_assert_ptr_eq(result_std, result_s21);
}
END_TEST

START_TEST(s21_strtok_6) {
  char str[] = "HelloWorld";
  const char delim[] = ", ";
  char *result_std = strtok(str, delim);
  char *result_s21 = s21_strtok(str, delim);
  ck_assert_str_eq(result_s21, result_std);
  ck_assert_ptr_eq(s21_strtok(S21_NULL, delim), strtok(S21_NULL, delim));
}
END_TEST

START_TEST(s21_strtok_7) {
  char str[] = "Hello,,,world!!";
  const char delim[] = ",!";
  char *result_std = strtok(str, delim);
  char *result_s21 = s21_strtok(str, delim);
  while (result_std && result_s21) {
    ck_assert_str_eq(result_s21, result_std);
    result_std = strtok(S21_NULL, delim);
    result_s21 = s21_strtok(S21_NULL, delim);
  }
  ck_assert_ptr_eq(result_std, result_s21);
}
END_TEST

START_TEST(s21_strtok_8) {
  char str[] = ",,Hello,world";
  const char delim[] = ",";
  char *result_std = strtok(str, delim);
  char *result_s21 = s21_strtok(str, delim);
  while (result_std && result_s21) {
    ck_assert_str_eq(result_s21, result_std);
    result_std = strtok(S21_NULL, delim);
    result_s21 = s21_strtok(S21_NULL, delim);
  }
  ck_assert_ptr_eq(result_std, result_s21);
}
END_TEST

START_TEST(s21_strtok_9) {
  char str[] = "Hello,world,,";
  const char delim[] = ",";
  char *result_std = strtok(str, delim);
  char *result_s21 = s21_strtok(str, delim);
  while (result_std && result_s21) {
    ck_assert_str_eq(result_s21, result_std);
    result_std = strtok(S21_NULL, delim);
    result_s21 = s21_strtok(S21_NULL, delim);
  }
  ck_assert_ptr_eq(result_std, result_s21);
}
END_TEST

START_TEST(s21_strtok_10) {
  char str[] = ",";
  const char delim[] = ",";
  ck_assert_ptr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(s21_strtok_11) {
  char str[] = "This is a test string";
  const char delim[] = " ";
  char *result_std = strtok(str, delim);
  char *result_s21 = s21_strtok(str, delim);
  while (result_std && result_s21) {
    ck_assert_str_eq(result_s21, result_std);
    result_std = strtok(S21_NULL, delim);
    result_s21 = s21_strtok(S21_NULL, delim);
  }
  ck_assert_ptr_eq(result_std, result_s21);
}
END_TEST

START_TEST(s21_strtok_12) {
  char *str = S21_NULL;
  const char delim[] = ",";
  ck_assert_ptr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(s21_strtok_13) {
  char str[] = "Hello,world";
  const char *delim = S21_NULL;
  ck_assert_ptr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(s21_strtok_14) {
  char str[] = "Hello,world";
  const char delim[] = "";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(s21_strtok_15) {
  char str[] = "   ";
  const char delim[] = " ";
  char *result_std = strtok(str, delim);
  char *result_s21 = s21_strtok(str, delim);
  ck_assert_ptr_eq(result_std, result_s21);
}
END_TEST

START_TEST(s21_strtok_16) {
  char str[] = ",,Hello,,world,,";
  const char delim[] = ",";
  char *result_std = strtok(str, delim);
  char *result_s21 = s21_strtok(str, delim);
  while (result_std && result_s21) {
    ck_assert_str_eq(result_s21, result_std);
    result_std = strtok(S21_NULL, delim);
    result_s21 = s21_strtok(S21_NULL, delim);
  }
  ck_assert_ptr_eq(result_std, result_s21);
}
END_TEST

START_TEST(s21_strtok_17) {
  char str[1000];
  memset(str, 'a', 999);
  str[999] = '\0';
  const char delim[] = "a";
  char *result_std = strtok(str, delim);
  char *result_s21 = s21_strtok(str, delim);
  while (result_std && result_s21) {
    ck_assert_str_eq(result_s21, result_std);
    result_std = strtok(S21_NULL, delim);
    result_s21 = s21_strtok(S21_NULL, delim);
  }
  ck_assert_ptr_eq(result_std, result_s21);
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
  tcase_add_test(tc_s21_strtok, s21_strtok_10);
  tcase_add_test(tc_s21_strtok, s21_strtok_11);
  tcase_add_test(tc_s21_strtok, s21_strtok_12);
  tcase_add_test(tc_s21_strtok, s21_strtok_13);
  tcase_add_test(tc_s21_strtok, s21_strtok_14);
  tcase_add_test(tc_s21_strtok, s21_strtok_15);
  tcase_add_test(tc_s21_strtok, s21_strtok_16);
  tcase_add_test(tc_s21_strtok, s21_strtok_17);

  suite_add_tcase(string, tc_s21_strtok);

  return string;
}