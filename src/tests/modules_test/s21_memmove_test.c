/**
 * @file s21_memmove_test.c
 * @author Alexandr Afanasev (https://github.com/pennyclo)
 * @brief Implementation function s21_memmove_test.
 * @version 1.0
 * @date 2024-12-30
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "tests/include_test/s21_memmove_test.h"

START_TEST(s21_memmove_1) {
  char src[] = "Hello, world!";
  char dest1[20] = {0};
  char dest2[20] = {0};

  memmove(dest1, src, strlen(src) + 1);
  s21_memmove(dest2, src, strlen(src) + 1);

  ck_assert_mem_eq(dest1, dest2, strlen(src) + 1);
}
END_TEST

START_TEST(s21_memmove_2) {
  char buffer1[20] = "Hello, world!";
  char buffer2[20] = "Hello, world!";

  memmove(buffer1 + 6, buffer1, 6);
  s21_memmove(buffer2 + 6, buffer2, 6);

  ck_assert_mem_eq(buffer1, buffer2, 20);
}
END_TEST

START_TEST(s21_memmove_3) {
  char buffer1[20] = "Hello, world!";
  char buffer2[20] = "Hello, world!";

  memmove(buffer1, buffer1 + 6, 6);
  s21_memmove(buffer2, buffer2 + 6, 6);

  ck_assert_mem_eq(buffer1, buffer2, 20);
}
END_TEST

START_TEST(s21_memmove_4) {
  char src[] = "Hello, world!";
  char dest1[20] = {0};
  char dest2[20] = {0};

  memmove(dest1, src, 0);
  s21_memmove(dest2, src, 0);

  ck_assert_mem_eq(dest1, dest2, 20);
}
END_TEST

START_TEST(s21_memmove_5) {
  char *src = S21_NULL;
  char *dest = S21_NULL;

  ck_assert_ptr_eq(memmove(dest, src, 0), s21_memmove(dest, src, 0));
}
END_TEST

START_TEST(s21_memmove_6) {
  char src[] = "A";
  char dest1[2] = {0};
  char dest2[2] = {0};

  memmove(dest1, src, 1);
  s21_memmove(dest2, src, 1);

  ck_assert_mem_eq(dest1, dest2, 2);
}
END_TEST

START_TEST(s21_memmove_7) {
  char buffer1[20] = "Hello, world!";
  char buffer2[20] = "Hello, world!";

  memmove(buffer1, buffer1, strlen(buffer1) + 1);
  s21_memmove(buffer2, buffer2, strlen(buffer2) + 1);

  ck_assert_mem_eq(buffer1, buffer2, 20);
}
END_TEST

START_TEST(s21_memmove_8) {
  char src[1024] = {0};
  char dest1[1024] = {0};
  char dest2[1024] = {0};

  for (int i = 0; i < 1024; i++) {
    src[i] = (char)(i % 256);
  }

  memmove(dest1, src, 1024);
  s21_memmove(dest2, src, 1024);

  ck_assert_mem_eq(dest1, dest2, 1024);
}
END_TEST

START_TEST(s21_memmove_9) {
  char buffer1[20] = "1234567890";
  char buffer2[20] = "1234567890";

  memmove(buffer1 + 3, buffer1 + 1, 6);
  s21_memmove(buffer2 + 3, buffer2 + 1, 6);

  ck_assert_mem_eq(buffer1, buffer2, 20);
}
END_TEST

START_TEST(s21_memmove_10) {
  char buffer1[20] = "ABCDEFGHIJ";
  char buffer2[20] = "ABCDEFGHIJ";

  memmove(buffer1 + 2, buffer1, 5);
  s21_memmove(buffer2 + 2, buffer2, 5);

  ck_assert_mem_eq(buffer1, buffer2, 20);
}
END_TEST

START_TEST(s21_memmove_11) {
  char buffer1[20] = "ABCDEFGHIJ";
  char buffer2[20] = "ABCDEFGHIJ";

  memmove(buffer1 + 4, buffer1 + 2, 4);
  s21_memmove(buffer2 + 4, buffer2 + 2, 4);

  ck_assert_mem_eq(buffer1, buffer2, 20);
}
END_TEST

START_TEST(s21_memmove_12) {
  char src[1024];
  char dest1[1024];
  char dest2[1024];

  for (int i = 0; i < 1024; i++) {
    src[i] = (char)(i % 256);
  }

  memmove(dest1, src, 1024);
  s21_memmove(dest2, src, 1024);

  ck_assert_mem_eq(dest1, dest2, 1024);
}
END_TEST

START_TEST(s21_memmove_13) {
  char src[3] = "AB";
  char dest1[3] = {0};
  char dest2[3] = {0};

  memmove(dest1, src, 2);
  s21_memmove(dest2, src, 2);

  ck_assert_mem_eq(dest1, dest2, 3);
}
END_TEST

START_TEST(s21_memmove_14) {
  char buffer1[20] = "ABCDEFGHIJ";
  char buffer2[20] = "ABCDEFGHIJ";

  memmove(buffer1 + 4, buffer1 + 4, 0);
  s21_memmove(buffer2 + 4, buffer2 + 4, 0);

  ck_assert_mem_eq(buffer1, buffer2, 20);
}
END_TEST

START_TEST(s21_memmove_15) {
  char src[] = "Hello";
  char dest1[6] = {0};
  char dest2[6] = {0};

  memmove(dest1, src, 1);
  s21_memmove(dest2, src, 1);

  ck_assert_mem_eq(dest1, dest2, 6);
}
END_TEST

START_TEST(s21_memmove_16) {
  char buffer1[20] = "Hello, world!";
  char buffer2[20] = "Hello, world!";

  memmove(buffer1 + 7, buffer1, 5);
  s21_memmove(buffer2 + 7, buffer2, 5);

  ck_assert_mem_eq(buffer1, buffer2, 20);
}
END_TEST

START_TEST(s21_memmove_17) {
  char buffer1[10] = "123456789";
  char buffer2[10] = "123456789";

  memmove(buffer1 + 1, buffer1, 1);
  s21_memmove(buffer2 + 1, buffer2, 1);

  ck_assert_mem_eq(buffer1, buffer2, 10);
}
END_TEST

START_TEST(s21_memmove_18) {
  char buffer1[20] = "This is a test";
  char buffer2[20] = "This is a test";

  memmove(buffer1 + 13, buffer1, 5);
  s21_memmove(buffer2 + 13, buffer2, 5);

  ck_assert_mem_eq(buffer1, buffer2, 20);
}
END_TEST

Suite *s21_memmove_case_1(void) {
  Suite *string = suite_create("\ns21_memmove (s21_memmove case 1)\n");

  TCase *tc_s21_memmove = tcase_create("s21_memmove  test");

  tcase_add_test(tc_s21_memmove, s21_memmove_1);
  tcase_add_test(tc_s21_memmove, s21_memmove_2);
  tcase_add_test(tc_s21_memmove, s21_memmove_3);
  tcase_add_test(tc_s21_memmove, s21_memmove_4);
  tcase_add_test(tc_s21_memmove, s21_memmove_5);
  tcase_add_test(tc_s21_memmove, s21_memmove_6);
  tcase_add_test(tc_s21_memmove, s21_memmove_7);
  tcase_add_test(tc_s21_memmove, s21_memmove_8);
  tcase_add_test(tc_s21_memmove, s21_memmove_9);
  tcase_add_test(tc_s21_memmove, s21_memmove_10);
  tcase_add_test(tc_s21_memmove, s21_memmove_11);
  tcase_add_test(tc_s21_memmove, s21_memmove_12);
  tcase_add_test(tc_s21_memmove, s21_memmove_13);
  tcase_add_test(tc_s21_memmove, s21_memmove_14);
  tcase_add_test(tc_s21_memmove, s21_memmove_15);
  tcase_add_test(tc_s21_memmove, s21_memmove_16);
  tcase_add_test(tc_s21_memmove, s21_memmove_17);
  tcase_add_test(tc_s21_memmove, s21_memmove_18);

  suite_add_tcase(string, tc_s21_memmove);

  return string;
}
