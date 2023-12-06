#ifndef ARN_H
    #define ARN_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

    typedef struct arn_ ARN;
    typedef struct no_ NO;

    ARN *arn_criar();
    void arn_inserir(ARN *arvore, int chave);
    void arn_imprimir(ARN *arvore);
    void arn_imprimir_nivel(ARN *arvore);

#endif