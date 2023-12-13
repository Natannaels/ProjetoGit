#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encontrar(char str[], char palavra[]) {
    int tam_str = strlen(str);
    int tam_pala = strlen(palavra);

    for(int i = 0; i < tam_str; i++) {
        int cont = 0;
        for(int j = 0; j < tam_pala; j++) {
            if(str[i + j] == palavra[j]) {
                cont++;
            }
            else{
                break;
            }
        }
        if(cont == tam_pala) {
            return i;
        }
    }
    return -1;
}

int main() {
    char str[100];
    char x[20];
    printf("Digite uma string: ");
    scanf(" %[^\n]s", str);

    printf("Digite uma palavra a ser procurada: ");
    scanf(" %[^\n]s", x);

    int pos = encontrar(x, str);
    if(pos != -1){
        printf("A palavra está na posicao %d", pos);
    }
    else{
        printf("palavra nao encontrada");
    }
    return 0;
}
