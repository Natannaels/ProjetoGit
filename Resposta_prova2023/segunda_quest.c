#include <stdio.h>
#define barra printf("\n")

int conta_passo(int nums[], int n) {
    static int passos = 0;
    int flag;
    
    do {
        flag = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                for (int j = i; j < n; j++) {
                    nums[j] = nums[j + 1];
                }
                n--;
                flag = 1;
            }
            
        }
        
        if (flag) {
            passos++;
            printf("Passo %d: ", passos);
            for(int i = 0; i < n; i++) {printf("%d ", nums[i]);}
        }
        printf("\n");
    } while (flag);
    
    return passos;
}

int main() {
    int nums[] = {5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11};
    int n = sizeof(nums) / sizeof(nums[0]);
    int passos = conta_passo(nums, n);
    
    printf("etapas executadas: %d\n", passos); 
    
    return 0;
}
