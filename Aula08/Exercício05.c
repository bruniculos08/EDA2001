#include "stdlib.h"
#include "stdio.h"

int factorial(int n){
    if(n > 1) return n*factorial(n-1);
    else return 1;
}

int combination(int n, int p){
    return factorial(n)/(factorial(p)*factorial(n-p));
}

void printArray(int array[], int arraySize){
    for(int i = 0; i < arraySize; i++) printf("%i ", array[i]);
    printf("\n");
}

int stairs(int stairsNumber){
    // (1) Número de maneiras para se subir a escada:
    int ways = 0;

    // (2) Número máximo de números iguais a 2 no vetor:
    int result = stairsNumber/2;
    // Obs.: note que result será sempre igual a quantidade de números iguais à 2 no vetor.

    // (3) Número mínimo de números iguais a 1 no vetor:
    int rest = stairsNumber%2;
    // Obs.: note que rest será sempre igual a quantidade de números iguais à 1 no vetor.


    // (4) Quando rest == stairsNumber tem-se o vetor [1, 1, 1,...] (apenas com números iguais à 1):
    while(rest <= stairsNumber){

        // (4.1) Vetor de tamanho igual a quantidade de números iguais a 1 somada a quantidade de números iguais a 2:
        int array[result+rest];
    
        // (4.2) Adicionando a quantidade de números iguais à 2 no vetor:
        for(int i = 0; i < result; i++) array[i] = 2;
    
        // (4.3) Adicionando a quantidade de números iguais à 1 no vetor:
        for(int i = result; i < rest+result; i++) array[i] = 1;

        // (4.4) Chama a função para imprimir todas as permutações do vetor:
        printArray(array, result+rest);
    
        // (4.5) Soma o número de permutações possíveis do vetor atual formado por 1's e 2's:
        ways += combination(result+rest, result);
        
        // (4.6) Quando se deixar de ter um número igual à 2 deve-se adicionar dois números iguais à 1:
        result --;
        rest += 2;
    }
    return ways;
}

int main(){
    int n = stairs(1);
    printf("%i\n", n);
}