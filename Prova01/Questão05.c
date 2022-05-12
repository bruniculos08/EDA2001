#include "stdlib.h"
#include "stdio.h"

int min(int a, int b, int c) {
    if(a <= b && a <= c) return a;
    if(b <= a && b <= c) return b;
    else return c;
}

int main(){
    char array1[] = "amor";
    char array2[] = "amora";
    int m = 4;
    int n = 5;
    int matrix[m][n];
    
    //for(int i = 0; i < m; i++){
      //  for(int j = 0; j < n; j++) matrix[i][j] = 0;
    //}

    int custo;

    for(int i = 0; i < m; i++) matrix[i][0] = i;

    for(int j = 0; j < n; j++) matrix[0][j] = j;

    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(array1[i] == array2[j]) custo = 0;
            else custo = 1;

            matrix[i][j] = min(matrix[i-1][j]+1, matrix[i-1][j-1]+custo, matrix[i][j-1]+1);
        }
    }

    printf("Resposta: %d\n", matrix[m-1][n-1]);

}