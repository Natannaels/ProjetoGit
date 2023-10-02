#include <stdlib.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int arr[n];
    int aux[n];

    for(int i = 0; i < n; i++) {
        printf("elemento %d - ", i);
        scanf("%d", &arr[i]);
    }
    

    for(int i = 0; i < n - 1; i++) {
        int cont = 1;
        for(int j = i + 1; j < n; j++) {
            
            if(aux[i] == 1) {continue;}
            if(arr[i] == arr[j]) {
                cont++;
                aux[j] = 1;
            }
        }
        if(cont > (float)n/2) {
            printf("%d que ocorre %d vezes que eh maior que %d/2.", arr[i], cont, n);
            break;
        }
    }



    return 0;
}