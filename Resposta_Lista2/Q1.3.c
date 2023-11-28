#include <stdio.h>
#include <string.h>

void invertOrdemPalavras(char str[]){
    int n = strlen(str), j = 0;

    for(int i = n - 1; i > j; i--) {
        char temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        j++;
    }
    
    int inicio = 0;
    for(int i = 0; i < n; i++) {
        
        if(str[i] == ' ' || str[i] == '\n' || str[i] == ','){
            int fim = i - 1;

            while(fim > inicio){
                char temp = str[inicio];
                str[inicio] = str[fim];
                str[fim] = temp;
                inicio++;
                fim--;    
            }
        }
        inicio = i + 1;     
    }

}

int main() {
    char str[100];

    printf("Digite: ");
    scanf(" %[^\n]s", str);

    invertOrdemPalavras(str);
    printf("%s", str);

    return 0;
}
