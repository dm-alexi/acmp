#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;

	fscanf(f, "%d", &n);
	for (int i = n; i; i &= i - 1)
		++n;
	fprintf(q, "%d", n);
	return 0;
}
