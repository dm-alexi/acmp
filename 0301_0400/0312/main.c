#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b, n;

	fscanf(f, "%d%d%d", &a, &b, &n);
	fprintf(q, "%d", a + (n - 1) * (b - a));
	return 0;
}
