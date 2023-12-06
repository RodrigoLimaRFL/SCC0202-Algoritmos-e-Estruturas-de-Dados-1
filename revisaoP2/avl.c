#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "avl.h"

#define max(a, b) ((a) > (b) ? (a) : (b))

struct no_
{
    int chave;
    NO *esq;
    NO *dir;
    int altura;
};

struct avl_
{
    NO *raiz;
    int profundidade;
};

NO *avl_criar_no(int chave)
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

AVL *avl_criar()
{
    AVL *novaArvore = (AVL *)malloc(sizeof(AVL));
    if (novaArvore == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    novaArvore->raiz = NULL;
    novaArvore->profundidade = -1;
    return novaArvore;
}

int avl_altura(NO *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }
    return raiz->altura;
}

NO *rotacao_dir(NO *no)
{
    NO *aux;
    aux = no->esq;

    no->esq = aux->dir;
    aux->dir = no;

    no->altura = max(avl_altura(no->esq), avl_altura(no->dir)) + 1;
    aux->altura = max(avl_altura(aux->esq), avl_altura(aux->dir)) + 1;

    return aux;
}

NO *rotacao_esq(NO *no)
{
    NO *aux;
    aux = no->dir;

    no->dir = aux->esq;
    aux->esq = no;

    no->altura = max(avl_altura(no->esq), avl_altura(no->dir)) + 1;
    aux->altura = max(avl_altura(aux->esq), avl_altura(aux->dir)) + 1;

    return aux;
}

NO *rotacao_esq_dir(NO *no)
{
    no->esq = rotacao_esq(no->esq);
    return rotacao_dir(no);
}

NO *rotacao_dir_esq(NO *no)
{
    no->dir = rotacao_dir(no->dir);
    return rotacao_esq(no);
}

NO *avl_inserir_no(NO *raiz, NO *novoNo)
{
    if (raiz == NULL)
    {
        raiz = novoNo;
    }
    else if (novoNo->chave < raiz->chave)
    {
        raiz->esq = avl_inserir_no(raiz->esq, novoNo);
    }
    else if (novoNo->chave > raiz->chave)
    {
        raiz->dir = avl_inserir_no(raiz->dir, novoNo);
    }

    raiz->altura = max(avl_altura(raiz->esq), avl_altura(raiz->dir)) + 1;

    if (avl_altura(raiz->esq) - avl_altura(raiz->dir) == -2)
    {
        if (novoNo->chave > raiz->dir->chave)
        {
            raiz = rotacao_esq(raiz);
        }
        else
        {
            raiz = rotacao_dir_esq(raiz);
        }
    }

    if (avl_altura(raiz->esq) - avl_altura(raiz->dir) == 2)
    {
        if (novoNo->chave < raiz->esq->chave)
        {
            raiz = rotacao_dir(raiz);
        }
        else
        {
            raiz = rotacao_esq_dir(raiz);
        }
    }

    return raiz;
}

bool avl_inserir(AVL *arvore, int chave)
{
    if (arvore == NULL)
    {
        return false;
    }

    NO *novoNo = avl_criar_no(chave);

    if (novoNo == NULL)
    {
        return false;
    }

    arvore->raiz = avl_inserir_no(arvore->raiz, novoNo);

    return true;
}

void avl_troca_max_esq(NO *troca, NO *raiz, NO *ant)
{
    if ((troca)->dir != NULL)
    {
        avl_troca_max_esq((troca)->dir, raiz, troca);
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
    raiz->altura = max(avl_altura(raiz->esq), avl_altura(raiz->dir)) + 1;
    free(troca);
    troca = NULL;
}

NO *avl_remover_aux(NO **raiz, int chave)
{
    if (*raiz == NULL)
    {
        return NULL;
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
            avl_troca_max_esq((*raiz)->esq, *raiz, *raiz);
        }
    }
    else if (chave < (*raiz)->chave)
    {
        return avl_remover_aux(&(*raiz)->esq, chave);
    }
    else
    {
        return avl_remover_aux(&(*raiz)->dir, chave);
    }

    if ((*raiz) != NULL)
    {
        (*raiz)->altura = max(avl_altura((*raiz)->esq), avl_altura((*raiz)->dir)) + 1;

        if (avl_altura((*raiz)->esq) - avl_altura((*raiz)->dir) == -2)
        {
            if (avl_altura((*raiz)->dir->esq) - avl_altura((*raiz)->dir->dir) <= 0)
            {
                (*raiz) = rotacao_esq((*raiz));
            }
            else
            {
                (*raiz) = rotacao_dir_esq((*raiz));
            }
        }

        if (avl_altura((*raiz)->esq) - avl_altura((*raiz)->dir) == 2)
        {
            if (avl_altura((*raiz)->esq->esq) - avl_altura((*raiz)->esq->dir) >= 0)
            {
                (*raiz) = rotacao_dir(*raiz);
            }
            else
            {
                (*raiz) = rotacao_esq_dir(*raiz);
            }
        }
    }

    return *raiz;
}

