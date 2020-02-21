#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n, a, b = 1, c = 2, i = 3;

	fscanf(f, "%d", &n);
	while (c < n)
		a = b, b = c, c = a + b, ++i;
	fprintf(q, c > n ? "0" : "1\n%d", i);
	return 0;
}
