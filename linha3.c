/*Escreva um programa em C para contar o número total de elementos duplicados
em um array.*/
#include <stdio.h>
#include <stdlib.h>
int main() {
  int n, i, j, cont=0;
  printf("Insira o número de elementos a serem armazenados no array: ");
  scanf("%d", &n);

  int arr[n];
  int aux[n];
  printf("Insira %d elementos no array:\n", n);

  for (i = 0; i < n; i++) {
    printf("elemento - %d: ", i);
    scanf("%d", &arr[i]);
  }

  for(i=0; i<n; i++){
    if(aux[i]== 1) continue;
    for(j=i+1; j<n; j++){
        if(arr[i]==arr[j]){
            cont++;
            aux[j]=1;
            break;
        }
    }
  }

 printf("\nO número total de elementos duplicados encontrados no array é: %d\n", cont);
  return 0;
}