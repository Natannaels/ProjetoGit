#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contar_ocorrencia(char palavra[], char str[]) {
    int tam_palavra = strlen(palavra);
    int tam_str = strlen(str);
    int cont = 0;

    for(int i = 0; i < tam_str; i++) {
        int verificador = 0;
        for(int j = 0; j < tam_palavra; j++) {
            if(str[i + j] == palavra[j]) {
                verificador++;
            }
            else {
                break;
            }
        }
        if(verificador == tam_palavra) {
            cont++;
        }
    }

    return cont;

}

int main() {
    char str[] = "Amor sabor pavor dor rancor dor dor Amor";
    char palavra[] = "Amor";

    int ocorrencias = contar_ocorrencia(palavra, str);

    printf("%d", ocorrencias);

    return 0;
}
