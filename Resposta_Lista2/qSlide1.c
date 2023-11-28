#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int totalPalavras(char str[]){
    int cont = 0, i = 0;
    int flag = 0;
    while(str[i] != '\0'){
        if(str[i] == ' ' || str[i] == ',' || str[i] == '\t'){
            flag = 0;
        }
        else if(flag == 0){
            flag = 1;
            cont++;
        }
        i++;
    }
    return cont;
}

int main() {

    char str[20];
    scanf(" %[^\n]s", str);

    printf("%d", totalPalavras(str));

    return 0;
}