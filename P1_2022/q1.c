#include <stdio.h>
#include <stdlib.h>

int soma(int n) {
    if(n == 0) {
        return 0;
    }
    return (n % 10) + soma(n / 10);
}

int main() {
    int n = 809;
    printf("Soma: %d", soma(n));
    return 0;
}