#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;
	long long k = 1;

	fscanf(f, "%d", &n);
	while (n > 4)
		k *= 3, n -= 3;
	fprintf(q, "%I64d", k * n);
	return 0;
}
