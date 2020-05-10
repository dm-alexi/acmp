#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n = 0;

	for (int i = 0, k; i < 31; ++i)
		fscanf(f, "%d", &k), n += k;
	fprintf(q, "%d", n / 27);
	return 0;
}
