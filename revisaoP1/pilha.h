#ifndef PILHA_H
    #define PILHA_H

    #define MAX 100

    typedef struct no_ NO;

    typedef struct pilhaEncadeada_ PILHA;

    typedef struct pilhaSequencial_ PILHASEQ;

    PILHA *pilha_criar_encadeada();
    PILHASEQ *pilha_criar_sequencial();
    bool pilha_cheia_seq(PILHASEQ *pilha);
    bool pilha_cheia_enc(PILHA *pilha);
    bool pilha_adicionar_seq(PILHASEQ *pilha, ITEM *item);
    bool pilha_adicionar_enc(PILHA *pilha, ITEM *item);
    ITEM* pilha_remover_seq(PILHASEQ *pilha);
    ITEM* pilha_remover_enc(PILHA *pilha);
    void pilha_imprimir_seq(PILHASEQ *pilha);
    void pilha_imprimir_enc(PILHA *pilha);
    bool pilha_apagar_seq(PILHASEQ **pilha);
    bool pilha_apagar_enc(PILHA **pilha);
    
#endif