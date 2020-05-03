#include "torrecartoni.h"
/*
typedef struct {
	unsigned p; //peso
	unsigned a; //altezza
	unsigned l; //limite
}cartone;
*/

void ottimizzazione(cartone *c, int *best, int *curr, int n, int i, int p_tot, int h_pacchi, int h_pacchi_best, int *s ) {
	if (i == n) {
		if (h_pacchi > h_pacchi_best) {
			h_pacchi_best = h_pacchi;
			best = realloc(best, (*s) * sizeof(curr));
			for (int j = 0; j < (*s); j++) {
				best[j] = curr[j];
			}
		}
		return;
	}
	
	ottimizzazione(c, best, curr, n, i + 1, p_tot, h_pacchi, h_pacchi_best, s);

	(*s)++;
	curr = realloc(curr, (*s) * sizeof(int));

	for (int j = 0; j < n; j++) {

		//controllo che j non ci sia già
		for (int y = 0; y < (*s); y++)
			if (curr[y] == j)
				continue;
		
		if (p_tot < c[j].l) {

			
			curr[*s]= j; //cartone jesimo
			p_tot += c[j].p;
			h_pacchi += c[j].a;
			ottimizzazione(c, best, curr, n, i + 1, p_tot, h_pacchi, h_pacchi_best, s);
			p_tot -= c[j].p;
			h_pacchi -= c[j].a;
		}

	}
}

void TorreCartoni(cartone *c, int n) {
	int *best=NULL;
	int *curr=NULL;
	int s=0;
	ottimizzazione(c, best, curr, n, 0, 0, 0, 0, &s);

	for (int j = 0; j < s; j++) {
		printf("  %d", best[j]);
	}

	free(best);
	free(curr);

}