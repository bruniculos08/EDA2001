#include <stdio.h>
#include <stdlib.h>
#include "insertionSort.h"
#include <time.h>

int main(){
    int n = 4;
    srand(time(NULL));
    int *array;
    array = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++) array[i] = rand()%10;
    printArray(array, n);
    array = insertionSort(array, n);
    printArray(array, n);
}