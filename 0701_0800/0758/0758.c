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
	long long t = 0;

	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%d", p + i);
	qsort(p, n, sizeof(int), cmp);
	if (n < 3)
		t = p[n - 1];
	else
	{
		while (n > 3)
		{
			t += p[0] + 2 * p[1] + p[n - 1] < p[n - 1] + p[n - 2] + 2 * p[0] ? p[0] + 2 * p[1] + p[n - 1] : p[n - 1] + p[n - 2] + 2 * p[0];
			n -= 2;
		}
		t += (n == 3 ? p[0] + p[1] + p[2] : p[1]);
	}
	fprintf(q, "%I64d", t);
	return 0;
}
