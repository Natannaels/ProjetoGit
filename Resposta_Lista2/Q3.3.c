#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
}Ponto;

int distancia(Ponto pontoA, Ponto pontoB);

int main() {
    
    Ponto pontoA;
    Ponto pontoB;

    printf("Digite o Ponto A: ");
    scanf("%d %d", &pontoA.x, &pontoA.y);
    printf("Digite o Ponto B: ");
    scanf("%d %d", &pontoB.x, &pontoB.y);

    int resultado = distancia(pontoA, pontoB);

    printf("A distancia entre PA e PB: %d", resultado);

    return 0;
}

int distancia(Ponto pontoA, Ponto pontoB) {
    int deltaX = pontoB.x - pontoA.x;
    int deltaY = pontoB.y - pontoA.y;

    int resultado = sqrt((deltaX * deltaX) + (deltaY * deltaY)); 
    return resultado;
}