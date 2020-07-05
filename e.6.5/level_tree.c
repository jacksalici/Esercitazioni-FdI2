#define _CRT_SECURE_NO_WARNINGS
#include"tree_int.h"
#include"stdio.h"
#include <stdlib.h>

Node * Treeify(int i, char vett[], int size_max, int size) {
	if (size >= size_max)
		return NULL;

	return CreateRootTree(&vett[i], Treeify(2 * i + 1, vett, size_max, size + 1), Treeify(2 * i + 2, vett, size_max, size + 2));

	
	
}

Node * ReadTree(FILE *f) {
	if (!f) return CreateEmptyTree();

	char *vett = NULL;
	int size = 0;
	char c;
	while ((c = fgetc(f))!=EOF) {
		size++;
		vett = realloc(vett, size * sizeof(char));
		vett[size - 1] = c;
	}

	Node *n = Treeify(0, vett, size, 0);
	

	free(vett);

	return n;
}

int main(void) {
	FILE *f = fopen("ciao.txt", "r");


	Node *n = ReadTree(f);

	WriteStdoutPreOrderTree(n);
}