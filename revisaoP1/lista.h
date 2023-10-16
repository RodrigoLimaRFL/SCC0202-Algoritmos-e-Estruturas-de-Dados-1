#ifndef LISTA_H
    #define LISTA_H
    #define MAX 100

    #include "item.h"

    typedef struct no_ NO;

    typedef struct listaSeq_ LISTASEQ;
    typedef struct listaEnc_ LISTAENC;

    typedef struct noGen_ NOGEN;
    typedef struct listaGen_ LISTAGEN;

    LISTASEQ *lista_criar_seq();
    bool lista_cheia_seq(LISTASEQ *lista);
    bool lista_inserir_seq(LISTASEQ *lista, ITEM *item);
    ITEM *lista_remover_seq(LISTASEQ *lista, int chave);
    void lista_imprimir_seq(LISTASEQ *lista);
    bool lista_apagar_seq(LISTASEQ **lista);

    LISTAENC *lista_criar_enc();
    bool lista_cheia_enc(LISTAENC *lista);
    bool lista_inserir_enc(LISTAENC *lista, ITEM *item);
    ITEM *lista_remover_enc(LISTAENC *lista, int chave);
    void lista_imprimir_enc(LISTAENC *lista);
    bool lista_apagar_enc(LISTAENC **lista);

#endif