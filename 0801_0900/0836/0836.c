#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k = 0, *p;

	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		fscanf(f, "%d", p + k);
		if (!(p[k] % 2) && p[k] & 64)
			++k;
	}
	qsort(p, k, sizeof(int), cmp);
	fprintf(q, "%d\n", k);
	for (int i = 0; i < k; ++i)
		fprintf(q, "%d ", p[i]);
	return 0;
}
