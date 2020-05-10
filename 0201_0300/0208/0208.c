#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, k = 0, r;

	fscanf(f, "%d", &n);
	r = m = n;
	while (m >>= 1)
		++k;
	m = 1 << k;
	while (k--)
		if ((n = (n & 1 ? (n >> 1) | m : n >> 1)) > r)
			r = n;
	fprintf(q, "%d", r);
	return 0;
}
