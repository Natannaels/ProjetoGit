#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void rota(int A[], int n, int t) {
    int temp = 0;
    for(int i = 0; i < n; i++) {
        temp = A[0];
        for(int j = 0; j < t - 1; j++) {
            A[j] = A[j + 1];
        }
        A[t - 1] = temp;
    }
}

int main() {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int t = sizeof(A)/sizeof(int);
    int n = 3;
    rota(A, n, t);

    for(int i = 0; i < t; i ++) {
        printf("%d ",A[i]);
    }

    return 0;
}