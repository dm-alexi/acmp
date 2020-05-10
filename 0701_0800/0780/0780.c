#include <stdio.h>
#include <math.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;

	fscanf(f, "%d", &n);
	fprintf(q, "%d", (int)(sqrt(1 + 8 * n) - 1) / 2);
	return 0;
}
