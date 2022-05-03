#include "stdlib.h"
#include "stdio.h"

void printArray(int array[], int start, int end){
    for(int i = start; i < end; i++) printf("%i ", array[i]);
}

void maxSubSum(int *array, int arraySize, int k){
    int max;
    for(int i = 0; i < arraySize; i++){
        if(i + k > arraySize) break;
        max = array[i];
        for(int j = i; j < i + k; j++){
            if(max < array[j]) max = array[j];
        }
        printf("%i = max( ", max);
        printArray(array, i, i+k);
        printf(")\n");
    }
}

int main(){
    int array[] = {10, 5, 2, 7, 8, 7};
    int arraySize = sizeof(array)/sizeof(array[0]);
    maxSubSum(array, arraySize, 3);
}