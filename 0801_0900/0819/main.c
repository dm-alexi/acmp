#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	long long a, b, c;

	fscanf(f, "%I64d%I64d%I64d", &a, &b, &c);
	fprintf(q, "%I64d %I64d", 2 * (a * b + a * c + b * c), a * b * c);
	return 0;
}
