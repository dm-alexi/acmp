#include <stdio.h>
#include <stdlib.h>

void upd(char **p, int n, int m, int x, int y)
{
	if (x >= 0 && y >= 0 && x < m && y < n && p[y][x] != '*')
		++p[y][x];
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k, x, y;
	char **p;

	fscanf(f, "%d%d%d", &n, &m, &k);
	p = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; ++i)
		p[i] = (char*)calloc(m, 1);
    while (k--)
	{
		fscanf(f, "%d%d", &y, &x);
		p[--y][--x] = '*';
		upd(p, n, m, x - 1, y - 1);
		upd(p, n, m, x - 1, y);
		upd(p, n, m, x - 1, y + 1);
		upd(p, n, m, x, y - 1);
		upd(p, n, m, x, y + 1);
		upd(p, n, m, x + 1, y - 1);
		upd(p, n, m, x + 1, y);
		upd(p, n, m, x + 1, y + 1);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			putc(p[i][j] == 0 ? '.' : p[i][j] == '*' ? '*' : p[i][j] + '0', q);
		putc('\n', q);
	}
	return 0;
}
