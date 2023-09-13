#ifndef CIRCULO_H
    #define CIRCULO_H

    #include "ponto.h"

    typedef struct circulo_ CIRCULO;
    CIRCULO *circulo_criar(PONTO *p, float raio);
    void circulo_apagar (CIRCULO* circ);
    float circulo_area (CIRCULO* circ);
    // funcao para conseguir o centro do circulo sem ferir o principio de TAD
    PONTO* get_centro(CIRCULO *c);
    // funcao para conseguir o raio do circulo sem ferir o principio de TAD
    float get_raio(CIRCULO *c);

    /*
    Pode ser necessário definir outras operações para o TAD.
    Se for o caso, faça e justifique!
    */
#endif


