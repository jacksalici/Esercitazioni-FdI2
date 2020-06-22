#include"secanti.h"
#include<math.h>

double f(double x, const polinomio *p) {
		double t=0;
		for (size_t i = 0; i < p->size; i++) {
			t += p->coeffs[i] * pow(x, i);
		}
		return t;
	}

	double Rec(const polinomio *p, double x0, double x1, double t, int max_iter, int iter) {
		if (fabs(x1 - x0) <= t)
			return x1;
		if (iter == max_iter)
			return x1;

		double next = x1 - ((x1 - x0) / (f(x1, p) - f(x0, p)))*f(x1, p);
		return Rec(p, x1, next, t, max_iter, iter + 1);

	}

	double Secanti(const polinomio *p, double x0, double x1, double t, int max_iter) {
		return Rec(p, x0, x1, t, max_iter, 0);
	}

int main(void) {
	int v[] = {1, 3, 0, 4};
	const polinomio p = { .coeffs = v,  .size = 4 };
	double f = Secanti(&p, 1, 8, 0.000001, 10);
}