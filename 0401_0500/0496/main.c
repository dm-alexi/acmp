#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, *p, m;

	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%d", p + i);
	m = p[n - 1] + p[0] + (p[n - 2] > p[1] ? p[n - 2] : p[1]);
	for (int i = 1; i < n - 1; ++i)
		if (p[i - 1] + p[i] + p[i + 1] > m)
			m = p[i - 1] + p[i] + p[i + 1];
	fprintf(q, "%d", m);
	return 0;
}
