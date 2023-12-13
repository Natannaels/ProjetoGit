#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    char nomeArquivo[100], novoTexto[100];
    int numeroLinha, linhaAtual = 0;

    // Solicita o nome do arquivo
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    // Solicita o número da linha a ser substituída
    printf("Digite o número da linha a ser substituída: ");
    scanf("%d", &numeroLinha);

    // Abre o arquivo para leitura e escrita
    arquivo = fopen(nomeArquivo, "r+");
    
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    // Loop para ler cada linha do arquivo
    while (!feof(arquivo)) {
        char linha[100];
        fgets(linha, sizeof(linha), arquivo);

        // Incrementa o número da linha atual
        linhaAtual++;

        // Se a linha atual for a linha a ser substituída, pede o novo texto
        if (linhaAtual == numeroLinha) {
            printf("Digite o novo texto para substituir a linha %d: ", numeroLinha);
            scanf("%s", novoTexto);

            // Move o cursor de volta para o início da linha
            fseek(arquivo, -strlen(linha), SEEK_CUR);

            // Substitui a linha no arquivo com o novo texto
            fprintf(arquivo, "%s\n", novoTexto);

            // Sai do loop, pois a substituição foi feita
            break;
        }
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("Substituição concluída com sucesso!\n");

    return 0;
}
