#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "ponto.h"

struct circulo_
{
    PONTO *centro;
    float raio;
};

typedef struct circulo_ CIRCULO;

CIRCULO *circulo_criar(PONTO *p, float raio)
{
    CIRCULO *c = (CIRCULO *)malloc(sizeof(CIRCULO));

    if (c != NULL)
    {
        c->centro = p;
        c->raio = raio;
    }
}

void circulo_apagar(CIRCULO *c)
{
    if (c != NULL)
    {
        ponto_apagar(c->centro);
        free(c);
        c = NULL;
    }
}

float circulo_area(CIRCULO *c)
{
    if (c != NULL)
    {
        return 3.14 * c->raio * c->raio;
    }

    printf("ERRO! CIRCULO NAO EXISTE\n");

    return -1;
}

PONTO* get_centro(CIRCULO *c)
{
    if (c != NULL)
    {
        return c->centro;
    }

    printf("ERRO! CIRCULO NAO EXISTE\n");
}

float get_raio(CIRCULO *c)
{
    if (c != NULL)
    {
        return c->raio;
    }

    printf("ERRO! CIRCULO NAO EXISTE\n");

    return -1;
}