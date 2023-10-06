#include <stdlib.h>
#include <stdio.h>

int podeSerCrescente(int nums[], int numsSize);

int main() {
    int nums[] = {1, 4, 6, 20, 2};

    int numsSize =  sizeof(nums) / sizeof(int);

    printf("Saida: %d", podeSerCrescente(nums, numsSize));

    return 0;
}

int podeSerCrescente(int nums[], int numsSize) {
    int aux[numsSize];
    int flag = 1;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] > nums[i+1]) {
            for(int j = i; j < numsSize - 1; j++) {
                nums[j] = nums[j+1];
            }
        numsSize--;
        break;
        }
    }
    for(int i = 0; i < numsSize - 1; i++) {
        if(nums[i] < nums[i + 1]) {
            flag = 1;
        }
        else {
            flag = -1;
            break;
        }
    }
    return flag;
}