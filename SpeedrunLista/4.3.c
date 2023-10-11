#include <stdio.h>
#include <stdlib.h>

int find_num(int A[], int n) {
    int temp;
    int flag;
    do{
        flag = 0;
        for(int i = 0; i < n - 1; i++) {
            if(A[i] > A[i + 1]) {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                flag = 1;
            }
        }
    } while (flag != 0);

    for(int i = 0; i < n; i ++) {
            if(A[i] != i + 1) {
                return i + 1;
            }
        }
    return -1;


    }


int main() {
    int A[] = {3, 2, 1, 10, 5, 6, 7, 9, 4};
    int n = sizeof(A)/sizeof(A[0]);

    printf("\nO numero que falta eh %d.\n", find_num(A, n));
    for(int i = 0; i < n; i++) printf("%d ", A[i]);

    

    return 0;
}