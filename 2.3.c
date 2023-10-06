#include <stdlib.h>
#include <stdio.h>

int main() {
    int n = 4;
    int cont = 1;

    for(int i = 1; i <= n; i++) { 
        for(int k = 0; k < n - i; k++) printf(" ");      
        for(int j = 1; j <= i; j++) {
            printf("%d  ", cont++);
        }
        printf("\n");
    }

    return 0;
}

