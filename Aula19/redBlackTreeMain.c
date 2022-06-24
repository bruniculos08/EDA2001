#include <stdlib.h>
#include <stdio.h>
#include "redBlackTree.h"

node *createNode(int number){
    node *auxNode = (node*)malloc(sizeof(node));
    auxNode->number = number;
    auxNode->father = NULL;
    auxNode->left = NULL;
    auxNode->right = NULL;
    auxNode->color = red;
}
