#makefile for caesar cypher
#elliott long

caesar: main.o
	gcc -std=c99 -pedantic -Wall -g -o caesar main.o

main.o: main.c
	gcc -std=c99 -pedantic -Wall -c main.c

clean:
	rm -f caesar main.o

