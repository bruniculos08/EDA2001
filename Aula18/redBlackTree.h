enum coloring {red, black};
typedef enum coloring coloring;

typedef struct Node node;
struct Node {
    node *father;
    node *left;
    node *right;
    coloring color;
    int number;
};

node *addNode(node *root);
node *removeNode(node *root);
node *createNode(int number);
node *searchNode(node *root);
node *rotateLeft(node *root);
node *rotateRight(node *root);
node *recolor(node *root);
