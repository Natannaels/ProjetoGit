#include <stdio.h>
#include <stdlib.h>

int sub(int A[], int B[], int n) {
    int C[n];
    for(int i = 0; i < n; i++) {
        C[i] = A[i] - B[i];
    }
    for(int i = 0; i < n; i++){
        printf("%d",C[i]);
    }
}

int main() {

    int A[] = {5, 2, 3};
    int n = sizeof(A)/sizeof(int);
    int B[] = {1, 2, 1};
    int m = sizeof(B)/sizeof(int);

    sub(A, B, n);
    
   
    return 0;
}