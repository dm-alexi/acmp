#include <stdio.h>
#include <stdlib.h>

struct time
{
	int t;
	int s;
};

int cmp(const void *x, const void *y)
{
	const struct time *a = (const struct time*)x, *b = (const struct time*)y;
	int d = a->t - b->t;

	if (d)
		return(d);
	return (a->s - b->s);
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k = 0, open = 0, m = 0;
	struct time *p;

	fscanf(f, "%d", &n);
	p = (struct time*)malloc(sizeof(struct time) * (2 * n + 2));
	for (int i = 0, a, b, c, d; i < n; ++i)
	{
		fscanf(f, "%d%d%d%d", &a, &b, &c, &d);
        a = a * 60 + b;
        c = c * 60 + d;
        if (a != c)
			p[k].t = a, p[k++].s = 1, p[k].t = c, p[k++].s = -1;
		if (a >= c)
			++open;
	}
	p[k].t = 0, p[k++].s = -2;
	p[k].t = 1440, p[k++].s = 2;
	qsort(p, k, sizeof(struct time), cmp);
    for (int i = 1; i < k; ++i)
	{
		if (open == n)
			m += p[i].t - p[i - 1].t;
		open += p[i].s;
	}
	fprintf(q, "%d", m);
    return 0;
}
