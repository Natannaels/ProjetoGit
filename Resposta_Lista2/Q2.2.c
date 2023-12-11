#include <stdlib.h>
#include <stdio.h>


typedef struct{
    int desejo;
}Crianca;

typedef struct{
    int tamanho;
}Biscoito;

int findContentChildren(Crianca* criancas, int numCriancas, Biscoito* biscoitos, int numBiscoitos);


int main() {
    int numBiscoitos, numCriancas;

    FILE* arquivo = fopen("entrada.txt", "r"); 
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo");
        return -1;
    }    
    fscanf(arquivo, "%d %d", &numCriancas, &numBiscoitos);

    Crianca* criancas = (Crianca*)malloc(sizeof(Crianca) * numCriancas);
    Biscoito* biscoitos = (Biscoito*)malloc(sizeof(Biscoito) * numBiscoitos);
    if(criancas == NULL || biscoitos == NULL) {
         printf("Erro de alocacao");
        return -1;
    }

    for(int i = 0; i < numCriancas; i++) {
        fscanf(arquivo, "%d", &criancas[i].desejo);
    }
    for(int i = 0; i < numBiscoitos; i++) {
        fscanf(arquivo, "%d", &biscoitos[i].tamanho);
    }
    fclose(arquivo);

    int resultado = findContentChildren(criancas, numCriancas, biscoitos, numBiscoitos);

    printf("Criancas contentes: %d\n", resultado);

    free(criancas);
    free(biscoitos);
    
    return 0;
}


int findContentChildren(Crianca* criancas, int numCriancas, Biscoito* biscoitos, int numBiscoitos) {
     int g[numCriancas];
     int s[numBiscoitos];

     for(int i = 0; i < numCriancas; i++){
        g[i] = criancas[i].desejo;
     }
     for(int i = 0; i < numBiscoitos; i++){
        s[i] = biscoitos[i].tamanho;
     }

     for(int x = 0; x < numCriancas - 1; x++) {
        for(int y = 0; y < numCriancas - 1; y++) {
            if(g[y] > g[y + 1]) {
                int temp = g[y];
                g[y] = g[y + 1];
                g[y + 1] = temp;
            }
        }
     }

     for(int x = 0; x < numBiscoitos - 1; x++) {
        for(int y = 0; y < numBiscoitos - 1; y++) {
            if(s[y] > s[y + 1]) {
                int temp = s[y];
                s[y] = s[y + 1];
                s[y + 1] = temp;
            }
        }
     }

    int i = 0, j = 0, cont = 0;

    while(i < numCriancas && j < numBiscoitos) {
        if(s[j] >= g[i]){
            cont++;
            i++;
        }
        j++;
    }
    return cont;
     
}
