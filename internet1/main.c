


/*
Scrivere in pseudo-codice una procedura che, preso in input un intero n, stampi
tutte le stringhe di lunghezza minore o uguale ad n sull’alfabeto {a, b, c}.

*/


#include <stdlib.h>
#include <stdio.h>
#define LEN 3

void back(char **voc, int i, int l, char *al, char *num) {
	if (i == l) {
		voc[*num][i] = 0;
		return;
	}

	(*num)++;
	voc = realloc(voc, (*num)*4*sizeof(char));
	for (int j = 0; j < 3; j++) {
		voc[*num][i] = al[j];
		back(voc, i + 1, l, al, num);
	}
}

void stringhe(int l){

	char *sn = malloc((l+1)*sizeof(char));
	char **voc = malloc(1 * sizeof(sn));
	char al[3] = { 'a', 'b', 'c' };
	char num=0;
	
	back(voc, 0, l, al, &num);
	
	for (int j = 0; j < num; j++)
		printf("%s\n", voc[j]);
}


int main(void) {
	


	stringhe(LEN);

}