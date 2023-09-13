all: item.o pilha.o labirinto.o main.o
	gcc item.o pilha.o labirinto.o main.o -o caminho -std=c99 -Wall

item.o:
	gcc -c item.c -o item.o

pilha.o:
	gcc -c pilha.c -o pilha.o

labirinto.o:
	gcc -c labirinto.c -o labirinto.o

main.o:
	gcc -c main.c -o main.o

clean:
	rm *.o caminho

run:
	./caminho

valgrind: 
	valgrind --leak-check=full ./caminho < data.txt