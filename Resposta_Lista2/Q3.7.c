#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char modelo[100];
    int ano;
} Carro;


void cadastrarCarro(Carro **catalogo, int *tamanho);

int main() {
    Carro* catalogo = NULL;
    int tamanho = 0;

    while(1) {
        cadastrarCarro(&catalogo, &tamanho);

        if(catalogo[tamanho - 1].ano < 0) {
            break;
        }
    }

    free(catalogo);

    return 0;
}
void cadastrarCarro(Carro **catalogo, int *tamanho) {
    (*tamanho)++;

    *catalogo = (Carro*)realloc(*catalogo, sizeof(Carro) * (*tamanho));
    if(*catalogo == NULL) {
        printf("Erro de alocacao");
        return -1;
    }

    printf("Digite o modelo:");
    scanf("%s", (*catalogo)[*tamanho - 1].modelo);
    printf("Digite o ano:");
    scanf("%d", &(*catalogo)[*tamanho - 1].ano);

    FILE* arquivo = fopen("catalogo.txt","a");
    if(arquivo == NULL){
        printf("Erro no arquivo");
        return -1;
    }

    fprintf(arquivo, "%s %d\n", (*catalogo)[*tamanho - 1].modelo, (*catalogo)[*tamanho - 1].ano);

    fclose(arquivo);

}