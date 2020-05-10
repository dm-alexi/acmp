#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, v, l;
	double t;

	fscanf(f, "%d%d%d", &n, &v, &l);
	t = (double)l / v * 60;
	while (n--)
		fscanf(f, "%d%d", &v, &v), t += v;
	fprintf(q, "%.2f", t);
	return 0;
}
