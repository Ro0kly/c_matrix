all: clean compile_and_use
compile_and_use:
	gcc -Wall -Werror -Wextra -g *.c
	./a.out
easy:
	gcc *.c
	./a.out
clean:
	rm -rf ./a.out
valgrind:
	valgrind --tool=memcheck --leak-check=yes ./a.out
leaks:
	leaks -atExit -- ./a.out