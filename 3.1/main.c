#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void ombrelloni(int k, int n, unsigned i, bool *vcurr, unsigned cnt, unsigned *nsol);


int main(void) {

	int nsol = 0;
	bool vcurr[6];
	ombrelloni(6, 14, 0, vcurr, 0, &nsol);

}