#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	long long n;

	fscanf(f, "%I64d", &n);
	fprintf(q, "%I64d", ((n + 1) * (n + 1) * (n + 1) - n - 1) / 2);
	return 0;
}
