#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, a, b;

	fscanf(f, "%d", &n);
	a = n / 144;
	if((n %= 144) > 133)
        ++a, n = 0;
	b = n / 12;
	if ((n %= 12) > 9)
        ++b, n = 0;
	fprintf(q, "%d %d %d", a, b, n);
	return 0;
}
