/**
 * @file s21_strerror_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_strerror_test.
 * @version 1.0
 * @date 2024-12-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include_test/s21_strerror_test.h"

#ifdef _LINUX_

#define ERROR_LIST_SIZE 134

#elif defined(_MACOS_)

#define ERROR_LIST_SIZE 107

#endif  // _LINUX_ || _MACOS_

START_TEST(s21_strerror_1) {
  int errnum = 0;
  while (errnum <= ERROR_LIST_SIZE) {
    ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
    ++errnum;
  }
}
END_TEST

START_TEST(s21_strerror_2) {
  int errnum = 13;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(s21_strerror_3) {
  int errnum = 0;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(s21_strerror_4) {
  int errnum = 5;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(s21_strerror_5) {
  int errnum = -1;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(s21_strerror_6) {
  int errnum = 12345;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(s21_strerror_7) {
  int errnum = 1;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(s21_strerror_8) {
  int errnum = ERROR_LIST_SIZE - 1;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(s21_strerror_9) {
  int errnum = 128;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(s21_strerror_10) {
  int errnum = 100;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(s21_strerror_11) {
  int errnum = 9999;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(s21_strerror_12) {
  int errnum = 0;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(s21_strerror_13) {
  int errnum = 22;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(s21_strerror_14) {
  int errnum = -100;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(s21_strerror_15) {
  int errnum = 11;
  ck_assert_str_eq(s21_strerror(errnum), strerror(errnum));
}
END_TEST

Suite *s21_strerror_case_1(void) {
  Suite *string = suite_create("\ns21_strerror (s21_strerror case 1)\n");

  TCase *tc_s21_strerror = tcase_create("s21_strerror  test");

  tcase_add_test(tc_s21_strerror, s21_strerror_1);
  tcase_add_test(tc_s21_strerror, s21_strerror_2);
  tcase_add_test(tc_s21_strerror, s21_strerror_3);
  tcase_add_test(tc_s21_strerror, s21_strerror_4);
  tcase_add_test(tc_s21_strerror, s21_strerror_5);
  tcase_add_test(tc_s21_strerror, s21_strerror_6);
  tcase_add_test(tc_s21_strerror, s21_strerror_7);
  tcase_add_test(tc_s21_strerror, s21_strerror_8);
  tcase_add_test(tc_s21_strerror, s21_strerror_9);
  tcase_add_test(tc_s21_strerror, s21_strerror_10);
  tcase_add_test(tc_s21_strerror, s21_strerror_11);
  tcase_add_test(tc_s21_strerror, s21_strerror_12);
  tcase_add_test(tc_s21_strerror, s21_strerror_13);
  tcase_add_test(tc_s21_strerror, s21_strerror_14);
  tcase_add_test(tc_s21_strerror, s21_strerror_15);

  suite_add_tcase(string, tc_s21_strerror);

  return string;
}
