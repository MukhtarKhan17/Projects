# Make File
all: main.o a.out

main.i: main.c
	gcc -E main.c -o main.i

main.s: main.i
	gcc -S main.i -o main.s 

main.o: main.s
	gcc -c main.s -o main.o

a.out: main.o 
	gcc main.o -o a.out

clean: 
	del *.out *.i *.s *.o 

