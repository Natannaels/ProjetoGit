#include <stdio.h>
#include <stdlib.h>


int* k_itens_com_max_soma(int num_uns, int num_zeros, int num_negativos, int k) {
    int total_itens = num_uns + num_zeros + num_negativos;

    // Criar array com os valores dos itens
    int* arr = (int*)malloc(total_itens * sizeof(int));

    // Preencher o array com os valores adequados
    for (int i = 0; i < num_uns; ++i) {
        arr[i] = 1;
    }
    for (int i = num_uns; i < num_uns + num_zeros; ++i) {
        arr[i] = 0;
    }
    for (int i = num_uns + num_zeros; i < total_itens; ++i) {
        arr[i] = -1;
    }

    int maxSum = 0, onesResult = 0, zerosResult = 0, negOnesResult = 0;

    // Calcula a soma máxima e os itens escolhidos
    for (int i = 0; i < k; i++) {
        maxSum += arr[i];
        if (arr[i] == 1) {
            onesResult++;
        } else if (arr[i] == 0) {
            zerosResult++;
        } else if (arr[i] == -1) {
            negOnesResult++;
        }
    }

    // Inicializa os valores atuais
    int currentSum = maxSum;
    int currentOnes = onesResult;
    int currentZeros = zerosResult;
    int currentNegOnes = negOnesResult;

    // Percorre o restante do array
    for (int i = k; i < total_itens; i++) {
        currentSum += arr[i] - arr[i - k];

        if (arr[i] == 1) {
            currentOnes++;
        } else if (arr[i] == 0) {
            currentZeros++;
        } else if (arr[i] == -1) {
            currentNegOnes++;
        }

        // Atualiza os resultados se encontrar uma soma maior
        if (currentSum > maxSum) {
            maxSum = currentSum;
            onesResult = currentOnes;
            zerosResult = currentZeros;
            negOnesResult = currentNegOnes;
        }
    }

    // Libera a memória alocada para o array de itens
    free(arr);

    // Cria o array de resultados
    int* resultados = (int*)malloc(4 * sizeof(int));
    resultados[0] = maxSum;
    resultados[1] = onesResult;
    resultados[2] = zerosResult;
    resultados[3] = negOnesResult;

    return resultados;
}

int main() {
    // Exemplo de uso
    int num_uns = 5, num_zeros = 3, num_negativos = 4, k = 6;

    int* resultado = k_itens_com_max_soma(num_uns, num_zeros, num_negativos, k);

    printf("Soma máxima: %d\n", resultado[0]);
    printf("Quantidade de uns escolhidos: %d\n", resultado[1]);
    printf("Quantidade de zeros escolhidos: %d\n", resultado[2]);
    printf("Quantidade de menos uns escolhidos: %d\n", resultado[3]);

    // Libera a memória alocada para o array de resultados
    free(resultado);

    return 0;
}
