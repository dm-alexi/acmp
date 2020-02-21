#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b, c, d;

	fscanf(f, "%d%d%d%d", &a, &b, &c, &d);
	for (long long i = -100; i <= 100; ++i)
		if (a * i * i * i + b * i * i + c * i + d == 0)
			fprintf(q,"%I64d ", i);
	return 0;
}
