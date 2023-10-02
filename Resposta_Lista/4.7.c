#include <stdlib.h>
#include <stdio.h>

int main() {
    int n = 9;
    int arr[n];
    int inicio = 0;
    int fim = 0;
    int soma = 0;
    
    printf("Array de entrada eh: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    //verifica o intervalo de i ate j
    for(int i = 0; i < n; i++) {
        int uns = 0;
        int zeros = 0;

        if(arr[i] == 0) {
            zeros++;
        }
        else {
            uns++;
        }

        for(int j = i + 1; j < n; j++) {
            if(arr[j] == 0) {
                zeros++;
            }
            else {
                uns++;
            }
            //verifica se a soma de elementos eh a maior e se a qtd de 1 e 0 sao iguais
            if(soma < (zeros + uns) && uns == zeros) {
                soma = zeros + uns;
                inicio = i;
                fim = j;            
            }  
        }
    }

    printf("sub-vetor encontrado do indice %d ao %d",  inicio, fim);
    
    return 0;
}