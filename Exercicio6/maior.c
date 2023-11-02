int maior(AB *T);
NO *maiorNo(NO *raiz, NO *maiorValor);

int maior(AB *T)
{
    NO *maiorValor = NULL;
    maiorValor = maiorNo(T->raiz, maiorValor);
    return (item_get_chave(maiorValor->item));
}

NO *maiorNo(NO *raiz, NO *maiorValor)
{
    if (raiz == NULL)
        return NULL;

    if (maiorValor == NULL)
    {
        maiorValor = raiz;
    }

    if (item_get_chave(raiz->item) > item_get_chave(maiorValor->item))
    {
        maiorValor = raiz;
    }

    if (raiz->esq != NULL)
        maiorValor = maiorNo(raiz->esq, maiorValor);

    if (raiz->dir != NULL)
        maiorValor = maiorNo(raiz->dir, maiorValor);

    return (maiorValor);
}