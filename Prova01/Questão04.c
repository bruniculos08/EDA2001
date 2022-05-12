#include "stdlib.h"
#include "stdio.h"

int countNumber(int *array, int arraySize, int number);
int pertence(int *array, int arraySize, int number);

//Obs.: meu código conta todas a possibilidades de pares

int pairs(int *array, int arraySize){
    int pares=0;
    int tamanhoPares[arraySize];
    int indexTamanhoPares = 0;

    for(int i=0; i<arraySize; i++){
        // 01. O vetor que "anota" os tamanhos já contados tem que ter seus elementos iguais a 0 inicialmente:
        tamanhoPares[i] = 0;

        // 02. Se o tamanho em questão já foi contabilizado pode-se pular para o próximo elemento
        if(pertence(tamanhoPares, arraySize, array[i]) == 0) continue;
        else{
            // 03. Anotar tamanho no vetor de anotação e neste andar um elemento:
            tamanhoPares[indexTamanhoPares] = array[i];
            indexTamanhoPares++;

            // 04. Ver é possível fazer um par:
            if(countNumber(array, arraySize, array[i]) > 1) pares++;
        }
    }
    return pares;
}

int countNumber(int *array, int arraySize, int number){
    int count = 0;
    for(int i=0; i<arraySize; i++){
        if(array[i] == number) count++;
    }
    return count;
}

int pertence(int *array, int arraySize, int number){
    for(int i=0; i<arraySize; i++){
        if(array[i]==0) return 1;
        else if(array[i]==number) return 0;
    }
    return 1;
}

int main(){
    int array[] = {6, 5, 2, 3, 5, 2, 2 , 1};
    int arraySize = sizeof(array)/sizeof(array[0]);
    printf("%i\n", pairs(array, arraySize));
}