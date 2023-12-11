#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main()
{
    clock_t inicio, fim;
    inicio = clock();

    FILE *arquivo;
    int capacidade, numItens;

    // Abrindo e Lendo "entrada.txt"
    arquivo = fopen("entrada.txt", "r");
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return -1;
    }

    fscanf(arquivo, "%d %d", &numItens, &capacidade);

    Item *itens = (Item*)(malloc(sizeof(Item) * numItens));
    Item *selecao = (Item*)(malloc(sizeof(Item) * numItens));;

    VERIFICAR_ALOCACAO(itens);
    VERIFICAR_ALOCACAO(selecao);

    for (int i = 0; i < numItens; i++) {
        fscanf(arquivo, "%d %d", &itens[i].valor, &itens[i].peso);
    }

    fclose(arquivo);

    int valorMaximo = selecionar_item(itens, numItens, capacidade);

    // Verifica se algum item foi selecionado
    if (valorMaximo == 0) {
        printf("Nenhum item foi selecionado!\n");
    }
    else {
        int valorTotal = valorMaximo;

        // Verificando itens selecionados
        printf("O caminhao levara os itens:\n\n");

        int capacidade_residual = capacidade;
        Item item_vazio = {0, 0}; //Estrutura vazia para inicializar selecao

        for (int i = numItens - 1; i >= 0; i--) {
            selecao[i] = item_vazio; //Inicializa selecao com valores vazios

            // Encontra os itens selecionados e armazena em selecao[i]
            if (valorMaximo - itens[i].valor == selecionar_item(itens, i, capacidade_residual - itens[i].peso)) {
                selecao[i].valor = itens[i].valor;
                selecao[i].peso = itens[i].peso;

                capacidade_residual -= itens[i].peso;
                valorMaximo -= itens[i].valor;
            }
        }

        // Imprimindo itens selecionados
        for (int i = 0; i < numItens; i++) {
            if (selecao[i].peso == itens[i].peso && selecao[i].valor == itens[i].valor){
                printf("Item %d ( Valor: %d - Peso: %d )\n", i + 1, selecao[i].valor, selecao[i].peso);
            }
        }

        //calculo do tempo de execucao
        fim = clock();
        double tempo_executado = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

        printf("\nValor agregado: %d\n", valorTotal);
        printf("Tempo de execucao: %f segundos\n", tempo_executado);
        

        char resposta;
        printf("\nDeseja salvar os resultados? (S para sim; N para nao): ");
        scanf(" %c", &resposta);

        if (resposta == 'S' || resposta == 's') {
            salvar_resultados("saida.txt", selecao, numItens, valorTotal, tempo_executado);
            printf("Resultados salvos com sucesso!\n");
        }
    }
    
    free(itens);
    free(selecao);
    
    
    return 0;
}