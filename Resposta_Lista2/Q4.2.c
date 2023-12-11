#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100
#define MAX_LINE_SIZE 1000

void removerPalavra(FILE *entrada, FILE *saida, const char *palavraRemover) {
    char linha[MAX_LINE_SIZE];
    size_t tamanhoPalavra = strlen(palavraRemover);

    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        char *ocorrencia = linha;
        while ((ocorrencia = strstr(ocorrencia, palavraRemover)) != NULL) {
            // Substitui a palavra encontrada por espaços em branco
            memset(ocorrencia, ' ', tamanhoPalavra);
            ocorrencia += tamanhoPalavra;
        }

        // Escreve a linha modificada no arquivo de saída
        fputs(linha, saida);
    }
}

int main() {
    char nomeArquivoEntrada[100], nomeArquivoSaida[100], palavraRemover[MAX_WORD_SIZE];

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nomeArquivoEntrada);

    printf("Digite o nome do arquivo de saída: ");
    scanf("%s", nomeArquivoSaida);

    printf("Digite a palavra a ser removida: ");
    scanf("%s", palavraRemover);

    FILE *arquivoEntrada = fopen(nomeArquivoEntrada, "r");
    FILE *arquivoSaida = fopen(nomeArquivoSaida, "w");

    // Verifica se os arquivos foram abertos com sucesso
    if (arquivoEntrada == NULL || arquivoSaida == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    // Remove a palavra do arquivo
    removerPalavra(arquivoEntrada, arquivoSaida, palavraRemover);

    printf("Palavra removida com sucesso.\n");

    // Fecha os arquivos
    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    return 0;
}
