#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "pilha.h"

struct no_{
    ITEM *item;
    NO *anterior;
};

struct pilhaEncadeada_{
    NO *topo;
    int tamanho;
};

struct pilhaSequencial_{
    ITEM *itens[MAX];
    int tamanho;
};

PILHA *pilha_criar_encadeada()
{
    PILHA *pilha = malloc(sizeof(PILHA));

    if(pilha != NULL)
    {
        pilha->topo = NULL;
        pilha->tamanho = 0;
    }

    return pilha;
}

PILHASEQ *pilha_criar_sequencial()
{
    PILHASEQ *pilha = malloc(sizeof(PILHASEQ));

    if(pilha != NULL)
    {
        pilha->tamanho = 0;
    }

    return pilha;
}

bool pilha_cheia_seq(PILHASEQ *pilha)
{
    if(pilha->tamanho == MAX)
        return true;

    return false;
}

bool pilha_cheia_enc(PILHA *pilha)
{
    NO *noTeste = malloc(sizeof(NO));

    if(noTeste == NULL)
    {
        free(noTeste);
        return true;
    }
    
    free(noTeste);
    noTeste = NULL;
    return false;
}

bool pilha_adicionar_seq(PILHASEQ *pilha, ITEM *item)
{   
    if(pilha == NULL || pilha_cheia_seq(pilha))
    {
        return false;
    }

    pilha->itens[pilha->tamanho] = item;
    pilha->tamanho++;

    return true;
}

bool pilha_adicionar_enc(PILHA *pilha, ITEM *item)
{
    if(pilha == NULL || pilha_cheia_enc(pilha))
    {
        return false;
    }

    NO* novoNo = malloc(sizeof(NO));
    novoNo->item = item;

    if(pilha->topo != NULL)
        novoNo->anterior = pilha->topo;
    else
        novoNo->anterior = NULL;

    pilha->topo = novoNo;
    pilha->tamanho++;

    return true;
}

ITEM* pilha_remover_seq(PILHASEQ *pilha)
{
    if(pilha == NULL || pilha->tamanho == 0)
    {
        return NULL;
    }

    pilha->tamanho--;
    ITEM* item = pilha->itens[pilha->tamanho];
    pilha->itens[pilha->tamanho] = NULL;

    return item;
}

ITEM* pilha_remover_enc(PILHA *pilha)
{
    if(pilha == NULL || pilha->tamanho == 0)
    {
        return NULL;
    }

    pilha->tamanho--;

    ITEM* item = pilha->topo->item;

    NO* noAux = pilha->topo;
    pilha->topo = pilha->topo->anterior;

    free(noAux);
    noAux = NULL;

    return item;
}

void pilha_imprimir_seq(PILHASEQ *pilha)
{
    for(int i = 0; i < pilha->tamanho; i++)
    {
        item_imprimir(pilha->itens[i]);
    }
}

void pilha_imprimir_enc(PILHA *pilha)
{
    NO *noAux = pilha->topo;

    ITEM *itens[pilha->tamanho];

    for(int i = pilha->tamanho-1; i >= 0; i--)
    {
        itens[i] = noAux->item;
        noAux = noAux->anterior;
    }

    for(int i = 0; i < pilha->tamanho; i++)
    {
        item_imprimir(itens[i]);
    }
}

bool pilha_apagar_seq(PILHASEQ **pilha)
{
    if(pilha == NULL)
    {
        return false;
    }

    for(int i = 0; i < (*pilha)->tamanho; i++)
    {
        item_apagar(&((*pilha)->itens[i]));
    }

    free((*pilha));
    (*pilha) = NULL;

    return true;
}

bool pilha_apagar_enc(PILHA **pilha)
{
    if(pilha == NULL)
    {
        return false;
    }

    NO *noTopo = (*pilha)->topo;

    while (noTopo != NULL)
    {
        item_apagar(&(noTopo->item));

        NO* noAux = noTopo;
        noTopo = noTopo->anterior;

        free(noAux);
        noAux = NULL;
    }

    free((*pilha));
    (*pilha) = NULL;

    return true;
}