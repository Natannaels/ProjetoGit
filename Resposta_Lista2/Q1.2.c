#include <stdio.h>
#include <string.h>

int ehpali(char str[]){
    int n = strlen(str), j = 0;
    char aux[n + 1];

    for(int i = n - 1; i >= 0; i--) {
        aux[j] = str[i];
        j++;
    }
    aux[j] = '\0';

    return strcmp(aux, str);
}

int main() {
    char str[20];

    printf("Digite uma string: ");
    scanf(" %[^\n]s", str);

    printf("%d\n", ehpali(str)); //se for palindromo retorna 0, senao retorna 1

    return 0;
}
