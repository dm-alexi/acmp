#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;
	short *p, s;

	fscanf(f, "%d", &n);
	p = (short*)malloc(sizeof(short) * n * n);
	for (int i = 0; i < n * n; ++i)
		fscanf(f, "%hd", p + i);
	s = p[0] + p[1] + p[2];
	for (int i = 0; i < n * n - 2; ++i)
	{
		if (i / n < n - 2 && p[i] + p[i + n] + p[i + 2 * n] > s)
			s = p[i] + p[i + n] + p[i + 2 * n];
		if (i % n < n - 2 && p[i] + p[i + 1] + p[i + 2] > s)
			s = p[i] + p[i + 1] + p[i + 2];
		if (i / n < n - 1 && i % n > 0 && p[i] + p[i + n] + p[i + n - 1] > s)
			s = p[i] + p[i + n] + p[i + n - 1];
		if (i / n < n - 1 && i % n < n - 1 && p[i] + p[i + 1] + p[i + n] > s)
			s = p[i] + p[i + 1] + p[i + n];
		if (i / n < n - 1 && i % n < n - 1 && p[i] + p[i + 1] + p[i + n + 1] > s)
			s = p[i] + p[i + 1] + p[i + n + 1];
		if (i / n < n - 1 && i % n < n - 1 && p[i] + p[i + n] + p[i + n + 1] > s)
			s = p[i] + p[i + n] + p[i + n + 1];
	}
	fprintf(q, "%hd", s);
	return 0;
}
