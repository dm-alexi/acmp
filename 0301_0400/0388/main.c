#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, **p, k = 0;

	fscanf(f, "%d%d", &n, &m);
	p = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i < n; ++i)
	{
		p[i] = (int*)malloc(sizeof(int) * (m + 1));
		fscanf(f, "%d", p[i]);
		p[i][m] = p[i][0];
		for (int j = 1; j < m; ++j)
		{
			fscanf(f, "%d", p[i] + j);
			if (p[i][j] < p[i][m])
				p[i][m] = p[i][j];
		}
	}
	p[n] = (int*)malloc(sizeof(int) * m);
	for (int j = 0; j < m; ++j)
	{
		p[n][j] = p[0][m];
		for (int i = 0; i < n; ++i)
			if (p[i][j] > p[n][j])
				p[n][j] = p[i][j];
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (p[i][j] == p[n][j] && p[i][j] == p[i][m])
				++k;
	fprintf(q, "%d", k);
	return 0;
}
