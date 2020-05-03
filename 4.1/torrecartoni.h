#ifndef TORRECARTONI_H
#define TORRECARTONI_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	unsigned p; //peso
	unsigned a; //altezza
	unsigned l; //limite
}cartone;

extern void TorreCartoni(cartone *c, int n);

#endif // !TORRECARTONI_H


