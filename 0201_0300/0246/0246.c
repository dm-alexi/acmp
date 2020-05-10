#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, *p, m = 0;

	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%d", p + i);
	for (int i = 1; i < n; ++i)
		if (p[i] != p[i - 1] + 1)
			++m;
	fprintf(q, "%d", m);
	return 0;
}
