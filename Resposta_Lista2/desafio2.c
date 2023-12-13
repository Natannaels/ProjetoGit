#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int cor;
    char nomeDono[50];
    float area;
}Casa;

int distancia(Casa* casas, int n);

int main() {
    int n;
    FILE* arquivo = fopen("casas.txt", "r");
    if(arquivo == NULL){
        printf("Erro ao abrir Arquivo");
        return -1;
    }
    fscanf(arquivo, "%d", &n);

    Casa* casas = (Casa*)malloc(sizeof(Casa) * n);
    if(casas == NULL){
        printf("Erro na alocacao");
        return -1;
    }
    for(int i = 0; i < n; i++) {
        fscanf(arquivo, "%d %s %f", &casas[i].cor, casas[i].nomeDono, &casas[i].area);
    }
    fclose(arquivo);
    int result = distancia(casas, n);
    printf("Maxima distancia: %d", result);
    free(casas);
    return 0;
}

int distancia(Casa* casas, int n) {
    int maxDist = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(casas[i].cor != casas[j].cor) {
                int dist = abs(i - j);
                if(dist > maxDist) {
                    maxDist = dist;
                }
            }
        }
    }
    return maxDist;
}