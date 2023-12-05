#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"

int debug = 1;

struct Node {
	Typ info[15];
	Typ status[5];
	struct Node *left;
	struct Node *right;
};


struct Node* createNode(Typ *value, Typ *status) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL){
		return 0;
		
		if(debug == 1)
			printf("mem alloc fail");

	}
	
//	if(debug == 1)
		//printf("%s %s\n", value, status);

	strcpy(newNode->info, value);
	strcpy(newNode->status, status);

//if(debug == 1) printf("%s %s\n", newNode->info, newNode->status);
	
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}


struct Node* insertNode(struct Node* root, Typ *value, Typ *status) {
	if (root == NULL) {
		return createNode(value, status);
	}
	
	int comparison = strcmp(value, root->info);	

	if (comparison < 0) {
		root->left = insertNode(root->left, value, status);
	}
	else if (comparison < 0) {
		root->right = insertNode(root->right, value, status);
	}

	return root;
}


void inOrderTraversal(struct Node* root){
	if (root != NULL) {
		inOrderTraversal(root->left);
		printf("%s %s\n", root->info, root->status);
		inOrderTraversal(root->right);
	}
}


int treeHeight(struct Node* root) {
	if (root == NULL) {
		return 0;
	}
	else {
		int leftHeight = treeHeight(root->left);
		int rightHeight = treeHeight(root->right);
		
		return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
	}
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}


void preOrder(struct Node **root){
	if (root == NULL)
		return;
	if (*root != NULL){
		printf("%s\n", (*root)->info);
		preOrder(&((*root))->left);
		preOrder(&((*root))->right);
	}
}
