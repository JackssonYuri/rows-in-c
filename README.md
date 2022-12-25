Para compilação:

all: main

main: filadeints.o
	gcc main.c filadeints.o -o main
filadeints.o:
	gcc -c filadeints.c 
rm: 
	rm *.o
