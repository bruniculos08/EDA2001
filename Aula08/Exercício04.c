#include "stdlib.h"
#include "stdio.h"

int biggestSum(int *array, int arraySize, int index){ 
    // (1) se o index atual não remete à um elemento do vetor, tem-se o caso base, retornando 0:
    if(index >= arraySize) return 0;
    
    // (2) Note que a partir de um elemento qualquer no vetor, sua sequência de elementos não adjacentes pode seguir...
    // ... pelo 1º elemento não adjacente (array[index+2]) ou pelo 2º elemento não adjacente (array[index+3]),...
    // ... por isso as variáveis sum1 e sum2:
    int sum1, sum2;
    sum1 = array[index] + biggestSum(array, arraySize, index+2); 
    sum2 = array[index] + biggestSum(array, arraySize, index+3); 
    
    // (3) Deve-se retornar o somatório da sequência de maior resultado (o que é exatamente o objetivo do código):
    if(sum1 > sum2) return sum1;
    else return sum2;
}

int sumWay(int *array, int arraySize){

    // (1) Visto que podemos começar o somatório a partir do 1º ou 2º elemento temos duas possibilidades iniciais de somatório:
    int sum1 = 0, sum2 = 0;

    // (2) Caso só haja 1 elemento no vetor só há então a possibilidade de haver um único somatório:
    if(arraySize == 1) return array[0];

    // (3) Soma do 1º elemento com o somatório de elementos não adjacentes a este gerado por biggestSum(...):
    sum1 = biggestSum(array, arraySize, 0); 
    // (4) Soma do 2º elemento com o somatório de elementos não adjacentes a este gerado por biggestSum(...):
    sum2 = biggestSum(array, arraySize, 1); 

    // (5) Retorna o somatório que resultou em um maior valor:
    if(sum1 > sum2) return sum1;
    else return sum2;
}

int main(){
    int array[] = {5, 1, 1, 5};
    int arraySize = sizeof(array)/sizeof(array[0]);
    printf("Soma = %i\n", sumWay(array, arraySize));
}