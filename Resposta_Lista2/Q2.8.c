#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetNum = NULL;
    int tam = 0;

    while(1) {
        int num;
        printf("Digite u numero: ");
        scanf("%d", &num);

        if(num == 0) {
            printf("FIM");
            break;
        }

        tam += 1;

        vetNum = realloc(vetNum, sizeof(int) * tam);
        if(vetNum == NULL) {
            return -1;
        }

        vetNum[tam - 1] = num; 
    }
    printf("Numeros:");
    for(int i = 0; i < tam; i++) {
        printf("%d ", vetNum[i]);
    }
    
    return 0;
}
