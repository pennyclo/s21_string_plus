/**
 * @file main_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief
 * @version 1.0
 * @date 2024-12-01
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/main_test.h"

#include <stdlib.h>

int main(void) {
  int number_failed = 0;
  SRunner *sr;

  sr = srunner_create(NULL);
#ifdef TEST
#define TEST
  srunner_add_suite(sr, s21_strcat_case_1());
  srunner_add_suite(sr, s21_strlen_case_1());
  srunner_add_suite(sr, s21_strncat_case_1());
#endif
  srunner_add_suite(sr, s21_strchr_case_1());
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
