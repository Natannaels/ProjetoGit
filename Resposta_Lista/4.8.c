#include <stdlib.h>
#include <stdio.h>

int main() {
    int n = 9;
    int arr1[n];
    int arr2[n];
    int result[n];
    
    printf("Array 1 eh: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Array 2 eh: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    for(int i = 0; i < n; i++) {
        result[i] = arr1[i] - arr2[i];
    }
    

    printf("Array resultante da subtracao: :\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    


    return 0;
}