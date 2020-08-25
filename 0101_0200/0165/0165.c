#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, *p;

	fscanf(f, "%d%d", &n, &m);
	p = (int*)calloc(n * m, sizeof(int));
	p[0] = 1;
	for (int i = 0, t; i < n * m - 1; ++i)
	{
		fscanf(f, "%d", &t);
		if (p[i] && t + i % m < m)
			p[t + i] += p[i];
		if (p[i] && t + i / m < n)
			p[t * m + i] += p[i];
	}
	fprintf(q, "%d", p[n * m - 1]);
	return 0;
}
