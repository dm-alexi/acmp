#include <stdio.h>
#include <stdlib.h>

struct team
{
	int id, num, mal;
};

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int cmp2(const void *a, const void *b)
{
	int d = ((struct team*)b)->num - ((struct team*)a)->num;

	return d ? d : ((struct team*)a)->mal - ((struct team*)b)->mal;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int k = 0, n, m, *p, c = 0;
	struct team *base;

	fscanf(f, "%d%d", &n, &m);
	base = (struct team*)malloc(sizeof(struct team) * n);
	p = (int*)malloc(sizeof(int) * (n + m));
	for (int i = 0; i < n; ++i)
	{
		fscanf(f, "%d%d%d", &base[c].id, &base[c].num, &base[c].mal);
		if (base[c].num > 0)
			++c;
	}
	if (c)
	{
		qsort(base, c, sizeof(struct team), cmp2);
		p[k++] = base[0].id;
		for (int i = 1; i < c; ++i)
			if (base[i].num == base[0].num || base[i].num > base[c / 2 - 1].num)
				p[k++] = base[i].id;
	}
	for (int i = 0, x, y, z; i < m; ++i)
	{
		fscanf(f, "%d%d%d", &x, &y, &z);
		if (y > 0)
			p[k++] = x;
	}
	qsort(p, k, sizeof(int), cmp);
	fprintf(q, "%d\n", k);
	for (int i = 0; i < k; ++i)
		fprintf(q, "%d ", p[i]);
	return 0;
}
