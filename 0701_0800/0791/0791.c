#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;

	fscanf(f, "%d", &n);
	if (n > 8)
		fprintf(q, "%d ", n - 8);
	if (n % 8 != 1)
		fprintf(q, "%d ", n - 1);
	if (n % 8)
		fprintf(q, "%d ", n + 1);
	if (n < 57)
		fprintf(q, "%d ", n + 8);
	return 0;
}
