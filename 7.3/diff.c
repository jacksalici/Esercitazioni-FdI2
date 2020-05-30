
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
struct Item
{
	ElemType value;
	struct Item *next;
};
typedef struct Item Item;

Item *add_head_elem(Item *i, ElemType *e) {
	Item *t = malloc(sizeof(Item));
	t->next = i;
	t->value = *e;
	return t;
}

Item *return_tail(const Item *i) {
	return i->next;
}

ElemType return_head(const Item *i) {
	return i->value;
}

void item_copy(const Item *i1, const Item *i2) {
	i1->next = i2->next;
	i1->value = i2->value;

}

Item* Diff(const Item* i1, const Item* i2) {
	const Item *i3 = malloc(sizeof(Item));
	Item *ret = NULL;
	bool flag = false;

	while (i1->next!=NULL) {
		ElemType t1 = return_head(i1);
		item_copy(i3, i2);
		while (!flag || i3->next==NULL) {
			ElemType t2 = return_head(i3);

			if (t2 == t1) {
				flag = true;
				}
						
			i3 = return_tail(i3);
		}
		if (!flag) {
			ret = add_head_elem(ret, &t1);
		}
		i1 = return_tail(i1);

	}


	return ret;
}