#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k;
	long long d;

	fscanf(f, "%d%d%I64d%d", &n, &m, &d, &k);
	fprintf(q, "%I64d", d * k * (m + n) - d * d * m * n);
	return 0;
}
