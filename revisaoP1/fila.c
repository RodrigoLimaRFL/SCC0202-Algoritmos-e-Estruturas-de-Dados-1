#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

struct filaSeqCirc_{
    ITEM *itens[MAX];
    int inicio;
    int fim;
    int tamanho;
};

struct no_{
    ITEM *item;
    NO *proximo;
};

struct filaEnc_{
    NO *inicio;
    NO *fim;
    int tamanho;
};

FILASEQ *fila_criar_seq()
{
    FILASEQ *fila = (FILASEQ*) malloc(sizeof(FILASEQ));

    if(fila != NULL)
    {
        fila->inicio = 0;
        fila->fim = 0;
        fila->tamanho = 0;
    }

    return fila;
}

FILAENC *fila_criar_enc()
{
    FILAENC *fila = (FILAENC*) malloc(sizeof(FILAENC));

    if(fila != NULL)
    {
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->tamanho = 0;
    }

    return fila;
}

bool fila_cheia_seq(FILASEQ *fila)
{
    if(fila == NULL)
    {
        printf("fila n existe");
        return true;
    }

    if(fila->tamanho == MAX)
    {
        return true;
    }

    return false;
}

bool fila_cheia_enc(FILAENC *fila)
{
    if(fila == NULL)
    {
        printf("fila n existe");
        return true;
    }

    NO *noTeste = (NO*) malloc(sizeof(NO));

    if(noTeste == NULL)
    {
        free(noTeste);
        return true;
    }

    free(noTeste);
    noTeste = NULL;

    return false;
}

bool fila_inserir_seq(FILASEQ *fila, ITEM *item)
{
    if(fila == NULL || fila_cheia_seq(fila))
    {
        return false;
    }

    fila->itens[fila->fim] = item;
    fila->fim = (fila->fim + 1) % MAX;
    fila->tamanho++;

    return true;
}

bool fila_inserir_enc(FILAENC *fila, ITEM *item)
{
    if(fila == NULL || fila_cheia_enc(fila))
    {
        return false;
    }

    NO *novoNo = (NO*) malloc(sizeof(NO));
    novoNo->item = item;
    novoNo->proximo = NULL;

    if(fila->inicio == NULL)
    {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    }
    else
    {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }

    fila->tamanho++;

    return true;
}

ITEM *fila_remover_seq(FILASEQ *fila)
{
    if(fila == NULL || fila->tamanho == 0)
    {
        return NULL;
    }

    ITEM *item = fila->itens[fila->inicio];
    
    fila->inicio = (fila->inicio + 1) % MAX;
    fila->tamanho--;

    return item;
}

ITEM *fila_remover_enc(FILAENC *fila)
{
    if(fila == NULL || fila->tamanho == 0)
    {
        return NULL;
    }

    NO *noInicio = fila->inicio;
    ITEM *item = noInicio->item;

    fila->inicio = noInicio->proximo;
    fila->tamanho--;

    free(noInicio);
    noInicio = NULL;

    return item;
}

bool fila_apagar_seq(FILASEQ **fila)
{
    if(*fila == NULL)
    {
        return false;
    }

    for(int i = (*fila)->inicio; i != (*fila)->fim; i = (i+1) % MAX)
    {
        item_apagar(&((*fila)->itens[i]));
    }

    free(*fila);
    (*fila) = NULL;

    return true;
}

bool fila_apagar_enc(FILAENC **fila)
{
    if(*fila == NULL)
    {
        return false;
    }

    NO* no = (*fila)->inicio;
    NO* noAux;

    for(int i = 0; i < (*fila)->tamanho; i++)
    {
        noAux = no;
        no = no->proximo;

        item_apagar(&(noAux->item));
        free(noAux);
        noAux = NULL;
    }

    free(*fila);
    (*fila) = NULL;

    return true;
}

void fila_imprimir_seq(FILASEQ *fila)
{
    if(fila == NULL)
        return;

    for(int i = fila->inicio; i != fila->fim; i = (i+1) % MAX)
    {
        item_imprimir(fila->itens[i]);
    }
}

void fila_imprimir_enc(FILAENC *fila)
{
    if(fila == NULL)
        return;

    NO* no = fila->inicio;

    for(int i = 0; i < fila->tamanho; i++)
    {
        item_imprimir(no->item);
        no = no->proximo;
    }
}