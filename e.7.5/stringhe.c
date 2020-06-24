#include <stdlib.h>
#include <stdio.h>

void print(char *c, int n) {
	printf("{ ");
	for (int i = 0; i < n; i++) {
		printf("%c", c[i]);
	}
	printf(" }, ");
}


void Helper(int n, int i, char * vettc) {
	if (i == n) {
		print(vettc, n);
		return;
	}
	
	for (int j = 0; j < n; j++) {
		vettc[i] = 'a' + j;
		Helper(n, i + 1, vettc);
	}

}


void BacktrackStr(int n) {
	if (n <= 0 || n > 26)
		return;
	
	char * vettc = malloc(n * sizeof(char));

	Helper(n, 0, vettc);

	free(vettc);

}

int main() {
	BacktrackStr(26);
}