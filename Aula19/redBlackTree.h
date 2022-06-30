enum coloring {red, black};
typedef enum coloring coloring;

typedef struct RedBlackTree tree;
struct RedBlackTree {
    node *root;
    node *nullRoot;
};

typedef struct Node node;
struct Node {
    node *father;
    node *left;
    node *right;
    coloring color;
    int number;
};

// Regras da árvore rubro negra:
// 1. Todo nó é vermelho ou preto
// 2. A nó raiz sempre será preto
// 3. Todo nó folha é preto
// 4. Se um nó é vermelho então ambos os seus filhos são pretos
// 5. Todos os caminhos de um nó até cada uma das suas folhas possui a mesma quantidade de nós pretos


node *addNode(tree *RB, node *root, int number);
node *removeNode(node *root);
node *createNode(tree *RB, node *father, int number);
tree *createTree();
node *searchNode(node *root, int number);
node *rotateLeft(node *root);
node *rotateRight(node *root);
node *recolor(node *root);
node *grandFather(node *root);
node *uncle(node *root);

