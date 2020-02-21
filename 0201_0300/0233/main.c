#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k, i;
	fscanf(f, "%d", &n);
	for (i = 1; i <= n; ++i)
	{
		fscanf(f, "%d", &k);
		if (k <= 437)
			break;
	}
	fprintf(q, i > n ? "No crash" : "Crash %d", i);
	return 0;
}
