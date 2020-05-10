#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b, k;

	fscanf(f, "%d%d%d", &a, &b, &k);
	for (int i = 0; i < k; ++i)
		a = a % b * 10;
	fprintf(q, "%d", a / b);
	return 0;
}
