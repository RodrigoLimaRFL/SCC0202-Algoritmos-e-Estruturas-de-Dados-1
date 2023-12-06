#include "arn.h"
#define max(a, b) ((a) > (b) ? (a) : (b))
#define BLACK false
#define RED true

struct no_
{
    int chave;
    NO *esq;
    NO *dir;
    bool cor; // 0 = preto, 1 = vermelho
    int altura;
};

struct arn_
{
    NO *raiz;
};

ARN *arn_criar()
{
    ARN *arvore = (ARN *)malloc(sizeof(ARN));
    if (arvore != NULL)
    {
        arvore->raiz = NULL;
    }
    return arvore;
}

int arn_altura(NO *raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }
    return raiz->altura;
}

NO *arn_criar_no(int chave)
{
    NO *novo = (NO *)malloc(sizeof(NO));
    if (novo != NULL)
    {
        novo->chave = chave;
        novo->esq = NULL;
        novo->dir = NULL;
        novo->cor = RED;
        novo->altura = 0;
    }
    return novo;
}

NO *arn_rotacao_dir(NO *no)
{
    NO *aux;
    aux = no->esq;

    no->esq = aux->dir;
    aux->dir = no;

    aux->cor = no->cor;
    no->cor = RED;

    no->altura = max(arn_altura(no->esq), arn_altura(no->dir)) + 1;
    aux->altura = max(arn_altura(aux->esq), arn_altura(aux->dir)) + 1;

    return aux;
}

NO *arn_rotacao_esq(NO *no)
{
    NO *aux;
    aux = no->dir;

    no->dir = aux->esq;
    aux->esq = no;

    aux->cor = no->cor;
    no->cor = RED;

    no->altura = max(arn_altura(no->esq), arn_altura(no->dir)) + 1;
    aux->altura = max(arn_altura(aux->esq), arn_altura(aux->dir)) + 1;

    return aux;
}

NO *arn_rotacao_esq_dir(NO *no)
{
    no->esq = arn_rotacao_esq(no->esq);
    return arn_rotacao_dir(no);
}

void arn_inversao(NO *no)
{
    if (no != NULL)
    {
        no->cor = !no->cor;
        no->esq->cor = !no->esq->cor;
        no->dir->cor = !no->dir->cor;
    }
}

bool is_vermelho(NO *no)
{
    if (no == NULL)
    {
        return false;
    }
    return no->cor == RED;
}

NO *arn_inserir_no(NO *raiz, NO *novo)
{
    if (raiz == NULL)
    {
        return novo;
    }

    if (is_vermelho(raiz->esq) && is_vermelho(raiz->dir))
    {
        arn_inversao(raiz);
    }

    if (novo->chave < raiz->chave)
    {
        raiz->esq = arn_inserir_no(raiz->esq, novo);
    }
    else
    {
        raiz->dir = arn_inserir_no(raiz->dir, novo);
    }

    raiz->altura = max(arn_altura(raiz->esq), arn_altura(raiz->dir)) + 1;

    if (is_vermelho(raiz->dir) && !is_vermelho(raiz->esq))
    {
        raiz = arn_rotacao_esq(raiz);
    }

    if (is_vermelho(raiz->esq) && is_vermelho(raiz->esq->esq))
    {
        raiz = arn_rotacao_dir(raiz);
    }

    return raiz;
}

void arn_inserir(ARN *arvore, int chave)
{
    NO *novo = arn_criar_no(chave);
    if (novo != NULL)
    {
        arvore->raiz = arn_inserir_no(arvore->raiz, novo);
        arvore->raiz->cor = BLACK;
    }
}

void arn_imprimir_aux(NO *raiz)
{
    if (raiz == NULL)
    {
        return;
    }

    arn_imprimir_aux(raiz->esq);
    printf("%d ", raiz->chave);
    arn_imprimir_aux(raiz->dir);
}

void arn_imprimir(ARN *arvore)
{
    if (arvore == NULL)
    {
        return;
    }

    arn_imprimir_aux(arvore->raiz);
    printf("\n");
}

void arn_imprimir_nivel_aux(NO *raiz, int nivel)
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
        arn_imprimir_nivel_aux(raiz->esq, nivel - 1);
        arn_imprimir_nivel_aux(raiz->dir, nivel - 1);
    }
}

void arn_imprimir_nivel(ARN *arvore)
{
    if (arvore == NULL)
    {
        return;
    }

    for (int i = 0; i <= arvore->raiz->altura; i++)
    {
        arn_imprimir_nivel_aux(arvore->raiz, i);
        printf("\n");
    }
}
