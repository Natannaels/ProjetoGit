#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char titulo[100];
    char autor[50];
    int ano;
}Livro;

void salvarLivros(Livro * livros, int n, char * nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "w");
    if(arq == NULL){
        return ;
    }
    for(int i = 0; i < n; i++){
        fprintf(arq,"%s;%s;%d\n", livros[i].titulo, livros[i].autor, livros[i].ano);
    }
    fclose(arq);
}

int main() {
    int n = 3;
    Livro *livros;

    livros = (Livro*)(malloc(sizeof(Livro)*n));
    if(livros ==  NULL){
        return -1;
    }

    Livro l1 = {"Narnia", "Lewis",1980};
    livros[0] = l1;

    Livro l2 = {"Sonic", "Nicolas",1999};
    livros[1] = l2;

    Livro l3 = {"D.Banana", "Pedro Alves",1999};
    livros[2] = l3;

    salvarLivros(livros, n, "FileF.txt");

    free(livros);
    return 0;
}