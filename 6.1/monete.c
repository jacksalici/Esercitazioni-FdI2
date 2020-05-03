#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int* Monete(int *t, int size, int b) {
	int *r = calloc(size, sizeof(int));
	
	int i = 0;
	int sum = 0;

	
	while (1) {
		
		if (i == size)
			break;

		while (sum + t[i] <= b) {
			sum += t[i];
			r[i]++;
		}

		i++;
	}
	return r;
}