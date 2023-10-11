#include <stdio.h>
#include <stdlib.h>

int lucro (int precos[], int n) {
    int min = precos[0];
    int max = 0;
    int lucro = 0;

    for(int i = 1; i < n; i++) {
        if(min < precos[i] && precos[i] > max) {
            max = precos[i];
            lucro = max - min;
        }
        else if(precos[i] < min){
            min = precos[i];
            max = precos[i + 1];
            lucro = max - min;
        }

    }
    return lucro;
}


int main() {
    int precos[] = {7, 1, 5, 3, 6, 10};
    int n = sizeof(precos)/sizeof(precos[0]);

    printf("Lucro maximo: %d", lucro(precos, n));

    return 0;
}