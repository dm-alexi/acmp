#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, s = 1, p;

	fscanf(f, "%d", &n);
	while (n--)
		fscanf(f, "%d", &p), s += p - 1;
	fprintf(q, "%d", s);
	return 0;
}
