#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"


void execMode(struct Node* root) {
	int command;
	scanf("%d", &command);
	if(command == 0){
		int height = treeHeight(root);
		printf("NA:%d", height);
	}
	if(command == 1){
	}
	if(command == 2){
	}
	if(command == 3){
		preOrder(&root);
	}
}


char* readFile() {
	FILE *file = fopen("arq.txt", "r");
	
	if (file == NULL) {
		exit(EXIT_FAILURE);
	}
	
	fseek(file, 0, SEEK_END);
	long file_size = ftell(file);
	fseek(file, 0, SEEK_SET);

	char *text = (char*) malloc(file_size + 1);
	if (text == NULL) {
		exit(EXIT_FAILURE);
	}

	size_t data_read = fread(text, 1, file_size, file);
	if (data_read != file_size) {
		exit(EXIT_FAILURE);
	}
	
	text[file_size] = '\0';

	fclose(file);

	return text;

}


