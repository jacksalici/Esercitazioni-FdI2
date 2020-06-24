#include"tree_int.h"

void Helper(const Node *m, const ElemType **Max) {

	if (ElemCompare(*Max, GetRootValueTree(m)) == 1)
		*Max = GetRootValueTree(m);

	if (!IsEmptyTree(LeftTree(m)))
		Helper(LeftTree(m), Max);

	if (!IsEmptyTree(RightTree(m)))
		Helper(RightTree(m), Max);


}



const ElemType* BstTreeMax(const Node *n) {
	if (IsEmptyTree(n)) return NULL;

	ElemType m = 0;

	const ElemType *max = &m;

	Helper(n, &max);

	return max;

}