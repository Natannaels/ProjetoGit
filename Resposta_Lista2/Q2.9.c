#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
}Produto;

void adicionarProd(Produto** carrinho, int *capacidade);

int main() {
    Produto* carrinho = NULL;
    int capacidade = 0;

    while(1) {
        adicionarProd(&carrinho, &capacidade);

        if(strlen(carrinho[capacidade - 1].nome) == 0){
            break;
        }
    }
    free(carrinho);
    return 0;
}


void adicionarProd(Produto** carrinho, int *capacidade){
    (*capacidade)++;

    *carrinho = (Produto*)realloc(*carrinho, sizeof(Produto) * (*capacidade));
    if(*carrinho == NULL){
        printf("Erro de Alocacao");
        return -1;
    }

    printf("Digite o nome do produto: ");
    scanf("%s", (*carrinho)[*capacidade - 1].nome);

    FILE* arquivo = fopen("carrinho.txt", "a");
    if(arquivo == NULL) {
        printf("Erro de arquivo");
        return -1;
    }

    fprintf(arquivo, "%s\n", (*carrinho)[*capacidade - 1].nome);

    fclose(arquivo);
}

