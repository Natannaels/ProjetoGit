#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main() {
    int n = 10;
    int arr[n];
    int temp = 0;

    printf("Array 1 eh: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0;  j < n - 1; j++) {
            if(arr[j] == 0) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] =  temp;
            }
        }
    }
    printf("Array alterado: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}