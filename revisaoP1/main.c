#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "pilha.h"
#include "lista.h"
#include "lista.h"

int main()
{
    ITEM *itemA = item_criar(10);
    ITEM *itemB = item_criar(15);
    ITEM *itemC = item_criar(20);
    ITEM *itemD = item_criar(18);
    ITEM *itemE = item_criar(12);
    ITEM *itemF = item_criar(8);

    LISTAENC *lista = lista_criar_enc();

    printf("1:\n");
    lista_inserir_enc(lista, itemA);
    printf("2:\n");
    lista_inserir_enc(lista, itemC);
    printf("3:\n");
    lista_inserir_enc(lista, itemB);
    printf("4:\n");
    lista_inserir_enc(lista, itemD);
    printf("5:\n");
    lista_inserir_enc(lista, itemE);
    printf("6:\n");
    lista_inserir_enc(lista, itemF);

    lista_imprimir_enc(lista);

    printf("\n");

    item_imprimir(lista_remover_enc(lista, 15));

    printf("\n");

    lista_imprimir_enc(lista);

    lista_apagar_enc(&lista);

    return 0;
}