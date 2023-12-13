#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int numerador;
    int denominador; 
}Fracao;

Fracao somaFracao(Fracao fracao1, Fracao fracao2);

int main() {
    Fracao fracao2;
    Fracao fracao1;

    printf("Digite a fracao 1: ");
    scanf("%d %d", &fracao1.numerador, &fracao1.denominador);
    printf("Digite a fracao 2: ");
    scanf("%d %d", &fracao2.numerador, &fracao2.denominador);
    
    Fracao result = somaFracao(fracao1, fracao2);

    printf("Resultado: %d/%d", result.numerador, result.denominador);


    return 0;
}

Fracao somaFracao(Fracao fracao1, Fracao fracao2) {
    Fracao resultado;

    int denominadorComum = (fracao1.denominador * fracao2.denominador);
    int novoNumerador1 = (fracao1.numerador * fracao2.denominador);
    int novoNumerador2 = (fracao2.numerador * fracao1.denominador);

    resultado.numerador = novoNumerador1 + novoNumerador2;
    resultado.denominador = denominadorComum;
    
    return resultado;
}