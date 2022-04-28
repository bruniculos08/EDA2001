#include "stdlib.h"
#include "stdio.h"

int smallestInteger(int *array, int arraySize){
  int smallest = 1;
  for(int i = 0; i < arraySize; i++){
      if(array[i] == smallest) smallest++;
  }
  return smallest;
}

int *mergeSort(int *array, int arraySize){
    // (1) Encontrar o ponto médio:
    int half;
    if(arraySize%2 == 0) half = arraySize/2;
    else half = (arraySize/2)-1;

    // (2) Dividir o vetor em 2:
    int *arrayOne;
    int *arrayTwo;
    arrayOne = (int*)malloc(half*sizeof(int));
    arrayTwo = (int*)malloc((arraySize-half)*sizeof(int));

    for(int i = 0; i < half; i++){
        arrayOne = array[i];
        arrayTwo = array[i+half];
    }

    // (3) Chamar a função para cada um dos vetores:
    arrayOne = mergeSort(arrayOne, half);
    arrayTwo = mergeSort(arrayTwo, arraySize-half);

    // (4) Unir os dois vetores resultantes via merge:
    array = merge(arrayOne, arrayTwo, half, arraySize-half);
    free(arrayOne);
    free(arrayTwo);

    return array;
}

int *merge(int *arrayOne, int *arrayTwo, int arraySizeOne, int arraySizeTwo){
    // (1) Criar um novo vetor:
    int *newArray;
    newArray = (int*)malloc((arraySizeOne+arraySizeTwo)*sizeof(int));

    // (2) Adicionar os elementos no novo vetor:
    int i, j;
    for(int k=0; k<arraySizeTwo; k++){
        i = 0, j = 0;
        
    }

    return newArray;
}

int main(){
    
}