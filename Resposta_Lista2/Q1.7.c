#include <stdio.h>
#include <string.h>

char *defangIPaddr(char *address) {
    int length = strlen(address);
    
    // Conta quantos caracteres '[' e ']' são necessários para substituir os pontos '.'
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (address[i] == '.') {
            count += 2;  // Cada ponto será substituído por "[.]"
        }
    }

    // Calcula o tamanho da nova string
    int newLength = length + count;
    
    // Cria uma nova string com o tamanho adequado
    char defangedIP[newLength + 1];  // +1 para o caractere nulo '\0'

    int j = 0;
    for (int i = 0; i < length; i++) {
        if (address[i] == '.') {
            defangedIP[j++] = '[';
            defangedIP[j++] = '.';
            defangedIP[j++] = ']';
        } else {
            defangedIP[j++] = address[i];
        }
    }

    defangedIP[j] = '\0';  // Adiciona o caractere nulo no final

    // Retorna o ponteiro para a nova string
    return strdup(defangedIP);  // Usa strdup para alocar dinamicamente uma cópia da string
}

int main() {
    // Exemplos de uso
    char endereco1[] = "1.1.1.1";
    char endereco2[] = "255.100.50.0";

    char *defanged1 = defangIPaddr(endereco1);
    char *defanged2 = defangIPaddr(endereco2);

    printf("Exemplo 1:\nEntrada: %s\nSaída: %s\n\n", endereco1, defanged1);
    printf("Exemplo 2:\nEntrada: %s\nSaída: %s\n", endereco2, defanged2);

    // Libera a memória alocada
    free(defanged1);
    free(defanged2);

    return 0;
}
