#include <stdlib.h>
#include <stdio.h>

int main() {
    int n = 9;
    int arr[n];
    int aux[n];
    
    printf("Array de entrada eh: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //buble sort
    printf("O novo array eh: \n");
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int temp = 0;
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    //coloca os menores elementos nos indices pares e os maiores no impares

    int c =1;
    for(int i = 0; i < n; i++) {
        
            aux[i * 2] = arr[i];
            aux[i + c] = arr[n - c];
            c++;    
                
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", aux[i]);
    }
    
    return 0;
}