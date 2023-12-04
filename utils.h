#ifndef _utils_h
#define _utils_h

typedef char Typ;
typedef struct Node {
		Typ tag[9];
		int status;
		struct Node* next;
} Node;
typedef struct TreeNode {
	Typ tag[9];
	int status;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;
Node* insertNode(Node* head, Typ tag[9], int status);
TreeNode* insertTreeNode(TreeNode* root, Typ tag[9], int status);
void printList(Node* head);
void printTree(TreeNode* root);
void printResult();
#endif
