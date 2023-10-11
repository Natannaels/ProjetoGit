#include <stdlib.h>
#include <stdio.h>

void reorganizar(int A[], int n) {
    int menor = A[0];
    int maior = A[1];
    int flag;
    int aux[n];
    do {
        flag = 0;
        for(int i = 0; i < n - 1; i++) {
            if(A[i] > A[i + 1]) {
                int temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                flag = 1;
            }
        }
    } while(flag != 0);

    for(int i = 0; i < n; i++) {
        aux[i] = A[i];
    }
    
    int j = 1;
    for(int i = 0; i < n; i++) {
        A[i * 2] = aux[i];
        A[i + j] = aux[n - j];
        j++;
    }
   

}
//1 2 3 4 5 6 7 8 9

int main() {

    int A[] = {5, 8, 1, 4, 2, 9, 3, 7, 6};
    int n = sizeof(A)/sizeof(int);
    reorganizar(A, n);
    printf("tamanho do array: %d\n", n);
    for(int i = 0; i < 9; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}