#include <stdio.h>
#include <stdlib.h>

struct point
{
	int x;
	int i;
};

int cmp(const void *a, const void *b)
{
	return ((struct point*)a)->x - ((struct point*)b)->x;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, ind = 1;
	struct point *p;

	fscanf(f, "%d", &n);
	p = (struct point*)malloc(sizeof(struct point) * n);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%d", &p[i].x), p[i].i = i;
	qsort(p, n, sizeof(struct point), cmp);
	for (int i = 2; i < n; ++i)
		if (p[i].x - p[i - 1].x < p[ind].x - p[ind - 1].x)
			ind = i;
	fprintf(q, "%d\n%d %d", p[ind].x - p[ind - 1].x, p[ind - 1].i + 1, p[ind].i + 1);
	return 0;
}
