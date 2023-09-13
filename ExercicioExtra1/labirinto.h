#ifndef LABIRINTO_H
    #define LABIRINTO_H

    #include <stdbool.h>

    #include "item.h"
    #include "pilha.h"

    #define MAX 150
    
    typedef struct labirinto_ LABIRINTO;
    
    LABIRINTO *criar_labirinto(ITEM ***mapa, int linhas, int colunas);
    bool labirinto_existe(LABIRINTO *labirinto);
    bool labirinto_apagar(LABIRINTO **labirinto);
    bool percorrer_labirinto(LABIRINTO *labirinto);

#endif
    