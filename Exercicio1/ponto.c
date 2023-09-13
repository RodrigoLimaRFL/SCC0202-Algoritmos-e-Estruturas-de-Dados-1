#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct ponto_
{
    float x;
    float y;
};

typedef struct ponto_ PONTO;

PONTO *ponto_criar(float x, float y)
{
    PONTO *p = (PONTO *)malloc(sizeof(PONTO));
    if (p != NULL)
    {
        p->x = x;
        p->y = y;
    }
    return p;
}

void ponto_apagar(PONTO *p)
{
    if (p != NULL)
    {
        free(p);
        p = NULL;
    }
}

bool ponto_set(PONTO *p, float x, float y)
{
    if (p != NULL)
    {
        return true;
    }

    return false;
}

float distancia(PONTO *p1, PONTO *p2)
{
    if (p1 != NULL && p2 != NULL)
    {
        return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
    }

    printf("ERRO! PONTO NAO EXISTE\n");

    return -1;
}