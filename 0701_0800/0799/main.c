#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k = 0, *p, r = 0;

	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	for (int i = 0, m = 0; i < n; ++i)
	{
		fscanf(f, "%d", p + i);
		if (p[i] > m)
			m = p[i], k = i;
	}
	for (++k; k < n - 1; ++k)
		if (p[k] % 10 == 5 && p[k] > p[k + 1] && p[k] > r)
			r = p[k];
	if (r)
	{
		qsort(p, n, sizeof(int), cmp);
		for (int i = 0; i < n; ++i)
			if (p[i] == r && (r = i + 1))
				break;
	}
	fprintf(q, "%d", r);
	return 0;
}
