#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k = 0;

	fscanf(f, "%d", &n);
	while (n)
		k = (k << 1) | (n & 1), n >>= 1;
	fprintf(q, "%d", k);
	return 0;
}
