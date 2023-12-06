#ifndef ABB_H
    #define ABB_H

    typedef struct no_ NO;
    typedef struct abb_ ABB;

    ABB *abb_criar();
    bool abb_inserir(ABB *arvore, int chave);
    bool abb_remover(ABB *arvore, int chave);
    bool abb_excluir(ABB **arvore);
    void abb_imprimir(ABB *arvore);
    void abb_imprimir_nivel(ABB *arvore);

#endif