/**
 * @file s21_strtok.h
 * @author Artemy Plokhikh (https://github.com/isiyar)
 * @brief Header file with function declaration s21_strtok.
 * @version 1.0
 * @date 2024-12-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef SRC_INCLUDE_S21_STRTOK_H_
#define SRC_INCLUDE_S21_STRTOK_H_

#include "include/common.h"
#include "include/s21_strpbrk.h"
#include "include/s21_strspn.h"

char *s21_strtok(char *str, const char *delim);

#endif  // SRC_INCLUDE_S21_STRTOK_H_
