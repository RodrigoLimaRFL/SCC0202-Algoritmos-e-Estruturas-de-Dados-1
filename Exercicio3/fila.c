#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

#define MAX 50

struct fila_ {
    ITEM *fila[MAX];
    int inicio;
    int fim;
    int tamanho;
};

FILA *fila_criar()
{
    FILA *fila = (FILA *) malloc(sizeof(FILA));
    if (fila != NULL) {
        fila->inicio = 0;
        fila->fim = 0;
        fila->tamanho = 0;
    }

    return fila;
}

bool fila_cheia(FILA *fila)
{
    return fila->tamanho == MAX;
}

bool fila_vazia(FILA *fila)
{
    return fila->tamanho == 0;
}

bool fila_inserir(FILA *fila, ITEM *item)
{
    if(fila != NULL && !fila_cheia(fila))
    {
        fila->fila[fila->fim] = item;
        fila->fim = (fila->fim + 1) % MAX;
        fila->tamanho++;
        return true;
    }

    return false;
}

ITEM *fila_remover(FILA *fila)
{
    if(fila != NULL && !fila_vazia(fila))
    {
        ITEM *item = fila->fila[fila->inicio];
        fila->fila[fila->inicio] = NULL;
        fila->inicio = (fila->inicio + 1) % MAX;
        fila->tamanho--;
        return item;
    }
}

void fila_apagar(FILA **fila)
{
    if(*fila != NULL)
    {
        for(int i = 0 ; i < (*fila)->tamanho ; i++)
        {
            item_apagar(&(*fila)->fila[i]);
        }
        free(*fila);
        *fila = NULL;
    }
}

ITEM *fila_frente(FILA *fila)
{
    if(fila != NULL && !fila_vazia(fila))
    {
        return fila->fila[fila->inicio];
    }
}

int fila_tamanho(FILA *fila)
{
    if(fila != NULL)
    {
        return fila->tamanho;
    }
}

void fila_imprimir(FILA *fila)
{
    if(fila != NULL)
    {
        for(int i = 0 ; i < fila->tamanho ; i++)
        {
            item_imprimir(fila->fila[i]);
        }
    }
}

void cartas(int n)
{
    FILA *fila = fila_criar();
    for(int i = 1 ; i <= n ; i++)
    {
        ITEM *item = item_criar(i);
        fila_inserir(fila, item);
    }

    printf("Discarded cards: ");
    while(fila_tamanho(fila) > 1)
    {
        ITEM *item = fila_remover(fila);
        printf("%d", item_get_chave(item));
        if(fila_tamanho(fila) > 1)
        {
            printf(", ");
        }
        item_apagar(&item);
        item = fila_remover(fila);
        fila_inserir(fila, item);
    }
    printf("\nRemaining card: ");
    ITEM *item = fila_remover(fila);
    printf("%d\n", item_get_chave(item));
    item_apagar(&item);
    fila_apagar(&fila);
}