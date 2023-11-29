#include <stdio.h>
#include <string.h>

int contarOcorrencias(char str[], char x[]) {
    int tamStr = strlen(str);
    int tamPalavra = strlen(x);
    int count = 0;

    for (int i = 0; i <= tamStr ; i++) {
        int cont = 0;

        for (int j = 0; j < tamPalavra; j++) {
            if (str[i + j] == x[j]) {
                cont++;
            } else {
                break;
            }
        }

        if (cont == tamPalavra) {
            // Encontramos uma ocorrência completa da palavra
            count++;
        }
    }

    return count;
}

int main() {
    char texto[] = "O exemplo é uma forma de explicar exemplos. Um bom exemplo é valioso.";

    char palavra[] = "exemplo";

    int resultado = contarOcorrencias(texto, palavra);

    printf("A palavra '%s' ocorre %d vezes na string.\n", palavra, resultado);

    return 0;
}
