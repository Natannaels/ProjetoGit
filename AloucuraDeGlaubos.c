#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 4, m = 4;
    int arr[] = {1, 4, 2, 3};

    for(int i = 0; i < n; i++) {    
            for(int j = i + 1; j < n; j++) {
                if(arr[i] > arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;      
                }      
            }
    }

    int aux[n];
    int j = 0;
    for(int i = 0; i  < n; i++) {
        aux[j] = arr[i];
        aux[++j] = arr[n - 1];
        j++;
        n--;
    }

    for(int i = 0; i < m; i++){
        printf("%d ", aux[i]);
    }

    return 0;
    
}