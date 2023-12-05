#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "BinaryTree.h"

int main() {
	struct Node* root = NULL;
	
	char *text = readFile();
	char tmp_info[9];
	char tmp_status[2];
	
	char *token = strtok(text, "\n");
	while (*token != 'x') {
		strcpy(tmp_info,token);
		token = strtok(NULL, "\n");
		strcpy(tmp_status,token);
		root = insertNode(root, tmp_info, tmp_status);
		token = strtok(NULL, "\n");
	}
	
	execMode(root);

	//printf("%s", text);
	free(text);
	freeTree(root);
}

