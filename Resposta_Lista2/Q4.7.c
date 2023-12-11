#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100

void criptografarSenha(char *senha, int chave) {
    int i;
    for (i = 0; senha[i] != '\0'; ++i) {
        if (senha[i] >= 'A' && senha[i] <= 'Z') {
            senha[i] = ((senha[i] - 'A' + chave) % 26) + 'A';
        } else if (senha[i] >= 'a' && senha[i] <= 'z') {
            senha[i] = ((senha[i] - 'a' + chave) % 26) + 'a';
        }
    }
}

void descriptografarSenha(char *senha, int chave) {
    criptografarSenha(senha, 26 - chave);
}

int main() {
    FILE *arquivo;
    char senha[MAX_PASSWORD_LENGTH];
    int chave;

    // a) Criptografar senhas do arquivo senhas.txt
    arquivo = fopen("senhas.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo senhas.txt.\n");
        return 1;
    }

    printf("Digite a chave para criptografar: ");
    scanf("%d", &chave);

    while (fscanf(arquivo, "%s", senha) != EOF) {
        criptografarSenha(senha, chave);
        printf("Senha criptografada: %s\n", senha);
    }

    fclose(arquivo);

    // b) Descriptografar senhas do banco de dados bd.txt
    arquivo = fopen("bd.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo bd.txt.\n");
        return 1;
    }

    printf("\nDigite a chave para descriptografar: ");
    scanf("%d", &chave);

    while (fscanf(arquivo, "%s", senha) != EOF) {
        descriptografarSenha(senha, chave);
        printf("Senha descriptografada: %s\n", senha);
    }

    fclose(arquivo);

    return 0;
}
