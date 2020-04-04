#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b, c, t;

	fscanf(f, "%d%d%d%d", &a, &b, &c, &t);
	fprintf(q, "%d", t <= a ? t * b : a * b + (t - a) * c);
	return 0;
}
