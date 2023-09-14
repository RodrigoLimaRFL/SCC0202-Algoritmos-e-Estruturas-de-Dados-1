#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

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