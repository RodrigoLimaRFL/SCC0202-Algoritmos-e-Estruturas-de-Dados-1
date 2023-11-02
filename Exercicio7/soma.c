NO *somaNo(NO *raiz, int *somaValor);

int soma(AB *T)
{
    if (T == NULL)
        return 0;

    int somaValor = 0;
    somaNo(T->raiz, &somaValor);

    return (somaValor);
}

NO *somaNo(NO *raiz, int *somaValor)
{
    *somaValor += item_get_chave(raiz->item);

    if (raiz->esq != NULL)
        somaNo(raiz->esq, somaValor);

    if (raiz->dir != NULL)
        somaNo(raiz->dir, somaValor);

    return (raiz);
}