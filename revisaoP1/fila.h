#ifndef FILA_H
    #define FILA_H
    #define MAX 100

    #include "item.h"

    typedef struct filaSeqCirc_ FILASEQ;
    typedef struct no_ NO;
    typedef struct filaEnc_ FILAENC;

    FILASEQ *fila_criar_seq();
    FILAENC *fila_criar_enc();
    bool fila_cheia_seq(FILASEQ *fila);
    bool fila_cheia_enc(FILAENC *fila);
    bool fila_inserir_seq(FILASEQ *fila, ITEM *item);
    bool fila_inserir_enc(FILAENC *fila, ITEM *item);
    ITEM *fila_remover_seq(FILASEQ *fila);
    ITEM *fila_remover_enc(FILAENC *fila);
    bool fila_apagar_seq(FILASEQ **fila);
    bool fila_apagar_enc(FILAENC **fila);
    void fila_imprimir_seq(FILASEQ *fila);
    void fila_imprimir_enc(FILAENC *fila);
    
#endif