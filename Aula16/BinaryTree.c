#include "stdio.h"
#include "stdlib.h"
#include "BinaryTree.h"

node *createNode(int number){
    node *newRoot;
    newRoot = (node *)malloc(sizeof(node));
    newRoot->number = number;
    newRoot->left = NULL;
    newRoot->right = NULL;
    return newRoot;
}

node *AddNode(node *root, node *father, int newNumber){
    if(root == NULL){
       node *newNode = createNode(newNumber);
       newNode->father = father;
       return newNode;
    }
    node *auxRoot;
    auxRoot = root;
    if(auxRoot->number >= newNumber) auxRoot->left = addNode(auxRoot->left, auxRoot, newNumber);
    else auxRoot->right = addNode(auxRoot->right, auxRoot, newNumber);
}

node *removeNode(node *root, int oldNumber){
   node *f, *p;
   p = root;
   f = root;
   if(root->number == oldNumber){
       
   }
}

int nodeHeight(node *root){
    int height = -1;
    if (root == NULL) return height;
    else if(root->left == NULL && root->right == NULL) return height+1;
    else if(nodeHeight(root->left) >= nodeHeight(root->right)) return nodeHeight(root->left)+1;
    else return nodeHeight(root->right)+1;
}




