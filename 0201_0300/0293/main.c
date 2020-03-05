#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, j, m = -1, *a;

	fscanf(f, "%d", &n);
	a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		fscanf(f, "%d", a + i);
	for (int i = 0, k; i < n; ++i)
	{
		fscanf(f, "%d", &k);
		if (k * a[i] > m)
			j = i, m = k * a[i];
	}
	fprintf(q, "%d", j + 1);
	return 0;
}
