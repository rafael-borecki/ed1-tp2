#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


Node* insertNode(Node* head, Typ tag[9], int status) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->tag, tag);
	newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
	} else {
		Node* temp = head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
	return head;
}


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


void printList(Node* head) {
	Node* temp = head;
	while (temp != NULL) {
		printf("%s %d\n", temp->tag, temp->status);
		temp = temp->next;
	}
}


void printTree(TreeNode* root) {
	if (root != NULL) {
		printf("%s %d\n", root->tag, root->status);
		printTree(root->left);
		printTree(root->right);
	}
}


void printResult(){
	int nodes_found;
	int v_nodes;
	int v_nodes_tree;
	printf("S:%d NL:%d NA: %d", nodes_found, v_nodes, v_nodes_tree);
}
