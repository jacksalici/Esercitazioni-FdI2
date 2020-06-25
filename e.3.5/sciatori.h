#ifndef SCIATORI
#define SCIATORI

typedef struct sciatore {
	double a;
	double l;
}sciatore;

extern sciatore* Accoppia(double *altezze, double *lunghezze, int size);

#endif // !SCIATORI
