#include "stdlib.h"
#include "stdio.h"
#include "math.h"

void printSet(int array[], int *binarySet, int arraySize){
    int flagFirst = 0;
    printf("[");
    for(int i = 0; i < arraySize; i++){
        if(binarySet[i] == 1 && flagFirst == 0){
            printf("%i", array[i]);
            flagFirst = 1;
        }
        else if(binarySet[i] == 1) printf(", %i", array[i]);
    }
    printf("]\n");
}

int *binaryArray(int arraySize, int decimal){
    int sum = 0;
    int *array;
    array = (int *)malloc(arraySize*sizeof(int));
    // (1) Anda-se de trás pra frente nas casas para montar o número binário igual ao algoritmo mental...
    // ... utilizado casualmente:
    for(int i = arraySize-1; i >= 0; i--){
        // (1.1) A casa setada não pode tornar a soma de todas as casa em um número mais que o decimal desejado:
        if(sum + pow(2, i) <= decimal){
            sum += pow(2, i);
            array[i] = 1;
        }
        // (1.2) A casa não setada é igual a 0:
        else array[i] = 0;
    }
    return array;
}

void powerSet(int array[], int arraySize){

    // (1) O númeero de permutações de um vetor binário de tamanho == arraySize é igual a quantidade de subconjuntos de um...
    // ... conjunto de mesmo tamanho: 
    int numberOfSets = pow(2, arraySize);
    
    // (2) Criando um vetor binário do mesmo tamanho do vetor de entrada:
    int *binarySet;
    binarySet = (int*)malloc(arraySize*sizeof(int));
    
    // (3) Loop que se repete uma quantidade de vezes igual ao número de permutação possíveis do vetor binário:
    for(int i = 0; i < numberOfSets; i++){
        // (3.1) Criando um vetor binário que representa o número i:
        binarySet = binaryArray(arraySize, i);
        // Obs.: a representação de todo número de decimal é diferente, por isso que essa técnica funciona:

        // (3.2) Printando o vetor normal de acordo com o vetor binário (se binarySet[i] == 1 então array[i] é impresso,...
        // ... já se binarySet[i] == 0 então array[i] não é impresso):
        printSet(array, binarySet, arraySize);
    }
}

int main(){
    int array[] = {1,2,3};
    int arraySize = sizeof(array)/sizeof(array[0]);
    powerSet(array, arraySize);
}