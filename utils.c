#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Typ; 


typedef struct TreeNode{
	Typ tag[9];
	int status;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;



Node* insertNode(Node* head, Typ tag[9], int status);


TreeNode* insertTreeNode(TreeNode* root, Typ tag[9], int status){
	if (root == NULL) {
		TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
		if (newNode == NULL) {
			exit(EXIT_FAILURE);
		}
		newNode->left = NULL;
		newNode->right = NULL;
		strcpy(newNode->tag, tag);
		newNode->status = status;
		return newNode;
	}

	int cmp = strcmp(tag, root->tag);
	if (cmp < 0) {
		root->left = insertTreeNode(root->left, tag, status);
	} else if (cmp > 0) {
		root->right = insertTreeNode(root->right, tag, status);
	}

	return root;
}



