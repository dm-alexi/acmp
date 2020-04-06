#include <stdio.h>
#include <math.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int x1, y1, x2, y2;

	fscanf(f, "%d%d%d%d", &x1, &y1, &x2, &y2);
	fprintf(q, "%.5f", sqrt((double)((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))));
	return 0;
}
