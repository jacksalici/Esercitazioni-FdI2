extern int* Monete(int *t, int size, int b);

int main(void) {
	int t[6] = { 50, 20, 10, 5, 2, 1 };
	int *r = Monete(t, 6, 126);
}