#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main() {
    int n = 10;
    int arr[n], soma_min = INT_MAX;
    int x = 0, y = 0;
    
    printf("Array 1 eh: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(abs(arr[i] + arr[j]) < soma_min) {
                soma_min = abs(arr[i] + arr[j]);
                x = arr[i];
                y = arr[j];
            }
        }
    }

    printf("par de elementos cuja soma eh minima: [%d, %d]\n", x, y);

    return 0;
}