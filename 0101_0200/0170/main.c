#include <stdio.h>
#include <math.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, i;

	fscanf(f, "%d", &n);
	for(i = (sqrt((double)n * 8 - 3) - 1) / 2 + 1; i > 1; --i)
		if (n > (i - 1) * i / 2 && !((n - ((i - 1) * i / 2)) % i))
			break;
	fprintf(q, "%d", i);
	return 0;
}
