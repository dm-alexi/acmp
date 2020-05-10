#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b, c;

	fscanf(f, "%d%d%d", &a, &b, &c);
	if (a > b)
		a ^= b ^= a ^= b;
	if (a > c)
		a ^= c ^= a ^= c;
	if (b > c)
		b ^= c ^= b ^= c;
	fprintf(q, "%d", c - a);
	return 0;
}
