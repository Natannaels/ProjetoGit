#include <stdio.h>

int valorDoCaractere(char c) {
    switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int romanToInt(char *s) {
    int resultado = 0;
    int n = strlen(s);
    // Percorre a string da direita para a esquerda
    for(int i = n - 1; i >= 0; i--) {
        int valorAtual = valorDoCaractere(s[i]);

        // Verifica se precisamos subtrair
        if (i < n - 1 && valorAtual < valorDoCaractere(s[i + 1])) {
            resultado -= valorAtual;
        } else {
            resultado += valorAtual;
        }
    }

    return resultado;
}

int main() {
    char numeralRomano[] = "XL";

    int resultado = romanToInt(numeralRomano);

    printf("O numeral romano %s é equivalente a %d\n", numeralRomano, resultado);

    return 0;
}
