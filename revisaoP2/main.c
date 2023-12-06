#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "abb.h"
#include "avl.h"
#include "arn.h"
#include "filaprioridade.h"

int main()
{
    AVL *arvore = avl_criar();

    avl_inserir(arvore, 20);
    avl_inserir(arvore, 15);
    avl_inserir(arvore, 25);
    avl_inserir(arvore, 12);
    avl_inserir(arvore, 17);
    avl_inserir(arvore, 24);
    avl_inserir(arvore, 30);
    avl_inserir(arvore, 10);
    avl_inserir(arvore, 14);
    avl_inserir(arvore, 13);
    avl_remover(arvore, 14);

    avl_imprimir_nivel(arvore);

    return 0;
}