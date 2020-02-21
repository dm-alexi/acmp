#include <stdio.h>
#include <math.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int sum, mul, x, y;

	fscanf(f, "%d%d", &sum, &mul);
	y = (sum + sqrt(sum * sum - 4 * mul)) / 2;
	x = sum - y;
	if (x > y)
		x ^= y ^= x ^= y;
	fprintf(q, "%d %d", x, y);
	return 0;
}
