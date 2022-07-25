#include <stdio.h>
#include <stdlib.h>
#include "insertionSort.h"

int *insertionSort(int *array, int n){
    int j, key, keyIndex;
    for(int i = 1; i < n; i++){
        key = array[i];
        keyIndex = i;
        j = i-1;
        while(j >= 0){
            if(key < array[j]){
                array[keyIndex] = array[j];
                array[j] = key;
                keyIndex = j;
            }
            j--;
        }
    }
    return array;
}

void printArray(int *array, int n){
    for(int i = 0; i < n; i++) printf("%i ", array[i]);
    printf("\n");
}