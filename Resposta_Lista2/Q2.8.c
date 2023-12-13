#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numero;
}Num;

void adicionarNum(int** vetNum, int* n, int num);

int main() {
    int *vetNum = NULL;
    int n = 0;
    int num;
    while (1)
    {   printf("Digite um numero: ");
        scanf("%d", &num);
        adicionarNum(&vetNum, &n, num);

        if(vetNum[n - 1] == 0) {
            break;
        }
    }

    for(int i = 0; i < n ; i++) {
        printf("%d\n", vetNum[i]);
    }
    printf("Salvos co sucesso");

    return 0;
}

void adicionarNum(int** vetNum, int* n, int num){
    (*n)++;
    FILE* arquivo = fopen("numsave.txt", "a");
    if(arquivo == NULL){
        printf("Erro no arquivo");
    }
    *vetNum = (int*)realloc(*vetNum, sizeof(int) * (*n));
    if(*vetNum == NULL) {
        printf("Erro de alocacao");
    }

    (*vetNum)[(*n) - 1] = num;
    fprintf(arquivo, "%d\n", (*vetNum)[(*n) - 1] );
    
    fclose(arquivo);
}