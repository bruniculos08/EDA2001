#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "redBlackTree.h"

int main(){
    tree *RB;
    RB = createTree();
    printf("teste\n");
    addNode(RB, 8);
    addNode(RB, 1);
    addNode(RB, 11);
    addNode(RB, 12);
    //addNode(RB, 10); // Quando não adiciona o 10 antes do 13 dá problema, provavelmente é algo relacionado ao tio do 13...
                     // ... que nesse caso é o nó 10.
    printf("teste\n");
    addNode(RB, 13);
    printTree(RB, RB->firstRoot);
    addNode(RB, 10);
    addNode(RB, 9);
    addNode(RB, 8);
    printf("teste\n");
    printTree(RB, RB->firstRoot);
}