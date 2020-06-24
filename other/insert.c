#include"tree_int.h"


Node* BstInsert(const ElemType *e, Node *n) {
	if (IsEmptyTree(n))
		return CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());

	Node *d = n;

	while (!IsEmptyTree(n)) {
		if (ElemCompare(e, GetRootValueTree(n)) <= 0) {
			if (IsEmptyTree(LeftTree(n))) {
				n->left = CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
				n = LeftTree(n);
			}
			n = LeftTree(n);
		}
		else {
			if (IsEmptyTree(RightTree(n))) {
				n->right = CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
				n = RightTree(n);
			}
			n = RightTree(n);
		}
	}


	return d;
}