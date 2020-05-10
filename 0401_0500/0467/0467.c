#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, *p, k = 0, j = 0, s = 0;

	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * (2 * n + 2));
	for (int i = 1; i < 2 * n + 1; ++i)
		fscanf(f, "%d", p + i);
	p[0] = 0, p[2 * n + 1] = 1000000000;
	qsort(p + 1, 2 * n, sizeof(int), cmp);
	while (j < 2 * n + 1)
	{
		int h = j + 1;
		s = p[j + 1] - p[j];
		while(p[h + 1] == p[h])
			s += p[h + 2] - p[h + 1], h += 2;
		if (s > k)
			k = s;
		j = h + 1;
	}
	fprintf(q, "%d", k);
	return 0;
}
