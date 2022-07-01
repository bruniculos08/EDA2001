#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "redBlackTree.h"

void printTree(tree *RB, node *root){
    if(root == RB->nullRoot) return;
    printf("%i ", root->number);
    if(root->color == red) printf("red\n");
    else printf("black\n");
    printTree(RB, root->left);
    printTree(RB, root->right);
}

tree *createTree(){
    tree *RB;
    RB = (tree *)malloc(sizeof(tree));
    RB->firstRoot = NULL;
    RB->nullRoot = (node *)malloc(sizeof(node));
    RB->nullRoot->color = black;
    RB->nullRoot->father = NULL;
    RB->nullRoot->left = NULL;
    RB->nullRoot->right = NULL;
    RB->nullRoot->number = -1;
    return RB;
}

node *createNode(tree *RB, node *father, int number){
    node *auxNode = (node*)malloc(sizeof(node));
    auxNode->number = number;
    auxNode->father = father;
    auxNode->left = RB->nullRoot;
    auxNode->right = RB->nullRoot;
    auxNode->color = red;
}

void addNode(tree *RB, int number){
    node *auxNode = RB->firstRoot;

    if(auxNode == NULL || auxNode == RB->nullRoot){ 
        RB->firstRoot = createNode(RB, RB->nullRoot, number);
        balance(RB, RB->firstRoot);
        return;
    }

    while(true){
        if(auxNode->number < number && (auxNode->right == RB->nullRoot || auxNode->right == NULL)){ 
            auxNode->right = createNode(RB, auxNode, number);
            balance(RB, auxNode->right);
            return;
        }
        else if(auxNode->number >= number && (auxNode->left == RB->nullRoot || auxNode->left == NULL)){
            auxNode->left = createNode(RB, auxNode, number);
            balance(RB, auxNode->left);
            return;
        }
        else if(auxNode->number < number) auxNode = auxNode->right;
        else auxNode = auxNode->left;
    }
}

node *searchNode(node *root, int number){
    if(root->number == number || root == NULL) return root;
    else if(root->number > number) return searchNode(root->left, number);
    else return searchNode(root->right, number);
}

node *grandFather(tree *RB, node *root){
    return root->father->father;
}

node *uncle(tree *RB, node *root){
    node *auxNode = grandFather(RB, root);
    if(auxNode == RB->nullRoot) return RB->nullRoot;
    else if(root->father == auxNode->left) return auxNode->right;
    else return auxNode->left;
}

void balance(tree *RB, node *root){

    // Caso (0): root é o nó incial (raiz da árvore)
    if(root->father == RB->nullRoot){
        root->color = black;
        return;
    }
    // Solução (0): recolorir o único nó existente.


    // Obs.: Suponha que o nó argumento da função é sempre vermelho, visto que...
    // ... será sempre um nó recém adicionado (ao menos inicialmente):
    while(root->father->color == red){
        node *fatherRoot = root->father;
        node *grandRoot = grandFather(RB, root);
        node *uncleRoot = uncle(RB, root);

        // Caso (1): o nó tio (uncle) é vermelho
        if(uncleRoot->color == red){
            fatherRoot->color = black;
            uncleRoot->color = black;
            grandRoot->color = red;
            // Obs.: note que o balanceamento terá que ocorrer em todos os nós no caminho...
            // ... entre o nó folha adicionado e a raiz.
        }
        // Solução (1): recolorir o nó tio, pai e avô.

        // Se o nó root é filho à esquerda:
        else if(root == root->father->left){

            // Caso (2): o nó tio (uncle) é preto e o nó pai é filho à direita
            if(uncleRoot->color == black && grandRoot->right == fatherRoot){
                rotateRight(RB, fatherRoot);
                // Obs.: note que nesse caso é de suma importância o fato de que o nó root...
                // ... é filho à esquerda de seu nó pai.
            }
            // Solução (2): rotacionar o nó pai para a direita, para que o balanceamento...
            // ... ocorra na próxima iteração do while.

            // Caso (3): o nó tio (uncle) é preto e o nó pai é filho à esquerda
            else if(uncleRoot->color == black && grandRoot->left == fatherRoot){
                rotateRight(RB, grandRoot);
                fatherRoot->color = black;
                grandRoot->color = red;
                root = root->father->father;
            }
            // Solução (3): rotacionar o nó avô para o lado contrário do nó root (à direita)... 
            // ... e recolorir o nó pai original e o nó avô original (que virou nó irmão de root).
        }

        // Se o nó root é filho à direita:
        else{

            // Caso (2): o nó tio (uncle) é preto e o nó pai é filho à esquerda
            if(uncleRoot->color == black && grandRoot->left == fatherRoot){
                rotateLeft(RB, fatherRoot);
                // Obs.: note que nesse caso é de suma importância o fato de que o nó root...
                // ... é filho à direita de seu nó pai.
            }
            // Solução (2): rotacionar o nó pai para a esquerda, para que o balanceamento...
            // ... ocorra na próxima iteração do while.

            // Caso (3): o nó tio (uncle) é preto e o nó pai é filho à direita
            else if(uncleRoot->color == black && grandRoot->right == fatherRoot){
                rotateLeft(RB, grandRoot);
                fatherRoot->color = black;
                grandRoot->color = red;
                root = root->father->father;
            }
            // Solução (3): rotacionar o nó avô para o lado contrário do nó root (à esquerda)... 
            // ... e recolorir o nó pai original e o nó avô original (que virou nó irmão de root).
        }
    }
    RB->firstRoot->color = black;
}

void rotateLeft(tree *RB, node *root){
    if(root == RB->nullRoot) return;
    node *rightRoot;
    rightRoot = root->right;
    rightRoot->father = root->father;
    if(root->father->left == root) root->father->left = rightRoot;
    else root->father->right = rightRoot;
    root->father = rightRoot;
    root->right = rightRoot->left;
    rightRoot->left = root;
    // Obs.: teremos que retornar para um dos ponteiros do pai do nó rotacionado.
    // return rightRoot;
}

void rotateRight(tree *RB, node *root){
    if(root == RB->nullRoot) return;
    node *leftRoot;
    leftRoot = root->left;
    leftRoot->father = root->father;
    if(root->father->left == root) root->father->left = leftRoot;
    else root->father->right = leftRoot;  
    root->father = leftRoot;
    root->left = leftRoot->right;
    leftRoot->right = root;
    // Obs.: teremos que retornar para um dos ponteiros do pai do nó rotacionado.
    // return leftRoot;
}