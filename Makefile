.PHONY: clean

FLAGS = gcc -Wall -Werror -Wextra -std=c11

# подбирает флаги для check в зависимости от системы (мак или линукс)
OS = $(shell uname -s)
ifeq ($(OS), Darwin)
CHECK_FLAGS = -lcheck
else ifeq ($(OS), Linux)
CHECK_FLAGS = -lcheck -lsubunit -lpthread -lm -lrt
endif

FILES_o = s21_string.o s21_sprintf.o
FILES_C = s21_string.c s21_sprintf.c

all: clean s21_string.a s21_sprintf.o test gcov_report

s21_string.a: $(FILES_o) 
	ar rcs s21_string.a $(FILES_o) 
	ranlib s21_string.a
	rm -rf *.o

s21_string.o:
	$(FLAGS) -c -g s21_string.c s21_string.h

s21_sprintf.o:
	$(FLAGS) -c -g s21_sprintf.c s21_sprintf.h

clean:
	rm -rf *.o *.a *.gch

rebuild: clean s21_string.a

test: s21_string.a s21_sprintf.o
	$(FLAGS) -g main_test.c s21_string.a -o run_tests.o $(CHECK_FLAGS)
	./run_tests.o

gcov_report:
	gcc main_test.c $(FILES_C) s21_string.a -o gcov_test -fprofile-arcs -ftest-coverage $(CHECK_FLAGS) -lm
	./gcov_test
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	gcovr -r . --html --html-details -o ./report/coverage_report.html
	rm -rf gcov_test

style: 
	cp ../materials/linters/.clang-format .
	clang-format -n *.c
	clang-format -n *.h
	rm -rf .clang-format