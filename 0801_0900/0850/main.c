#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b;

	fscanf(f, "%d%d", &a, &b);
	if (a > b)
		a ^= b, b ^= a, a ^= b;
	fprintf(q, "%d %d", (b + 1) / 2, a);
	return 0;
}