bool avl_remover(AVL *arvore, int chave)
{
    if (arvore == NULL)
    {
        return false;
    }

    return avl_remover_aux(&(arvore->raiz), chave);
}

void avl_excluir_aux(NO **raiz)
{
    if ((*raiz)->esq != NULL)
    {
        avl_excluir_aux(&((*raiz)->esq));
    }
    if ((*raiz)->dir != NULL)
    {
        avl_excluir_aux(&((*raiz)->dir));
    }

    free(*raiz);
    *raiz = NULL;
}

bool avl_excluir(AVL **arvore)
{
    if ((*arvore == NULL))
    {
        return false;
    }

    avl_excluir_aux(&((*arvore)->raiz));
    free(*arvore);
    *arvore = NULL;
    return true;
}

void avl_imprimir_aux(NO *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    avl_imprimir_aux(raiz->esq);
    printf("%d ", raiz->chave);
    avl_imprimir_aux(raiz->dir);
}

void avl_imprimir(AVL *arvore)
{
    if (arvore == NULL)
    {
        return;
    }

    avl_imprimir_aux(arvore->raiz);
    printf("\n");
}

void avl_imprimir_nivel_aux(NO *raiz, int nivel)
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
        avl_imprimir_nivel_aux(raiz->esq, nivel - 1);
        avl_imprimir_nivel_aux(raiz->dir, nivel - 1);
    }
}

void avl_imprimir_nivel(AVL *arvore)
{
    if (arvore == NULL)
    {
        return;
    }

    for (int i = 0; i <= arvore->raiz->altura; i++)
    {
        avl_imprimir_nivel_aux(arvore->raiz, i);
        printf("\n");
    }
}

bool avl_busca_aux(NO *raiz, int chave)
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
        return avl_busca_aux(raiz->esq, chave);
    }
    else
    {
        return avl_busca_aux(raiz->dir, chave);
    }
}

bool avl_busca(AVL *arvore, int chave)
{
    if (arvore == NULL)
    {
        return false;
    }

    return avl_busca_aux(arvore->raiz, chave);
}

int num_nos(NO *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }

    int num = 0;

    if (raiz->esq != NULL)
    {
        num++;
        num += num_nos(raiz->esq);
    }

    if (raiz->dir != NULL)
    {
        num++;
        num += num_nos(raiz->dir);
    }

    return num;
}

int avl_num_nos(AVL *arvore)
{
    return num_nos(arvore->raiz) + 1;
}

int somar_nos(NO *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }

    int num = raiz->chave;

    num += somar_nos(raiz->esq);
    num += somar_nos(raiz->dir);

    return num;
}

int avl_somar_nos(AVL *arvore)
{
    return somar_nos(arvore->raiz);
}

int profundidade(NO *no)
{
    if (no == NULL)
    {
        return 0;
    }

    int prof = 0;

    if (no->esq != NULL || no->dir != NULL)
    {
        prof++;
    }

    prof += max(profundidade(no->esq), profundidade(no->dir));

    return prof;
}

int avl_profundidade(AVL *arvore)
{
    return profundidade(arvore->raiz);
}

bool completa(NO *no, int index, int numNos)
{
    if (no == NULL)
    {
        return true;
    }

    if (index >= numNos)
    {
        return false;
    }

    return completa(no->esq, 2 * index + 1, numNos) && completa(no->dir, 2 * index + 2, numNos);
}

bool avl_completa(AVL *arvore)
{
    return completa(arvore->raiz, 0, avl_num_nos(arvore));
}