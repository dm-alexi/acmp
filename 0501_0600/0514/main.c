#include <stdio.h>
#include <math.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int k;

	fscanf(f, "%d", &k);
	fprintf(q, "%d", (int)((sqrt(1 + 8 * k) - 1) / 2));
	return 0;
}
