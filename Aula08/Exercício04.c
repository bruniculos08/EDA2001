#include "stdlib.h"
#include "stdio.h"

int biggestSum(int *array, int arraySize, int index){ 
    // index é o índice do atual elemento a ser somado.
    int sum1, sum2;
    if(index >= arraySize) return 0;
    else{
        sum1 = array[index] + biggestSum(array, arraySize, index+2); 
        sum2 = array[index] + biggestSum(array, arraySize, index+3); 
    }
    if(sum1 > sum2) return sum1;
    else return sum2;
}

int sumWay(int *array, int arraySize){
    int sum1 = 0, sum2 = 0;
    if(arraySize == 1) return array[0];
    sum1 = array[0] + biggestSum(array, arraySize, 2); 
    sum2 = array[1] + biggestSum(array, arraySize, 3); 
    if(sum1 > sum2) return sum1;
    else return sum2;
}

int main(){
    int array[] = {1, 2, 3, 4, 2, 8};
    int arraySize = sizeof(array)/sizeof(array[0]);
    printf("Soma = %i\n", sumWay(array, arraySize));
}