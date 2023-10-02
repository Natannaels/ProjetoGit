#include <stdio.h>
#include <limits.h>

int main() {
    int t, cont = 0;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &t);
    int arr[t];
    int aux[t];

    for(int i = 0; i < t; i++) {
        aux[i] = 0;
    }

    for(int i = 0; i < t; i++) {
        printf("elemento %d: ", i);
        scanf("%d", &arr[i]);
    }

    int repetidos[t];
    int repetidosCont = 0;

    printf("Elementos que se repetem: ");
    for(int i = 0;  i < t - 1; i++) {
        int cont_temp = 1;
        for(int j = i + 1; j < t; j++) {
            if(aux[j] != 1) {
                if(arr[j] == arr[i]) {
                    cont_temp++;
                    aux[j] = 1;
                    
                }
            }
        }
        if(cont_temp != 1) {
            cont ++;
            repetidos[repetidosCont++] = arr[i];
        }
        
    }

    for(int i= 0; i < repetidosCont; i++) {
        printf("%d ", repetidos[i]);
    }

    printf("\nQuantidade de numeros repetidos: %d", cont);

    return 0;
}