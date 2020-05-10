#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;

	fscanf(f, "%d", &n);
	fprintf(q, "%d %d %d", n / 6, n / 3 * 2, n / 6);
	return 0;
}
