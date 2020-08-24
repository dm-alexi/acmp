#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, t[20][20];

	fscanf(f, "%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			fscanf(f, "%d", t[i] + j);
	for (int i = 1; i < n; ++i)
		t[i][0] += t[i - 1][0];
	for (int j = 1; j < m; ++j)
		t[0][j] += t[0][j - 1];
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < m; ++j)
			t[i][j] += t[i - 1][j] < t[i][j - 1] ? t[i - 1][j] : t[i][j - 1];
	fprintf(q, "%d", t[n - 1][m - 1]);
	return 0;
}
