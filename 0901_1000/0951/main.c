#include <stdio.h>
#include <stdlib.h>

int dist(int x1, int y1, int x2, int y2)
{
	return (x1 > x2 ? x1 - x2 : x2 - x1) + (y1 > y2 ? y1 - y2 : y2 - y1);
}

int main()
{
    FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int m, n, k, *s, r, p, t;

	fscanf(f, "%d%d%d", &n, &m, &k);
	s = (int*)malloc(sizeof(int) * 2 * k);
	for (int i = 0; i < k; ++i)
		fscanf(f, "%d%d", s + 2 * i, s + 2 * i + 1);
	r = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			if ((p = dist(i, j, s[0], s[1])) <= r)
				continue;
			for (int d = 1; d < k; ++d)
				if ((t = dist(i, j, s[2 * d], s[2 * d + 1])) < p && (p = t) <= r)
					break;
			if (p > r)
				r = p;
		}
	fprintf(q, "%d", r);
    return 0;
}
