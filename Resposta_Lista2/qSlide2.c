#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ehPali(char str[]) {
    int n = strlen(str), j = 0;
    char aux[n + 1];
    for(int i = n - 1; i >= 0; i--) {
        aux[j] = str[i];
        j++;
    }
    aux[j] = '\0';

    if(strcmp(aux, str) == 0) {
        return 1;
    }
    else {
        return 0;
    }
    
}

int main() {

    char str[20];
    scanf(" %[^\n]s", str);

    printf("%d", ehPali(str));

    return 0;
}