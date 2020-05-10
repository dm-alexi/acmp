#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, m;

	fscanf(f, "%d%d", &n, &m);
	fprintf(q, "%d", m >= n ? m - n : 12 - n + m);
	return 0;
}
