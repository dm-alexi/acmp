#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, *p, *d;
	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	d = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		fscanf(f, "%d", p + i);
		d[i] = i + 1;
	}
	for (int i = n - 1, t; i > 0; --i)
		if (p[i] > 0)
		{
			t = d[i - p[i]];
			memmove(d + i - p[i], d + i - p[i] + 1, sizeof(int) * p[i]);
			d[i] = t;
		}
	for (int i = 0; i < n; ++i)
		fprintf(q, "%d ", d[i]);
	return 0;
}
