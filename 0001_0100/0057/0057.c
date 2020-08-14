#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	int x, y;
} dot;

double dist(dot a, dot b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, c;
	double p, **len;
	dot *t;
	char *s = "NO";

	fscanf(f, "%d%d%lf", &n, &c, &p);
	t = (dot*)malloc(sizeof(dot) * (n + 1));
	for (int i = 0; i <= n; ++i)
		fscanf(f, "%d%d", &(t + i)->x, &(t + i)->y);
	len = (double**)malloc(sizeof(double*) * (n + 1));
	for (int i = 0; i <= n; ++i)
	{
		len[i] = (double*)malloc(sizeof(double) * (i + 1));
		for (int j = 0; j <= i; ++j)
			len[i][j] = dist(t[i], t[j]);
	}
	for (int i = 0; i < n; ++i)
	{
		double m = 0;
		for (int j = 0; j <= n; ++j)
			m += j <= i ? len[i][j] : len[j][i];
		if (m * c <= p && (s = "YES"))
			break;
	}
	fprintf(q, s);
	return 0;
}
