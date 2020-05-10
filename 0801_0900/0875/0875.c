#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k;
	char **s[2];

	fscanf(f, "%d%d%d", &n, &m, &k);
	s[0] = (char**)malloc(sizeof(char*) * n);
	s[1] = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; ++i)
	{
		s[0][i] = (char*)malloc(m + 1);
		s[1][i] = (char*)malloc(m + 1);
		s[1][i][m] = '\0';
		fscanf(f, "%s", s[0][i]);
	}
	for (int l = 0; l < k; ++l)
		for (int i = 0; i < n; ++i)
			for (int j = 0, count; j < m; ++j)
			{
				count = (s[l % 2][(i - 1 + n) % n][(j - 1 + m) % m] == '*') + (s[l % 2][(i - 1 + n) % n][j] == '*') + (s[l % 2][(i - 1 + n) % n][(j + 1) % m] == '*') +
				(s[l % 2][i][(j - 1 + m) % m] == '*') + (s[l % 2][i][(j + 1) % m] == '*') + (s[l % 2][(i + 1) % n][(j - 1 + m) % m] == '*') +
				(s[l % 2][(i + 1) % n][j] == '*') + (s[l % 2][(i + 1) % n][(j + 1) % m] == '*');
				s[(l + 1) % 2][i][j] = (count == 3 || (s[l % 2][i][j] == '*' && count == 2) ? '*' : '.');
			}
	for (int i = 0; i < n; ++i)
		fprintf(q, "%s\n", s[k % 2][i]);
	return 0;
}
