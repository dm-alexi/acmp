#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, *p, k, d = 0;

	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%d", p + i);
	fscanf(f, "%d", &k);
	for (int i = 0; i < n; ++i)
		d += (p[i] < k ? p[i] : k);
	fprintf(q, "%d", d);
	return 0;
}
