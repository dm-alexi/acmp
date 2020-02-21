#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int m, n, k;

	fscanf(f, "%d%d", &n, &m);
	if (m == 1 || n == 1)
		k = 4 * m * n;
	else if (m % 2 && n % 2)
		k = 2 * (m + n + m * n - 1);
	else
		k = 2 * (m + n + m * n);
	fprintf(q, "%d", k);
	return 0;
}
