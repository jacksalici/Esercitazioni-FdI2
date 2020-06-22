#include"minheap_int.h"


void HeapsortMinHeap(Heap *h) {
	for (size_t i = 0; i <= (h->size - 1) / 2; i++) {
		ElemSwap(&h->data[i], &h->data[h->size - 1 - i]);
		MoveUpMinHeap(h, h->size - 1 - i);
	}
}
