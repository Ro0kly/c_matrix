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
clean:
	rm -rf ./*.o *.a
valgrind:
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes -s ./$(TARGET)
leaks:
	leaks -atExit -- ./$(TARGET)
