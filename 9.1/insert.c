#include"tree_int.h"
void DetectorPos(const ElemType *e, Node *n) {
	
	if (ElemCompare(e , GetRootValueTree(n))==1) {
		if (!IsEmptyTree(RightTree(n))) {
			DetectorPos(e, RightTree(n));
		}
		else {
			n->right = CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
			return;
		}
	}
	else {
		if (!IsEmptyTree(LeftTree(n))) {
			DetectorPos(e, LeftTree(n));
		}
		else {
			n->left = CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
			return;
		}
	}
}

Node* BstInsert(const ElemType *e, Node *n) {
	if (IsEmptyTree(n)) {
		return CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
	}

	Node *tmp = n;

	DetectorPos(e, tmp);

	return n;
	
}