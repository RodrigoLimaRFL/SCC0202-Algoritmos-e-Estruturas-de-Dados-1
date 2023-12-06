#ifndef FILAPRIORIDADE_H
#define FILAPRIORIDADE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct heap_ HEAP;

HEAP *heap_criar();
bool heap_inserir(HEAP *heap, int num);
int heap_remover(HEAP *heap);
void heap_imprimir_em_nivel(HEAP *heap);

#endif // FILAPRIORIDADE_H