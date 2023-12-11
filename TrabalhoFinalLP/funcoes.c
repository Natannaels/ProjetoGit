#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Comparacao entre as combinacoes encontradas
int maximo_valor(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

//Funcao para salvar resultados
void salvar_resultados(const char *nome_arquivo, Item *selecao, int numItens, int valorTotal, double tempo_executado){
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar resultados.\n");
        return;
    }
    fprintf(arquivo, "Itens selecionados:\n\n");
    for (int i = 0; i < numItens; i++) {
      if (selecao[i].valor != 0 ) {
        fprintf(arquivo, "Item %d - Valor: %d - Peso: %d\n", i + 1, selecao[i].valor, selecao[i].peso);
      }
    }

    fprintf(arquivo, "\nValor agregado: %d\n", valorTotal);
    fprintf(arquivo, "\nO programa demorou %f segundos para achar a melhor combinação.\n", tempo_executado);

    fclose(arquivo);
}


// Resolvendo o problema
int selecionar_item(Item *itens, int numItens, int capacidade) {
  
  // Se o numero de itens for 0 ou a capacidade residual da mala for 0
  if (numItens == 0 || capacidade == 0) {
    return 0;
  }

  // Verificando se o peso do item atual é menor ou igual à capacidade residual
  if (itens[numItens - 1].peso <= capacidade) {
    // Calculando o valor máximo ao incluir ou excluir o item atual
    int item_incluido = itens[numItens - 1].valor +
                         selecionar_item(itens, numItens - 1,
                                         capacidade - itens[numItens - 1].peso);
    int item_excluido = selecionar_item(itens, numItens - 1, capacidade);

    // Retornando o máximo entre incluir e excluir o item atual
    return maximo_valor(item_incluido, item_excluido);
  } else {
    return selecionar_item(itens, numItens - 1, capacidade);
  }
}