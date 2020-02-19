#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, i, j;

	fscanf(f, "%d%d%d", &n, &i, &j);
	if (i > j)
		i ^= j, j ^= i, i ^= j;
	fprintf(q, "%d", (j - i < n - j + i ? j - i : n - j + i) - 1);
	return 0;
}
