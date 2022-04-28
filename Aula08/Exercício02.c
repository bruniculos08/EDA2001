#include "stdlib.h"
#include "stdio.h"

int *oneProduct(int *array, int arraySize){
    int *newArray;
    newArray = (int*)malloc(arraySize*sizeof(int));

    for(int i = 0; i < arraySize; i++){
        newArray[i] = 1;
        //Obs.: é possível resolver de maneira mais eficiente utilizando uma divisão (pelo elemento atual)...
        //... e uma multiplicão pelo elemento anterior.
        for(int j = 0; j < arraySize; j++){
            if(i == j) j++;
            if(j < arraySize) newArray[i] = newArray[i]*array[j];

        }
    }
    return newArray;
}

int main(){
    int array[] = {1,2,3,4,5};
    int arraySize = sizeof(array)/sizeof(array[0]);
    
    int *newArray;
    newArray = (int*)malloc(arraySize*sizeof(int));
    newArray = oneProduct(array, arraySize);

    printf("[");
    for(int i = 0; i < arraySize; i++){
        if(i < arraySize - 1) printf("%i, ", newArray[i]);
        else printf("%i", newArray[i]);
    }
    printf("]\n");
    
}