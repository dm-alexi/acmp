#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a[3], b[3];

	fscanf(f, "%d%d%d%d%d%d", a, a + 1, a + 2, b, b + 1, b + 2);
	qsort(a, 3, sizeof(int), cmp);
	qsort(b, 3, sizeof(int), cmp);
	fprintf(q, "%d", a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
	return 0;
}
