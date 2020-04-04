#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b, c, d;

	fscanf(f, "%d%d%d%d", &a, &b, &c, &d);
	fprintf(q, (a + b) % 2 == (c + d) % 2 ? "YES" : "NO");
	return 0;
}
