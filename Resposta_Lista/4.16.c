#include <stdio.h>
#include <limits.h>

int main() {
    int m, n, cont = 0;

    printf("Digite o tamanho do vetor 1:\n");
    scanf("%d", &m);
    printf("Digite o tamanho do vetor 2:\n");
    scanf("%d", &n);
    int A[m];
    int B[n];

    printf("Digite elementos do vetor A:");
    for(int i = 0; i < m; i++) {
        scanf("%d", &A[i]);
    }
    printf("Digite elementos do vetor B:");
    for(int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }
    
    for(int i = 0; i < m; i++ ) {
        for(int j = 0; j < n; j++) {
            if(A[i] == B[j]) {
                cont++;
                break;
            }
        }
    }

    if(cont >= m) {
        printf("A eh subconjunto de B");
    }
    else {
        printf("A nao eh subconjunto de B");
    }
    return 0;
}