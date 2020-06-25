	#include"sciatori.h"
	#include <stdlib.h>
	#include <math.h>


	sciatore* Accoppia(double *altezze, double *lunghezze, int size) {
		if (size == 0) return NULL;
		sciatore * Lista = malloc(size * sizeof(sciatore));

		for (int t = 0; t < size; t++) {
			//trova minore
			double MinRapp = 10000;
			int BestL=0, BestH=0;
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (lunghezze[j] != 0 && altezze[i] != 0) {
						if (fabs(altezze[i] - lunghezze[j]) < MinRapp) {
							MinRapp = fabs(altezze[i] - lunghezze[j]);
							BestL = j;
							BestH = i;
						}
					}
				}
			}
			Lista[t].a = altezze[BestH];
			Lista[t].l = lunghezze[BestL];
			lunghezze[BestL] = 0;
			altezze[BestH] = 0;
		}

		return Lista;

	}


int main(void) {
	double altezze[] = { 198, 161, 134, 167, 181, 178 };
	double lunghezze[] = { 177, 180, 169, 133, 160, 199 };

	sciatore * L = Accoppia(altezze, lunghezze, 6);

}