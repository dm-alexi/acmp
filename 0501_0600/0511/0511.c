#include <stdio.h>

int main()
{
	FILE *f = fopen("input.txt", "r"), *q = fopen("output.txt", "w");
	int n;

	fscanf(f, "%d", &n);
	n = 5 * (n - 1);
	fprintf(q, n > 720 ? "NO" : "%d %d", n / 60, n % 60);
	return 0;
}
