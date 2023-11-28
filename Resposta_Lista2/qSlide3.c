#include <stdio.h>
#include <string.h>

void crip(char str[], int k) {
    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        str[i] = (((str[i]-'A') + k)%26) + 'A';
    }
}

void decrip(char str[], int k) {
    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        str[i] = (((str[i]+'A') - k)%26) + 'A';
    }
}

int main() {
    char str[20];
    int k;

    printf("Digite um valor para k: ");
    scanf("%d", &k);

    printf("Digite uma string: ");
    scanf(" %[^\n]s", str);

    crip(str, k);
    printf("Texto criptografado: %s\n", str);

    decrip(str, k);
    printf("Texto descriptografado: %s\n", str);

    return 0;
}
