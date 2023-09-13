#include <stdio.h>
#include <stdlib.h>

#include "labirinto.h"

struct labirinto_{
    // mapa com a caracteristica da celula e a posicao x e y
    ITEM *mapa[MAX][MAX];
    int linhas;
    int colunas;
    // pilha de deep first search
    PILHA *dfs;
};

LABIRINTO *criar_labirinto(ITEM ***mapa, int linhas, int colunas)
{
    LABIRINTO *labirinto = (LABIRINTO *) malloc(sizeof(LABIRINTO));
    if(labirinto == NULL)
        return NULL;
    
    labirinto->linhas = linhas;
    labirinto->colunas = colunas;
    labirinto->dfs = pilha_criar();
    
    for(int i = 0; i < linhas; i++)
        for(int j = 0; j < colunas; j++)
            labirinto->mapa[i][j] = mapa[i][j];
    
    return labirinto;
}

bool labirinto_existe(LABIRINTO *labirinto)
{
    return (labirinto != NULL);
}

// apaga o labirinto
bool labirinto_apagar(LABIRINTO **labirinto)
{
    if(!labirinto_existe(*labirinto))
        return false;

    pilha_apagar(&((*labirinto)->dfs), false);
    
    free(*labirinto);
    *labirinto = NULL;
    
    return true;
}

// retorna true se conseguir percorrer o labirinto, se nao retorna false
bool percorrer_labirinto(LABIRINTO *labirinto)
{
    if(!labirinto_existe(labirinto))
        return false;

    if(item_get_chave(labirinto->mapa[0][0]) == 2)
    {
        item_imprimir(labirinto->mapa[0][0]);
        return true;
    }

    if(item_get_chave(labirinto->mapa[0][0]) != 1)
        return false;

    item_imprimir(labirinto->mapa[0][0]);

    int currentCoords[2] = {0, 0};

    item_set_visited(labirinto->mapa[0][0], true);

    while(1)
    {
        ITEM *top_item = pilha_topo(labirinto->dfs);

        if(top_item != NULL)
        {
            if(item_get_chave(top_item) == 2)
            {
                item_imprimir(top_item);
                break;
            }
            currentCoords[0] = item_get_coordsX(top_item);
            currentCoords[1] = item_get_coordsY(top_item);
            item_set_visited(top_item, true);
            item_imprimir(pilha_desempilhar(labirinto->dfs));
        }

        // checa se a celula existe e se ela nao eh parede

        // caso sul
        if(currentCoords[0] + 1 < labirinto->linhas && item_get_visited(labirinto->mapa[currentCoords[0] + 1][currentCoords[1]]) == false)
        {
            if(item_get_chave(labirinto->mapa[currentCoords[0] + 1][currentCoords[1]]) >= 1)
            {
                item_set_direction(labirinto->mapa[currentCoords[0] + 1][currentCoords[1]], 0);
                pilha_empilhar(labirinto->dfs, labirinto->mapa[currentCoords[0] + 1][currentCoords[1]]);
            }
        }

        // caso oeste
        if(currentCoords[1] - 1 >= 0 && item_get_visited(labirinto->mapa[currentCoords[0]][currentCoords[1] - 1]) == false)
        {
            if(item_get_chave(labirinto->mapa[currentCoords[0]] [currentCoords[1] - 1]) >= 1)
            {
                item_set_direction(labirinto->mapa[currentCoords[0]] [currentCoords[1] - 1], 1);
                pilha_empilhar(labirinto->dfs, labirinto->mapa[currentCoords[0]][currentCoords[1] - 1]);
            }
        }

        // caso norte
        if(currentCoords[0] - 1 >= 0 && item_get_visited(labirinto->mapa[currentCoords[0] - 1] [currentCoords[1]]) == false)
        {
            if(item_get_chave(labirinto->mapa[currentCoords[0] - 1] [currentCoords[1]]) >= 1)
            {
                item_set_direction(labirinto->mapa[currentCoords[0] - 1] [currentCoords[1]], 2);
                pilha_empilhar(labirinto->dfs, labirinto->mapa[currentCoords[0] - 1][currentCoords[1]]);
            }
        }

        // caso leste
        if(currentCoords[1] + 1 < labirinto->colunas && item_get_visited(labirinto->mapa[currentCoords[0]] [currentCoords[1] + 1]) == false)
        {
            if(item_get_chave(labirinto->mapa[currentCoords[0]] [currentCoords[1] + 1]) >= 1)
            {
                item_set_direction(labirinto->mapa[currentCoords[0]] [currentCoords[1] + 1], 3);
                pilha_empilhar(labirinto->dfs, labirinto->mapa[currentCoords[0]][currentCoords[1] + 1]);
            }
        }

        if (pilha_vazia(labirinto->dfs))
            return false;
    }

    return true;
}