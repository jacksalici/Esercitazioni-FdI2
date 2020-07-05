void InsertSort(int * vett, int size) {
	for (int i = 1; i < size; i++) {
		int value = vett[i];
		int j;

		for (j = i - 1; j >= 0 && vett[j] > value; j--) {
			vett[j + 1] = vett[j];
		}

		vett[j + 1] = value;
	}
}

