#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define N 10

typedef struct {
	int tipologia;
	int Kcal;
	char nome[20];
} piatto;

void Backtracking(piatto *menu, piatto *curr, int cal_curr, int i, int cal) {
	if (i == 3) {
		if (cal_curr == cal)
		{
			printf("Possibile menu':\t\t");
			for (int j = 0; j < 3; j++) {
				printf("%d, %s\t\t", curr[j].tipologia, curr[j].nome);
			}
			printf("\n");
		}
		return;
	}

	for (int t = 0; t < N; t++) {
		if (menu[t].tipologia == i+1) {
			if (cal_curr + menu[t].Kcal <= cal) {
				curr[i] = menu[t];
				Backtracking(menu, curr, cal_curr + menu[t].Kcal, i + 1, cal);
			}
		}

	}


}

void Cena (piatto *menu) {
	piatto *curr = malloc(3 * sizeof(piatto));
	Backtracking(menu, curr, 0, 0, 700);
	free(curr);
}


int main(void) {
	piatto menu[N] = {
		{1, 250, "pasta"},
		{1, 300, "riso"},
		{1, 600, "lasagne"},
		{2, 400, "arrosto"},
		{2, 250, "bistecca"},
		{2, 200, "pesce"},
		{2, 50, "fils"},
		{3, 100, "patate"},
		{3, 50, "insalata"},
		{3, 200, "tonno"}
	};

	Cena(menu);
}