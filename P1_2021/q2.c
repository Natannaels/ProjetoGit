#include <stdlib.h>
#include <stdio.h>

int main() {

    int n, x;
    printf("Insira o tamanho do array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Insira %d elementos:\n", n);
    for(int i = 0; i < n; i++) {
        printf("elemento - %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Insira a posicao onde deseja excluir:");
    scanf("%d", &x);

    for(int i = 0; i < n; i++) {
        if(i == x) {
            for(int j = i; j < n - 1; j++){
                arr[j] = arr[j + 1];
            }
            n--;
            break;
        }
    }
    
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}