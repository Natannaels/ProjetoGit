#include <stdio.h>
#include <stdlib.h>


int main() {

    int A[] = {0, 1, 0, 0, 1, 1, 0, 1, 1, 1};
    int n = sizeof(A)/sizeof(int);

    int inicio = 0;
    int fim = 0;
    
    int soma = 0;

    for(int i = 0; i < n; i++) {
        int zeros = 0;
        int uns = 0;
        if(A[i] == 0) {
            zeros++;
        }
        else {
            uns++;
        }
        for(int j = i + 1; j < n; j++) {
            if(A[j] == 0) {
                zeros++;
            }
            else {
                uns++;
            }
            if((zeros == uns) && ((zeros + uns) > soma)) {
                soma = zeros + uns;
                inicio = i;
                fim = j;
            }
        }
    }
   
    printf("sub-vetor encontrado do indice %d ao %d", inicio, fim);
    return 0;
}