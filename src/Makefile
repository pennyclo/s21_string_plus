PROJECT_NAME = s21_string_plus

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -g -I.
LDFLAGS = -lcheck -lsubunit -lm -I.

MODULES_DIR = ./modules
TESTS_DIR = ./tests
INCLUDE_DIR = ./include
DOCS_DIR = ../docs
OBJ_DIR = ./obj

#===================================TARGETS====================================

STATIC_LIB = s21_string.a
TEST = test

MAIN_TEST = ./tests/main_test.c
ALL_FILES = $(shell find . -type f \( -name "*.c" -o -name "*.h" \))

dvi: $(DOCS_DIR)
	doxygen Doxyfile

#список файлов в каталоге modules
C_FILES = $(shell find $(MODULES_DIR) -type f -name "*.c")
HEADERS = $(shell find $(INCLUDE_DIR) -type f -name "*.h")
OBJ_FILES = $(C_FILES:$(MODULES_DIR)/%.c=$(OBJ_DIR)/modules/%.o)

#список файлов в каталоге tests
TEST_C = $(shell find $(TESTS_DIR)/modules -type f -name "*.c")
TEST_H = $(shell find $(TESTS_DIR)/include -type f -name "*.h")
TEST_O = $(TEST_C:$(TESTS_DIR)/modules/%.c=$(OBJ_DIR)/tests/%.o)

#сборка объектников
$(OBJ_DIR)/modules/%.o: $(MODULES_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/tests/%.o: $(TESTS_DIR)/modules/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(STATIC_LIB): $(OBJ_DIR)/modules $(OBJ_FILES)
	ar rcs $@
	ranlib $@

$(TEST): clean $(OBJ_DIR)/tests $(TEST_O)
	$(CC) $(MAIN_TEST) $(TEST_O) $(LDFLAGS) -o $@
	./$(TEST)

$(OBJ_DIR)/modules:
	mkdir -p $@

$(OBJ_DIR)/tests:
	mkdir -p $@

$(DOCS_DIR):
	mkdir $(DOCS_DIR)

clean:
	rm -rf $(DOCS_DIR)
	rm -rf $(OBJ_DIR)
	rm -f $(STATIC_LIB)
	rm -f $(TEST)

cpplint: 
	cpplint $(ALL_FILES)

dependencies:
	sudo apt install doxygen
	sudo apt install check
