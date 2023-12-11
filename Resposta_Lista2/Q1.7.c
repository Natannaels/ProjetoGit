#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* defangIPaddr(char * address) { 
    int n = strlen(address);
    char* desativado = (char*) malloc((n + 6) * sizeof(char));

    if(desativado == NULL) {
        return -1;
    }

    int j = 0;
    for(int i = 0; i < n; i++) {
        if(address[i] == '.') {
            desativado[j++] = '[';
            desativado[j++] = '.';
            desativado[j++] = ']';
        }
        else {
            desativado[j++] = address[i];
        }
    }
    desativado[j] = '\0';
    return desativado;
}


int main() {
    char ip[] ="1.2.3.4";

    char* desativado = defangIPaddr(ip);

    printf("%s", desativado);

    free(desativado);

    return 0;
}
