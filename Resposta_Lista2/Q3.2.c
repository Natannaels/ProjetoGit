#include <stdio.h>

// Definição da struct Fração
typedef struct {
    int numerador;
    int denominador;
} Fracao;

// Função para somar duas frações
Fracao somarFracao(Fracao fracao1, Fracao fracao2) {
    Fracao resultado;

    // Encontrar o denominador comum
    int denominadorComum = fracao1.denominador * fracao2.denominador;

    // Calcular os novos numeradores
    int novoNumerador1 = fracao1.numerador * fracao2.denominador;
    int novoNumerador2 = fracao2.numerador * fracao1.denominador;

    // Calcular o numerador do resultado
    resultado.numerador = novoNumerador1 + novoNumerador2;

    // Atribuir o denominador comum ao resultado
    resultado.denominador = denominadorComum;

    return resultado;
}

int main() {
    Fracao fracao1, fracao2, resultado;

    // Solicitar a entrada para a fração 1
    printf("Digite a fração 1 (numerador denominador): ");
    scanf("%d %d", &fracao1.numerador, &fracao1.denominador);

    // Solicitar a entrada para a fração 2
    printf("Digite a fração 2 (numerador denominador): ");
    scanf("%d %d", &fracao2.numerador, &fracao2.denominador);

    // Chamar a função para somar as frações
    resultado = somarFracao(fracao1, fracao2);

    // Exibir o resultado
    printf("Resultado: %d/%d\n", resultado.numerador, resultado.denominador);

    return 0;
}
