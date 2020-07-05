#include"tree_int.h"
#include <stdlib.h>
#include <stdio.h>

void DeTreefy(int *vett, int *size, Node * n) {
	if (IsEmptyTree(n))
		return;
	*size++;
	vett = realloc(vett, *size * sizeof(int));
	vett[*size - 1] = n->value;

	DeTreefy(vett, size, LeftTree(n));
	DeTreefy(vett, size, RightTree(n));
	}



void Treefy(int *vett, int *size, Node * n, int i) {
	if (i == *size) return;
	
	n = CreateRootTree(&vett[i], CreateEmptyTree(), CreateEmptyTree());

	
	if (vett[i + 1] < vett[i])
		Treefy(vett, size, LeftTree(n), i + 1);
	else
		Treefy(vett, size, RightTree(n), i + 1);
	
}


Node * Tree2Bst(Node * t) {
	if (IsEmptyTree(t)) return CreateEmptyTree();

	int size = 0;
	int *vett;

	DeTreefy(vett, &size, t);

	Node * n = CreateEmptyTree();
	Treefy(vett, &size, n, 0);

	free(vett);
	return n;

}
