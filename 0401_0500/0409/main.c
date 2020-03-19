#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, a, b, m = 0;

	fscanf(f, "%d%d", &n, &a);
	for (int i = 1, k; i < n - 1; ++i)
		fscanf(f, "%d", &k), m += k;
	fscanf(f, "%d",&b);
	fprintf(q, "%f", (m + (double)(a + b) / 2) / (n - 1));
	return 0;
}
