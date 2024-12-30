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
  char str[] = ",apple,banana,cherry,";
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

START_TEST(s21_strtok_3) {
  char str[] = "apple,,banana,cherry";
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

START_TEST(s21_strtok_4) {
  char str[] = "";
  char *delim = ",";
  char *token, *token_sample;

  token = s21_strtok(str, delim);
  token_sample = strtok(str, delim);
  ck_assert_ptr_eq(token, token_sample);
}
END_TEST

START_TEST(s21_strtok_5) {
  char str[] = "apple";
  char *delim = ",";
  char *expected[] = {"apple"};
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

START_TEST(s21_strtok_6) {
  char str[] = "apple,banana,cherry,";
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

START_TEST(s21_strtok_7) {
  char str[] = ",,,";
  char *delim = ",";
  char *token, *token_sample;

  token = s21_strtok(str, delim);
  token_sample = strtok(str, delim);
  while (token != NULL && token_sample != NULL) {
    ck_assert_str_eq(token, token_sample);
    token = strtok(NULL, delim);
    token_sample = strtok(NULL, delim);
  }
  ck_assert_ptr_eq(token, token_sample);
}
END_TEST

START_TEST(s21_strtok_8) {
  char str[] = "apple,banana,cherry,,,";
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

START_TEST(s21_strtok_9) {
  char str[] = ",,apple,banana,cherry";
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

START_TEST(s21_strtok_10) {
  char str[] = "apple,,,banana,,,cherry";
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

START_TEST(s21_strtok_11) {
  char str[] = "apple\0banana\0cherry";
  char *delim = "\0";
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

START_TEST(s21_strtok_12) {
  char str[] = "apple\0banana,cherry";
  char *delim = ",\0";
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

START_TEST(s21_strtok_13) {
  char str[] = "apple\0,banana,cherry";
  char *delim = ",\0";
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

START_TEST(s21_strtok_14) {
  char str[] = "apple\0,banana,cherry";
  char *delim = ",\0";
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

START_TEST(s21_strtok_15) {
  char str[] = "apple,banana\0cherry";
  char *delim = ",\0";
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

  suite_add_tcase(string, tc_s21_strtok);

  return string;
}
