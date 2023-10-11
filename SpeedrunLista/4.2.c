#include <stdio.h>
#include <stdlib.h>

 int majoritario(int A[], int n) {
    

    if(n == 1 || n == 2) {
        return A[0];
    }

    for(int i = 0; i < n - 1; i++) {
        int cont = 1;
        for(int j = i + 1; j < n; j++) {
            if(A[i] == A[j]) {
                cont++;
            }
            
        }
        if(cont > (n/2)) {
            return A[i];
        }
        cont = 0;
    }
 }

int main() {
    int A[] = {7, 3, 4, 7, 7};
    int n = sizeof(A)/sizeof(A[0]);

    printf("Elemento Majoritario: %d", majoritario(A, n));

    return 0;
}