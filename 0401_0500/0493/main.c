#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k = 0;
	char **s, c;

	fscanf(f, "%d%d", &n, &m);
	s = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; ++i)
	{
		s[i] = (char*)malloc(m);
		for (int j = 0; j < m; ++j)
		{
			while (isspace(c = getc(f)));
			s[i][j] = (c == '*');
		}
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			k += (!s[i][j] && (i == 0 || !s[i - 1][j]) && (i == n - 1 || !s[i + 1][j]) && (j == 0 || !s[i][j - 1]) && (j == m - 1 || !s[i][j + 1]));
	fprintf(q, "%d", k);
	return 0;
}
