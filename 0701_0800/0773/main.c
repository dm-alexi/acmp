#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, k;

	fscanf(f, "%d%d", &n, &k);
	fprintf(q, "%d", n * n * k);
	return 0;
}
