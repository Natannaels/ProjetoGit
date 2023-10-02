#include <stdio.h>
#include <limits.h>

int main() {
    int t = 10, temp;
    int n = 3;
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < t-1; j++) {   
            temp = arr[j];         
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
        
    }

    printf("rotacionado: \n");
    for(int i = 0; i < t; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}