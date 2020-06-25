#define _CRT_SECURE_NO_WARNINGS
#include"tree_int.h"
#include <stdio.h>

void TreeRec(Node *n, FILE *f) {
	if (IsEmptyTree(n))
		return;

	fprintf(f, "%d ", n->value);

	TreeRec(LeftTree(n), f);
	TreeRec(RightTree(n), f);

}


bool SaveTree(Node* t, const char *filename) {
	FILE *f = fopen(filename, "w");
	if (f == NULL) return false;

	TreeRec(t, f);
	
	return true;

}


int main() {
	int vett[] = { 1, 2, 3, 4, 5, 6, 7 };

	Node *n = CreateRootTree(
		&vett[0],
		CreateRootTree(
			&vett[1],
			CreateRootTree(&vett[2], NULL, NULL),
			CreateRootTree(&vett[3], NULL, NULL)
		),
		CreateRootTree(
			&vett[4],
			CreateRootTree(&vett[5], NULL, NULL),
			CreateRootTree(&vett[6], NULL, NULL)
			)
	);

	bool t = SaveTree(n, "text.txt");
}