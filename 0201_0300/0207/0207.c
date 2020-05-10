#include <stdio.h>
#include <math.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	const double s = 1 / sqrt(2.0);
	int n, p[4] = {0}, a, b;

	fscanf(f, "%d", &n);
	while (n--)
	{
		fscanf(f, "%d%d", &a, &b);
		if (a < 5)
			p[a - 1] += b;
		else
			p[(a - 1) % 4] -= b;
	}
	fprintf(q, "%.3f %.3f", p[2] + s * (p[1] + p[3]), p[0] + s * (p[1] - p[3]));
	return 0;
}
