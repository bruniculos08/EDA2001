#include "stdlib.h"
#include "stdio.h"

// Complexidade de tempo O(n²) pois f(n) = (n²)/2

int twoSum(int *array, int sum, int arraySize){
    for(int i = 0; i < arraySize-1; i++){
        for(int j = i+1; j < arraySize; j++){
            if(array[i] + array[j] == sum) return 0;
            else if(array[arraySize-j] + array[arraySize-i] == sum) return 0;
        }
    }
    return 1;
}

int main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 , 10};
    int size = sizeof(array)/sizeof(array[0]);
    
    if(twoSum(array, 19, size) == 0) printf("True.\n");
    else printf("False.\n");
}