#include <stdio.h>

int main() {
    FILE *file1, *file2, *mergedFile;
    char filename1[100], filename2[100], mergedFilename[100];
    char buffer[256];

    // Solicitar os nomes dos arquivos a serem mesclados
    printf("Insira o nome do primeiro arquivo: ");
    scanf("%s", filename1);

    printf("Insira o nome do segundo arquivo: ");
    scanf("%s", filename2);

    // Abrir os arquivos para leitura
    file1 = fopen(filename1, "r");
    file2 = fopen(filename2, "r");

    if (file1 == NULL || file2 == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1; // Encerrar o programa com código de erro
    }

    // Solicitar o nome do arquivo mesclado
    printf("Insira o nome do arquivo mesclado: ");
    scanf("%s", mergedFilename);

    // Abrir o arquivo mesclado para escrita
    mergedFile = fopen(mergedFilename, "w");

    if (mergedFile == NULL) {
        printf("Erro ao criar o arquivo mesclado.\n");
        fclose(file1);
        fclose(file2);
        return 1; // Encerrar o programa com código de erro
    }

    // Mesclar os arquivos
    while (fgets(buffer, sizeof(buffer), file1) != NULL) {
        fputs(buffer, mergedFile);
    }

    while (fgets(buffer, sizeof(buffer), file2) != NULL) {
        fputs(buffer, mergedFile);
    }

    // Fechar todos os arquivos
    fclose(file1);
    fclose(file2);
    fclose(mergedFile);

    printf("Arquivos mesclados com sucesso em %s.\n", mergedFilename);

    return 0; // Encerrar o programa com sucesso
}
