#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k;

	fscanf(f, "%d%d", &n, &k);
	fprintf(q,"%d %d", k - 1, n - 1);
	return 0;
}
