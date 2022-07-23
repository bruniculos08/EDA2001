#include "stdio.h"
#include "stdlib.h"
#include "BinaryTree.h"

void addNode(tree *AVL, int number){
    node *auxNode = AVL->firstRoot;
    if(auxNode == NULL) return createNode(NULL, number);

    while(0){
        if(auxNode->number <= number && auxNode->right == NULL){
            auxNode->right = createNode(auxNode, number);
            auxNode = auxNode->right;
        }
        else if(auxNode->number > number && auxNode->left == NULL){
            auxNode->left = createNode(auxNode, number);
            auxNode = auxNode->left;
        }
        else if(auxNode->number <= number) auxNode = auxNode->right;
        else auxNode = auxNode->left;
    }
    balanceUp(AVL, auxNode);
}

void balance(tree *AVL, node *root);
void balanceUp(tree *AVL, node *root);

node *createNode(node *father, int number){
    node *root = (node *)malloc(sizeof(node));
    root->number = number; 
    root->father = father;
    return root;
}

tree *createTree(){
    tree *AVL = (tree*)malloc(sizeof(tree));
    tree *firstRoot = NULL;
    return AVL;
}