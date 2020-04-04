#include <stdio.h>

#define N 75

void mult(int *a, int b)
{
	for (int i = 0; i < N; ++i)
		a[i] *= b;
	for (int i = N - 1; i > 0; --i)
		if (a[i] > 100000)
			a[i - 1] += a[i] / 100000, a[i] %= 100000;
}

void sum(int *s, int *a)
{
	for (int i = 0; i < N; ++i)
		s[i] += a[i];
	for (int i = N - 1; i > 0; --i)
		if (s[i] > 100000)
			s[i - 1] += s[i] / 100000, s[i] %= 100000;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a[N] = {0}, s[N] = {0}, n, i;

	fscanf(f, "%d", &n);
	for (i = 1, a[N - 1] = 1; i <= 8 && i <= n; ++i)
		a[N - 1] *= i, s[N - 1] += a[N - 1];
	for (; i <= n; ++i)
		mult(a, i), sum(s, a);
	for (i = 0; !s[i]; ++i);
	fprintf(q, "%d", s[i++]);
	while (i < N)
		fprintf(q, "%05d", s[i++]);
	return 0;
}

