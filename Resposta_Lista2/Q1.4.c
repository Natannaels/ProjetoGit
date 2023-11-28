#include <stdio.h>
#include <string.h>

int encontrar(char x[], char str[]){
    int tamStr = strlen(str);
    int tamPalavra = strlen(x);
    
    for(int i = 0; i < tamStr; i++) {
        int cont = 0;
        for(int j = 0; j < tamPalavra; j++) {
            if(str[i + j] == x[j]) {
                cont++;
            }
            else {
                break;
            }
        }
        if(cont == tamPalavra) {
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

    printf("Digite uma string a ser procurada: ");
    scanf(" %[^\n]s", x);

    int pos = encontrar(x, str);
    if(pos != -1){
        printf("A string está na posicao %d", pos);
    }
    else{
        printf("string nao encontrada");
    }
    return 0;
}
