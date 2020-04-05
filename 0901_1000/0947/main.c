#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;
	double k, s = 0;

	fscanf(f, "%lf", &k);
	for (n = 2; s < k; ++n)
		s += 1.0 / n;
	fprintf(q, "%d card(s)", n - 2);
	return 0;
}

