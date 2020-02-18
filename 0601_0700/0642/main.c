#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, s, *p, j = 0;

	fscanf(f, "%d%d", &n, &s);
	p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%d", p + i);
	qsort(p, n, sizeof(int), cmp);
	for (int k = 0; j < n && k + p[j] <= s; ++j)
		k += p[j];
	fprintf(q, "%d", j);
	return 0;
}
