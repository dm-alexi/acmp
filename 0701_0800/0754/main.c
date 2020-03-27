#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b, c;

	fscanf(f, "%d%d%d", &a, &b, &c);
	fprintf(q, (a < 94 || b < 94 || c < 94 || a > 727 || b > 727 || c > 727) ? "Error" : "%d", a >= b && a >= c ? a : b >= a && b >= c ? b : c);
	return 0;
}
