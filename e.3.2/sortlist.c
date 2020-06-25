#include"list_int.h"

void Sorting(Item *n) {
	
	while (!IsEmptyList(n)) {
		Item *m = n;
		while (!IsEmptyList(m)) {
			if (n->value < m->value) {
				ElemType tmp = n->value;
				n->value = m->value;
				m->value = tmp;
			}
			m = GetTailList(m);
		}
		n = GetTailList(n);
	}
}



Item * SortList(Item * l) {
	if (IsEmptyList(l)) return CreateEmptyList();

	Item *n = l;
	Sorting(n);
	return l;
}

int main() {
	ElemType vett[] = { 3, 5, 7, 2, 1, 9 };
	Item * j = CreateEmptyList();
	for (int i = 0; i < 6; i++)
		j = InsertBackList(j, &vett[i]);
	
	
	WriteStdoutList(j);


	j = SortList(j);

	WriteStdoutList(j);

}

