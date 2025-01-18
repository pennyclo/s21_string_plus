/**
 * @file main_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function main_test.
 * @version 1.0
 * @date 2024-12-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/main_test.h"

#include <stdlib.h>

/**
 * @brief Main function to run test suites and report the number of failed
 * tests.
 *
 * @return int Returns EXIT_SUCCESS if all tests pass, otherwise EXIT_FAILURE.
 */
int main(void) {
  int number_failed = 0;
  SRunner *sr;

  sr = srunner_create(NULL);
#ifdef TEST
#define TEST
  srunner_add_suite(sr, s21_strcat_case_1());
  srunner_add_suite(sr, s21_strlen_case_1());
  srunner_add_suite(sr, s21_strncat_case_1());
  srunner_add_suite(sr, s21_strchr_case_1());
  srunner_add_suite(sr, s21_strcmp_case_1());
  srunner_add_suite(sr, s21_strncmp_case_1());
  srunner_add_suite(sr, s21_strcpy_case_1());
  srunner_add_suite(sr, s21_strncpy_case_1());
  srunner_add_suite(sr, s21_strcspn_case_1());
  srunner_add_suite(sr, s21_strerror_case_1());
  srunner_add_suite(sr, s21_strpbrk_case_1());
  srunner_add_suite(sr, s21_strrchr_case_1());
  srunner_add_suite(sr, s21_strspn_case_1());
  srunner_add_suite(sr, s21_strstr_case_1());
  srunner_add_suite(sr, s21_strtok_case_1());
  srunner_add_suite(sr, s21_strtok_case_1());
  srunner_add_suite(sr, s21_memcpy_case_1());
  srunner_add_suite(sr, s21_memmove_case_1());
  srunner_add_suite(sr, s21_memset_case_1());
#endif
  srunner_add_suite(sr, s21_sprintf_case_1());

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
