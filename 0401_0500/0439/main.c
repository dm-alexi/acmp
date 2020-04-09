#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, p;

	fscanf(f, "%d%d", &n, &p);
	fprintf(q, "%f", 1 / ((1 - p / 100.0) / n + p / 100.0));
	return 0;
}
