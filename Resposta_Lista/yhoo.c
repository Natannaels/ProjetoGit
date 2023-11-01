#include <stdio.h>
#include <stdlib.h>
#define quebra printf("\n");

int maxProfit(int precos[], int bonus[], int n){
    int min = precos[0];
    int max = precos[1];
    static int compra = 0;
    static int venda = 1; int lucro = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n - 1; j++){
            if(lucro < (precos[j] - precos[i])+ bonus[j]){
                min = precos[i];
                max = precos[j];
                compra = 1;
                venda = j;
                lucro = (max - min) + bonus[j];
            }
        }
    }

    printf("Dia de compra: %d", compra);
    quebra;
    printf("Dia de venda: %d", venda);
    quebra;
    printf("O lucro maximo eh: %d", lucro); 
}

int main() {
    int n = 6;
    int precos[] = {7, 1, 5, 3, 6, 10};
    int bonus[]  = {0, 0, 1, 0, 2, 0};
    

    maxProfit(precos, bonus, n);
    quebra;

    
    return 0;
}