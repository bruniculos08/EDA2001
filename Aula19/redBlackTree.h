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

node *addNode(tree *RB, node *root, int number);
node *removeNode(node *root);
node *createNode(tree *RB, node *father, int number);
tree *createTree();
node *searchNode(node *root);
node *rotateLeft(node *root);
node *rotateRight(node *root);
node *recolor(node *root);
node *grandFather(node *root);
node *uncle(node *root);