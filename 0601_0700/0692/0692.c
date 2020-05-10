#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;

	fscanf(f, "%d", &n);
	fprintf(q, n > 0 && !(n & (n - 1)) ? "YES" : "NO");
	return 0;
}
