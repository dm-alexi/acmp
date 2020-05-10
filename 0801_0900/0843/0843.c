#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m, p, l;

	fscanf(f, "%d%d%d%d", &n, &m, &p, &l);
	fprintf(q, "%d %d %d", m + p + l - n, n - p - l, n - m - l);
	return 0;
}
