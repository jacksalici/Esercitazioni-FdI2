#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void Print(char ** Current, int k) {
	printf("{ ");
	for (int i = 0; i < k-1; i++)
		printf("%s, ", Current[i]);
		printf("%s }\n", Current[k-1]);
}


bool Check(char ** Current, int k) {
	for (int i = 0; i < k; i++) {
		char Iniziale = Current[i][0];
		for (int j = i; j < k; j++) {
			if (Current[j][0] == Iniziale || Current[j][0] == Iniziale + 1 || Current[j][0] == Iniziale -1) {
				return false;
			}
		}

	}
	return true;

}

void Back(char ** Nomi, int k, int i, size_t n, char ** Current, int * r) {
	if (i == k) {
		if (Check(Current, k)) {
			Print(Current, k);
			*r++;
		}
		return;
	}

	for (size_t j = 0; j < n; j++) {
		Current[i] = Nomi[j];
		Back(Nomi, k, i+1, n, Current, r);
	}

}


int Sottogruppi(const char *filename, int k) {
	if (k <= 0) return -1;

	FILE *f = fopen(filename, "r");
	if (f == NULL) return -1;

	char Nome[20];
	size_t NumeroNomi = 2;
	char **Nomi = malloc(NumeroNomi * sizeof(Nome));
	
	
	while (!(fscanf(f, "%s\n", Nomi[NumeroNomi - 1])==EOF)) {
		NumeroNomi++;
		Nomi = realloc(Nomi, NumeroNomi * sizeof(Nome));
	}

	char **Current = malloc(k * sizeof(Nome));

	int r = 0;
	Back(Nomi, k, 0, NumeroNomi, Current, &r);

	free(Current);
	free(Nomi);
	fclose(f);
	return r;
}


int main() {
	int r = Sottogruppi("es4_input1.txt", 1);
}