#include"minheap_int.h"
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>


bool PopMinHeap(Heap *h, ElemType *e) {
	if (IsEmptyHeap(h))
		return false;

	*e = h->data[0];

	for (size_t i = 0; i < (h->size) - 1; i++)
		h->data[i] = h->data[i + 1];

	(h->size)--;

	h->data = realloc(h->data, h->size * sizeof(ElemType));

	for (int i = (int)h->size / 2 - 1; i >= 0; i--) {
		MoveDownMinHeap(h, i);
	}
	return true;
}

