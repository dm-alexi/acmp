#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b;

	fscanf(f, "%d%d", &a, &b);
	fprintf(q, "%d", (a - 1) * (b - 1));
	return 0;
}
