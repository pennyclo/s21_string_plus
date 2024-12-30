/**
 * @file s21_memcpy_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_memcpy_test.
 * @version 1.0
 * @date 2024-12-30
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include_test/s21_memcpy_test.h"

START_TEST(s21_memcpy_1) {
  char src[] = "Hello, world!";
  char dest1[20], dest2[20];

  memcpy(dest1, src, strlen(src) + 1);

  s21_memcpy(dest2, src, strlen(src) + 1);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_memcpy_2) {
  char src[] = "Hello, world!";
  char dest1[20], dest2[20];

  memcpy(dest1, src, strlen(src) + 1);

  s21_memcpy(dest2, src, strlen(src) + 1);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_memcpy_3) {
  char src[] = "Hello, world!";
  char dest1[20] = {0}, dest2[20] = {0};

  memcpy(dest1, src, 0);
  s21_memcpy(dest2, src, 0);

  ck_assert_mem_eq(dest1, dest2, 20);
}
END_TEST

START_TEST(s21_memcpy_4) {
  char src[] = "Hello, world!";
  char dest1[20] = "Initial text";
  char dest2[20] = "Initial text";

  memcpy(dest1, src, strlen(src) + 1);

  s21_memcpy(dest2, src, strlen(src) + 1);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(s21_memcpy_5) {
  char data[] = "Hello, world!";

  memcpy(data + 6, data, 6);
  char data2[] = "Hello, world!";
  s21_memcpy(data2 + 6, data2, 6);

  ck_assert_str_eq(data, data2);
}
END_TEST

START_TEST(s21_memcpy_6) {
  size_t size = 1000000;
  char *src = (char *)malloc(size);
  char *dest1 = (char *)malloc(size);
  char *dest2 = (char *)malloc(size);

  for (size_t i = 0; i < size; ++i) {
    src[i] = 'A';
  }

  memcpy(dest1, src, size);

  s21_memcpy(dest2, src, size);

  for (size_t i = 0; i < size; ++i) {
    ck_assert_int_eq(dest1[i], 'A');
    ck_assert_int_eq(dest2[i], 'A');
  }

  free(src);
  free(dest1);
  free(dest2);
}
END_TEST

START_TEST(s21_memcpy_7) {
  char data[] = "Hello, world!";

  memcpy(data, data, strlen(data) + 1);
  char data2[] = "Hello, world!";
  s21_memcpy(data2, data2, strlen(data2) + 1);

  ck_assert_str_eq(data, data2);
}
END_TEST

START_TEST(s21_memcpy_8) {
  char data[] = "Hello, world!";

  memcpy(data, data, 0);
  char data2[] = "Hello, world!";
  s21_memcpy(data2, data2, 0);

  ck_assert_str_eq(data, data2);
}
END_TEST

Suite *s21_memcpy_case_1(void) {
  Suite *string = suite_create("\ns21_memcpy (s21_memcpy case 1)\n");

  TCase *tc_s21_memcpy = tcase_create("s21_memcpy  test");

  tcase_add_test(tc_s21_memcpy, s21_memcpy_1);
  tcase_add_test(tc_s21_memcpy, s21_memcpy_2);
  tcase_add_test(tc_s21_memcpy, s21_memcpy_3);
  tcase_add_test(tc_s21_memcpy, s21_memcpy_4);
  tcase_add_test(tc_s21_memcpy, s21_memcpy_5);
  tcase_add_test(tc_s21_memcpy, s21_memcpy_6);
  tcase_add_test(tc_s21_memcpy, s21_memcpy_7);
  tcase_add_test(tc_s21_memcpy, s21_memcpy_8);

  suite_add_tcase(string, tc_s21_memcpy);

  return string;
}
