//Naive sort in ordine decrescente

void SelectionSort(int * vett, int size) {
	for (int i = 0; i < size; i++) {
		int j, max = i;

		for (j = 0; j < size; j++) {
			if (vett[j] > vett[max]) {
				max = j;
			}
		}

		int tmp = vett[max];
		vett[max] = vett[i];
		vett[i] = tmp;

		

}
}