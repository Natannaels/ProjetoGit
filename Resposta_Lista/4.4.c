#include <stdlib.h>
#include <stdio.h>

int main() {
    int n = 6;
    int precos[] = {7, 1, 5, 3, 6, 10};

    int preco_min = precos[0]; 
    int lucro_max = 0;
    int d_compra = 0;
    int d_venda = 0;
    int preco_venda = 0;

    for(int i = 1; i < n; i++ ) {
        if(precos[i] < preco_min) {
            preco_min = precos[i];
            d_compra = i+1;
        }
        else if((precos[i] - preco_min) > lucro_max){
            lucro_max = precos[i] - preco_min;
            d_venda = i+1;
            preco_venda = precos[i];
        }
    }

    printf("Compre no dia %d (preco = %d) e venda no dia %d (preco = %d), lucro = %d.\n", d_compra, preco_min, d_venda, preco_venda, lucro_max);
    

    return 0;
}