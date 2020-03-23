#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;

	fscanf(f, "%d", &n);
	fprintf(q, "%d/09/%04d", !(n % 400) || (n % 100 && !(n % 4)) ? 12 : 13, n);
	return 0;
}
