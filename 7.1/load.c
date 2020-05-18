#define _CRT_SECURE_NO_WARNINGS
#include"list_int.h"
#include<stdlib.h>
#include<stdint.h>

Item* LoadList(const char *filename) {
	Item *Lista = CreateEmptyList();
	
	FILE *f = fopen(filename, "r");

	if (f == NULL) {
		return Lista;
	}

	ElemType temp;
	int res = fscanf(f, " %d", &temp);
	while (1) {
		if (res == EOF)
			break;
		Lista = InsertHeadList(&temp, Lista);
		res = fscanf(f, " %d", &temp);
	}


	fclose(f);
	return Lista;

}