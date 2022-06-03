#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"
#include "time.h"

int pesquisaSequencial(int array[], int length, int key){
    int count = 0;
    for(int i=0; i<length; i++){
        count = i;
        if(array[i] == key) return count;
    }
    return count;   
}

int pesquisaSequencialSentinela(int array[], int length, int key){
    int i = 0;
    array[length-1] = key;
    while(array[i] != key){
        i++;
    }
    return i; 
}

int pesquisaBinaria(int array[], int length, int key){
    int start = 0, end = length - 1, count = 0, middle;
    while(start <= end){
        count++;
        middle = (end + start)/2;
        //printf("middle = %i\n", middle);
        if(array[middle] == key) return count;
        else if(array[middle] < key) start = middle + 1;
        else if(array[middle] > key) end = middle - 1;
    }
    return count;
}

int pesquisaBinariaRecursiva(int array[], int start, int end, int key){
    int middle = (end + start)/2, count = 0;
    count++;
    //printf("middle = %i, start = %i, end = %i\n", middle, start, end);
    if(start > end) return count;
    else if(array[middle] == key) return count;
    else if(array[middle] < key) return (count + pesquisaBinariaRecursiva(array, middle+1, end, key));
    else return (count + pesquisaBinariaRecursiva(array, start, middle-1, key));
    //return count;
}

int pesquisaInterpolacao(int array[], int length, int key){
    int start = 0, end = length-1, count = 0, middle;
    while(start < end){
        middle = (start + (end - start)*(key - array[start]))/(array[end] - array[start]);
        //printf("middle = %i\n", middle);
        count++;
        if(array[middle] == key) return count;
        else if(array[middle] < key) start = middle + 1;
        else if(array[middle] > key) end = middle - 1;
    }
    return count;
}

int *randomArray(int length){
    int *array;
    array = (int*)malloc(length*sizeof(int));
    for(int i = 0; i < length; i++){
        array[i] = rand()%10;
        if(i > 0 && array[i] < array[i-1]) array[i] += array[i-1]; 
    }
    return array;
}

int main(){
    int cases = 20;
    int resultsSequencial[cases], resultsSequencialSentinela[cases], resultsBinaria[cases], resultsBinariaRecursiva[cases], resultsInterpolacao[cases];
    
    FILE *filePointer;
    filePointer = fopen("Performance.txt", "w+");
    int arraySize = 10;
    int *array = (int*)malloc(arraySize*sizeof(int));
    srand(time(NULL));

    for(int i = 0; i < cases; i++){

        int random = rand()%arraySize;
        array = randomArray(arraySize);

        resultsSequencial[i] = pesquisaSequencial(array, arraySize, array[random]);
        resultsSequencialSentinela[i] = pesquisaSequencialSentinela(array, arraySize, array[random]);
        resultsBinaria[i] = pesquisaBinaria(array, arraySize, array[random]);
        resultsBinariaRecursiva[i] = pesquisaBinariaRecursiva(array, 0, arraySize-1, array[random]);
        resultsInterpolacao[i] = pesquisaInterpolacao(array, arraySize, array[random]);

        free(array);
    }

    fprintf(filePointer, "pesquisa Sequencial: ");
    for (int i = 0; i < cases; i++) fprintf(filePointer, "%i ", resultsSequencial[i]);

    fprintf(filePointer, "\npesquisa Sequencial Sentinela: ");
    for (int i = 0; i < cases; i++) fprintf(filePointer, "%i ", resultsSequencialSentinela[i]);

    fprintf(filePointer, "\npesquisa Binaria: ");
    for (int i = 0; i < cases; i++) fprintf(filePointer, "%i ", resultsBinaria[i]);

    fprintf(filePointer, "\npesquisa Binaria Recursiva: ");
    for (int i = 0; i < cases; i++) fprintf(filePointer, "%i ", resultsBinariaRecursiva[i]);

    fprintf(filePointer, "\npesquisa Interpolacao: ");
    for (int i = 0; i < cases; i++) fprintf(filePointer, "%i ", resultsInterpolacao[i]);

}