CC=gcc
CFLAGS= -g -O0 -Wall -Wextra -Werror -std=c99 -fopenmp
DEPS = parallel.h seq.h aux.h
OBJ = main.o parallel.o seq.o aux.o
Vflags = valgrind --leak-check=full

%.o: %.c $(DEPS)
				$(CC) -c -o $@ $< $(CFLAGS)

exec: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

	rm -rf *.o

run: exec
	./exec

val: exec
	$(Vflags) ./exec

testes: exec
	$(Vflags) ./exec < \* insert entry tests here*\
