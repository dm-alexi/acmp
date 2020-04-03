#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;

	fscanf(f, "%d", &n);
	fprintf(q, "%d", n + 1);
	return 0;
}
