#include <stdio.h>
#include <stdlib.h>

void mov_zero(int A[], int n) {

    for(int j = 0; j < n; j++) {
            for(int i = 0; i < n - 1; i++) {
                if(A[i] == 0) {
                    A[i] = A[i + 1];
                    A[i + 1] = 0;
                }      
            }
        }    
   
}

int main() {

    int A[] = {38, 44, 63, 0, 0, 19, 84, 0, 4, 0};
    int n = sizeof(A)/sizeof(int);

    mov_zero(A, n);

    for(int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}