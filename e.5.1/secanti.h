#ifndef SEC
#define SEC
#include <stdlib.h>


typedef struct polinomio {
	int *coeffs;
	size_t size;
} polinomio;


extern double Secanti(const polinomio *p, double x0, double x1, double t, int max_iter);


#endif // !SEC
