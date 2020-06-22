#include <stdlib.h>
#include <stdio.h>

size_t helper(int n, size_t f) {
	if (n == 1) {
		return f;
		}
	else if (n % 2 == 1) {
		n = 3 * n + 1;
		printf("%d, ", n);
		return helper(n, ++f);
	}
	else {
		n = n/2;
		printf("%d, ", n);
		return helper(n, ++f);

	}
}


size_t Hailstone(int n) {
	if (n <= 0)
		return 0;

	printf("%d, ", n);
	return helper(n, 1);
}


int main() {
	size_t size = Hailstone(5);
}