#include <stdio.h>
#include <limits.h>

int ordenar(int arr[], int n) {
    int temp = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int missing_number(int arr[], int n) {
    ordenar(arr, n);
    for(int i = 0; i < n; i++) {
        if(arr[i] != i+1) {
            return i+1;
            break;
        }
    }
    return 0;
}

int main() {
    int n;

    
    printf("Digite o tamanho do vetor 2:\n");
    scanf("%d", &n);
    int B[n];

    printf("Digite elementos do vetor B:");
    for(int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }
    
    
    ordenar(B, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", B[i]);
    }
    
    return 0;
}