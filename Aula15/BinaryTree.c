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

node *addNode(node *root, node *father, int newNumber){
    // (01) Chegando na posição do nó a ser alocado:
    if(root == NULL){ 
       node *newNode = createNode(newNumber); 
       // (02) Pai aponta para o nó anterior:
       newNode->father = father; 
       return newNode;
    }
    node *auxRoot;
    auxRoot = root;
    // (03) Nó atual irá apontar para o retorno da recursão:
    if(auxRoot->number >= newNumber) auxRoot->left = addNode(auxRoot->left, auxRoot, newNumber);
    else auxRoot->right = addNode(auxRoot->right, auxRoot, newNumber); 
    // (04) Nó atual irá ser retornado pois a função deve retornar um node mantendo atualizando os ponteiros
    return auxRoot;

}

node *searchNode(node *root, int number){
    if(root == NULL) return NULL;
    node *auxRoot;
    auxRoot = root;
    while(auxRoot->number != number){
        if(auxRoot->number > number) auxRoot = auxRoot->left;
        else auxRoot = auxRoot->right;
        if(auxRoot == NULL) return NULL;
    }
    return auxRoot;
}

node *removeNode(node *root, int oldNumber){
    node *oldNode = searchNode(root, oldNumber);
    node *father = oldNode->father;
    if(oldNode->father != NULL){
        if(father->left == oldNode) father->left = auxRemoveNode(oldNode);
        else father->right = auxRemoveNode(oldNode);
        return root;
    }
    else return auxRemoveNode(oldNode);
}

node *auxRemoveNode(node *son){

    // (1) se o nó a ser removido não tem filhos:
    if(son->left == NULL && son->right == NULL){
        free(son);
        return NULL;
    }

    // (2) se o nó a ser removido só tem filho à direita:
    else if(son->left == NULL){
        node *auxSon;
        auxSon = son->right;
        auxSon->father = son->father;
        free(son);
        return auxSon;
    }

    // (3) se o nó a ser removido só tem filho à esquerda:
    else if(son->right == NULL){
        node *auxSon;
        auxSon = son->left;
        auxSon->father = son->father;
        free(son);
        return auxSon;
    }

    // (4) se o nó a ser removido tem dois filhos:

    // (4.1) encontrar o sucessor do nó a ser removido e o pai deste sucessor (nesse caso estamos...
    // ... buscando o sucessor, mas também é possível utilizar o antecessor para realizar a remoção):
    node *successor, *successorFather;
    successor = son->right;
    successorFather = son;

    // (4.2) percorrer a árvore até encontrar o sucessor e o pai do sucessor:
    while(successor->left != NULL){
        successorFather = successor;
        successor = successor->left;
    }
    // Obs.: note que andando pro filho a direita do nó removido e depois indo até o nó folha...
    // ... mais à esquerda temos então o nó com o menor valor maior que o valor do nó a ser removido,...
    // ... ou seja, temos então o nó sucessor.

    // (4.3) trocar o sucessor do nó a ser removido de lugar com o nó a ser removido:
    successorFather->left = NULL;
    successor->father = son->father;
    successor->left = son->left;
    successor->right = son->right;
    free(son);
    return successor;
    
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

void printTree(node *root){
    if(root == NULL) return;
    printf("%i\n", root->number);
    printTree(root->left);
    printTree(root->right);
}

node *menu(){
    node *l;
    l = NULL;
    int n, i;
    do
    {
        printf("Digite a opcao desejada:\n1- inserir\n2- remover\n3- buscar\n4- imprimir\n5- altura\n6- profundidade\n7- verificar AVL\n");
        scanf("%i", &n);
        switch(n)
        {
        case 1:
            printf("Digite o valor: ");
            scanf("%i", &i);
            l = addNode(l, NULL, i);
            break;
        case 2:
            printf("Digite o valor: ");
            scanf("%i", &i);
            l = removeNode(l, i);
            break;
        case 3:
            printf("Digite o valor: ");
            scanf("%i", &i);
            searchNode(l, i);
        case 4:
            printTree(l);
            break;
        case 5:
            printf("Digite o valor: ");
            scanf("%i", &i);
            node *x = searchNode(l, i);
            printf("Altura: %i\n", nodeHeight(x));
            break;
        case 6:
            // not used for now
            break;
        case 7:
            // not used for now
            break;
        default:
            break;
        }
    } while (n != 0);
    return l;
}



