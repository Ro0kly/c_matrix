CC = gcc -std=c11
CFLAGS = -Wall -Werror -Wextra -g
SOURCELIBFILESDIR = ./matrix_operations
TESTFILE = s21_test.c
TARGET = output

all: clean s21_matrix.a test
s21_matrix.a:
	$(CC) $(CFLAGS) -c $(SOURCELIBFILESDIR)/*.c
	ar rcs s21_matrix.a *.o
	rm -rf *.o
test:
	$(CC) $(CFLAGS) $(TESTFILE) s21_matrix.a -o $(TARGET) -lcheck -lm -lsubunit
	./$(TARGET)
gcov_report: clean s21_matrix.a
	$(CC) $(CFLAGS) --coverage $(TESTFILE) ./matrix_operations/*.c s21_matrix.a -o gcovreport -lcheck -lm -lsubunit
	./gcovreport
	lcov -t "gcovreport" -o gcovreport.info -c -d .
	genhtml -o report gcovreport.info
	open report/index.html
clean:
	rm -rf ./*.o *.a *.gcno *.gcda gcovreport gcovreport.info report $(TARGET)
valgrind:
	valgrind --tool=memcheck --leak-check=yes -s ./$(TARGET)
leaks:
	leaks -atExit -- ./$(TARGET)
clang:
	clang-format -i *.c
	clang-format -i *.h
	clang-format -i ./matrix_operations/*.c
	clang-format -i ./matrix_operations/*.h