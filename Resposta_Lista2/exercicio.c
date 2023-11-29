#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    char nome[100];
    int telefone;
}Pessoa;

void addPessoa(Pessoa *agenda, Pessoa pessoa, int indice){
    agenda[indice] = pessoa;
}

int main() {
    int n = 3;
    Pessoa *agenda;

    agenda = (Pessoa *)(malloc(sizeof(Pessoa)*n));

    if(agenda == NULL){
        return -1;
    }
    
    Pessoa p1 = {"Filiphe", 914405};
    Pessoa p2 = {"Lucas", 980723};
    Pessoa p3 = {"Joao", 334405};
    addPessoa(agenda, p1, 0);
    addPessoa(agenda, p2, 1);
    addPessoa(agenda, p3, 2);

    for(int i = 0; i < n; i++){
        printf("Contato %d: %s - %d \n", i, agenda[i].nome, agenda[i].telefone);
    }

    char procura[100];
    printf("Procura: ");
    scanf(" %[^\n]s", procura);
    int i = 0;
    for(i = 0; i < n; i++){
        
        if(strcmp(agenda[i].nome, procura) == 0){
            printf("Contato encontrado: %s - %d", agenda[i].nome, agenda[i].telefone);
            break;
        }
    }
    if(i >= n){
        printf("Numero nao encontrado.");
    }


    return 0;
}
