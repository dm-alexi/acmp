#include <stdio.h>
#include <stdlib.h>

struct rect
{
	int x1, y1, x2, y2;
};

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k, d;
	struct rect *p;

	fscanf(f, "%d%d%d", &n, &m, &k);
	p = (struct rect*)malloc(sizeof(struct rect) * k);
	for (int i = 0; i < k; ++i)
		p[i].x1 = -1;
	for (int i = 0; i < n; ++i)
		for (int j = 0, a; j < m; ++j)
		{
			fscanf(f, "%d", &a);
			if (a == 0)
				continue;
			if (p[--a].x1 < 0)
			{
				p[a].x1 = j;
				p[a].x2 = j + 1;
				p[a].y1 = n - i - 1;
				p[a].y2 = n - i;
				d = a;
				continue;
			}
			if (j < p[a].x1)
				p[a].x1 = j;
			if (j + 1 > p[a].x2)
				p[a].x2 = j + 1;
			if (n - i - 1 < p[a].y1)
				p[a].y1 = n - i - 1;
		}
	for (int i = 0; i < k; ++i)
		if (p[i].x1 >= 0)
			fprintf(q, "%d %d %d %d\n", p[i].x1, p[i].y1, p[i].x2, p[i].y2);
		else
			fprintf(q, "%d %d %d %d\n", p[d].x1, p[d].y1, p[d].x2, p[d].y2);
	return 0;
}
