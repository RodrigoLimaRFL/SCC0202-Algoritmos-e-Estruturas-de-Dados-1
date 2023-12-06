#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "abb.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

struct no_
{
    int chave;
    int altura;
    struct no_ *esq;
    struct no_ *dir;
};

struct abb_
{
    struct no_ *raiz;
    int profundidade;
};

NO *abb_criar_no(int chave)
{
    NO *novo = (NO *)malloc(sizeof(NO));
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    novo->chave = chave;
    novo->altura = 0;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

ABB *abb_criar()
{
    ABB *novaArvore = (ABB *)malloc(sizeof(ABB));
    if (novaArvore == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    novaArvore->raiz = NULL;
    novaArvore->profundidade = -1;
    return novaArvore;
}

int abb_altura(NO *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }
    return raiz->altura;
}

NO *abb_inserir_no(NO *raiz, NO *novoNo)
{
    if (raiz == NULL)
    {
        raiz = novoNo;
    }
    else if (novoNo->chave < raiz->chave)
    {
        raiz->esq = abb_inserir_no(raiz->esq, novoNo);
    }
    else
    {
        raiz->dir = abb_inserir_no(raiz->dir, novoNo);
    }

    raiz->altura = max(abb_altura(raiz->esq), abb_altura(raiz->dir)) + 1;

    return raiz;
}

bool abb_inserir(ABB *arvore, int chave)
{
    if (arvore == NULL)
    {
        return false;
    }

    NO *novoNo = abb_criar_no(chave);
    if (novoNo == NULL)
    {
        return false;
    }
    arvore->raiz = abb_inserir_no(arvore->raiz, novoNo);
    arvore->profundidade = arvore->raiz->altura;
    return true;
}

void troca_max_esq(NO *troca, NO *raiz, NO *ant)
{
    if ((troca)->dir != NULL)
    {
        troca_max_esq((troca)->dir, raiz, troca);
        return;
    }
    if (raiz == ant)
    {
        ant->esq = troca->esq;
    }
    else
    {
        ant->dir = troca->esq;
    }

    raiz->chave = (troca)->chave;
    raiz->altura = max(abb_altura(raiz->esq), abb_altura(raiz->dir)) + 1;
    free(troca);
    troca = NULL;
}

bool abb_remover_aux(NO **raiz, int chave)
{
    if (*raiz == NULL)
    {
        return false;
    }

    NO *aux;

    if (chave == (*raiz)->chave)
    {
        if ((*raiz)->esq == NULL || (*raiz)->dir == NULL)
        {
            aux = *raiz;

            if ((*raiz)->esq == NULL)
            {
                *raiz = (*raiz)->dir;
            }
            else
            {
                *raiz = (*raiz)->esq;
            }

            free(aux);
            aux = NULL;
        }
        else
        {
            troca_max_esq((*raiz)->esq, *raiz, *raiz);
        }
        return true;
    }
    else if (chave < (*raiz)->chave)
    {
        return abb_remover_aux(&(*raiz)->esq, chave);
    }
    else
    {
        return abb_remover_aux(&(*raiz)->dir, chave);
    }
}

bool abb_remover(ABB *arvore, int chave)
{
    if (arvore == NULL)
    {
        return false;
    }

    return abb_remover_aux(&(arvore->raiz), chave);
}

void abb_excluir_aux(NO **raiz)
{
    if ((*raiz)->esq != NULL)
    {
        abb_excluir_aux(&((*raiz)->esq));
    }
    if ((*raiz)->dir != NULL)
    {
        abb_excluir_aux(&((*raiz)->dir));
    }

    free(*raiz);
    *raiz = NULL;
}

bool abb_excluir(ABB **arvore)
{
    if ((*arvore == NULL))
    {
        return false;
    }

    abb_excluir_aux(&((*arvore)->raiz));
    free(*arvore);
    *arvore = NULL;
    return true;
}

void abb_imprimir_aux(NO *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    abb_imprimir_aux(raiz->esq);
    printf("%d ", raiz->chave);
    abb_imprimir_aux(raiz->dir);
}

void abb_imprimir(ABB *arvore)
{
    if (arvore == NULL)
    {
        return;
    }

    abb_imprimir_aux(arvore->raiz);
    printf("\n");
}

void imprimir_nivel_aux(NO *raiz, int nivel)
{
    if (raiz == NULL)
    {
        return;
    }

    if (nivel == 0)
    {
        printf("%d -> ", raiz->chave);
    }
    else
    {
        imprimir_nivel_aux(raiz->esq, nivel - 1);
        imprimir_nivel_aux(raiz->dir, nivel - 1);
    }
}

void abb_imprimir_nivel(ABB *arvore)
{
    if (arvore == NULL)
    {
        return;
    }

    for (int i = 0; i <= arvore->raiz->altura; i++)
    {
        imprimir_nivel_aux(arvore->raiz, i);
        printf("\n");
    }
}

bool abb_busca_aux(NO *raiz, int chave)
{
    if (raiz == NULL)
    {
        return false;
    }

    if (raiz->chave == chave)
    {
        return true;
    }
    else if (raiz->chave < chave)
    {
        return abb_busca_aux(raiz->esq, chave);
    }
    else
    {
        return abb_busca_aux(raiz->dir, chave);
    }
}

bool abb_busca(ABB *arvore, int chave)
{
    if (arvore == NULL)
    {
        return false;
    }

    return abb_busca_aux(arvore->raiz, chave);
}