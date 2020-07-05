#include"tree_int.h"
#include<stdio.h>
#include<stdlib.h>





void ExpressionTree(Node * n) {

	if (!IsLeafTree(n)) {

		if (LeftTree(n)->value.is_op) {
			printf("(");
			ExpressionTree(LeftTree(n));
			printf(")");
		}
		else
			ExpressionTree(LeftTree(n));
	}

	if (n->value.is_op)
		printf(" %c ", n->value.op);
	else
		printf("%d", n->value.vl);


	if (!IsLeafTree(n)) {

		if (RightTree(n)->value.is_op) {
			printf("(");
			ExpressionTree(RightTree(n));
			printf(")");
		}
		else
			ExpressionTree(RightTree(n));
	}


}


int main() {
	int v[] = { 0, 1, 2, 3, 4 };
	char op[] = { '+', '-', '*', '/' };
	Node * n = CreateRootTree()
}