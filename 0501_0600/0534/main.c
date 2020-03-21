#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k, d, *p;

	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%d", p + i);
	fscanf(f, "%d", &k);
	while (k--)
	{
		fscanf(f, "%d", &d);
		--p[d - 1];
	}
	for (int i = 0; i < n; ++i)
		fprintf(q, p[i] < 0 ? "yes\n" : "no\n");
	return 0;
}
