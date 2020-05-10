#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k, x, y, p, s = 0;
	char **t;

	fscanf(f, "%d%d%d", &n, &m, &k);
	t = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; ++i)
		t[i] = (char*)calloc(m, 1);
	while (k--)
	{
		fscanf(f, "%d%d%d", &p, &y, &x);
		if (--x >= 0 && --y >= 0 && x < m - 1 && y < n - 1)
		{
			if (p == 1 && !t[y][x + 1] && !t[y + 1][x] && !t[y + 1][x + 1])
				t[y][x + 1] = t[y + 1][x] = t[y + 1][x + 1] = 1, s += 3;
			else if (p == 2 && !t[y][x] && !t[y + 1][x] && !t[y + 1][x + 1])
				t[y][x] = t[y + 1][x] = t[y + 1][x + 1] = 1, s += 3;
			else if (p == 3 && !t[y][x] && !t[y][x + 1] && !t[y + 1][x + 1])
				t[y][x] = t[y][x + 1] = t[y + 1][x + 1] = 1, s += 3;
			else if (p == 4 && !t[y][x] && !t[y + 1][x] && !t[y][x + 1])
				t[y][x] = t[y + 1][x] = t[y][x + 1] = 1, s += 3;
		}
	}
	fprintf(q, "%d", s);
	return 0;
}
