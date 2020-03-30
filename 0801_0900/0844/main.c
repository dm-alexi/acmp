#include <stdio.h>
#include <math.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	long long a, b, c;

	fscanf(f, "%I64d%I64d", &a, &b);
	c = sqrt(a * b);
	fprintf(q, "%I64d", c * c == a * b ? c : 0);
	return 0;
}
