#include <stdio.h>
#include <stdlib.h>

int ispalindrome(int a[], int n) {
    // Caso base: se o tamanho for 0 ou 1, o array é um palíndromo
    if (n <= 1) {
        return 1;
    }

    // Compare o primeiro e o último caracteres
    if (a[0] != a[n - 1]) {
        return 0; // Se não coincidirem, não é um palíndromo
    }

    // Chame a função recursivamente para o subarray sem o primeiro e último caracteres
    return ispalindrome(a + 1, n - 2);
}


int main() {
int a[] = {1,2,1};
int n = 3;

printf("eh palidromo?: %d", ispalindrome(a, n));

    return 0;
}