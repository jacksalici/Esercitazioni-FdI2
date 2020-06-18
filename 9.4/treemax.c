	#include"tree_int.h"

	void Minm(const Node *n, const ElemType **min) {
	
	
		if ((!IsEmptyTree(n)) && ((n->value) < **min))
			(*min) = &n->value;
		
		if (IsLeafTree(n)) 
				return;
	

	
		Minm(LeftTree(n), min);
		Minm(RightTree(n), min);

	}
	const ElemType* MinTree(const Node *n) {
		if (IsEmptyTree(n))
			return NULL;
	
		const ElemType *min = GetRootValueTree(n);
	
		Minm(n, &min);

		return min;
	}