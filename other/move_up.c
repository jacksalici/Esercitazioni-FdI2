#include"minheap_int.h"


void MoveUpMinHeapRec(Heap *h, int i) {
	if(h->data[i] > h->data[ParentHeap(i)])
		return;
	else {
		ElemSwap(&h->data[i], &h->data[ParentHeap(i)]);
		MoveUpMinHeapRec(h, ParentHeap(i));
	}
}