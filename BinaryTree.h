typedef char Typ;
struct Node* createNode(Typ *value, Typ *status);
struct Node* insertNode(struct Node* root, Typ *value, Typ *status);
void inOrderTraversal(struct Node* root);
int treeHeight(struct Node* root);
void freeTree(struct Node* root);
void preOrder(struct Node **root);

