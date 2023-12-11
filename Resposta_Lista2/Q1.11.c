#include <stdio.h>

int myAtoi(char* s) {
    int result = 0;
    int sign = 1;  // Assume que o número é positivo por padrão

    // Passo 1: Ignorar espaços em branco iniciais
    int i = 0;
    while (s[i] == ' ') {
        i++;
    }

    // Passo 2: Verificar sinal
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    // Passo 3: Ler os dígitos e converter para inteiro
    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';
        result = result * 10 + digit;
        i++;
    }

    // Aplicar o sinal
    return sign * result;
}

int main() {
    char s[] = "4193 -com palavras";
    int result = myAtoi(s);
    printf("Saída: %d\n", result);

    return 0;
}
