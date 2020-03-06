#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, *p;

	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%d", p + i);
	qsort(p, n, sizeof(int), cmp);
	for (int i = 0; i < n; i += 2)
		fprintf(q, "%d ", p[i]);
	for (int i = n - 1 - n % 2; i > 0; i -= 2)
		fprintf(q, "%d ", p[i]);
	return 0;
}
