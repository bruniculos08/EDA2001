#include "stdlib.h"
#include "stdio.h"
#include "headSearch.h"
#include "math.h"
#include "time.h"

int main(){
    int *array = randomArray(10);
    for(int i = 0; i < 10; i++) printf("%i ", array[i]);
}