#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "BinaryTree.h"

void printSteps(FILE *filePointer){
    fprintf(filePointer, "%i ", countSteps);
    countSteps = 0;    
}

void worstCase(){
    tree *AVL;
    AVL = createTree();
    FILE *filePointer;
    filePointer = fopen("PerformanceWorstCase.txt", "w+");
    for(int i = 0; i < 100; i++){
        addNode(AVL, i);
        printSteps(filePointer);
    }
}

void averageCase(int n){
    tree *AVL;
    FILE *filePointer;
    filePointer = fopen("PerformanceAverageCase.txt", "w+");
    srand(time(NULL));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 100; j++){
            addNode(AVL, rand());
            printSteps(filePointer);
        }
        if(i != n-1) fprintf(filePointer, "\n");
        free(AVL);
        AVL = NULL;
    }
}

int main(){
    tree *AVL;
    AVL = createTree();
    srand(time(NULL));
    addNode(AVL, 2);
    addNode(AVL, 4);
    addNode(AVL, 7);
    addNode(AVL, 8);
    addNode(AVL, 11);
    addNode(AVL, 10);
    addNode(AVL, 6);
    printTree(AVL->firstRoot);
}