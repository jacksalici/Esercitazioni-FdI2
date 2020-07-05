void QuickSort(int vett[], int first, int last) {
	int i, j, pivot;

	while (first < last) {
		i = first;
		j = last;
		pivot = (i + j) / 2;

		int val = vett[pivot];

		do {
			while (vett[i] > val) i++;
			while (vett[j] < val) j--;

			if (i <= j) {
				int tmp = vett[i];
				vett[i] = vett[j];
				vett[j] = tmp;
				i++;
				j--;
			}


		} while (i <= j);

		QuickSort(vett, first, j);
		QuickSort(vett, i, last);
	}

	

}