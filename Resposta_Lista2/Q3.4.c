#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cor;
    char nomeDoDono[50];
    float area;
}Casa;

int maiorDistancia(Casa *casas, int n);


int main() {
    int n;
    FILE* arquivo = fopen("entrada.txt", "r");
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo");
        return -1;
    }

    fscanf(arquivo,"%d", &n);

    Casa* casas = (Casa*)malloc(sizeof(Casa) * n);
    if(casas == NULL){
        printf("Erro ao alocar");
        return -1;
    }

    for(int i = 0; i < n; i++){
        fscanf(arquivo, "%d %s %f", &casas[i].cor, &casas[i].nomeDoDono, &casas[i].area);
    }

    fclose(arquivo);

    int resultado = maiorDistancia(casas, n);

    printf("A maior distancia eh: %d", resultado);

    free(casas);

    return 0;
}

int valorAbsoluto(int x) {
    if(x < 0)
        return x*-1;
    else
        return x;
}

int maiorDistancia(Casa *casas, int n) {
    int disMax = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(casas[j].cor != casas[i].cor) {
                int distancia = valorAbsoluto(i - j);
                if(distancia > disMax) {
                    disMax = distancia;
                }
            }
        }
    }

    return disMax;
}