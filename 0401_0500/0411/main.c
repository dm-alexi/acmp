#include <stdio.h>
#include <math.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b, c;
	double d;

	fscanf(f, "%d%d%d", &a, &b, &c);
	d = b * b - 4 * a * c;
	if (!a)
		fprintf(q, !b && !c ? "-1" : !b && c ? "0" : "1\n%f", -(double)c / b);
	else if ((d = b * b - 4.0 * a * c) <= 0)
		fprintf(q, d < 0 ? "0" : "1\n%f", -b / (2.0 * a));
	else
		fprintf(q, "2\n%f\n%f", (-b - sqrt(d)) / (2 * a), (-b + sqrt(d)) / (2 * a));
	return 0;
}
