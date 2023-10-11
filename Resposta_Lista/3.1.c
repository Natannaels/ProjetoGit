#include <stdio.h>
#include <stdlib.h>

int findmin(int a[], int n) {
    int min;
    if(n == 1) {
        return a[0];
    }
    
    min = findmin(a, n - 1);

    if(min < a[n -1]) {
        return min;
    }
    else {
        return a[n - 1];
    }
}

int main() {
int a[] ={-2, 1, -3, 4, 7};
int n =5;

printf("Min: %d", findmin(a, n));

    return 0;
}