typedef struct Node node;
struct Node{
    int number;
    node *father;
    node *left;
    node *right;
};

typedef struct Tree tree;
struct Tree{
    node *firstRoot; 
};

void addNode(tree *RB, int number);
void balance(tree *AVL, node *root);
void balanceUp(tree *AVL, node *root);
node *createNode(node *father, int number);
tree *createTree();