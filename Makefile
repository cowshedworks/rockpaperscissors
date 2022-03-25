all: run.o
run.o: main.c rpslib.c
	gcc main.c -o run.o