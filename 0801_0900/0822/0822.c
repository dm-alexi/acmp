#include <stdio.h>
#include <math.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	double x1, y1, x2, y2, x3, y3;

	fscanf(f, "%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
	fprintf(q, "%f", fabs(((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)) / 2));
	return 0;
}
