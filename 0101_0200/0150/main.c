#include <stdio.h>
#include <stdlib.h>

int dfs(char *m, int n, char *r, int d)
{
	int s = 1;

	r[d] = 1;
	for (int i = 0; i < n; ++i)
		if (m[d * n + i] && !r[i])
			s += dfs(m, n, r, i);
	return s;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, s, d;
	char *r, *m;

	fscanf(f, "%d%d", &n, &s);
	m = (char*)malloc(n * n);
	r = (char*)calloc(1, n);
	for (int i = 0; i < n * n; ++i)
	{
		fscanf(f, "%d", &d);
		m[i] = d;
	}
	fprintf(q, "%d", dfs(m, n, r, s - 1) - 1);
	return 0;
}
