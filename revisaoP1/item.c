#include <stdio.h>
#include <stdlib.h>

#include "item.h"

struct item_{
    int chave;
};

ITEM* item_criar(int chave)
{
    ITEM *item = (ITEM*) malloc(sizeof(item));

    if(item != NULL)
    {
        item->chave = chave;
    }

    return item;
}

bool item_apagar(ITEM *(*item))
{
    if(*item == NULL)
    {
        return false;
    }

    free(*item);

    *item = NULL;

    return true;
}

int item_get_chave(ITEM *item)
{
    if(item == NULL)
    {
        printf("ERRO: ITEM NULO");
        exit(0);
    }

    return item->chave;
}

bool item_set_chave(ITEM *item, int chave)
{
    if(item == NULL)
    {
        printf("ERRO: ITEM NULO");
        exit(0);
    }

    item->chave = chave;

    return true;
}

void item_imprimir(ITEM *item)
{
    if (item != NULL)
        printf("[%i]; ", item->chave);
}