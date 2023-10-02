#include <stdio.h>

int countSteps(int nums[], int length) {
    int steps = 0;
    int changed;
    
    do {
        changed = 0;
        for (int i = 1; i < length; i++) {
            if (nums[i - 1] > nums[i]) {
                for (int j = i; j < length; j++) {
                    nums[j] = nums[j + 1];
                }
                length--;
                changed = 1;
            }
            
        }
        printf("Passo :\n");
        if (changed) {
            steps++;
            
            for(int i = 0; i < length; i++) {printf("%d ", nums[i]);}
        }
    } while (changed);
    
    return steps;
}

int main() {
    int nums1[] = {5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11};
    int length1 = sizeof(nums1) / sizeof(nums1[0]);
    int steps1 = countSteps(nums1, length1);
    
    printf("Exemplo 1: %d\n", steps1); // Saída esperada: 
    
    return 0;
}
