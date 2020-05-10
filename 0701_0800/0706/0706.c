#include <stdio.h>
#include <math.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int r, x, y;

	fscanf(f, "%d%d%d", &r, &x, &y);
	fprintf(q, "%f", fabs((double)x * r / (2 * r - y)));
	return 0;
}
