//in ordine crescente

void BubbleSort(int * vett, int size) {
	int i = 0, ordered = 0;
	while (!ordered && i<size) {
		ordered++;
		for (int j = i; j < size - 1; j++) {
			if (vett[j] > vett[j + 1]) {
				int tmp = vett[j];
				vett[j] = vett[j + 1];
				vett[j + 1] = tmp;
				ordered--;
			}
		}
		i++;
	}
}
