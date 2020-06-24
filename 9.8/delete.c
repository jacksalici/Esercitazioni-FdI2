#include"tree_int.h"

Node * Succ(Node *n) {
	Node *s = n;
	while (!IsEmptyTree(LeftTree(s))) {
		s = LeftTree(s);
	}
	return s;

}

void helper(Node *n, const ElemType *key) {
	if (IsEmptyTree(n))
		return;
	
	
	if (IsLeafTree(n)) {
		if (ElemCompare(GetRootValueTree(n), key) == 0) {
			DeleteTree(n);
		}
		return;
	}

	if (ElemCompare(GetRootValueTree(n), key) == 0) {
		int l, r;
		if ((l = IsEmptyTree(LeftTree(n))) != (r = IsEmptyTree(RightTree(n)))) {
			if (l)
				n->value = RightTree(n)->value;
			else
				n->value = LeftTree(n)->value;
		}
		else {
			Node * succ = Succ(n);
			n->value = succ->value;
			succ = RightTree(succ);

		}
	}

	helper(LeftTree(n), key);
	helper(RightTree(n), key);


}


Node* DeleteBstNode(Node *n, const ElemType *key) {
	if (!IsEmptyTree(n)) {
		Node *d = n;
		helper(d, key);
	}

	return n;
}


int main(void)
{
	ElemType v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	Node* n = CreateRootTree(&v[5],
		CreateRootTree(
			&v[3],
			CreateRootTree(&v[2], CreateEmptyTree(), CreateEmptyTree()),
			CreateRootTree(&v[8], CreateEmptyTree(), CreateEmptyTree())
		),
		CreateRootTree(
			&v[10],
			CreateEmptyTree(),
			CreateEmptyTree())
	);

	n = DeleteBstNode(n, &v[2]);
	DeleteTree(n);
}

