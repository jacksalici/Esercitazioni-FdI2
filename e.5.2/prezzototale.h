#ifndef PREZZOTOTALE_C
#define PREZZOTOTALE_C
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct articolo {
	char nome[11];
	int prezzo;
} articolo;


extern void TrovaArticoli(const articolo* a, size_t a_size, int sum);

#endif // !PREZZOTOTALE_C
