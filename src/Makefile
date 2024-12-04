#===================================COMPILER===================================#
PROJECT_NAME = s21_string
CC = gcc

#====================================FLAGS=====================================#
CFLAGS = -Wall -Wextra -std=c11 -pedantic -g -I.
LDFLAGS = -lcheck -lsubunit -lm -I.
COV_FLAGS = -fprofile-arcs -ftest-coverage
VAL_FLAGS = --tool=memcheck --leak-cheack=yes


#===================================PATH_DIR===================================#
MODULES_DIR = ./modules
TESTS_DIR = ./tests
INCLUDE_DIR = ./include
DOCS_DIR = ../docs
OBJ_DIR = ./obj
OBJ_DIR_COV = ./obj/cov
REPORT_DIR = ./report

#=============
GCOVR_EXCLUDES        := --exclude='.*tests/.*|.*include/.*'
GCOVR_HTML            := -r . $(GCOVR_EXCLUDES) --html --html-details -o $(REPORT_DIR)/coverage.html 
GCOVR_TXT             := -r . $(GCOVR_EXCLUDES) --txt -o $(REPORT_DIR)/coverage.txt

#===================================TARGETS====================================#
STATIC_LIB = $(PROJECT_NAME).a
TEST = test
GCOV_REPORT = gcov_report
STATIC_LIB_COV = $(PROJECT_NAME)_gcovr.a
DVI = dvi

MAIN_TEST = ./tests/main_test.c
ALL_FILES = $(shell find . -type f \( -name "*.c" -o -name "*.h" \))


#список файлов в каталоге modules
C_FILES = $(shell find $(MODULES_DIR) -type f -name "*.c")
HEADERS = $(shell find $(INCLUDE_DIR) -type f -name "*.h")
OBJ_FILES = $(C_FILES:$(MODULES_DIR)/%.c=$(OBJ_DIR)/modules/%.o)
OBJ_FILES_COV = $(C_FILES:$(MODULES_DIR)/%.c=$(OBJ_DIR_COV)/%.o)


1:
	echo $(OBJ_FILES_COV)

#список файлов в каталоге tests
TEST_C = $(shell find $(TESTS_DIR)/modules_test -type f -name "*.c")
TEST_H = $(shell find $(TESTS_DIR)/include_test -type f -name "*.h")
TEST_O = $(TEST_C:$(TESTS_DIR)/modules_test/%.c=$(OBJ_DIR)/tests/%.o)

#сборка объектников
$(OBJ_DIR)/modules/%.o: $(MODULES_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR_COV)/%.o: $(MODULES_DIR)/%.c
	$(CC) $(CFLAGS) $(COV_FLAGS) -c -o $@ $<

$(OBJ_DIR)/tests/%.o: $(TESTS_DIR)/modules_test/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

#===
$(STATIC_LIB): $(OBJ_DIR)/modules $(OBJ_FILES)
	ar rcs $@ $(OBJ_FILES)
	ranlib $@

$(STATIC_LIB_COV): $(OBJ_DIR_COV) $(OBJ_FILES_COV)
	ar rcs $@ $(OBJ_FILES_COV)
	ranlib $@

$(TEST): $(OBJ_DIR)/tests $(TEST_O) $(STATIC_LIB)
	$(CC) $(MAIN_TEST) $(TEST_O) $(STATIC_LIB) $(LDFLAGS) -o $@
	./$(TEST)

$(GCOV_REPORT): $(REPORT_DIR) $(OBJ_DIR)/tests $(TEST_O) $(STATIC_LIB_COV)
	$(CC) $(MAIN_TEST) $(TEST_O) $(STATIC_LIB_COV) $(LDFLAGS) $(COV_FLAGS) -o $(OBJ_DIR_COV)/report
	./$(OBJ_DIR_COV)/report
# gcovr $(GCOVR_TXT)
	gcovr $(GCOVR_HTML)
# @cat $(REPORT_DIR)/coverage.txt
	xdg-open $(REPORT_DIR)/coverage.html

$(DVI): $(DOCS_DIR)
	doxygen Doxyfile
#==============================CREATE_DIRECTORIES==============================
$(OBJ_DIR)/modules:
	mkdir -p $@

$(OBJ_DIR)/tests:
	mkdir -p $@

$(DOCS_DIR):
	mkdir $(DOCS_DIR)

$(OBJ_DIR_COV):
	mkdir -p $@

$(REPORT_DIR):
	mkdir -p $@

#===================================CLEAN======================================
clean:
	rm -rf $(DOCS_DIR)
	rm -rf $(OBJ_DIR)
	rm -f $(STATIC_LIB)
	rm -f $(TEST)
	rm -rf $(REPORT_DIR)
	rm -rf $(OBJ_DIR_COV)
	rm -f $(STATIC_LIB_COV)

#==============================================================================
cpplint: 
	cpplint $(ALL_FILES)

dependencies:
	sudo apt install doxygen
	sudo apt install check
