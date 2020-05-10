#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int type;
} point;

int cmp(const void *a, const void *b)
{
	const point **c = (const point**)a, **d = (const point**)b;

	return (*c)->x - (*d)->x ? (*c)->x - (*d)->x : (*c)->type - (*d)->type;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m;
	point **p, **init;

	fscanf(f, "%d%d", &n, &m);
	init = (point**)malloc(sizeof(point*) * m);
	p = (point**)malloc(sizeof(point*) * (2 * n + m));
	for (int i = 0, a, b; i < n; ++i)
	{
		p[2 * i] = (point*)malloc(sizeof(point));
		p[2 * i + 1] = (point*)malloc(sizeof(point));
		fscanf(f, "%d%d", &a, &b);
		p[2 * i]->x = a < b ? a : b, p[2 * i + 1]->x = a < b ? b : a;
		p[2 * i]->type = 0, p[2 * i + 1]->type = 2;
	}
	for (int i = 0; i < m; ++i)
	{
		p[2 * n + i] = init[i] = (point*)malloc(sizeof(point));
		fscanf(f, "%d", &(init[i]->x));
		init[i]->type = 1;
	}
	qsort(p, 2 * n + m, sizeof(point*), cmp);
	for (int i = 0, s = 0; i < 2 * n + m; ++i)
		if (p[i]->type == 0)
			++s;
		else if (p[i]->type == 2)
			--s;
		else
			p[i]->type = s;
	for (int i = 0; i < m; ++i)
		fprintf(q, "%d ", init[i]->type);
	return 0;
}
