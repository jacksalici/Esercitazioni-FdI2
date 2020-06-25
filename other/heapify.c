#include"minheap_int.h"

Heap* HeapifyMinHeap(const ElemType *v, size_t v_size) {
	
	Heap * new = CreateEmptyHeap();

	for (size_t i = 0; i < v_size; i++) {
		InsertNodeMinHeap(new, &v[i]);
	}
	
	return new;
}