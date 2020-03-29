#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k;

	fscanf(f, "%d%d%d", &n, &m, &k);
	fprintf(q, n * m >= k ? "YES" : "NO");
	return 0;
}
