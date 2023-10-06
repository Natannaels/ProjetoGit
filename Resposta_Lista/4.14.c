#include <stdlib.h>
#include <stdio.h>

void rotacionar(int arr[], int t, int n);

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int t = sizeof(arr)/sizeof(int);
    rotacionar(arr, t, 3);

    for(int i = 0; i < t; i++)
        printf("%d ", arr[i]);
    
    return 0;
}

void rotacionar(int arr[], int t, int n ) {
    int temp = 0;
    for(int i = 0; i < n; i++) {
        temp = arr[0];
        for(int j = 0; j < t - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[t - 1] = temp;
    }
}