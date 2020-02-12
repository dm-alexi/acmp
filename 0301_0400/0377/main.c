#include <stdio.h>
#include <stdlib.h>

struct point
{
	int x;
	int s;
};

int cmp(const void *a, const void *b)
{
	return ((const struct point*)a)->x - ((const struct point*)b)->x;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, l = 0;
	struct point *p;

	fscanf(f, "%d", &n);
	p = (struct point*)malloc(sizeof(struct point) * 2 * n);
	for (int i = 0; i < 2 * n; i += 2)
	{
		fscanf(f, "%d%d", &p[i].x, &p[i + 1].x);
		p[i].s = 1, p[i + 1].s = -1;
	}
	qsort(p, 2 * n, sizeof(struct point), cmp);
	for (int i = 1, s = p[0].s; i < 2 * n; ++i)
	{
		if (s > 0)
			l += p[i].x - p[i - 1].x;
		s += p[i].s;
	}
	fprintf(q, "%d", l);
	return 0;
}
