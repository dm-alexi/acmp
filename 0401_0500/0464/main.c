#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k = 0;

	fscanf(f, "%d", &n);
	--n;
	while (n)
		k += n & 1, n >>= 1;
	fprintf(q, "%d", k % 3);
	return 0;
}
