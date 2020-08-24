#include <stdio.h>
#include <stdlib.h>

int clear(char *m, int n, int x, int y)
{
	for (int i = 0; i < x; ++i)
		if (m[i * n + y])
			return 0;
	for (int i = 0; i < y; ++i)
		if (m[x * n + i])
			return 0;
	for (int i = 1; x - i >= 0 && y - i >= 0; ++i)
		if (m[(x - i) * n + y - i])
			return 0;
	for (int i = 1; x - i >= 0 && y + i < n; ++i)
		if (m[(x - i) * n + y + i])
			return 0;
	return !((x > 0 && y > 1 && m[(x - 1) * n + y - 2]) || (x > 0 && y < n - 2 && m[(x - 1) * n + y + 2]) ||
		(x > 1 && y > 0 && m[(x - 2) * n + y - 1]) || (x > 1 && y < n - 1 && m[(x - 2) * n + y + 1]));
}

void put(char *m, int n, int k, int start, int *count, int *total)
{
	for (int i = start; i <= n - k + *count; ++i)
		for (int j = 0; j < n; ++j)
			if (clear(m, n, i, j))
			{
				m[i * n + j] = 1;
				if (++*count == k)
					++*total;
				else
					put (m, n, k, i + 1, count, total);
				m[i * n + j] = 0;
				--*count;
			}
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	char *m;
	int n, k, count = 0, total = 0;

	fscanf(f, "%d%d", &n, &k);
	m = (char*)calloc(n * n, 1);
	put(m, n, k, 0, &count, &total);
	fprintf(q, "%d", total);
	return 0;
}
