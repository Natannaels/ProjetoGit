#include <stdlib.h>
#include <stdio.h>

void organizar_estoque(int arr[], int n);

int main() {
    
    int arr[] = {19, 7, 0, 3, 18, 15, 12, 6, -1, -1, 11, 10, 9, 5, 13, 16, 2, -1, 17, 4};
    int n = sizeof(arr) / sizeof(int);
    organizar_estoque(arr, n);
    printf("Estoque Organizado: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }



    return 0;
}

void organizar_estoque(int arr[], int n) {
    int temp = 0;
    for(int j = 0; j < n; j++ ) {
        for(int i = 0; i < n; i++) {
            if(arr[i] != -1 && arr[i] != i) {
                temp = arr[arr[i]];
                arr[arr[i]] = arr[i];
                arr[i] = temp;
            }
        }
    }
}