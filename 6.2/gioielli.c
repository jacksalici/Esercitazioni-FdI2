#define _CRT_SECURE_NO_WARNINGS
#include"gioielli.h"
#include <stdlib.h>
#include<string.h>

Gioiello* Gioielli(const char* filename, float b, int *ret_size) {
	
	//lettura
	FILE *f = fopen(filename, "r");
	if (f == NULL)
		return NULL;
	
	int size = 0;
	Gioiello *vett = NULL;
	while (!feof(f)) {
		size++;
		vett = realloc(vett, size * sizeof(Gioiello));
		fscanf(f, "%d %f %f\n", &vett[size - 1].codice, &vett[size - 1].peso, &vett[size - 1].prezzo);
	}
	
	
	float max_peso_prezzo = vett[0].peso / vett[0].prezzo;
	//ordinamento per prezzo/peso
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			float app = vett[j].peso / vett[j].prezzo;
			if (app > max_peso_prezzo) {
				max_peso_prezzo = app;
				float temp1 = vett[i].peso;
				int temp3 = vett[i].codice;
				float temp2 = vett[i].prezzo;
				memcpy(&vett[i], &vett[j], sizeof(Gioiello));
				vett[j].peso = temp1;
				vett[j].prezzo = temp2;
				vett[j].codice = temp3;
			}
		}
	}

	*ret_size = 0;
	float peso = 0;
	int flag=0;
	Gioiello *ret = NULL;
	//greedy
	while (1) {
		if (flag == size)
			break;
		if (peso + vett[flag].peso <= b) {
			peso += vett[flag].peso;
			*ret_size++;
			ret = realloc(ret, *ret_size * sizeof(Gioiello));
			memcpy(&ret[*ret_size-1], &vett[flag], sizeof(Gioiello));
			
		}
		flag++;
	}
	fclose(f);
	free(vett);
	return ret;

}