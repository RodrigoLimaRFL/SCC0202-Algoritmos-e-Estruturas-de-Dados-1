#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

// codigo comentado eh a parte extra do exercicio

int main()
{
    LISTA *lista = lista_criar();
    int n;

    scanf("%d", &n);

    int *chaves = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &chaves[i]);

        ITEM *item = item_criar(chaves[i]);
        lista_inserir_busca(lista, item);
    }

    lista_imprimir(lista);

    /*ITEM **itens;

    itens = lista_remover_todos(lista, chaves, n);

    for(int i = 0; i < n; i++)
    {
        item_imprimir(itens[i]);
    }*/

    lista_apagar(&lista);

    free(chaves);
    chaves = NULL;

    /*for(int i = 0; i<n; i++)
    {
        item_apagar(&itens[i]);
    }

    free(itens);
    itens = NULL;*/

    return 0;
}