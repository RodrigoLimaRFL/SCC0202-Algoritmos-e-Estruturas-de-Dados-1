#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct no_{
    ITEM *item;
    NO *prox;
};

struct lista_{
    NO *primeiro;
    NO *ultimo;
    int tamanho;
};

LISTA *lista_criar()
{
    LISTA *lista = malloc(sizeof(LISTA));

    if (lista != NULL)
    {
        lista->primeiro = NULL;
        lista->ultimo = NULL;
        lista->tamanho = 0;
    }

    return lista;
}

bool lista_inserir(LISTA *lista, ITEM *item)
{
    NO *no = malloc(sizeof(NO));

    if (no != NULL)
    {
        no->item = item;
        no->prox = NULL;

        if (lista->primeiro == NULL)
        {
            lista->primeiro = no;
            lista->ultimo = no;
        }
        else
        {
            lista->ultimo->prox = no;
            lista->ultimo = no;
        }

        lista->tamanho++;
        return true;
    }

    return false;
}

bool lista_inserir_busca(LISTA *lista, ITEM *item)
{
    NO *no = malloc(sizeof(NO));

    if (no != NULL)
    {
        no->item = item;
        no->prox = NULL;

        if (lista->primeiro == NULL)
        {
            lista->primeiro = no;
            lista->ultimo = no;
        }
        else if (item_get_chave(item) < item_get_chave(lista->primeiro->item))
        {
            no->prox = lista->primeiro;
            lista->primeiro = no;
        }
        else
        {
            NO* noAux = lista->primeiro;

            while(noAux->prox != NULL && item_get_chave(noAux->prox->item) < item_get_chave(item))
            {
                noAux = noAux->prox;
            }

            no->prox = noAux->prox;
            noAux->prox = no;
        }


        lista->tamanho++;
        return true;
    }

    return false;
}

ITEM *lista_remover(LISTA *lista, int chave)
{
    if (lista == NULL)
        return NULL;

    NO *no = lista->primeiro;
    NO *noAnterior = NULL;

    while (no != NULL)
    {
        if (item_get_chave(no->item) == chave)
        {
            if (noAnterior == NULL)
            {
                lista->primeiro = no->prox;
            }
            else
            {
                noAnterior->prox = no->prox;
            }

            if (no->prox == NULL)
            {
                lista->ultimo = noAnterior;
            }

            lista->tamanho--;

            ITEM *item = no->item;
            free(no);

            return item;
        }
        else
        {
            noAnterior = no;
            no = no->prox;
        }
    }

    return NULL;
}

ITEM **lista_remover_todos(LISTA *lista, int* chaves, int tamanho)
{
    ITEM **itens = malloc(tamanho * sizeof(ITEM*));

    if(itens == NULL)
        return NULL;
    
    for(int i = 0; i < tamanho; i++)
    {
        itens[i] = lista_remover(lista, chaves[i]);
    }

    lista -> tamanho = 0;
    lista -> primeiro = NULL;
    lista -> ultimo = NULL;

    return itens;
}

void lista_apagar(LISTA **lista)
{
    if (*lista != NULL)
    {
        NO *no = (*lista)->primeiro;

        while (no != NULL)
        {
            NO *noAux = no->prox;
            item_apagar(&no->item);
            free(no);
            no = noAux;
        }

        free(*lista);
        *lista = NULL;
    }
}

ITEM *lista_busca(LISTA *lista, int chave)
{
    if(lista == NULL)
        return NULL;
    
    NO *no;

    if(lista->primeiro != NULL)
    {
        no = lista->primeiro;

        while(no != NULL)
        {
            if(item_get_chave(no->item) == chave)
                return no->item;
            else
                no = no->prox;
        }
    }

    return NULL;
}

int lista_tamanho(LISTA *lista)
{
    return lista->tamanho;
}

bool lista_vazia(LISTA *lista)
{
    if(lista->tamanho == 0 && lista->primeiro == NULL)
        return true;
    else
        return false;
}

bool lista_cheia(LISTA *lista)
{
    NO* noTeste = malloc(sizeof(NO));

    if(noTeste == NULL)
    {
        free(noTeste);
        noTeste = NULL;
        return true;
    }
    else
    {
        free(noTeste);
        return false;
    }
}

void lista_imprimir(LISTA *lista)
{
    if(lista != NULL)
    {
        NO *no = lista->primeiro;

        while(no != NULL)
        {
            item_imprimir(no->item);
            no = no->prox;
        }

        printf("\n");
        printf("\n");
    }
}