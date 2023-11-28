#include <stdio.h>
#include <string.h>

void removeEspaco(char str[]) {
    int tam = strlen(str);
    int flag = 0;
    int j = 0;
    for(int i = 0; i < tam; i ++) {
        if(str[i] != ' '){
            str[j] = str[i];
            j++;
            flag = 0;
        }
        else{
            if(flag == 0){
                str[j] = ' ';
                j++;
                flag = 1;
            }
        }
       
    }
    str[j] = '\0';

}

int main() {
    char str[100];
    printf("Digite uma string: ");
    scanf(" %[^\n]s", str);

    removeEspaco(str);

    printf("String sem espacos extra: %s", str);
   
    return 0;
}
