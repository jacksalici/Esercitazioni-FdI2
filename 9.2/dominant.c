#include "tree_int.h"

void counter(int *flag, const Node *t) {
	if (IsEmptyTree(t))
		return;


	if ((RightTree(t)->value + LeftTree(t)->value) < t->value)
		(*flag)++;

	counter(flag, RightTree(t));
	counter(flag, LeftTree(t));
	
}


int CountDominant(const Node* t) {
	int flag = 0;
	counter(&flag, t);
	return flag;

}