#include <stdio.h>
#include <string.h>

void convertM(char str[]){
    int n = strlen(str);
    for(int i = 0; i < n; i++) {
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - ('a' - 'A');
        }
    }
}

int main() {
    char str[20];

    printf("Digite uma string: ");
    scanf(" %[^\n]s", str);

    convertM(str);
    printf("Texto Maiusculo: %s\n", str);

    return 0;
}
