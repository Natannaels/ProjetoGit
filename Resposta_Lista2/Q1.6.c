#include <stdio.h>
#include <string.h>

void removeRepetidos(char str[]) {
    int tam = strlen(str);

    int i, j;

    for(i = 0; i < tam; i++){
        for(j = i + 1; j < tam;){
            if(str[i] == str[j]){
                for(int k = j; k < tam; k++){
                    str[k] = str[k + 1];
                }
                tam--;
            }
            else{
                j++;
            }
        }
    }
    
}

int main() {
    char str[100];
    printf("Digite uma string: ");
    scanf(" %[^\n]s", str);

    removeRepetidos(str);

    printf("String sem repeticoes: %s", str);
   
    return 0;
}
