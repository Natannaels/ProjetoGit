#include <stdio.h>

int main() {
    int t = 0, n = 0;

    scanf("%d", &t);
    int arr[t];
    printf("digite os elementos: \n");

    for(int i = 0; i < t; i++ ) {
        scanf("%d", &arr[i]);
    }

    for(int j = 0; j < t-1; j++){
        for(int i = 0; i < t-1; i++) {
            
            if(arr[i] == 0) {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }       
    }

    for(int i = 0; i < t; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}