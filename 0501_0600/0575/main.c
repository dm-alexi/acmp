#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, *p, w = 0, c = 0;

	fscanf(f, "%d%d", &n, &m);
	p = (int*)malloc(sizeof(int) * n * m);
	for (int i = 0, s = n * m; i < s; ++i)
		fscanf(f, "%d", p + i);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (i < n - 1 && p[i * m + j] != p[(i + 1) * m + j])
				++w;
			if (j < m - 1 && p[i * m + j] != p[i * m + j + 1])
				++w;
			if (i < n - 1 && j < m - 1 && (p[i * m + j] != p[(i + 1) * m + j] || p[i * m + j] != p[i * m + j + 1] || p[i * m + j] != p[(i + 1) * m + j + 1]))
				++c;
		}
	fprintf(q, "%f", (0.8 * w + 0.2 * c) * 0.6);
	return 0;
}
