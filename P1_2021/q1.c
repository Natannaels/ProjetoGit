#include <stdio.h>
#include <stdlib.h>

int funcao_rec(int n) {
    if(n == 1) {
        return 0;
    }
    if(n == 2) {
        return 1;
    }
    if(n == 3) {
        return 2;
    }

    return funcao_rec(n - 1) + funcao_rec(n - 2) + funcao_rec(n - 3);
}

int main() {
    int n = 7;
    printf("Saida: %d", funcao_rec(n));

    return 0;
}