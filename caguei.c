#include <stdlib.h>
#include <stdlib.h>

int main() {
    int n = 10;
    int arr[n-1] = { 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(int i = 0; i < 10; i++) {
        if(arr[i] != i + 1) {
            printf("O numero que falta eh: %d", i+1);
            break;
        }
    }
    
    return 0;
}