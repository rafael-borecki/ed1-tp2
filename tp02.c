#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char tag[9];
    int status;
    struct Node* next;
} Node;

typedef struct TreeNode {
    char tag[9];
    int status;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

Node* insertNode(Node* head, char tag[9], int status) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->tag, tag);
    newNode->status = status;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

TreeNode* insertTreeNode(TreeNode* root, char tag[9], int status) {
    if (root == NULL) {
        TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
        if (newNode == NULL) {
            // Handle memory allocation failure
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

int main() {
    Node* listHead = NULL;
    TreeNode* treeRoot = NULL;

    char tag[9];
    int status;
    FILE* file = fopen("arq.txt", "r");

    while (fscanf(file, "%s", tag) != EOF) {
        if (strcmp(tag, "x") == 0) {
            break;
        }
        fscanf(file, "%d", &status);
        listHead = insertNode(listHead, tag, status);
        treeRoot = insertTreeNode(treeRoot, tag, status);
    }
    fclose(file);

    // Sample commands (assuming you have implemented the required functionality)
    // For example, to print the list and tree:
    printList(listHead);
    printTree(treeRoot);

    // Free allocated memory (not shown in this basic example)
    
    return 0;
}

