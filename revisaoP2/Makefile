all: abb.o avl.o arn.o filaprioridade.o main.o
	gcc abb.o avl.o arn.o filaprioridade.o main.o -o revisao -std=c99 -Wall -lm

abb.o:
	gcc -c abb.c -o abb.o

avl.o:
	gcc -c avl.c -o avl.o

arn.o:
	gcc -c arn.c -o arn.o

filaprioridade.o:
	gcc -c filaprioridade.c -o filaprioridade.o
	 
main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o revisao

run:
	./revisao

valgrind: 
	valgrind --leak-check=full ./revisao < data.txt