#include <stdio.h>
#include <stdlib.h>

unsigned readip(FILE *f)
{
	unsigned a, b, c, d;
	fscanf(f, "%u.%u.%u.%u", &a, &b, &c, &d);
	return (((((a << 8) | b) << 8) | c) << 8) | d;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m;
	unsigned *p, x, y;

	fscanf(f, "%d", &n);
	p = (unsigned*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		p[i] = readip(f);
	fscanf(f, "%d", &m);
	for (int i = 0; i < m; ++i)
	{
		int k = 0;
		x = readip(f);
		y = readip(f);
		for (int j = 0; j < n; ++j)
			if ((x & p[j]) == (y & p[j]))
				++k;
		fprintf(q, "%d\n", k);
	}
	return 0;
}
