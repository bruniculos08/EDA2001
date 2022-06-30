#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "redBlackTree.h"

node *createNode(tree *RB, node *father, int number){
    node *auxNode = (node*)malloc(sizeof(node));
    auxNode->number = number;
    auxNode->father = father;
    auxNode->left = RB->nullRoot;
    auxNode->right = RB->nullRoot;
    auxNode->color = red;
}

node *addNode(tree *RB, node *root, int number){
    node *auxNode = root;
    while(true){
        if(auxNode->number <= number && auxNode->right == NULL){ 
            auxNode->right = createNode(RB, auxNode, number);
            break;
        }
        else if(auxNode->number > number && auxNode->left == NULL){
            auxNode->left = createNode(RB, auxNode, number);
            break;
        }
        else if(auxNode->number <= number) auxNode = auxNode->right;
        else auxNode = auxNode->left;
    }
    return root;
}

node *searchNode(node *root, int number){

}

node *grandFather(node *root){
    node *auxNode = root;
    if(root->father != NULL){
        auxNode = root->father->father;
    }
}

node *uncle(node *root);

