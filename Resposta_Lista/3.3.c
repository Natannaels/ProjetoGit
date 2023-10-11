#include <stdio.h>
#include <stdlib.h>

int findsum(int a[], int n) {
    // Caso base: quando n é 1, retorne o único elemento do array
    if (n == 1) {
        return a[0];
    } else {
        // Chamada recursiva para encontrar a soma dos elementos no subarray
        int sum = findsum(a, n - 1);
        
        // Adicione o elemento atual ao resultado da chamada recursiva
        sum += a[n - 1];
        
        return sum;
    }
}


int main() {
int a[] ={2, 1, 4};
int n =3;

printf("Min: %d", findsum(a, n));

    return 0;
}