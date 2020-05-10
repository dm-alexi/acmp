#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;

	fscanf(f, "%d", &n);
	fprintf(q, "%d %d %d", n / 24 * 13, n / 6, n / 24 * 7);
	return 0;
}
