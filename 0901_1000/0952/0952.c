#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m;

	fscanf(f, "%d%d", &n, &m);
	fprintf(q, !n && m ? "Impossible" : "%d %d", m > n ? m : n, m > 0 ? n + m - 1 : n);
	return 0;
}
