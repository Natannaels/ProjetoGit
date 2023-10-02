#include <stdio.h>
#include <limits.h>

int main() {
    int m, n;

    printf("digite o tamanho da matriz: \n");
    scanf("%d %d", &m, &n);

    int mat[m] [n];
    printf("digite os elementos: \n");

    for(int i = 0; i < m; i++ ) {
        for(int  j = 0; j < n; j++) {
            printf("mat[%d] [%d]: ", i, j);
            scanf("%d", &mat[i] [j]);
        }
    }

    int menor = INT_MAX, segundo_menor = INT_MAX;
    for(int i = 0; i < m; i++ ) {
        for(int  j = 0; j < n; j++) {
            if(mat[i] [j] <= menor) {
                menor = mat[i] [j];
            }
            else if(mat[i] [j] <= segundo_menor) {
                segundo_menor = mat[i] [j];
            }
        }
    }
    if(segundo_menor == INT_MAX) {
        segundo_menor = menor;
    }

    printf("O segundo menor elemento eh: %d", segundo_menor);


    return 0;
}