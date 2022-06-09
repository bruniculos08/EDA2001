typedef struct Node node;
struct Node{
    int number;
    node *father;
    node *left;
    node *right;
};
node *menu();
node *createNode(int number);
node *auxRemoveNode(node *son);
node *searchNode(node *root, int number);
node *removeNode(node *root, int oldNumber);
node *addNode(node *root, node *father, int newNumber);
int nodeHeight(node *root);
void printTree(node *root);
