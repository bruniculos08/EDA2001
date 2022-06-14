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
    node *treeNode;
    queueNode *next;
};

typedef struct Queue queue;
struct Queue{
    queueNode *start;
    queueNode *end;
};

typedef struct StackNode stackNode;
struct StackNode{
    node *treeNode;
    stackNode *next;
};

typedef struct Stack stack;
struct Stack{
    stackNode *start;
};

stack *createStack();
queue *createQueue();
void insertQueue(queue *list, node *treeNode);
void insertStack(stack *list, node *treeNode);
node *removeQueue(queue *list);
node *removeStack(stack *list);
void breadthSearch(node *treeNode);
void deepSearch(node *treeNode);
void recursiveDeepSearch(node *treeNode);