#include <stdio.h>

#include "ponto.h"
#include "circulo.h"

int main()
{
    float p1x, p1y;

    scanf("%f %f", &p1x, &p1y);

    PONTO *p1 = ponto_criar(p1x, p1y);

    float p2x, p2y, raio;

    scanf("%f %f %f", &p2x, &p2y, &raio);

    CIRCULO *c1= circulo_criar(ponto_criar(p2x, p2y), raio);

    float dist = distancia(p1, get_centro(c1));
    float raio_c = get_raio(c1);

    if(dist < raio_c)
    {
        printf("O ponto é interior à circunferência.\nDistância: %.2f\n", dist);
    }
    else if (dist == raio_c)
    {
        printf("O ponto pertence à circunferência.\nDistância: %.2f\n", dist);
    }
    else if (dist > raio_c)
    {
        printf("O ponto é exterior à circunferência.\nDistância: %.2f\n", dist);
    }
}