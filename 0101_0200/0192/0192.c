#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, i, *p, k;
	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; ++i)
		fscanf(f, "%d", p + i);
	i = n - 1;
	while (i > 0 && p[i] < p[i - 1])
		--i;
	if ((k = i))
	{
		for (int j = i + 1; j < n; ++j)
			if (p[j] > p[i - 1] && p[j] < p[k])
				k = j;
		p[k] ^= p[i - 1], p[i - 1] ^= p[k], p[k] ^= p[i - 1];
	}
	qsort(p + i, n - i, sizeof(int), cmp);
	for (int i = 0; i < n; ++i)
		fprintf(q, "%d ", p[i]);
	return 0;
}
