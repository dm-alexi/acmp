#include <stdio.h>
#include <stdlib.h>

int deadend(char *s, int i, int n, char *t)
{
	int k = -1;

	for (int j = 0; j < n; ++j)
		if (s[i * n + j] == 1)
			if (k == -1)
				k = j;
			else return -1;
	t[i] = 1;
	return k;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, a, b;
	char *s, *t;

	fscanf(f, "%d%d", &n, &m);
	s = (char*)calloc(n * n, 1);
	t = (char*)calloc(n, 1);
	for (int i = 0; i < m; ++i)
	{
		fscanf(f, "%d%d", &a, &b);
		s[(a - 1) * n + b - 1] = s[(b - 1) * n + a - 1] = 1;
	}
	a = 0;
	while (!a)
	{
		a = 1;
		for (int i = 0; i < n; ++i)
			if (!t[i] && (b = deadend(s, i, n, t)) >= 0)
				a = s[i * n + b] = s[b * n + i] = 0;
	}
	for (a = 0; a < n * n; ++a)
		if (s[a] == 1)
			break;
	fprintf(q, a == n * n ? "NO" : "YES");
	return 0;
}
