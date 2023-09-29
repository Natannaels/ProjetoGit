#include <stdio.h>
#include <time.h>

int main() {

    int A[5] [5];
    srand(time(NULL));

    for(int i = 0; i < 5; i++ ) {
        for(int j = 0; j < 5; j++) {
            A[i] [j] = rand() %10;
        }
    }

    for(int i = 0; i < 5; i++ ) {
        for(int j = 0; j < 5; j++) {
            printf("%d ", A[i] [j]);
           
        }
        printf("\n");
    }
    
    int produto = 1;
    for(int i = 0; i < 5; i++ ) {
        for(int j = 0; j < 5; j++) {
            if(i == j) {
                produto = produto * A[i] [j];
            }
           
        }
        printf("\n");
    }

    printf("O produto da diagonal principal: %d", produto);

    return 0;
}