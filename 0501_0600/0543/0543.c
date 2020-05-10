#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, w, d, p, s;

	fscanf(f, "%d%d%d%d", &n, &w, &d, &p);
	s = (w * n * (n - 1) / 2 - p) / d;
	fprintf(q, "%d", s ? s : n);
	return 0;
}
