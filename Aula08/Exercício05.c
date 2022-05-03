#include "stdlib.h"
#include "stdio.h"

void permute(int array[], int size, int n)
{
  int tmp;
  int i, j;
  if (n == 1) {
    for (i = 0; i < size; i++)
      printf("%i ", array[i]);
    putchar('\n');
  } 
  else {
    for (i = 0; i < n; i++) {
            permute(array, size, n - 1);
            j = (n % 2 == 1) ? n - 1 : 0;
            tmp = array[n - 1];
            array[n - 1] = array[j];
            array[j] = tmp;
        }
    }
}

// Essa função deve imprimir todas as possibilidades de ordem de um vetor:
void arrayAll(int *array, int arraySize, int numberOfTwo){
}

void stairs(int stairsNumber){
    
    // (1) Número máximo de números iguais a 2 no vetor:
    int result = stairsNumber/2;
    
    // (2) Número mínimo de números iguais a 1 no vetor:
    int rest = stairsNumber%2;

    // (3) Quando rest == stairsNumber tem-se o vetor [1, 1, 1,...] (apenas com números iguais à 1):
    while(rest != stairsNumber){

        // (3.1) Vetor de tamanho igual a quantidade de números iguais a 1 somada a quantidade de números iguais a 2:
        int *array = (int*)malloc((result+rest)*sizeof(int));
    
        // (3.2) Adicionando a quantidade de números iguais à 2 no vetor:
        for(int i = 0; i < result; i++) array[i] = 2;
    
        // (3.3) Adicionando a quantidade de números iguais à 1 no vetor:
        for(int i = 0; i < rest; i++) array[i+rest] = 1;

        // (3.4) Chama a função para imprimir todas as permutações do vetor:
        arrayAll(array, result+rest, result);

        free(array);

        rest += 2;
        result --;
    }


    // (3) Vetor de tamanho igual a quantidade de números iguais a 1 somada a quantidade de números iguais a 2:
    int *array = (int*)malloc((result+rest)*sizeof(int));
    
    // (4) Adicionando a quantidade de números iguais à 2 no vetor:
    for(int i = 0; i < result; i++) array[i] = 2;
    
    // (5) Adicionando a quantidade de números iguais à 1 no vetor:
    for(int i = 0; i < rest; i++) array[i+rest] = 1;

    arrayAll(array, result+rest, result);
    // 1 = [1]
    // 2 = [2] [1, 1]
    // 3 = [2, 1] [1, 1, 1] [1, 2]
    // 4 = [2, 2] [2, 1, 1] 
}

int main(){
    int array[] = {1, 2, 2, 1};
    int arraySize = sizeof(array)/sizeof(array[0]);
    //arrayAll(array, arraySize);
    permute(array, 4, 2);
}