#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    char sexo;
    float teste1, teste2, pontuacaoTotal;
} Estudante;

void adicionarEstudante(Estudante* estudantes, int* quantidadeEstudantes, char* nomeArquivo);


int main() {
    int numEstudante;
    FILE* arquivo = fopen("entrada.txt", "r");
    if(arquivo == NULL) {
        printf("Erro ao abrir arquivo");
        return -1;
    }

    fscanf(arquivo, "%d", &numEstudante);

    Estudante* estudantes = (Estudante*)malloc(sizeof(Estudante) * numEstudante);
    if(estudantes == NULL) {
        printf("Erro ao alocar");
        return -1;
    }

    for(int i = 0; i < numEstudante; i++) {
        fscanf(arquivo, "%d %s %c %f %f", &estudantes[i].id, &estudantes[i].nome, &estudantes[i].sexo, &estudantes[i].teste1, &estudantes[i].teste2);
    }

    fclose(arquivo);

    adicionarEstudante(estudantes, &numEstudante, "registro.txt");

    free(estudantes);

    return 0;
}


void adicionarEstudante(Estudante* estudantes, int* quantidadeEstudantes, char* nomeArquivo) {

    FILE* arquivo = fopen(nomeArquivo, "w");
    if(arquivo == NULL) {
        printf("Erro ao abrir arquivo");
        return -1;
    }
    fprintf(arquivo, "REGISTRO: \n");

    for(int i = 0; i < *quantidadeEstudantes; i++) {
        fprintf(arquivo, "%d %s %c %f %f\n", estudantes[i].id, estudantes[i].nome, estudantes[i].sexo, estudantes[i].teste1, estudantes[i].teste2);
    }   
    printf("ALUNOS FORAM REGISTRADOS COM SUCESSO");

    fclose(arquivo);
}
