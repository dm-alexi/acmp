#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k = 0;
	char **s;

	fscanf(f, "%d%d", &n, &m);
	s = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; ++i)
	{
		s[i] = (char*)malloc(m);
		fscanf(f, "%s\n", s[i]);
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (s[i][j] == '#' && (i == 0 || s[i - 1][j] == '.') && (j == 0 || s[i][j - 1] == '.'))
				++k;
	fprintf(q, "%d", k);
	return 0;
}
