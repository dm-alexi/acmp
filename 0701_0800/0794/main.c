#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k;

	fscanf(f, "%d%d%d", &n, &m, &k);
	fprintf(q, "%d", m < k ? n * m : n * (k - 1 + m / k));
	return 0;
}
