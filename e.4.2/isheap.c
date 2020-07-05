#include"minheap_int.h"


bool IsHeap(Heap *h) {
	if (IsEmptyHeap(h)) return true;
	for (size_t i = h->size - 1; i > 0; i--) {
		int l = h->data[ParentHeap(i)];
		int r = h->data[i];
		if ( l>r)
			return false;
	}
	return true;

}

int main(void) {

	Heap* heap = CreateEmptyHeap();
	int* data[10] = { 1,2,3,6,7,4,5,8,9,10 };
	heap->data = data;
	heap->size = 10;

	printf("%d", (int)IsHeap(heap));

}