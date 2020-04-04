#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int l, n, a, b, c;

	fscanf(f, "%d%d%d%d%d", &l, &n, &a, &b, &c);
	fprintf(q, "%d", l == 2 ? (a <= b && a <= c ? a : b < c ? b : c) : a + b + c > 2 * n ? a + b + c - 2 * n : 0);
	return 0;
}
