#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, i, odd = 0, b[100];

	fscanf(f, "%d", &n);
	for (i = 0; i < n; ++i)
		fscanf(f, "%d", b + i);
	for (i = 0; i < n; ++i)
		if (b[i] % 2)
			fprintf(q, "%d ", b[i]), ++odd;
	putc('\n', q);
	for(i = 0; i < n; ++i)
		if (!(b[i] % 2))
			fprintf(q, "%d ", b[i]);
	putc('\n', q);
	fprintf(q, 2 * odd > n ? "NO" : "YES");
	return 0;
}
