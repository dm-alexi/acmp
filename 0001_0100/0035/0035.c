#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int m, n, k;

	fscanf(f, "%d", &k);
	while (k--)
	{
		fscanf(f, "%d%d", &n, &m);
		fprintf(q, "%d\n", 19 * m + (n + 239) * (n + 366) / 2);
	}
	return 0;
}
