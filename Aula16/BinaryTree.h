typedef struct Node node;
struct Node{
    int number;
    node *father;
    node *left;
    node *right;
};
node *createNode(int number);
node *AddNode(node *root, node *father, int newNumber);
node *removeNode(node *root, int oldNumber);
int nodeHeight(node *root);