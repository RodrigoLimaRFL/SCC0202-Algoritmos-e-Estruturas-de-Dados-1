#ifndef PONTO_H
    #define PONTO_H
	#include <stdbool.h>
	
    typedef struct ponto_ PONTO;
    PONTO *ponto_criar(float x, float y);
    void ponto_apagar(PONTO *p);
    bool ponto_set(PONTO *p, float x, float y);
    // funcao para calculo da distancia entre 2 pontos
    float distancia(PONTO *p1, PONTO *p2);

    /*
    Pode ser necessário definir outras operações para o TAD.
    Se for o caso, faça e justifique!
    */
#endif





