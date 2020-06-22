#include<stdlib.h>
#include<stdint.h>
#include<stdio.h>

void Backtracking(size_t n, int * vettC, size_t i) {
	if (i == n) {
		int flag = 1;
		for (int j = 0; j < n - 2; j++) {
			if (!(((vettC[j] < vettC[j + 1]) && (vettC[j + 1] > vettC[j + 2])) || ((vettC[j] > vettC[j + 1]) && (vettC[j + 1] < vettC[j + 2])))) {
				flag = 0;
				break;
			}
		}
		
		if (flag) {
			fprintf(stdout, "(");
			for (int j = 0; j < n-1; j++)
				fprintf(stdout, "%i, ", vettC[j]);
			fprintf(stdout, "%i), ", vettC[n-1]);

		}
		return;
	}

	for (int j = 0; j < 3; j++) {
		vettC[i] = j;
		Backtracking(n, vettC, i + 1);
	}
}



void GolaCresta(size_t n) {
	int *VettC = malloc(n * sizeof(int));

	Backtracking(n, VettC, 0);

	free(VettC);
}



int main(void) {
	GolaCresta(3);
}