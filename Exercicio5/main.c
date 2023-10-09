#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main()
{
    LISTA *lista = lista_criar();

    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int chave;

        scanf("%d", &chave);

        ITEM* item = item_criar(chave);

        if(item == NULL)
        {
            printf("Erro ao criar item\n");
            exit(1);
        }
        
        lista_inserir(lista, item);
    }

    lista_inverter(&lista);

    lista_imprimir(lista);

    lista_apagar(&lista);

    return 0;
}