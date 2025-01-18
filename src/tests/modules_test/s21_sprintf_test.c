/**
 * @file s21_sprintf_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_sprintf_test.
 * @version 1.0
 * @date 2025-01-15
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "tests/include_test/s21_sprintf_test.h"

START_TEST(s21_sprintf_1) {
  // char buffer[100] = {0};
  // char format[] = "%100";
  // char ch;

  // s21_sprintf(buffer, format, ch);
}
END_TEST

Suite *s21_sprintf_case_1(void) {
  Suite *string = suite_create("\ns21_sprintf (s21_sprintf case 1)\n");

  TCase *tc_s21_sprintf = tcase_create("s21_sprintf  test");

  tcase_add_test(tc_s21_sprintf, s21_sprintf_1);

  suite_add_tcase(string, tc_s21_sprintf);

  return string;
}