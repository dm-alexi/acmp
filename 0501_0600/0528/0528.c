#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	long long n, k;

	fscanf(f, "%I64d%I64d", &n, &k);
	fprintf(q, "%I64d",  n + (2 + (2 + k) * (n - 2)) * (k - 1) / 2);
	return 0;
}
