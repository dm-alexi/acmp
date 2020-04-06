#include <stdio.h>
#include <math.h>

typedef struct {int x, y;} dot;

double distance(dot a, dot b)
{
	return sqrt((double)((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int i, n;
	dot d, g, t;

	fscanf(f,"%d%d%d%d%d", &g.x, &g.y, &d.x, &d.y, &n);
	for (i = 1; i <= n; ++i)
	{
		fscanf(f, "%d%d", &t.x, &t.y);
		if (2 * distance(g, t) <= distance(d, t))
			break;
	}
	fprintf(q, i > n ? "NO" : "%d", i);
	return 0;
}
