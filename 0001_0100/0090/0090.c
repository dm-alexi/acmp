#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x, y;
} dot;

int same_side(dot g, dot h, dot v, dot w)
{
	int a = w.y - v.y, b = v.x - w.x, c = w.x * v.y - w.y * v.x, k1 = a * g.x + b * g.y + c, k2 = a * h.x + b * h.y + c;
	return (k1 > 0 && k2 > 0) || (k1 < 0 && k2 < 0);
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m = 0, *p;
	dot t, d1, d2, d3;

	fscanf(f, "%d%d%d", &t.x, &t.y, &n);
	p = (int*)malloc(sizeof(int) * n);
	for (int i = 1; i <= n; ++i)
	{
		fscanf(f, "%d%d%d%d%d%d", &d1.x, &d1.y, &d2.x, &d2.y, &d3.x, &d3.y);
		if (same_side(t, d1, d2, d3) && same_side(t, d2, d1, d3) && same_side(t, d3, d1, d2))
			p[m++] = i;
	}
	fprintf(q, "%d\n", m);
	for (int i = 0; i < m; ++i)
		fprintf(q, "%d ", p[i]);
	return 0;
}
