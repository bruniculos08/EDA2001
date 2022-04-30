#include "stdlib.h"
#include "stdio.h"

int *merge(int *arrayOne, int *arrayTwo, int arraySizeOne, int arraySizeTwo){

    // (1) Criar um novo vetor:
    int *newArray;
    newArray = (int*)malloc((arraySizeOne+arraySizeTwo)*sizeof(int));

    // (2) Adicionar os elementos de maneira ordenada no novo vetor:
    int i = 0, j = 0;
    for(int k = 0; k < arraySizeOne+arraySizeTwo && i < arraySizeOne && j < arraySizeTwo; k++){
        if(arrayOne[i] <= arrayTwo[j]){
            newArray[k] = arrayOne[i];
            i++;
        }
        else{
            newArray[k] = arrayTwo[j];
            j++;
        }
    }
    
    // (3) Se um dos vetores tem elementos ainda não adicionados ao vetor enquanto o outro...
    // ... já teve todos os seus elementos adicionados, deve-se adicionar os elementos restantes do vetor em questão:

    while(i < arraySizeOne){
        newArray[i+arraySizeTwo] = arrayOne[i];
        i++;
    }

    while(j < arraySizeTwo){
        newArray[j+arraySizeOne] = arrayTwo[j];
        j++;
    }

    // Obs.: deve haver alguma maneira de fazer como nas listas encadeadas, encadeando o resto do vetor com elementos...
    // ... restantes em uma única instrução.

    return newArray;
}

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
        arrayOne[i] = array[i];
        arrayTwo[i] = array[i+half];
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

int main(){
    int array[] = {4,5,2,3,1};
    *array = mergeSort(array, 5);
    for(int i = 0; i < 5; i++) printf("%i ", array[i]);
}