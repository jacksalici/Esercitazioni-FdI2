#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
k: il numero di ragazzi da posizionare;
n: il numero di posti disponibili in prima fila;
i: la posizione attuale. Si noti che questo valore corrisponde al livello dell'albero di
backtrack che la funzione corrente sta esplorando;
vcurr: un array che indica lo stato degli ombrelloni in prima fila (ad esempio 1 =
occupato, 0 = libero). All'inizio dovranno essere tutti liberi;
cnt: un contatore che memorizza il numero di ragazzi posizionati nella soluzione
corrente;
nsol: il numero totale di soluzioni trovate;
*/
void ombrelloni(int k, int n, unsigned i, bool *vcurr, unsigned cnt, unsigned *nsol) {
	
	if (cnt==k) {
		(*nsol)++;
		if (i < n) {
			for (i; i < n; i++) {
				vcurr[i] = 0;
			}
		}
		//stampa soluzione
		printf("   %i)   ", (*nsol));
		for (int j = 0; j < n; j++)
			printf("%d ", vcurr[j]);
		printf("\n");
		return;
	}
	if (i == n)
		return;

	if (i==0||(i != 0 && vcurr[i - 1] == false)) {
		vcurr[i] = true;
		cnt++;
		ombrelloni(k, n, i + 1, vcurr, cnt, nsol);
		cnt--;
	}
	
	vcurr[i] = false;
	ombrelloni(k, n, i + 1, vcurr, cnt, nsol);

}