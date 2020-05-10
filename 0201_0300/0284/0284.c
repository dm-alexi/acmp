#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int *p, n;

	fscanf(f, "%d", &n);
	p = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%d", p + i);
	fscanf(f, "%d", &n);
	for (int i = 0, k, l; i < n; ++i)
	{
		fscanf(f, "%d%d", &k, &l);
		--k, --l;
		while (k <= l)
			fprintf(q, "%d ", p[k++]);
		putc('\n', q);
	}
	return 0;
}
