#include "list_int.h"
#include <stdio.h>
#include<stdlib.h>

bool AnyLoop(Item* l) {
	if (IsEmptyList(l))
		return false;

	Item *j = l;
	Item *b = l;
	int count;
	while (!IsEmptyList(l)) {
		j = b;
		count = 0;
		while (!IsEmptyList(j)) {
			if (j == l) {
				count++;
				if (count > 1)
					return true;
			}
			j = GetTailList(j);

		}
		if (count > 1) {
			return true;
		}
		l = GetTailList(l);
	}

	DeleteList(j);
	DeleteList(b);

	return false;
}

int main() {

	Item* list = malloc(sizeof(Item));
	Item* list2 = malloc(sizeof(Item));

	list->value = 3;
	list->next = malloc(sizeof(Item));
	list->next->value = 2;
	list->next->next = malloc(sizeof(Item));
	list->next->next->value = 1;
	list->next->next->next = list;


	printf("%d", (int)AnyLoop(list));


}