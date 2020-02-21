#include <stdio.h>

int z(int n, int m)
{
	return n == 1 ? 1 : 1 + (z(n - 1, m) + m - 1) % n;
}

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int k, n;

	fscanf(f, "%d%d", &n, &k);
	fprintf(q, "%d", z(n, k));
	return 0;
}
