#include <stdio.h>
#include <stdlib.h>

void inverter(int A[], int n) {
    int temp;
    for(int i = 0; i < n/2; i++) {
        temp = A[i];
        A[i] = A[n - 1 - i];
        A[n - 1 - i] = temp;
    }
    
}

int main() {
    int n = 5;
    int A[n];

    printf("Digite 5 numeros :\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    inverter(A, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}