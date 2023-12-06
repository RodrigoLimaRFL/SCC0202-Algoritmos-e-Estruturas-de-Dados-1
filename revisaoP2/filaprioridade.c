#include "filaprioridade.h"
#include <math.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define TAM 100

struct heap_
{
    int tamanho;
    int vetor[TAM];
};

HEAP *heap_criar()
{
    HEAP *novaHeap = (HEAP *)malloc(sizeof(HEAP));
    if (novaHeap == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    novaHeap->tamanho = 0;
    return novaHeap;
}

int heap_pai(int i)
{
    return (i - 1) / 2;
}

int heap_esq(int i)
{
    return (2 * i) + 1;
}

int heap_dir(int i)
{
    return (2 * i) + 2;
}

void heap_swap(HEAP *heap, int i, int j)
{
    int aux = heap->vetor[i];
    heap->vetor[i] = heap->vetor[j];
    heap->vetor[j] = aux;
}

void heap_fix_up(HEAP *heap)
{
    int w = heap->tamanho - 1;
    int p = heap_pai(w);

    while (w > 0 && heap->vetor[p] < heap->vetor[w])
    {
        heap_swap(heap, p, w);
        w = p;
        p = heap_pai(w);
    }
}

bool heap_inserir(HEAP *heap, int num)
{
    heap->vetor[heap->tamanho] = num;
    heap_fix_up(heap);
    heap->tamanho++;
    return true;
}

void heap_fix_down(HEAP *heap)
{
    int w = 0;
    int m = 0;

    while (heap_esq(w) <= heap->tamanho)
    {
        m = heap_esq(w);

        // Compare with the right child if it exists and is greater
        if (heap_dir(w) < heap->tamanho && heap->vetor[heap_dir(w)] > heap->vetor[m])
        {
            m = heap_dir(w);
        }

        if (heap->vetor[w] >= heap->vetor[m])
        {
            break;
        }

        heap_swap(heap, w, m);
        w = m;
    }
}

int heap_remover(HEAP *heap)
{
    int retorno = heap->vetor[0];
    heap->vetor[0] = heap->vetor[heap->tamanho - 1];
    heap->tamanho--;
    heap_fix_down(heap);

    return retorno;
}

void heap_imprimir_em_nivel(HEAP *heap)
{
    int i = 0;
    int j = 0;
    int nivel = 0;

    while (i < heap->tamanho)
    {
        printf("%i ", heap->vetor[i]);
        i++;
        j++;
        if (j == pow(2, nivel))
        {
            printf("\n");
            nivel++;
            j = 0;
        }
    }
    printf("\n");
}