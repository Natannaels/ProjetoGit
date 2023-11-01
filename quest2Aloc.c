#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N, i;
    int *array;
    int soma = 0;
    const int limite = 100;

    // Solicita ao usuário a digitação de um número inteiro positivo N
    printf("Digite um número inteiro positivo N: ");
    scanf("%d", &N);

    // Verifica se N é um número positivo
    if (N <= 0) {
        printf("N deve ser um número inteiro positivo.\n");
        return 1;
    }

    // Aloca dinamicamente um array de inteiros de tamanho N
    array = (int *)malloc(N * sizeof(int);

    // Verifica se a alocação de memória foi bem-sucedida
    if (array == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    // Preenche o array com valores aleatórios e calcula a soma
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        array[i] = rand() % 100;  // Números aleatórios entre 0 e 99
        soma += array[i];
    }

    // Exibe os valores do array
    printf("Valores no array: ");
    for (i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Exibe a soma dos elementos do array
    printf("Soma dos elementos do array: %d\n", soma);

    // Verifica se a soma ultrapassa o limite
    if (soma > limite) {
        int novo_tamanho = N * 1.5;  // Aumenta o tamanho em 50%
        array = (int *)realloc(array, novo_tamanho * sizeof(int));
        
        // Preenche as vagas adicionais com valores aleatórios
        for (i = N; i < novo_tamanho; i++) {
            array[i] = rand() % 100;  // Números aleatórios entre 0 e 99
            soma += array[i];
        }

        printf("Array realocado e preenchido com novos valores.\n");
    }

    // Exibe a nova soma dos elementos do array
    printf("Nova soma dos elementos do array: %d\n", soma);

    // Libera a memória alocada para o array
    free(array);

    return 0;
}
