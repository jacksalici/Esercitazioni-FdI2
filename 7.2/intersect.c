#include"list_int.h"





Item* Intersect(const Item* i1, const Item* i2) {
	Item *i3 = CreateEmptyList();
	Item *c1 = i1, *c2 = i2;
	while (1) {
		ElemType *r = GetHeadValueList(c1);
		while (1) {
			Item *c22 = c2;
			ElemType *b = GetHeadValueList(c22);
			c22 = GetTailList(c22);
			if (*b == *r){
				InsertHeadList(r, i3);
				break;
			}
			if (IsEmptyList(c1))
				break;
		}


		c1 = GetTailList(c1);
		if (IsEmptyList(c1))
			break;
	}

	return i3;

}