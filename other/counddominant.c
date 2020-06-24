#include"tree_int.h"

void helper(const Node * t, int * n) {
	if (IsLeafTree(t)) return;

	ElemType l = 0;
	ElemType *pl = &l;
	if (!IsEmptyTree(LeftTree(t)))
		l = LeftTree(t)->value;


	ElemType r = 0;
	ElemType *pr = &r;
	if (!IsEmptyTree(RightTree(t)))
		r = RightTree(t)->value;

	if ((t->value) > (*pr) + (*pl))
		(*n)++;

	helper(LeftTree(t), n);
	helper(RightTree(t), n);

}




int CountDominant(const Node* t) {
	if (IsEmptyTree(t)) return 0;
		
	int numero = 0;

	helper(t, &numero);

	return numero;
}