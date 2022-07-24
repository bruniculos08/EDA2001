#include "stdio.h"
#include "stdlib.h"
#include "BinaryTree.h"
#include "stdbool.h"

void printTree(node *root){
    printf("%i ", root->number);
    if(root->left != NULL) printTree(root->left);
    if(root->right != NULL) printTree(root->right);
}

void addNode(tree *AVL, int number){
    if(AVL->firstRoot == NULL){
        AVL->firstRoot = createNode(NULL, number);
        return;
    }

    node *auxNode = AVL->firstRoot;

    while(true){
        printf("Line 21\n");
        if(auxNode->number <= number && auxNode->right == NULL){
            auxNode->right = createNode(auxNode, number);
            auxNode = auxNode->right;
            break;
        }
        else if(auxNode->number > number && auxNode->left == NULL){
            auxNode->left = createNode(auxNode, number);
            auxNode = auxNode->left;
            break;
        }
        else if(auxNode->number <= number) auxNode = auxNode->right;
        else auxNode = auxNode->left;
    }
    printf("Line 35\n");
    balanceUp(AVL, auxNode);
}

int balanceFactor(node *root){
    if(root == NULL) return -1;
    return nodeHeight(root->left) - nodeHeight(root->right);
}

int nodeHeight(node *root){
    int height = -1;

    // (01) Se a árvore não existe será retornado -1:
    if (root == NULL) return height;

    // (02) Se existe um nó atual retorna 0:
    else if(root->left == NULL && root->right == NULL) return height+1;

    // (03) Retornar a maior altura entre os nós filhos:
    else if(nodeHeight(root->left) >= nodeHeight(root->right)) return nodeHeight(root->left)+1;
    else return nodeHeight(root->right)+1;
}

void balance(tree *AVL, node *root){
    // (1) Se o nó não existir:
    if(root == NULL) return;

    // (2) Se o nó está desbalanceado em 2 para à esquerda:
    if(balanceFactor(root) == 2){
        // Obs.: deve-se verificar se o nó filho que será afetado diretamente pela rotação...
        // ... está balanceado e então deixa-lo o mais balanceado possível..
        if(balanceFactor(root->left) > 0) rotateRight(AVL, root->left);
        rotateRight(AVL, root);
        return;
    }

    // (3) Se o nó está desbalanceado em 2 para à direita:
    if(balanceFactor(root) == -2){
        // Obs.: deve-se verificar se o nó filho que será afetado diretamente pela rotação...
        // ... está balanceado e então deixa-lo o mais balanceado possível.
        if(balanceFactor(root->right) > 0){
            rotateRight(AVL, root->right);
        }
        rotateLeft(AVL, root);
        return;
    }
        
    // (4) Se o nó está desbalanceado em mais de 2 para à esquerda:
    if(balanceFactor(root) > 2){
        // Obs.: nesses casos deve se rotacionar o nó atual antes de seus filhos,...
        // ... pois se rotacionarmos primeiro o filho o balanceamento pode não funcionar.
        rotateRight(AVL, root);
        root = root->father;
        if(balanceFactor(root->left) > 0) rotateRight(AVL, root->left);
        else rotateLeft(AVL, root->left);
        return;
    }

    // (5) Se o nó está desbalanceado em mais de 2 para à direita:
    if(balanceFactor(root) < -2){
        // Obs.: nesses casos deve se rotacionar o nó atual antes de seus filhos,...
        // ... pois se rotacionarmos primeiro o filho o balanceamento pode não funcionar.
        rotateLeft(AVL, root);
        root = root->father;
        if(balanceFactor(root->right) > 0) rotateRight(AVL, root->right);
        else rotateLeft(AVL, root->right);
        return;
    }
}

void balanceUp(tree *AVL, node *root){
    node *auxNode;
    auxNode = root;

    while(auxNode != NULL){
        balance(AVL, auxNode);
        auxNode = auxNode->father;
    }

    if(AVL->firstRoot->father != NULL) AVL->firstRoot = AVL->firstRoot->father;
}

node *createNode(node *father, int number){
    node *root = (node *)malloc(sizeof(node));
    root->number = number; 
    root->father = father;
    root->right = NULL;
    root->left = NULL;
    return root;
}

tree *createTree(){
    tree *AVL = (tree*)malloc(sizeof(tree));
    AVL->firstRoot = NULL;
    return AVL;
}

void rotateLeft(tree *AVL, node *root){
    if(root == NULL) return;
    node *rightRoot;
    rightRoot = root->right;
    rightRoot->father = root->father;
    if(root->father != NULL && root->father->left == root) root->father->left = rightRoot;
    else if(root->father != NULL) root->father->right = rightRoot;
    root->father = rightRoot;
    root->right = rightRoot->left;
    if(root->right != NULL) root->right->father = root;
    rightRoot->left = root;
    if(AVL->firstRoot->father != NULL) AVL->firstRoot = AVL->firstRoot->father;
    // Obs.: teremos que retornar para um dos ponteiros do pai do nó rotacionado.
    // return rightRoot;
}

void rotateRight(tree *AVL, node *root){
    if(root == NULL) return;
    node *leftRoot;
    leftRoot = root->left;
    leftRoot->father = root->father;
    if(root->father != NULL && root->father->left == root) root->father->left = leftRoot;
    else if(root->father != NULL) root->father->right = leftRoot;  
    root->father = leftRoot;
    root->left = leftRoot->right;
    if(root->left != NULL) root->left->father = root;
    leftRoot->right = root;
    if(AVL->firstRoot->father != NULL) AVL->firstRoot = AVL->firstRoot->father;
    // Obs.: teremos que retornar para um dos ponteiros do pai do nó rotacionado.
    // return leftRoot;
}

int isAVL(node *root){
    if(root == NULL) return 0;
    else if(balanceFactor(root) >=  2) return 1;
    else return isAVL(root->left) + isAVL(root->right); 
} 