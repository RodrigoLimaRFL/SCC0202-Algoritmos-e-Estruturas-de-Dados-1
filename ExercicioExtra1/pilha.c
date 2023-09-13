#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "item.h"
#include "pilha.h"

typedef struct pilha {
    ITEM *itens[TAM];
    int tamanho;
} PILHA;

PILHA *pilha_criar() {
    PILHA *pilha = (PILHA *) malloc(sizeof(PILHA));

    if(pilha == NULL) {
        printf("Erro ao alocar memória para a pilha.\n");
        exit(1);
    }

    pilha->tamanho = 0;

    return pilha;
}

bool pilha_vazia(PILHA *pilha)
{
    if(pilha == NULL)
    {
        return false;
    }

    return ((pilha->tamanho == 0) ? true : false);
}

bool pilha_cheia(PILHA *pilha)
{
    if(pilha == NULL)
    {
        return true;
    }

    return ((pilha->tamanho == TAM) ? true : false);
}

void pilha_apagar(PILHA **pilha, bool apagar_itens)
{
    if(*pilha != NULL && !pilha_vazia(*pilha))
    {
        if(apagar_itens)
        {
            while((*pilha)->tamanho != 0)
            {
                item_apagar(&((*pilha)->itens[(*pilha)->tamanho - 1]));
                (*pilha)->tamanho--;
            }
        }
    }

    free(*pilha);
    *pilha = NULL;
}

int pilha_tamanho(PILHA *pilha)
{
    if(pilha == NULL)
    {
        printf("PILHA NAO EXISTE\n");
        return 0;
    }

    return pilha->tamanho;
}

ITEM *pilha_topo(PILHA *pilha)
{
    if(pilha == NULL)
    {
        printf("PILHA NAO EXISTE\n");
        exit(1);
    }

    if(pilha->tamanho == 0)
    {
        return NULL;
    }

    return pilha->itens[pilha->tamanho-1];
}

bool pilha_empilhar(PILHA *pilha, ITEM *item)
{
    if(pilha == NULL || pilha_cheia(pilha))
    {
        printf("ERRO AO EMPILHAR\n");
        return false;
    }

    pilha->itens[pilha->tamanho] = item;
    pilha->tamanho++;
    return true;
}

ITEM *pilha_desempilhar(PILHA *pilha)
{
    if(pilha == NULL || pilha_vazia(pilha))
    {
        return NULL;
    }

    ITEM* item;

    item = pilha_topo(pilha);
    pilha->itens[pilha->tamanho-1] = NULL;
    pilha->tamanho--;
    return item;
}

void pilha_print(PILHA *pilha)
{
    if(pilha == NULL)
    {
        printf("PILHA NAO EXISTE");
        return;
    }

    for(int i = 0; i < pilha->tamanho; i++)
    {
        printf("%i ", item_get_chave(pilha->itens[pilha->tamanho-1]));
    }
}