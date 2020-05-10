#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b;

	fscanf(f, "%d%d", &a, &b);
	fprintf(q, a == 1 && b == 1 ? "0" : a == b ? "2" : "1");
	return 0;
}
