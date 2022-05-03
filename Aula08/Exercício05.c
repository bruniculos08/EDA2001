#include "stdlib.h"
#include "stdio.h"

// Essa função deve imprimir todas as possibilidades de ordem de um vetor:
void arrayAll(int array[]){
    
}

void stairs(int stairsNumber){
    int arraySize = stairsNumber;
    int *arrayOne;
    int *arrayTwo;
    arrayOne = (int*)malloc(arraySize*sizeof(int));
    arrayTwo = (int*)malloc((arraySize-1)*sizeof(int));
    for(int i = 0; i < arraySize; i++) arrayOne[i] = 1;
    int boolEnd = 1;
    

    while(boolEnd == 1){
        for(int i = arraySize-1; i > 0; i--){

        }
    }

    // 1 = [1]
    // 2 = [2] [1, 1]
    // 3 = [2, 1] [1, 1, 1] [1, 2]
    // 4 = [2, 2] [2, 1, 1] 
}

int main(){
}