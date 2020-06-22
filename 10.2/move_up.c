#include"minheap_int.h"

void MoveUpMinHeapRec(Heap *h, int i) {	if (IsEmptyHeap(h) || (h->data[ParentHeap(i)]) < h->data[i])		return;	ElemSwap(&h->data[ParentHeap(i)], &h->data[i]);	MoveUpMinHeapRec(&h[ParentHeap(i)], i);}