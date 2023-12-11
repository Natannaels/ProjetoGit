#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

void contarCaracteresPalavrasLinhas(FILE *arquivo, int *caracteres, int *palavras, int *linhas) {
    char buffer[MAX_BUFFER_SIZE];
    int caractere;
    int noEspaco = 1; // Indica se o último caractere foi um espaço em branco

    while ((caractere = fgetc(arquivo)) != EOF) {
        (*caracteres)++;

        // Verifica se o caractere é um espaço em branco
        if (caractere == ' ' || caractere == '\t' || caractere == '\n') {
            noEspaco = 1;
        } else {
            // Se o caractere não for espaço em branco, e o último foi, incrementa a contagem de palavras
            if (noEspaco) {
                (*palavras)++;
                noEspaco = 0;
            }
        }

        // Verifica se o caractere é uma quebra de linha
        if (caractere == '\n') {
            (*linhas)++;
        }
    }
}

int main() {
    FILE *arquivo;
    char nomeArquivo[100];
    int caracteres = 0, palavras = 0, linhas = 0;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    contarCaracteresPalavrasLinhas(arquivo, &caracteres, &palavras, &linhas);

    printf("Caracteres: %d\n", caracteres);
    printf("Palavras: %d\n", palavras);
    printf("Linhas: %d\n", linhas);

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}
