#include "prezzototale.h"

void stampa(const articolo * a, bool * current, size_t a_size) {
	for (size_t j = 0; j < a_size; j++) {
		if (current[j])
			fprintf(stdout, "%s, ", &(a[j].nome));
		
	}
	fprintf(stdout, "\n");
}

void ListaBacktracked(const articolo* a, size_t a_size, int sum, int sum_curr, size_t i, bool * current) {
	


	if (i == a_size) {	
		if (sum == sum_curr) {
			stampa(a, current, a_size);
		}
		
		return;
	}
	
	current[i] = false;
	ListaBacktracked(a, a_size, sum, sum_curr, i + 1, current);

	if (sum_curr + a[i].prezzo <= sum) {
		current[i] = true;
		ListaBacktracked(a, a_size, sum, sum_curr + a[i].prezzo, i + 1, current);
	}


}


void TrovaArticoli(const articolo* a, size_t a_size, int sum) {
	bool * current = calloc(a_size, sizeof(bool));

	ListaBacktracked(a, a_size, sum,0, 0, current);

	free(current);
}


int main(void) {

	articolo a = { .nome = "Monopoli",.prezzo = 20 };
	articolo b = { .nome = "Carcassone",.prezzo = 30 };
	articolo c = { .nome = "Perudo",.prezzo = 20 };

	articolo art[3] = { a, b, c };
	TrovaArticoli(art, 3, 50);

}