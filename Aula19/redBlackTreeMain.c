#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "redBlackTree.h"

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
    while(true){
        if(auxNode->number <= number && auxNode->right == RB->nullRoot){ 
            auxNode->right = createNode(RB, auxNode, number);
            return;
        }
        else if(auxNode->number > number && auxNode->left == RB->nullRoot){
            auxNode->left = createNode(RB, auxNode, number);
            return;
        }
        else if(auxNode->number <= number) auxNode = auxNode->right;
        else auxNode = auxNode->left;
    }
}

node *searchNode(node *root, int number){
    if(root->number == number || root == NULL) return root;
    else if(root->number > number) return searchNode(root->left, number);
    else return searchNode(root->right, number);
}

node *grandFather(node *root){
    node *auxNode = root;
    if(root->father != NULL){
        auxNode = root->father->father;
    }
    return auxNode;
}

node *uncle(node *root){
    node *auxNode = grandFather(root);
    if(auxNode == NULL) return NULL;
    else if(root->father == auxNode->left) return auxNode->right;
    else return auxNode->left;
}

void balanceFromLeaf(node *root){
    node *auxNode = root;
}

node *balance(tree *RB, node *root){

    // Caso (0): root é o nó incial (raiz da árvore)
    if(root->father == RB->nullRoot){
        root->color = black;
        return root;
    }
    // Solução (0): recolorir o único nó existente.


    // Obs.: Suponha que o nó argumento da função é sempre vermelho, visto que...
    // ... será sempre um nó recém adicionado (ao menos inicialmente):
    while(root->father->color == red && root->color == red){
        node *fatherRoot = root->father;
        node *grandRoot = grandFather(root);
        node *uncleRoot = uncle(root);

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
        if(root == root->father->left){

            // Caso (2): o nó tio (uncle) é preto e o nó pai é filho à direita
            if(uncleRoot->color == black && grandRoot->right == fatherRoot){
                root = rotateRight(fatherRoot);
                // Obs.: note que nesse caso é de suma importância o fato de que o nó root...
                // ... é filho à esquerda de seu nó pai.
            }
            // Solução (2): rotacionar o nó pai para a direita, para que o balanceamento...
            // ... ocorra na próxima iteração do while.

            // Caso (3): o nó tio (uncle) é preto e o nó pai é filho à esquerda
            else if(uncleRoot->color == black && grandRoot->left == fatherRoot){
                fatherRoot = rotateRight(grandRoot);
                fatherRoot->color = black;
                grandRoot->color = red;
            }
            // Solução (3): rotacionar o nó avô para o lado contrário do nó root (à direita)... 
            // ... e recolorir o nó pai original e o nó avô original (que virou nó irmão de root).
        }

        // Se o nó root é filho à direita:
        else{

            // Caso (2): o nó tio (uncle) é preto e o nó pai é filho à esquerda
            if(uncleRoot->color == black && grandRoot->right == fatherRoot){
                root = rotateLeft(fatherRoot);
                // Obs.: note que nesse caso é de suma importância o fato de que o nó root...
                // ... é filho à direita de seu nó pai.
            }
            // Solução (2): rotacionar o nó pai para a esquerda, para que o balanceamento...
            // ... ocorra na próxima iteração do while.

            // Caso (3): o nó tio (uncle) é preto e o nó pai é filho à direita
            else if(uncleRoot->color == black && grandRoot->left == fatherRoot){
                fatherRoot = rotateLeft(grandRoot);
                fatherRoot->color = black;
                grandRoot->color = red;
            }
            // Solução (3): rotacionar o nó avô para o lado contrário do nó root (à esquerda)... 
            // ... e recolorir o nó pai original e o nó avô original (que virou nó irmão de root).
        }
    }
    return root;
}

node *rotateLeft(node *root){
    if(root == NULL) return NULL;
    node *rightRoot;
    rightRoot = root->right;
    rightRoot->father = root->father;
    root->father = rightRoot;
    root->right = rightRoot->left;
    rightRoot->left = root;
    // Obs.: teremos que retornar para um dos ponteiros do pai do nó rotacionado.
    return rightRoot;
}

node *rotateRight(node *root){
    if(root == NULL) return NULL;
    node *leftRoot;
    leftRoot = root->left;
    leftRoot->father = root->father;
    root->father = leftRoot;
    root->left = leftRoot->right;
    leftRoot->right = root;
    // Obs.: teremos que retornar para um dos ponteiros do pai do nó rotacionado.
    return leftRoot;
}
