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
    FILE *filePointer;
    filePointer = fopen("PerformanceWorstCase.txt", "w+");
    tree *RB;
    RB = createTree();

    for(int i = 0; i < 100; i++){
        addNode(RB, i);
        printSteps(filePointer);
    }
    fprintf(filePointer, "\n");

    free(RB);
}

void AverageCase(int n){
    FILE *filePointer;
    filePointer = fopen("PerformanceAverageCase.txt", "w+");
    tree *RB;
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        RB = createTree();
        for(int j = 0; j < 100; j++){
            int random = rand()%100;
            addNode(RB, random);
            printSteps(filePointer);
            countSteps = 0;
        }
        free(RB);
        RB = NULL;
    }
}

int main(){
    WorstCase();
    AverageCase(4);
}