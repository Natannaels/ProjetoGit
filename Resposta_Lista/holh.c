#include <stdio.h>
#include <stdlib.h>
#define quebra printf("\n");

int findsum(int a[], int n){
    int soma = 0;
    if(n == 0){
        return 0;
    }
    if(n == 1) {
        return a[0];
    }
    soma = a[n - 1] + findsum(a, n - 1);
    return soma; 
}

int main() {
    int n = 4;
    int precos[] = {1, 2, 4, 2};
    
    

    printf("soma: %d", findsum(precos, n));
    quebra;

    
    return 0;
}