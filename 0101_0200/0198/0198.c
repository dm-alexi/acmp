#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void elim(double *a, double *b, int k, int n)
{
	for (int i = k + 1; i < n; ++i)
		b[i] -= a[i] * b[k];
	b[k] = 0;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	double **m, *t;
	int n, *a;

	fscanf(f, "%d", &n);
	m = (double**)malloc(sizeof(double*) * n);
	a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		m[i] = (double*)malloc(sizeof(double) * (n + 1));
		for (int j = 0; j <= n; ++j)
			fscanf(f, "%lf", m[i] + j);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n && m[i][i] == 0; ++j)
			if (m[j][i] != 0)
				t = m[i], m[i] = m[j], m[j] = t;
		for (int j = i + 1; j <= n; ++j)
			m[i][j] /= m[i][i];
		m[i][i] = 1;
		for (int j = i + 1; j < n; ++j)
			elim(m[i], m[j], i, n + 1);
	}
	for (int i = n - 1; i >= 0; --i)
	{
		for (int j = i + 1; j < n; ++j)
			m[i][n] -= m[i][j] * a[j];
		a[i] = floor(m[i][n] + 0.5);
	}
	for (int i = 0; i < n; ++i)
		fprintf(q, "%d ", a[i]);
	return 0;
}
