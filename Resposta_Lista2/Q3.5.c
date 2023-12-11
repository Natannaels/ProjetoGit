#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    char endereco[200];
    char telefone[20];
} Pessoa;

void addPessoa(Pessoa *agenda, int *contador, int n);
char* buscarPessoaNoArquivo(const char *nome);

int main() {
    int n = 2, contador = 0;
    Pessoa *agenda = (Pessoa *)malloc(sizeof(Pessoa) * n);

    if (agenda == NULL) {
        printf("Erro na alocacao");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nome: ");
        scanf(" %[^\n]s", agenda[i].nome);
        printf("Endereço: ");
        scanf(" %[^\n]s", agenda[i].endereco);
        printf("Telefone: ");
        scanf(" %[^\n]s", agenda[i].telefone);
    }

    addPessoa(agenda, &contador, n);

    // Exemplo de utilização da função buscarPessoaNoArquivo
    char nomeBusca[100];
    printf("Digite o nome para buscar na agenda: ");
    scanf(" %[^\n]s", nomeBusca);

    char* telefoneEncontrado = buscarPessoaNoArquivo(nomeBusca);

    if (telefoneEncontrado != NULL) {
        printf("O telefone de %s e: %s\n", nomeBusca, telefoneEncontrado);
    } else {
        printf("Pessoa nao encontrada na agenda.\n");
    }

    free(agenda);
    return 0;
}

void addPessoa(Pessoa *agenda, int *contador, int n) {
    FILE *arquivo = fopen("agenda.txt", "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(arquivo, "%s %s %s\n", agenda[i].nome, agenda[i].endereco, agenda[i].telefone);
    }

    printf("Contatos adicionados\n");
    fclose(arquivo);
}

char* buscarPessoaNoArquivo(const char *nome) {
    FILE *arquivo = fopen("agenda.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo");
        return NULL;
    }

    char linha[400]; // Assumindo que uma linha terá no máximo 400 caracteres
    char *telefone = NULL;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char nomeArquivo[100];
        sscanf(linha, "%s", nomeArquivo);

        if (strcmp(nomeArquivo, nome) == 0) {
            // Encontrou a pessoa, então aloca espaço para o telefone
            telefone = malloc(sizeof(char) * 20);
            sscanf(linha, "%*s %*s %s", telefone); // Ignora os campos de nome e endereço
            break; // Não precisa continuar procurando
        }
    }

    fclose(arquivo);
    return telefone;
}
