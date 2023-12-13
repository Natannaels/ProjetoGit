#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char titulo[100];
    char autor[50];
    int ano;
}Livro;
void salvarLivros(Livro* livros, int n, char* nomeArquivo);

int main() {
    int n = 3;
    Livro* livros = (Livro*)malloc(sizeof(Livro) * n);
    if(livros == NULL){
        printf("Erro de alocacao");
        return -1;
    }
    for(int i = 0; i < n; i++){
        printf("Nome do livro: ");
        scanf(" %[^\n]s", livros[i].titulo);
        printf("Autor: ");
        scanf(" %[^\n]s", livros[i].autor);
        printf("Ano: ");
        scanf("%d", &livros[i].ano);
    }
    salvarLivros(livros, n, "save.txt");
    free(livros);
    return 0;
}

void salvarLivros(Livro* livros, int n, char* nomeArquivo) {
    FILE* arquivo = fopen("nomeArquivo", "w");
    if(arquivo == NULL) {
        printf("Erro no Arquivo");
    }
    for(int i = 0; i < n; i++){
        fprintf(arquivo, "%s;%s;%d\n", livros[i].titulo, livros[i].autor, livros[i].ano);
    }
    fclose(arquivo);
    printf("Livos salvos!");
}