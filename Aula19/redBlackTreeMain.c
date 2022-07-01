#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "redBlackTree.h"

int main(){
    tree *RB;
    RB = createTree();
    printf("teste\n");
    addNode(RB, 10);
    addNode(RB, 1);
    addNode(RB, 11);
    printf("teste\n");
    printTree(RB, RB->firstRoot);
}