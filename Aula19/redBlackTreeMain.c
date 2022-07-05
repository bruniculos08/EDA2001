#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "redBlackTree.h"

int main(){
    tree *RB;
    RB = createTree();
    addNode(RB, 8);
    addNode(RB, 1);
    addNode(RB, 11);
    addNode(RB, 12);
    addNode(RB, 13);
    addNode(RB, 10);
    addNode(RB, 9);
    addNode(RB, 8);
    printf("teste\n");
    printTree(RB, RB->firstRoot);

    removeNode(RB, 10);
    
    printf("teste\n");
    printTree(RB, RB->firstRoot);
}