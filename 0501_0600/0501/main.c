#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k = 0, m[100][100], x1, x2, y1, y2;

	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			m[i][j] = 0;
	fscanf(f, "%d", &n);
	while (n--)
	{
		fscanf(f, "%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x1 > x2)
			x1 ^= x2, x2 ^= x1, x1 ^= x2;
		if (y1 > y2)
			y1 ^= y2, y2 ^= y1, y1 ^= y2;
		for (; y1 < y2; ++y1)
			for (int i = x1; i < x2; ++i)
				++m[y1][i];
	}
	fscanf(f, "%d%d%d%d", &x1, &y1, &x2, &y2);
	if (x1 > x2)
		x1 ^= x2, x2 ^= x1, x1 ^= x2;
	if (y1 > y2)
		y1 ^= y2, y2 ^= y1, y1 ^= y2;
	for (; y1 < y2; ++y1)
		for (int i = x1; i < x2; ++i)
			k += m[y1][i];
	fprintf(q, "%d", k);
	return 0;
}
