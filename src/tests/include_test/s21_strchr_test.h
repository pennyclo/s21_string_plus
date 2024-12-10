/**
 * @file s21_strchr_test.h
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Header file with function declaration s21_strchr_test.
 * @version 1.0
 * @date 2024-12-10
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_TESTS_INCLUDE_TEST_S21_STRCHR_TEST_H_
#define SRC_TESTS_INCLUDE_TEST_S21_STRCHR_TEST_H_

#include <check.h>
#include <string.h>

#include "include/s21_strchr.h"

Suite *s21_strchr_case_1(void);
void comparison_func(char *dst, int ch);

#endif  // SRC_TESTS_INCLUDE_TEST_S21_STRCHR_TEST_H_
