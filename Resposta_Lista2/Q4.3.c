#include <stdio.h>

int main() {
    FILE *arquivoEntrada, *arquivoSaida;
    char linha[1000];  // Tamanho arbitrário para a linha

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

    // Lê cada linha do arquivo de entrada
    while (fgets(linha, sizeof(linha), arquivoEntrada) != NULL) {
        // Verifica se a linha não está vazia
        if (linha[0] != '\n' && linha[0] != '\0') {
            // Grava a linha no arquivo de saída
            fputs(linha, arquivoSaida);
        }
    }

    // Fecha os arquivos
    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    printf("Linhas vazias removidas com sucesso.\n");

    return 0;
}
