#include"tree_int.h"

const ElemType* BstTreeMax(const Node *n) {
	if (IsLeafTree(n))
		return &(n->value);
	else
		return BstTreeMax(n->right);
}