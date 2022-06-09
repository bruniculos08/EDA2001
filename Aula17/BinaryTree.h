typedef struct Node node;
struct Node{
    int number;
    node *father;
    node *left;
    node *right;
};
node *menu();
node *balance(node *root);
node *balanceAll(node *root);
node *rotateLeft(node *root);
node *rotateRight(node *root);
node *createNode(int number);
node *auxRemoveNode(node *son);
node *searchNode(node *root, int number);
node *removeNode(node *root, int oldNumber);
node *addNode(node *root, node *father, int newNumber);
int nodeHeight(node *root);
int balanceFactor(node *root);
int verifyAVL(node *root);
void printTree(node *root);

typedef struct QueueNode queueNode;
struct QueueNode{
    node *root;
    queueNode *next;
};

queueNode *createQueue(node *root);
queueNode *insertQueue(queue *list, node *root);
queueNode *removeQueue(queue *list);
void breadthSearcher(node *root);
