#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int A[] = {38, 44, 63, -51, -35, 19, 84, -69, 4, -46};
    int n = sizeof(A)/sizeof(int);
    int elemento1 = A[0];
    int elemento2 = A[1];
    int soma = INT_MAX; 
    
    for(int i = 0; i < n; i++) {

        for(int j = i + 1; j < n; j++) {
            
            if(abs(A[i] + A[j]) < soma) {
                soma = abs(A[i] + A[j]);
                elemento1 = A[i];
                elemento2 = A[j];
            }
        }
    }

    printf("par de elementos cuja soma é mínima: [%d, %d]", elemento1, elemento2);

    return 0;
}