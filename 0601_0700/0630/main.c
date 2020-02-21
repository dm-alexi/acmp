#include <stdio.h>
#include <stdlib.h>

struct guard
{
	int start, fin;
};

int cmp(const void *a, const void *b)
{
	return ((struct guard*)a)->start - ((struct guard*)b)->start;
}

int check(struct guard *p, int n)
{
	if (p[0].start > 0 || p[n - 1].fin < 10000 || (n > 1 && p[1].start == 0))
		return 0;
	for (int i = 1; i < n; ++i)
		if (p[i - 1].fin < p[i].start || p[i - 1].fin >= p[i].fin)
			return 0;
	for (int i = 2; i < n; ++i)
		if (p[i].start <= p[i - 2].fin)
			return 0;
	return 1;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int k, n;
	struct guard *p;

	fscanf(f, "%d", &k);
	while (k--)
	{

		fscanf(f, "%d", &n);
		p = (struct guard*)malloc(sizeof(struct guard) * n);
		for (int i = 0; i < n; ++i)
			fscanf(f, "%d%d", &p[i].start, &p[i].fin);
		qsort(p, n, sizeof(struct guard), cmp);
		fprintf(q, "%s\n", check(p, n) ? "Accepted" : "Wrong Answer");
		free(p);
	}
	return 0;
}
