#include "stdlib.h"
#include "stdio.h"
#include "headSearch.h"
#include "math.h"
#include "time.h"

int main(){
    int length = 10;
    int *array = randomArray(length);
    srand(time(NULL));
    int randomIndex = rand()%length;
    for(int i = 0; i < length; i++) printf("%i ", array[i]);
    printf("\nresultado = %i", pesquisaInterpolacao(array, length, array[randomIndex]));
}