#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, t[100][100], r = 1;

	fscanf(f, "%d", &n);
	for (int i = 0; i < n * n && r; ++i)
		for(int j = 0; j < n * n && r; ++j)
		{
			fscanf(f, "%d", t[i] + j);
			if (t[i][j] > n * n)
				r = 0;
		}
	for (int i = 0; i < n * n && r; ++i)
	{
		char l[101] = {0}, c[101] = {0}, k[101] = {0};
		for (int j = 0; j < n * n; ++j)
			++l[t[i][j]], ++c[t[j][i]], ++k[t[i / n * n + j / n][i % n * n + j % n]];
		for (int j = 1; j <= n * n && r; ++j)
			if (l[j] != 1 || c[j] != 1 || k[j] != 1)
				r = 0;
	}
	fprintf(q, r ? "Correct" : "Incorrect");
	return 0;
}
