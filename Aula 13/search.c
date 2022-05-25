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
        middle = (end + start)/2;
        count++;
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
    if(start >= end) return count;
    else if(array[middle] == key) return count;
    else if(array[middle] < key) return (count + pesquisaBinariaRecursiva(array, middle+1, end, key));
    else return (count + pesquisaBinariaRecursiva(array, start, middle-1, key));
    //return count;
}

int pesquisaInterpolacao(int array[], int length, int key){
    int start = 0, end = length - 1, count = 0, middle;
    while(start <= end){
        middle = (start + (end - start)*(key - array[start]))/(array[end] - array[start]);
        //printf("middle = %i\n", middle);
        count++;
        if(array[middle] == key) return count;
        else if(array[middle] < key) start = middle + 1;
        else if(array[middle] > key) end = middle - 1;
    }
    return count;
}

int randomNumber(int min_num, int max_num)
    {
        int result = 0, low_num = 0, hi_num = 0;

        if (min_num < max_num)
        {
            low_num = min_num;
            hi_num = max_num + 1; // include max_num in output
        } else {
            low_num = max_num + 1; // include max_num in output
            hi_num = min_num;
        }

        srand(time(NULL));
        result = (rand() % (hi_num - low_num)) + low_num;
        return result;
    }

int *randomArray(int lenght){
    int *array = (int*)malloc(lenght*sizeof(int));
    srand(time(NULL));
    array[0] = randomNumber(1, 100);
    for(int i = 1; i < lenght; i++) array[i] = randomNumber(1, 100) + array[i-1];
    return array;
}

int main(){
    float averageSequencial = 0, averageSequencialSentinela = 0, averageBinaria = 0, averageBinariaRecursiva = 0, averageInterpolacao = 0;
    FILE *filePointer;
    filePointer = fopen("Performance.txt", "w+");
    int cases = 10;
    for(int i = 0; i < cases; i++){
        int arraySize = 10;
        int random = randomNumber(0, arraySize-1);
        int *array = randomArray(arraySize);
        averageSequencial += pesquisaSequencial(array, arraySize, array[random]);
        averageSequencialSentinela += pesquisaSequencialSentinela(array, arraySize, array[random]);
        averageBinaria += pesquisaBinaria(array, arraySize, array[random]);
        averageBinariaRecursiva += pesquisaBinariaRecursiva(array, 0, arraySize, array[random]);
        averageInterpolacao += pesquisaInterpolacao(array, arraySize, array[random]);
    }

    fprintf(filePointer, "pesquisa Sequencial = %f\n", averageSequencial/cases);
    fprintf(filePointer, "pesquisa Sequencial Sentinela = %f\n", averageSequencialSentinela/cases);
    fprintf(filePointer, "pesquisa Binaria = %f\n", averageBinaria/cases);
    fprintf(filePointer, "pesquisa Binaria Recursiva = %f\n", averageBinariaRecursiva/cases);
    fprintf(filePointer, "pesquisa Interpolacao = %f\n", averageInterpolacao/cases);

}