#include<stdlib.h>



int Quoziente(size_t x, size_t y) {
	if (y == 0)
		return -1;
	
	if (y > x)
		return 0;
	else
		return 1 + Quoziente(x - y, y);
}