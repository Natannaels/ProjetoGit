#include <stdlib.h>
#include <stdio.h>
#define LONG_INT  unsigned long long int

LONG_INT calcularFatorial( LONG_INT numero);

int main() {
    int numero =  10;

    printf("Fatorial de %d: %d", numero, calcularFatorial(numero));


    return 0;
}

LONG_INT calcularFatorial( LONG_INT numero) {
    if(numero == 1 || numero == 0) {
        return 1;
    }
    return numero * calcularFatorial(numero - 1);
}