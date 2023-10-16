all: item.o main.o pilha.o fila.o lista.o
	gcc item.o pilha.o fila.o lista.o main.o -o revisao -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

pilha.o:
	gcc -c pilha.c -o pilha.o

fila.o:
	gcc -c fila.c -o fila.o

lista.o:
	gcc -c lista.c -o lista.o
	 
main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o revisao

run:
	./revisao

valgrind: 
	valgrind --leak-check=full ./revisao < data.txt