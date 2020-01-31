#include <stdio.h>
#include <stdlib.h>

typedef struct edge
{
	int a, b, dist;
} edge;

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, *d;
	edge *e;

	fscanf(f, "%d%d", &n, &m);
    d = (int*)malloc(sizeof(int) * n);
    e = (edge*)malloc(sizeof(edge) * m);
    for (int i = 1; i < n; ++i)
		d[i] = 30000;
	d[0] = 0;
	for (int i = 0; i < m; ++i)
	{
        fscanf(f, "%d%d%d", &(e[i].a), &(e[i].b), &(e[i].dist));
        --e[i].a, --e[i].b;
	}
	for (int i = 0; i < n - 1; ++i)
	{
		int stop = 1;
		for (int j = 0; j < m; ++j)
			if (d[e[j].a] < 30000 && d[e[j].b] > d[e[j].a] + e[j].dist)
				stop = 0, d[e[j].b] = d[e[j].a] + e[j].dist;
		if (stop)
			break;
	}
	for (int i = 0; i < n; ++i)
		fprintf(q, "%d ", d[i]);
    return 0;
}
