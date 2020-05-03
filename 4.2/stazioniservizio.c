#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#define consumo 0.05
#define capacita 30

void ricorsione(double km_tot, int n, int i,
	double *dist, double *prezzo, double serbatoio, bool *curr, bool *best, int* min, int costo) {
	if (i != n) {

		serbatoio -= consumo * dist[i];
		if (serbatoio < 0)
			return;

		km_tot -= dist[i];
	}

	if (i == n||km_tot<=0) {
		if (*min < costo && km_tot<=0 ) {
			*min = costo; 
			for (int j = 0; j < n; j++)
				best[j] = curr[j];
		}
		return;	}

	
	//non mi fermo alla stazione i

	curr[i] = 0;
	ricorsione(km_tot, n, i + 1, dist, prezzo, serbatoio, curr, best, min, costo);


	//mi fermo alla stazione i
	
	curr[i] = 1;
	costo += ((double)capacita - (double)serbatoio)*(double)prezzo[i];
	serbatoio = capacita;
	ricorsione(km_tot, n, i + 1, dist, prezzo, serbatoio, curr, best, min, costo);

}




void StazioniServizio(double m, int n, double *d, double *p) {
	bool *vettc = malloc(n * sizeof(vettc));
	bool *vettb = malloc(n * sizeof(vettb));
	int min = -1;

	double serb = capacita;
	ricorsione(m, n, 0, d, p, serb, vettc, vettb, &min, 0);

	//stampa...
	if (min == -1)
		printf("Non esistono soluzioni");
	else
		for (int j = 0; j < n; j++)
			if (vettb[j] == 1)
				printf("%d   ", j);
	free(vettc);
	free(vettb);
}