#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAX 1000  // Tamanho arbitrário para a linha

int main() {
    FILE *arquivoEntrada, *arquivoSaida;
    char linha[TAMANHO_MAX];
    char palavraParaLocalizar[TAMANHO_MAX];
    char novaPalavra[TAMANHO_MAX];

    // Abre o arquivo de entrada para leitura
    arquivoEntrada = fopen("entrada.txt", "r");

    // Verifica se o arquivo de entrada foi aberto corretamente
    if (arquivoEntrada == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    // Abre o arquivo de saída para escrita
    arquivoSaida = fopen("saida.txt", "w");

    // Verifica se o arquivo de saída foi aberto corretamente
    if (arquivoSaida == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        fclose(arquivoEntrada);
        return 1;
    }

    // Solicita a palavra a ser localizada e substituída
    printf("Digite a palavra a ser localizada: ");
    scanf("%s", palavraParaLocalizar);

    // Solicita a nova palavra
    printf("Digite a nova palavra: ");
    scanf("%s", novaPalavra);

    // Lê cada linha do arquivo de entrada
    while (fgets(linha, sizeof(linha), arquivoEntrada) != NULL) {
        // Localiza a palavra e substitui, se necessário
        char *posicao = strstr(linha, palavraParaLocalizar);
        while (posicao != NULL) {
            // Substitui a palavra
            strncpy(posicao, novaPalavra, strlen(novaPalavra));
            posicao = strstr(posicao + strlen(novaPalavra), palavraParaLocalizar);
        }

        // Grava a linha no arquivo de saída
        fputs(linha, arquivoSaida);
    }

    // Fecha os arquivos
    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    printf("Substituicao concluida com sucesso.\n");

    return 0;
}