#include <stdlib.h>
#include <stdio.h>

int main() {
    
    int arr[5];
    printf("Digite 5 numeros: \n");
    for(int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    printf("numeros em ordem inversa: \n");
    for(int i = 4; i >= 0; i--) {
        printf("%d ", arr[i]);
    }


    return 0;
}