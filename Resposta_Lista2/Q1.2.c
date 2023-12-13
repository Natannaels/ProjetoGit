#include <stdio.h>
#include <string.h>

int comparar( char *str1, char *str2) {
    

    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            // Se os caracteres são diferentes, retorna a diferença
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }

    // Retorna 0 se as strings forem iguais até o final
    return 0;
}

int ehpali(char str[]){
    int n = strlen(str), j = 0;
    char aux[n + 1];

    for(int i = n - 1; i >= 0; i--) {
        aux[j] = str[i];
        j++;
    }
    aux[j] = '\0';

    return comparar(aux, str);
}

int main() {
    char str[20];

    printf("Digite uma string: ");
    scanf(" %[^\n]s", str);

    printf("%d\n", ehpali(str)); //se for palindromo retorna 0, senao retorna 1

    return 0;
}
