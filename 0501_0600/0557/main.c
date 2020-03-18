#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int m, n, y, x, p, *row, *matrix, *t, *tmp;

	fscanf(f, "%d%d%d%d%d", &m, &n, &y, &x, &p);
	--y, --x;
	row = (int*)malloc(sizeof(int) * n);
	t = (int*)malloc(sizeof(int) * n);
	matrix = (int*)malloc(sizeof(int) * n * n);
	for (int i = 0; i < n * n; ++i)
		fscanf(f, "%d", matrix + i);
	for (int i = 0; i < n; ++i)
		row[i] = matrix[y * n + i];
	while (--m)
	{
		for (int i = 0; i < n * n; ++i)
			fscanf(f, "%d", matrix + i);
		for (int i = 0; i < n; ++i)
		{
			t[i] = 0;
			for (int j = 0; j < n; ++j)
				t[i] += row[j] * matrix[j * n + i];
			t[i] %= p;
		}
		tmp = row, row = t, t = tmp;
	}
	fprintf(q, "%d", row[x]);
	return 0;
}
