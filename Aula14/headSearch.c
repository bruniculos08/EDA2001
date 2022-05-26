#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "time.h"

int pesquisaSequencial(int array[], int length, int key){
    for(int i=0; i<length; i++){
        if(array[i] == key) return array[i];
    }
    return -1;   
}

int pesquisaSequencialSentinela(int array[], int length, int key){
    int i = 0;
    array[length-1] = key;
    while(array[i] != key){
        i++;
    }
    if (i != length-1) return array[i]; 
    else return -1;
}

int pesquisaBinaria(int array[], int length, int key){
    int start = 0, end = length - 1, middle;
    while(start <= end){
        middle = (end + start)/2;
        //printf("middle = %i\n", middle);
        if(array[middle] == key) return array[middle];
        else if(array[middle] < key) start = middle + 1;
        else if(array[middle] > key) end = middle - 1;
    }
    return -1;
}

int pesquisaBinariaRecursiva(int array[], int start, int end, int key){
    int middle = (end + start)/2;
    if(start > end) return -1;
    else if(array[middle] == key) return array[middle];
    else if(array[middle] > key) return (pesquisaBinariaRecursiva(array, start, middle-1, key));
    else return (pesquisaBinariaRecursiva(array, middle+1, end, key));
}

int pesquisaInterpolacao(int array[], int length, int key){
    int start = 0, end = length - 1, middle;
    while(start <= end){
        middle = (start + ((end - start)*(key - array[start])))/(array[end] - array[start]);
        if(array[middle] == key) return array[middle];
        else if(array[middle] < key) start = middle + 1;
        else if(array[middle] > key) end = middle - 1;
    }
    return -1;
}

int *randomArray(int length){
    srand(time(NULL));
    int *array;
    array = (int*)malloc(length*sizeof(int));
    for(int i = 0; i < length; i++){
        array[i] = rand()%100;
        if(i > 0) array[i] += array[i-1]; 
    }
    return array;
}