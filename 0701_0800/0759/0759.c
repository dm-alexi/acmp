#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, *p, m, s = 0;

	fscanf(f, "%d%d", &n, &m);
	p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%d", p + i);
	qsort(p, n, sizeof(int), cmp);
	for (int i = n - 1; i >= 0 && p[i] > 0 && m > 0; --i, --m)
		s += p[i];
	fprintf(q, "%d", s);
	return 0;
}
