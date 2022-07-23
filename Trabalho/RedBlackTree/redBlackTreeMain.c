#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "redBlackTree.h"

void printSteps(FILE *filePointer){
    fprintf(filePointer, "%i ", countSteps);
    countSteps = 0;    
}

void WorstCase(){
    tree *RB;
    RB = createTree();
    FILE *filePointer;
    filePointer = fopen("PerformanceWorstCase.txt", "w+");

    for(int i = 0; i < 100; i++){
        addNode(RB, i);
        printSteps(filePointer);
        if(i != 99) fprintf(filePointer, "\n");
    }
}

void AverageCase(int n){
    FILE *filePointer;
    filePointer = fopen("PerformanceAverageCase.txt", "w+");

    srand(time(NULL));

    for(int i = 0; i < n; i++){
        tree *RB;
        RB = createTree();

        for(int j = 0; j < 100; j++){
            //fprintf(filePointer, "Caso %i: ", j);
            int random = rand()%100;
            addNode(RB, random);
            printf("Caso %i (random = %i): %i \n", j, random, countSteps);
            countSteps = 0;
            mantainTreeRoot(RB);
        }
        free(RB);
        RB = NULL;
    }
    
    
}

int main(){
    WorstCase();
    AverageCase(1);
}