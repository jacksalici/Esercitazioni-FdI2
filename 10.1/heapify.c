#include"minheap_int.h"
#include <stdlib.h>	


void copy(ElemType *v_copy, const ElemType *v, size_t v_size) {
	for (size_t i = 0; i < v_size; i++) {
		v_copy[i] = v[i];	
	}
}

void reorder(ElemType *v_copy, const ElemType *v, size_t v_size) {

	copy(v_copy, v, v_size);

	for (size_t i = 0; i < v_size; i++) {
		for (size_t j = i; j < v_size; j++) {
			if (v_copy[i] > v_copy[j]) {
				v_copy[i] = v_copy[j];
			}
		}
	}

	return;
}


Heap* HeapifyMinHeap(const ElemType *v, size_t v_size) {
	Heap *h = CreateEmptyHeap();

	ElemType *v_copy = malloc(v_size * sizeof(ElemType));

	reorder(v_copy, v, v_size);

	for (size_t i = 0; i < v_size; i++) {
		h->data[i] = v_copy[i];
	}

	return h;
}