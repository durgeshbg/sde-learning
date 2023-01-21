output: main

main: main.o operations.o
		clang main.o operations.o -o main

main.o: main.c
		clang -c main.c

operations.o: operations.c
		clang -c operations.c

clean:
		rm *.o main