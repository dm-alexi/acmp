#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, *p, r = 0, col = 0, row = 0;

	fscanf(f, "%d%d", &n, &m);
	p = (int*)malloc(sizeof(int) * n * m);
	for (int i = 0, s = n * m; i < s; ++i)
	{
		fscanf(f, "%d", p + i);
		if (p[i] > p[r])
			r = i;
	}
	for (int i = 1, l = r % m; i < n; ++i)
		if (i != r / m && p[i * m + l] < p[col * m + l])
			col = i;
	for (int i = 1, l = r / m * m; i < m; ++i)
		if (p[l + i] < p[l + row])
			row = i;
	fprintf(q, "%d", p[col * m + row]);
	return 0;
}
