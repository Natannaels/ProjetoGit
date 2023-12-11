#ifndef MOCHILA_LIB_H
#define MOCHILA_LIB_H
#define VERIFICAR_ALOCACAO(ptr) \
    do { \
        if ((ptr) == NULL) { \
            printf("Erro na alocação de memória\n"); \
            return -1; \
        } \
    } while (0)



// Struct para os itens
typedef struct {
  int valor;
  int peso;
}Item;


// Comparacao entre as combinacoes encontradas
int maximo_valor(int a, int b);

//Funcao para salvar resultados
void salvar_resultados(const char *nome_arquivo, Item *selecao, int numItens, int valorTotal, double tempo_executado);
// Resolvendo o problema
int selecionar_item(Item *itens, int numItens, int capacidade);

#endif