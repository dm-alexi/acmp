#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, *p, *a, d = 0;

	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%d", p + i);
	a[n - 1] = p[n - 1];
	for (int i = n - 2; i > 0; --i)
		a[i] = (p[i] > a[i + 1] ? p[i] : a[i + 1]);
	a[d++] = p[0];
	for (int i = 1, m = p[0]; i < n - 1; ++i)
	{
		if (p[i] > m)
			m = p[i];
		if (p[i] >= m || p[i] >= a[i])
			a[d++] = p[i];
	}
	if (n > 1)
		a[d++] = p[n - 1];
	fprintf(q, "%d\n", d);
	for (int i = 0; i < d; ++i)
		fprintf(q, "%d ", a[i]);
	return 0;
}
