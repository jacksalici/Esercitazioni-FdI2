#include "list_int.h"

Item * SortList(Item * l) {
	if (IsEmptyList(l)) {
		return CreateEmptyList();
	}

	Item *s = l;
	Item *m = s;
	while (!IsEmptyList(s)) {
		Item *flag = s;
		while (!IsEmptyList(flag)) {
			if (*GetHeadValueList(flag) > *GetHeadValueList(s)) {
				ElemType tmp = s->value;
				s->value = flag->value;
				flag->value = tmp;
			}
			flag = GetTailList(flag);

		}
		s = GetTailList(s);
	}

	return m;
	   
}


int main() {
	ElemType vett[] = { 3, 4, 5, 6, 7 };
	Item *old = CreateEmptyList();
	for (int i = 0; i < 5; i++) {
		old = InsertBackList(old, &vett[i]);
	}
	Item *new = SortList(old);
	WriteStdoutList(new);

}