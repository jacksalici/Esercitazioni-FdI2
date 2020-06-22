#include"minheap_int.h"
#include <stdlib.h>	
#include <string.h>



void reorder(ElemType *v_copy, const ElemType *v, size_t v_size) {

	memcpy( v_copy, v, sizeof(ElemType)*v_size);


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
	h->size = v_size;
	h->data = malloc(v_size * sizeof(ElemType));

	ElemType *v_copy = malloc(v_size * sizeof(ElemType));

	reorder(v_copy, v, v_size);

	memcpy(h->data, v_copy, sizeof(ElemType)*v_size);

	return h;
}