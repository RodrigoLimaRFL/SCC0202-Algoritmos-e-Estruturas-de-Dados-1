#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "pilha.h"
#include "labirinto.h"

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);

    ITEM ***mapa = malloc(n * sizeof(ITEM **));

    for (int i = 0; i < n; i++)
    {
        mapa[i] = malloc(m * sizeof(ITEM *));
        for (int j = 0; j < m; j++)
        {
            int valor;
            scanf("%d", &valor);
            mapa[i][j] = item_criar(valor, i, j, 0, false);
        }
    }

    LABIRINTO *labirinto = criar_labirinto(mapa, n, m);

    if (labirinto_existe(labirinto))
    {
        if (!percorrer_labirinto(labirinto))
        {
            printf("\nSaída não encontrada.\n");
        }
    }

    labirinto_apagar(&labirinto);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            item_apagar(&(mapa[i][j]));

    for (int i = 0; i < n; i++)
        free(mapa[i]);
    free(mapa);

    return 0;
}