#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b, c;

	fscanf(f, "%d%d%d", &a, &b, &c);
	fprintf(q, 2 * c <= a && 2 * c <= b ? "YES" : "NO");
	return 0;
}
