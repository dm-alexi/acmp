#include <stdio.h>
#include <math.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int l, w, h;

	fscanf(f, "%d%d%d", &l, &w, &h);
	fprintf(q, "%d", (int)ceil(2 * (l + w) * h / 16.0));
	return 0;
}
