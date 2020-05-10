#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int max, min;

	fscanf(f, "%d%d", &min, &max);
	for (int i = 1, a; fscanf(f, "%d", &a) != EOF; ++i)
		if (i % 2 && a < min)
			min = a;
		else if (!(i % 2) && a > max)
			max = a;
	fprintf(q, "%d", max + min);
	return 0;
}
