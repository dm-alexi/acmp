#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int a, b, c;

	fscanf(f, "%d%d%d", &a, &b, &c);
	fprintf(q, a + b > c && a + c > b && b + c > a ? "YES" : "NO");
	return 0;
}
